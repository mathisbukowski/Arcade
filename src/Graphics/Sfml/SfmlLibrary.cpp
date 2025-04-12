/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SFML implementation for arcade
*/

#include "SfmlLibrary.hpp"
#include "Arcade.hpp"

extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::SFMLLibrary;
    }

    void destroy(arcade::IDisplayLibrary* library) {
        delete library;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::DISPLAY;
    }

    std::string entryPointName() {
        return "SFML";
    }
}
