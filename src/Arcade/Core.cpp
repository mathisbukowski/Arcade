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
#include <thread>

namespace arcade {

Core::Core(const std::string& initialLibPath)
    : _state(GameState::MENU),
      _playerName("Player"),
      _libManager(std::make_unique<DynamicLibraryManager>(initialLibPath)),
      _currentGraphicLib(nullptr),
      _currentGame(nullptr),
      _deltaTime(0.0f)
{
    this->initializeGraphicsLib(initialLibPath);
    this->loadScores();
    _lastFrameTime = std::chrono::high_resolution_clock::now();
}

Core::~Core() {
    this->saveScores();

    if (_currentGame)
        _currentGame->stop();
    if (_currentGraphicLib)
        _currentGraphicLib->getDisplay().stop();
}

void Core::run() {
    while (_state != GameState::EXIT) {
        this->updateDeltaTime();
        if (_state == GameState::MENU) {
            this->updateMenu();
            this->displayMenu();
        } else if (_state == GameState::GAME) {
            this->updateGame();
            this->displayGame();
        }
        if (_currentGraphicLib->getDisplay().getName() == "NCURSES") {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
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

        if (!graphicLib)
            throw std::runtime_error("No graphic library found");
        using EntryPointFunc = IDisplayLibrary* (*)();
        auto entryPointFunc = graphicLib->getFunction<EntryPointFunc>("entryPoint");
        _currentGraphicLib.reset(entryPointFunc());
        _currentGraphicLib->getDisplay().init("Arcade", 800, 600);
        _resolutionScaler = std::make_unique<ResolutionScaler>(_currentGraphicLib->getDisplay());
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize graphics library: " << e.what() << std::endl;
        throw;
    }
}

void Core::initializeGameLib() {
    try {
        auto gameLib = _libManager->getCurrentGameLib();

        if (!gameLib)
            throw std::runtime_error("No game library found");

        using EntryPointFunc = IGameModule* (*)();
        auto entryPointFunc = gameLib->getFunction<EntryPointFunc>("entryPoint");
        _currentGame.reset(entryPointFunc());
        _currentGame->init(_currentGraphicLib);
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize game: " << e.what() << std::endl;
        throw;
    }
}

void Core::updateMenu() {
    this->handleMenuInput();
}

void Core::displayMenu() {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    display.clearWindow(Color(0, 0, 0));
    auto titleText = MyTexture(TextureText("Arcade", Color(255, 255, 255)));

    int result = textures.load("menu_title", titleText);
    if (result != 0)
        std::cerr << "Failed to load menu_title texture" << std::endl;

    display.drawTexture(textures.get("menu_title"), _resolutionScaler->toScreenPosition(Vector<float>(300, 50)));
    auto positionGameList = _resolutionScaler->toScreenPosition(Vector<float>(100, 150));
    auto positionGraphicsList = _resolutionScaler->toScreenPosition(Vector<float>(500, 150));
    auto positionScores = _resolutionScaler->toScreenPosition(Vector<float>(100, 350));
    auto positionPlayerName = _resolutionScaler->toScreenPosition(Vector<float>(500, 400));
    this->renderGameList(positionGameList.getX(), positionGameList.getY());
    this->renderGraphicsList(positionGraphicsList.getX(), positionGraphicsList.getY());
    this->renderScores(positionScores.getX(), positionScores.getY());
    this->renderPlayerNameInput(positionPlayerName.getX(), positionPlayerName.getY());

    auto instructionsText = MyTexture(TextureText("Controls: F1-Next Lib, F2-Next Game, F3-Restart, ESC-Exit", Color(200, 200, 200)));
    result = textures.load("menu_instructions", instructionsText);

    if (result != 0)
        std::cerr << "Failed to load menu_instructions texture" << std::endl;

    display.drawTexture(textures.get("menu_instructions"), _resolutionScaler->toScreenPosition(Vector<float>(250, 550)));
    display.updateWindow(_deltaTime);
}

void Core::updateGame() {
    this->handleGameInput();
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
                    this->initializeGameLib();
                    _state = GameState::GAME;
                    return;
                }
                index++;
            }
        }
    }
    if (mouse.isPressed()) {
        Vector<float> pos = mouse.getPos();
        this->checkGameListClicks(pos.getX(), pos.getY());
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
            this->initializeGameLib();
            _state = GameState::GAME;
        } catch (const std::exception& e) {
            std::cerr << "Failed to start game: " << e.what() << std::endl;
        }
        return;
    }

    if (mouse.isPressed()) {
        Vector<float> pos = mouse.getPos();
        this->checkGameListClicks(pos.getX(), pos.getY());
    }
    if (keyboard.isKeyPressed(Keyboard::KeyCode::KEY_2)) {
        try {
            _libManager->setNextGame();
            auto nextGame = _libManager->getCurrentGameLib();
            this->switchGame(nextGame->getName());
        } catch (const std::exception& e) {
            std::cerr << "Failed to switch game: " << e.what() << std::endl;
        }
        return;
    }
    if (keyboard.isKeyPressed(Keyboard::KeyCode::KEY_3)) {
        try {
            this->restartGame();
        } catch (const std::exception& e) {
            std::cerr << "Failed to restart game: " << e.what() << std::endl;
        }
        return;
    }
}

