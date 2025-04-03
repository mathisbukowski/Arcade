/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Nibbler game library exports
*/

#include "NibblerGame.hpp"
#include "IGameModule.hpp"
#include "Arcade.hpp"
#include <cstring>

namespace arcade {
    class NibblerExport {
        public:
        static LibType getType() {
            return LibType::GAME;
        }
        static std::string getName() {
            return "Nibbler";
        }
        static IGameModule* createInstance() {
            return new NibblerGame();
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
        return arcade::NibblerExport::getType();
    }

    const char* entryPointName() {
        return arcade::NibblerExport::getNameCString();
    }

    arcade::IGameModule* entryPoint() {
        return arcade::NibblerExport::createInstance();
    }

    void destroy(arcade::IGameModule* game) {
        arcade::NibblerExport::destroyInstance(game);
    }
}
