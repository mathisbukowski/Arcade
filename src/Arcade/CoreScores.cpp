/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core score management
*/

#include "Core.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace arcade {

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
        file << score._playerName << "," << score._gameName << "," << score._score << std::endl;
    file.close();
}

}