void Core::renderGameList(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    auto gamesTitle = MyTexture(TextureText("Games:", Color(255, 255, 255)));
    int result = textures.load("games_title", gamesTitle);
    if (result != 0)
        std::cerr << "Failed to load games_title texture" << std::endl;

    display.drawTexture(textures.get("games_title"), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));

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
        auto gameText = MyTexture(TextureText(displayName, textColor));

        int result = textures.load("game_" + std::to_string(index), gameText);
        if (result != 0)
            std::cerr << "Failed to load game_" << index << " texture" << std::endl;

        display.drawTexture(textures.get("game_" + std::to_string(index)), _resolutionScaler->toScreenPosition(Vector<float>(x, y + yOffset)));
        yOffset += 25;
        index++;
    }
}

void Core::renderGraphicsList(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    auto graphicsTitle = MyTexture(TextureText("Graphics Libraries:", Color(255, 255, 255)));
    int result = textures.load("graphics_title", graphicsTitle);
    if (result != 0)
        std::cerr << "Failed to load graphics_title texture" << std::endl;

    display.drawTexture(textures.get("graphics_title"), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));

    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int yOffset = 30;

    for (const auto& [name, lib] : graphicLibs) {
        auto graphicText = MyTexture(TextureText(name, Color(200, 200, 200)));
        int result = textures.load("graphic_" + name, graphicText);
        if (result != 0)
            std::cerr << "Failed to load graphic_" << name << " texture" << std::endl;

        display.drawTexture(textures.get("graphic_" + name), _resolutionScaler->toScreenPosition(Vector<float>(x, y + yOffset)));
        yOffset += 25;
    }
}

void Core::renderScores(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    auto scoresTitle = MyTexture(TextureText("Scores:", Color(255, 255, 255)));
    int result = textures.load("scores_title", scoresTitle);
    if (result != 0)
        std::cerr << "Failed to load scores_title texture" << std::endl;

    display.drawTexture(textures.get("scores_title"), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));

    int yOffset = 30;
    int count = 0;

    std::sort(_scores.begin(), _scores.end(),
              [](const Score& a, const Score& b) { return a.score > b.score; });

    for (const auto& score : _scores) {
        if (count >= 10) break;

        std::string scoreText = score.playerName + " - " + score.gameName + ": " + std::to_string(score.score);
        auto scoreTextObj = MyTexture(TextureText(scoreText, Color(200, 200, 200)));

        int result = textures.load("score_" + std::to_string(count), scoreTextObj);
        if (result != 0)
            std::cerr << "Failed to load score_" << count << " texture" << std::endl;

        display.drawTexture(textures.get("score_" + std::to_string(count)), _resolutionScaler->toScreenPosition(Vector<float>(x, y + yOffset)));

        yOffset += 25;
        count++;
    }
}

void Core::renderPlayerNameInput(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();

    auto nameTitle = MyTexture(TextureText("Your Name:", Color(255, 255, 255)));
    int result = textures.load("name_title", nameTitle);
    if (result != 0)
        std::cerr << "Failed to load name_title texture" << std::endl;

    display.drawTexture(textures.get("name_title"), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));

    auto nameText = MyTexture(TextureText(_playerName + "_", Color(255, 255, 0)));
    result = textures.load("player_name", nameText);
    if (result != 0)
        std::cerr << "Failed to load player_name texture" << std::endl;

    display.drawTexture(textures.get("player_name"), _resolutionScaler->toScreenPosition(Vector<float>(x, y + 30)));
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
    if (_currentGraphicLib)
        _currentGraphicLib->getDisplay().stop();

    for (const auto& [name, lib] : _libManager->getAllLibrariesByType(LibType::DISPLAY)) {
        if (name == libName) {
            using EntryPointFunc = IDisplayLibrary* (*)();
            auto entryPointFunc = lib->getFunction<EntryPointFunc>("entryPoint");

            _currentGraphicLib.reset(entryPointFunc());
            _currentGraphicLib->getDisplay().init("Arcade", 800, 600);
            if (_state == GameState::GAME && _currentGame) {
                _currentGame->stop();
                _currentGame->init(_currentGraphicLib);
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
            _currentGame->init(_currentGraphicLib);
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
        _currentGame->init(_currentGraphicLib);
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

}
