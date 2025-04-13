/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core input handling
*/

#include "Core.hpp"
#include <iostream>

namespace arcade {

bool Core::isKeyJustPressed(Keyboard& keyboard, Keyboard::KeyCode key, bool& previousState) {
    bool currentState = keyboard.isKeyPressed(key);
    bool justPressed = currentState && !previousState;
    previousState = currentState;

    return justPressed;
}

void Core::handleMenuInput() {
    auto& keyboard = _currentGraphicLib->getDisplay().getKeyboard();
    auto& mouse = _currentGraphicLib->getDisplay().getMouse();

    if (processMenuKeyboardInput(keyboard))
        return;
    if (mouse.isPressed()) {
        Vector<float> pos = mouse.getPos();
        this->checkMenuClicks(pos.getX(), pos.getY());
    }
}

bool Core::processMenuKeyboardInput(Keyboard& keyboard) {
    if (isKeyJustPressed(keyboard, Keyboard::KeyCode::ESCAPE, _previousEscapeState)) {
        _state = GameState::EXIT;
        return true;
    }
    if (isKeyJustPressed(keyboard, Keyboard::KeyCode::UP, _previousUpState)) {
        navigateMenuUp();
        return false;
    }
    else if (isKeyJustPressed(keyboard, Keyboard::KeyCode::DOWN, _previousDownState)) {
        navigateMenuDown();
        return false;
    }
    else if (isKeyJustPressed(keyboard, Keyboard::KeyCode::LEFT, _previousLeftState)) {
        navigateMenuLeft();
        return false;
    }
    else if (isKeyJustPressed(keyboard, Keyboard::KeyCode::RIGHT, _previousRightState)) {
        navigateMenuRight();
        return false;
    }
    if (isKeyJustPressed(keyboard, Keyboard::KeyCode::ENTER, _previousEnterState)) {
        handleMenuSelection();
        return false;
    }
    return false;
}

void Core::handleGameInput() {
    auto& keyboard = _currentGraphicLib->getDisplay().getKeyboard();

    if (isKeyJustPressed(keyboard, Keyboard::KeyCode::ESCAPE, _previousEscapeState)) {
        _state = GameState::MENU;
        return;
    }
    if (isKeyJustPressed(keyboard, Keyboard::KeyCode::A, _previousAState)) {
        tryRestartGame();
        return;
    }
}

void Core::tryRestartGame() {
    try {
        this->restartGame();
    } catch (const std::exception& e) {
        std::cerr << "Failed to restart game: " << e.what() << std::endl;
    }
}

void Core::trySwitchToNextGame() {
    try {
        _libManager->setNextGame();
        auto nextGame = _libManager->getCurrentGameLib();
        this->switchGame(nextGame->getName());
    } catch (const std::exception& e) {
        std::cerr << "Failed to switch game: " << e.what() << std::endl;
    }
}

void Core::navigateMenuUp() {
    switch (_currentMenuSection) {
        case MenuSection::GAMES:
            navigateGamesListUp();
            break;
        case MenuSection::GRAPHICS:
            navigateGraphicsListUp();
            break;
        case MenuSection::PLAYER_NAME:
            break;
    }
}

void Core::navigateGamesListUp() {
    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int gameCount = gameLibs.size();

    if (gameCount > 0)
        _selectedGameIndex = (_selectedGameIndex - 1 + gameCount) % gameCount;
}

void Core::navigateGraphicsListUp() {
    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int libCount = graphicLibs.size();

    if (libCount > 0)
        _selectedGraphicLibIndex = (_selectedGraphicLibIndex - 1 + libCount) % libCount;
}

void Core::navigateMenuDown() {
    switch (_currentMenuSection) {
        case MenuSection::GAMES:
            navigateGamesListDown();
            break;
        case MenuSection::GRAPHICS:
            navigateGraphicsListDown();
            break;
        case MenuSection::PLAYER_NAME:
            break;
    }
}

void Core::navigateGamesListDown() {
    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int gameCount = gameLibs.size();

    if (gameCount > 0)
        _selectedGameIndex = (_selectedGameIndex + 1) % gameCount;
}

void Core::navigateGraphicsListDown() {
    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int libCount = graphicLibs.size();

    if (libCount > 0)
        _selectedGraphicLibIndex = (_selectedGraphicLibIndex + 1) % libCount;
}

void Core::navigateMenuLeft() {
    switch (_currentMenuSection) {
        case MenuSection::GAMES:
            _currentMenuSection = MenuSection::PLAYER_NAME;
            break;
        case MenuSection::GRAPHICS:
            _currentMenuSection = MenuSection::GAMES;
            break;
        case MenuSection::PLAYER_NAME:
            _currentMenuSection = MenuSection::GRAPHICS;
            break;
    }
}

void Core::navigateMenuRight() {
    switch (_currentMenuSection) {
        case MenuSection::GAMES:
            _currentMenuSection = MenuSection::GRAPHICS;
            break;
        case MenuSection::GRAPHICS:
            _currentMenuSection = MenuSection::PLAYER_NAME;
            break;
        case MenuSection::PLAYER_NAME:
            _currentMenuSection = MenuSection::GAMES;
            break;
    }
}

void Core::handleMenuSelection() {
    switch (_currentMenuSection) {
        case MenuSection::GAMES:
            selectGame();
            break;
        case MenuSection::GRAPHICS:
            selectGraphicsLib();
            break;
        case MenuSection::PLAYER_NAME:
            break;
    }
}

void Core::selectGame() {
    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int index = 0;

    for (const auto& [name, lib] : gameLibs) {
        if (index == _selectedGameIndex) {
            _libManager->setCurrentGameLib(lib);
            this->initializeGameLib();
            _state = GameState::GAME;
            return;
        }
        index++;
    }
}

void Core::selectGraphicsLib() {
    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int index = 0;

    for (const auto& [name, lib] : graphicLibs) {
        if (index == _selectedGraphicLibIndex) {
            auto currentState = _state;
            auto currentGame = _libManager->getCurrentGameLib();

            switchGraphicsLib(name);
            _state = currentState;
            if (currentGame && _state == GameState::GAME)
                switchGame(currentGame->getName());
            return;
        }
        index++;
    }
}

void Core::checkMenuClicks(float mouseX, float mouseY) {
    checkGameListClicks(mouseX, mouseY);
    checkGraphicsListClicks(mouseX, mouseY);
    checkPlayerNameClick(mouseX, mouseY);
}

void Core::checkGameListClicks(float mouseX, float mouseY) {
    int gameListX = 100;
    int gameListY = 150;
    int itemHeight = 25;
    int maxWidth = 200;

    if (mouseX < gameListX || mouseX > gameListX + maxWidth)
        return;

    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int index = 0;

    for (const auto& [name, lib] : gameLibs) {
        int itemY = gameListY + 30 + (index * itemHeight);

        if (mouseY >= itemY && mouseY < itemY + itemHeight) {
            try {
                _libManager->setCurrentGameLib(lib);
                this->initializeGameLib();
                _state = GameState::GAME;
                return;
            } catch (const std::exception& e) {
                std::cerr << "Failed to start game: " << e.what() << std::endl;
            }
        }
        index++;
    }
}

void Core::checkGraphicsListClicks(float mouseX, float mouseY) {
    int graphicsListX = 500;
    int graphicsListY = 150;
    int itemHeight = 25;
    int maxWidth = 200;

    if (mouseX < graphicsListX || mouseX > graphicsListX + maxWidth)
        return;

    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int index = 0;

    for (const auto& [name, lib] : graphicLibs) {
        int itemY = graphicsListY + 30 + (index * itemHeight);

        if (mouseY >= itemY && mouseY < itemY + itemHeight) {
            try {
                auto currentState = _state;
                auto currentGame = _libManager->getCurrentGameLib();

                switchGraphicsLib(name);
                _state = currentState;
                if (currentGame && _state == GameState::GAME)
                    switchGame(currentGame->getName());
                return;
            } catch (const std::exception& e) {
                std::cerr << "Failed to switch graphics library: " << e.what() << std::endl;
            }
        }
        index++;
    }
}

void Core::checkPlayerNameClick(float mouseX, float mouseY) {
    int nameListX = 500;
    int nameListY = 400;
    int maxWidth = 200;

    if (mouseX >= nameListX && mouseX <= nameListX + maxWidth &&
        mouseY >= nameListY + 30 && mouseY < nameListY + 60)
        _currentMenuSection = MenuSection::PLAYER_NAME;
}

}
