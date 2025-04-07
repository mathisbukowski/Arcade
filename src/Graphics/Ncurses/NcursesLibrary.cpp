/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlLibrary.cpp
*/

#include "NcursesLibrary.hpp"

arcade::NcursesLibrary::NcursesLibrary() = default;

arcade::NcursesLibrary::~NcursesLibrary() = default;


extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::NcursesLibrary;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::DISPLAY;
    }

    const char* entryPointName() {
        return "NCURSES";
    }
}