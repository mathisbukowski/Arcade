/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SdlLibrary.cpp
*/

#include "SdlLibrary.hpp"

arcade::SdlLibrary::SdlLibrary()




extern "C" arcade::IDisplayLibrary *entryPoint()
{
    return new arcade::SdlLibrary;
}

extern "C" const char *entryPointName()
{
    return "SDL2";
}

extern "C" arcade::LibType entryPointType()
{
    return arcade::DISPLAY;
}