/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core initialization methods
*/

#include "Core.hpp"
#include <iostream>

namespace arcade {

Core::Core(const std::string& initialLibPath)
    : _state(GameState::MENU),
      _playerName("Player"),
      _libManager(std::make_unique<DynamicLibraryManager>(initialLibPath)),
      _currentGraphicLib(nullptr),
      _currentGame(nullptr),
      _deltaTime(0.0f),
      _selectedGameIndex(0),
      _selectedGraphicLibIndex(0)
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

void Core::switchGraphicsLib(const std::string& libName) {
    if (_currentGraphicLib)
        _currentGraphicLib->getDisplay().stop();

    for (const auto& [name, lib] : _libManager->getAllLibrariesByType(LibType::DISPLAY)) {
        if (name == libName) {
            using EntryPointFunc = IDisplayLibrary* (*)();
            auto entryPointFunc = lib->getFunction<EntryPointFunc>("entryPoint");

            _currentGraphicLib.reset(entryPointFunc());
            _currentGraphicLib->getDisplay().init("Arcade", 800, 600);
            _resolutionScaler = std::make_unique<ResolutionScaler>(_currentGraphicLib->getDisplay());

            if (_state == GameState::GAME && _currentGame) {
                _currentGame->stop();
                _currentGame->init(_currentGraphicLib);
            }
            return;
        }
    }
    std::cerr << "Failed to find graphics library: " << libName << std::endl;
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
        _previousUpState = false;
        _previousDownState = false;
        _previousLeftState = false;
        _previousRightState = false;
        _previousEnterState = false;
        _previousAState = false;
        _previousEscapeState = false;
        _state = GameState::MENU;
    }
}

}
