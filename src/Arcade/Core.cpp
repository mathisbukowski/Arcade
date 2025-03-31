/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace arcade {

Core::Core(const std::string& initialLibPath)
    : _state(GameState::MENU),
      _playerName("Player"),
      _libManager(std::make_unique<DynamicLibraryManager>(initialLibPath)),
      _currentGraphicLib(nullptr),
      _currentGame(nullptr),
      _deltaTime(0.0f)
{
    initializeGraphicsLib(initialLibPath);
    loadScores();
    _lastFrameTime = std::chrono::high_resolution_clock::now();
}

Core::~Core() {
    saveScores();

    if (_currentGame) {
        _currentGame->stop();
    }

    if (_currentGraphicLib) {
        _currentGraphicLib->getDisplay().stop();
    }
}

void Core::run() {
    while (_state != GameState::EXIT) {
        updateDeltaTime();
        if (_state == GameState::MENU) {
            updateMenu();
            displayMenu();
        } else if (_state == GameState::GAME) {
            updateGame();
            displayGame();
        }
    }
}

void Core::updateDeltaTime() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    _deltaTime = std::chrono::duration<float>(currentTime - _lastFrameTime).count();
    _lastFrameTime = currentTime;
}

void Core::initializeGraphicsLib(const std::string& path) {
    try {
        _libManager->scanDirectory(path);
        auto graphicLib = _libManager->getCurrentGraphicLib();

        if (!graphicLib) {
            throw std::runtime_error("No graphic library found");
        }
        using EntryPointFunc = IDisplayLibrary* (*)();
        auto entryPointFunc = graphicLib->getFunction<EntryPointFunc>("entryPoint");
        _currentGraphicLib.reset(entryPointFunc());
        _currentGraphicLib->getDisplay().init("Arcade", 800, 600);
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize graphics library: " << e.what() << std::endl;
        throw;
    }
}

void Core::initializeGameLib() {
    try {
        auto gameLib = _libManager->getCurrentGameLib();
        if (!gameLib) {
            throw std::runtime_error("No game library found");
        }
        using EntryPointFunc = IGameModule* (*)();
        auto entryPointFunc = gameLib->getFunction<EntryPointFunc>("entryPoint");
        _currentGame.reset(entryPointFunc());
        _currentGame->init(*_currentGraphicLib);
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize game: " << e.what() << std::endl;
        throw;
    }
}

void Core::updateMenu() {
    handleMenuInput();
}

void Core::displayMenu() {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    display.clearWindow(Color(0, 0, 0));
    TextureText titleText("ARCADE", Color(255, 255, 255));
    textures.load("menu_title", titleText);
    display.drawTexture(textures.get("menu_title"), Vector<float>(300, 50));
    renderGameList(100, 150);
    renderGraphicsList(500, 150);
    renderScores(100, 350);
    renderPlayerNameInput(500, 400);
    TextureText instructionsText("Controls: F1-Next Lib, F2-Next Game, F3-Restart, ESC-Exit", Color(200, 200, 200));
    textures.load("menu_instructions", instructionsText);
    display.drawTexture(textures.get("menu_instructions"), Vector<float>(150, 550));
    display.updateWindow(_deltaTime);
}

void Core::updateGame() {
    handleGameInput();
    if (_currentGame)
        _currentGame->update(_deltaTime);
}

void Core::displayGame() {
    auto& display = _currentGraphicLib->getDisplay();

    display.clearWindow(Color(0, 0, 0));
    if (_currentGame)
        _currentGame->display();
    display.updateWindow(_deltaTime);
}

void Core::handleMenuInput() {
    auto& keyboard = _currentGraphicLib->getDisplay().getKeyboard();
    auto& mouse = _currentGraphicLib->getDisplay().getMouse();

    if (keyboard.isKeyPressed(Keyboard::KeyCode::ESCAPE)) {
        _state = GameState::EXIT;
        return;
    }
    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int gameCount = gameLibs.size();

    if (gameCount > 0) {
        if (keyboard.isKeyPressed(Keyboard::KeyCode::UP)) {
            _selectedGameIndex = (_selectedGameIndex - 1 + gameCount) % gameCount;
            return;
        }
        if (keyboard.isKeyPressed(Keyboard::KeyCode::DOWN)) {
            _selectedGameIndex = (_selectedGameIndex + 1) % gameCount;
            return;
        }

        if (keyboard.isKeyPressed(Keyboard::KeyCode::ENTER)) {
            int index = 0;
            for (const auto& [name, lib] : gameLibs) {
                if (index == _selectedGameIndex) {
                    _libManager->setCurrentGameLib(lib);
                    initializeGameLib();
                    _state = GameState::GAME;
                    return;
                }
                index++;
            }
        }
    }
    if (mouse.isPressed()) {
        Vector<float> pos = mouse.getPos();
        checkGameListClicks(pos.getX(), pos.getY());
    }
}

