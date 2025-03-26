/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlLibrary.cpp
*/

#include "NcursesLibrary.hpp"


extern "C" arcade::IDisplayLibrary *entrypoint()
{
    return new arcade::NcursesLibrary();
}

extern "C" const char *entryPointName()
{
    return "SDL2";
}

extern "C" arcade::LibType entryPointType()
{
    return arcade::DISPLAY;
}