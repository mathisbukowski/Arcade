/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "NcursesFontManager.hpp"
#include <iostream>

int arcade::NcursesFontManager::load(const std::string& name, const Font& font)
{
    try {
        _fonts[name] = std::make_shared<NcursesFont>(font);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load font: " << e.what() << std::endl;
        return -1;
    }
}

std::shared_ptr<arcade::IFont> arcade::NcursesFontManager::get(const std::string& name) const
{
    auto it = _fonts.find(name);
    if (it != _fonts.end())
        return it->second;
    std::cerr << "Font not found: " + name << std::endl;
}