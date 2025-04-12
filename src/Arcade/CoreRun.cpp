/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core main loop
*/

#include "Core.hpp"
#include <iostream>
#include <thread>

namespace arcade {

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
    }
}

void Core::updateDeltaTime() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    _deltaTime = std::chrono::duration<float>(currentTime - _lastFrameTime).count();
    _lastFrameTime = currentTime;
}

void Core::updateMenu() {
    this->handleMenuInput();
}

void Core::updateGame() {
    this->handleGameInput();
    if (_currentGame)
        _currentGame->update(_deltaTime);
}

}
