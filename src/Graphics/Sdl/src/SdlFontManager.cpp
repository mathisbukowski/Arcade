/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlFontManager.hpp"
#include <iostream>

int arcade::SDLFont::createFont(const Font &informations)
{
    _font = std::shared_ptr<TTF_Font>(TTF_OpenFont(informations.getPath().c_str(), informations.getSize()), TTF_CloseFont);
    if (!_font) {
        std::cerr << "Failed to load font: " << informations.getPath() << " - " << TTF_GetError() << std::endl;
        return -1;
    }
    return 0;
}

arcade::SDLFontManager::SDLFontManager()
{
    if (TTF_Init() == -1)
        throw std::runtime_error("Failed to initialize TTF");
}

int arcade::SDLFontManager::load(const std::string& name, const Font &newFont)
{
    auto font = std::make_shared<SDLFont>(newFont);
    if (font->createFont(newFont) == -1)
        return -1;
    if (_fonts.find(name) != _fonts.end())
        return -1;
    _fonts.emplace(name, font);
    return 0;
}

std::shared_ptr<arcade::IFont> arcade::SDLFontManager::get(const std::string& name) const
{
    auto it = _fonts.find(name);
    if (it == _fonts.end())
        return nullptr;
    return it->second;
}