void Core::handleGameInput() {
    auto& keyboard = _currentGraphicLib->getDisplay().getKeyboard();
    auto& mouse = _currentGraphicLib->getDisplay().getMouse();

    if (keyboard.isKeyPressed(Keyboard::KeyCode::ESCAPE)) {
        _state = GameState::EXIT;
        return;
    }
    if (keyboard.isKeyPressed(Keyboard::KeyCode::A)) {
        try {
            initializeGameLib();
            _state = GameState::GAME;
        } catch (const std::exception& e) {
            std::cerr << "Failed to start game: " << e.what() << std::endl;
        }
        return;
    }

    if (mouse.isPressed()) {
        Vector<float> pos = mouse.getPos();
        checkGameListClicks(pos.getX(), pos.getY());
    }
    if (keyboard.isKeyPressed(Keyboard::KeyCode::KEY_2)) {
        try {
            _libManager->setNextGame();
            auto nextGame = _libManager->getCurrentGameLib();
            switchGame(nextGame->getName());
        } catch (const std::exception& e) {
            std::cerr << "Failed to switch game: " << e.what() << std::endl;
        }
        return;
    }
    if (keyboard.isKeyPressed(Keyboard::KeyCode::KEY_3)) {
        try {
            restartGame();
        } catch (const std::exception& e) {
            std::cerr << "Failed to restart game: " << e.what() << std::endl;
        }
        return;
    }
}

void Core::renderGameList(int x, int y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    TextureText gamesTitle("Games:", Color(255, 255, 255));
    textures.load("games_title", gamesTitle);
    display.drawTexture(textures.get("games_title"), Vector<float>(x, y));

    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int yOffset = 30;
    int index = 0;

    for (const auto& [name, lib] : gameLibs) {
        bool isHovered = false;
        auto& mouse = display.getMouse();
        Vector<float> mousePos = mouse.getPos();

        if (mousePos.getX() >= x && mousePos.getX() <= x + 200 &&
            mousePos.getY() >= y + yOffset && mousePos.getY() <= y + yOffset + 25) {
            isHovered = true;
        }

        bool isSelected = (index == _selectedGameIndex);

        Color textColor = Color(200, 200, 200);
        if (isSelected) {
            textColor = Color(255, 255, 0);
        } else if (isHovered) {
            textColor = Color(220, 220, 100);
        } else {
            textColor = Color(200, 200, 200);
        }
        std::string displayName = isSelected ? "> " + name : "  " + name;
        TextureText gameText(displayName, textColor);
        textures.load("game_" + std::to_string(index), gameText);
        display.drawTexture(textures.get("game_" + std::to_string(index)), Vector<float>(x, y + yOffset));
        yOffset += 25;
        index++;
    }
}

void Core::renderGraphicsList(int x, int y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    TextureText graphicsTitle("Graphics:", Color(255, 255, 255));
    textures.load("graphics_title", graphicsTitle);
    display.drawTexture(textures.get("graphics_title"), Vector<float>(x, y));

    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int yOffset = 30;

    for (const auto& [name, lib] : graphicLibs) {
        TextureText graphicText(name, Color(200, 200, 200));
        textures.load("graphic_" + name, graphicText);
        display.drawTexture(textures.get("graphic_" + name), Vector<float>(x, y + yOffset));
        yOffset += 25;
    }
}

void Core::renderScores(int x, int y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    TextureText scoresTitle("High Scores:", Color(255, 255, 255));
    textures.load("scores_title", scoresTitle);
    display.drawTexture(textures.get("scores_title"), Vector<float>(x, y));

    int yOffset = 30;
    int count = 0;

    std::sort(_scores.begin(), _scores.end(),
              [](const Score& a, const Score& b) { return a.score > b.score; });

    for (const auto& score : _scores) {
        if (count >= 10) break;

        std::string scoreText = score.playerName + " - " + score.gameName + ": " + std::to_string(score.score);
        TextureText scoreTextObj(scoreText, Color(200, 200, 200));
        textures.load("score_" + std::to_string(count), scoreTextObj);
        display.drawTexture(textures.get("score_" + std::to_string(count)), Vector<float>(x, y + yOffset));

        yOffset += 25;
        count++;
    }
}

