/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlFontManager.hpp"


// Font Manager

int arcade::SDLFontManager::load(const std::string& name, std::shared_ptr<IFont> newFont)
{
    if (_fonts.find(name) != _fonts.end())
        return -1;
    _fonts.emplace(name, std::move(newFont));
    return 0;
}

std::shared_ptr<arcade::IFont> arcade::SDLFontManager::get(const std::string& name) const
{
    auto it = _fonts.find(name);
    if (it == _fonts.end())
        return nullptr;
    return it->second;
}