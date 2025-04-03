/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlLibrary.cpp
*/

#include "NcursesLibrary.hpp"


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