void Core::renderPlayerNameInput(int x, int y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    TextureText nameTitle("Your Name:", Color(255, 255, 255));
    textures.load("name_title", nameTitle);
    display.drawTexture(textures.get("name_title"), Vector<float>(x, y));

    TextureText nameText(_playerName + "_", Color(255, 255, 0));
    textures.load("player_name", nameText);
    display.drawTexture(textures.get("player_name"), Vector<float>(x, y + 30));
}

void Core::loadScores() {
    std::ifstream file("scores.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open scores file. Starting with empty scores." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t firstDelim = line.find(',');
        size_t secondDelim = line.find(',', firstDelim + 1);

        if (firstDelim != std::string::npos && secondDelim != std::string::npos) {
            std::string name = line.substr(0, firstDelim);
            std::string game = line.substr(firstDelim + 1, secondDelim - firstDelim - 1);
            int score = std::stoi(line.substr(secondDelim + 1));

            _scores.emplace_back(name, game, score);
        }
    }

    file.close();
}

void Core::saveScores() {
    std::ofstream file("scores.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open scores file for writing." << std::endl;
        return;
    }
    for (const auto& score : _scores)
        file << score.playerName << "," << score.gameName << "," << score.score << std::endl;
    file.close();
}

void Core::switchGraphicsLib(const std::string& libName) {
    if (_currentGraphicLib) {
        _currentGraphicLib->getDisplay().stop();
    }

    for (const auto& [name, lib] : _libManager->getAllLibrariesByType(LibType::DISPLAY)) {
        if (name == libName) {
            using EntryPointFunc = IDisplayLibrary* (*)();
            auto entryPointFunc = lib->getFunction<EntryPointFunc>("entryPoint");

            _currentGraphicLib.reset(entryPointFunc());
            _currentGraphicLib->getDisplay().init("Arcade", 800, 600);
            if (_state == GameState::GAME && _currentGame) {
                _currentGame->stop();
                _currentGame->init(*_currentGraphicLib);
            }
            break;
        }
    }
}

void Core::switchGame(const std::string& gameName) {
    if (_currentGame)
        _currentGame->stop();
    for (const auto& [name, lib] : _libManager->getAllLibrariesByType(LibType::GAME)) {
        if (name == gameName) {
            using EntryPointFunc = IGameModule* (*)();
            auto entryPointFunc = lib->getFunction<EntryPointFunc>("entryPoint");
            _currentGame.reset(entryPointFunc());
            _currentGame->init(*_currentGraphicLib);
            std::cout << "Switched to game: " << name << std::endl;
            break;
        }
    }
}

void Core::restartGame() {
    if (_currentGame) {
        _currentGame->stop();

        auto gameLib = _libManager->getCurrentGameLib();
        using EntryPointFunc = IGameModule* (*)();
        auto entryPointFunc = gameLib->getFunction<EntryPointFunc>("entryPoint");

        _currentGame.reset(entryPointFunc());
        _currentGame->init(*_currentGraphicLib);
    }
}

void Core::goToMenu() {
    if (_state == GameState::GAME) {
        if (_currentGame)
            _currentGame->stop();
        _state = GameState::MENU;
    }
}

void Core::checkGameListClicks(float mouseX, float mouseY) {
    int listX = 100;
    int listY = 150;
    int itemHeight = 25;
    int maxWidth = 200;

    if (mouseX < listX || mouseX > listX + maxWidth)
        return;

    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int index = 0;

    for (const auto& [name, lib] : gameLibs) {
        int itemY = listY + 30 + (index * itemHeight);

        if (mouseY >= itemY && mouseY < itemY + itemHeight) {
            std::cout << "Clicked on game: " << name << std::endl;
            try {
                _libManager->setCurrentGameLib(lib);
                initializeGameLib();
                _state = GameState::GAME;
                return;
            } catch (const std::exception& e) {
                std::cerr << "Failed to start game: " << e.what() << std::endl;
            }
        }
        index++;
    }
}

}
