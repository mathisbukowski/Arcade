/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Level Manager implementation
*/

#include "LevelManager.hpp"
#include <fstream>
#include <iostream>

namespace arcade {

LevelManager::LevelManager(const std::string& levelFilePath) {
    this->loadLevelsFromFile(levelFilePath);
}

std::vector<std::string> LevelManager::getLevel(int level) const {
    if (level < 1 || level > static_cast<int>(_levels.size()))
        return this->createDefaultLevel();
    return _levels[level - 1];
}

int LevelManager::getLevelCount() const {
    return static_cast<int>(_levels.size());
}

void LevelManager::loadLevelsFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open level file: " << filePath << std::endl;
        _levels.push_back(this->createDefaultLevel());
        return;
    }

    std::vector<std::string> currentLevel;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == '#' && line.find("Level") != std::string::npos) {
            if (!currentLevel.empty()) {
                _levels.push_back(currentLevel);
                currentLevel.clear();
            }
            continue;
        }
        currentLevel.push_back(line);
    }
    if (!currentLevel.empty())
        _levels.push_back(currentLevel);
    if (_levels.empty())
        _levels.push_back(this->createDefaultLevel());
}

std::vector<std::string> LevelManager::createDefaultLevel() const {
    return {
        "####################",
        "#                  #",
        "#  #############   #",
        "#  #               #",
        "#  #  #########    #",
        "#  #  #       #    #",
        "#  #  #  ###  #    #",
        "#  #  #  #    #    #",
        "#  #  #  #    #    #",
        "#  #     #         #",
        "#  ###############  #",
        "#                  #",
        "####################"
    };
}

}
