/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlLibrary.cpp
*/

#include "NcursesLibrary.hpp"

arcade::NcursesLibrary::NcursesLibrary() :
    _display(std::make_unique<NcursesDisplayModule>()),
    _textures(std::make_unique<NcursesTextureManager>()),
    _fonts(std::make_unique<NcursesFontManager>()),
    _sounds(std::make_unique<NcursesSoundManager>())
{
}

arcade::NcursesLibrary::~NcursesLibrary() = default;


extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::NcursesLibrary();
    }

    void destroy(arcade::IDisplayLibrary* library) {
        delete library;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::DISPLAY;
    }

    const char* entryPointName() {
        return "NCURSES";
    }
}