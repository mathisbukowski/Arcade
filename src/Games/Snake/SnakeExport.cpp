/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Snake game library exports
*/

#include "SnakeGame.hpp"
#include "IGameModule.hpp"
#include "Arcade.hpp"
#include <cstring>

namespace arcade {
    class SnakeExport {
        public:
        static LibType getType() {
            return LibType::GAME;
        }
        static std::string getName() {
            return "Snake";
        }
        static IGameModule* createInstance(bool cyclical = false) {
            return new SnakeGame(cyclical);
        }
        static void destroyInstance(IGameModule* game) {
            delete game;
        }
        static const char* getNameCString() {
            static const char* name = nullptr;
            if (!name) {
                std::string gameName = getName();
                char* buffer = new char[gameName.length() + 1];
                std::strcpy(buffer, gameName.c_str());
                name = buffer;
            }
            return name;
        }
    };
}

extern "C" {
    arcade::LibType entryPointType() {
        return arcade::SnakeExport::getType();
    }

    const char* entryPointName() {
        return arcade::SnakeExport::getNameCString();
    }

    arcade::IGameModule* entryPoint() {
        return arcade::SnakeExport::createInstance();
    }

    void destroy(arcade::IGameModule* game) {
        arcade::SnakeExport::destroyInstance(game);
    }
}
