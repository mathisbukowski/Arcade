/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "NcursesTextureManager.hpp"

#include <iostream>

std::shared_ptr<arcade::ITexture> arcade::NcursesTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);
    if (it != _textures.end())
        return it->second;
    std::cerr << "NcursesTextureManager::get: " << name << " not found" << std::endl;
    return nullptr;
}

int arcade::NcursesTextureManager::load(const std::string& name, const MyTexture& newTexture)
{
    try {
        _textures[name] = std::make_shared<NcursesTexture>(newTexture);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load texture: " << e.what() << std::endl;
        return -1;
    }
}

arcade::NcursesTexture::NcursesTexture(const MyTexture& texture) : ITexture(texture),
    _textureInformations(texture)
{
    if (std::holds_alternative<TextureImg>(texture)) {
        std::cerr << "Images don't support." << std::endl;
    }
    if (std::holds_alternative<TextureText>(texture)) {
        auto textureText = std::get<TextureText>(texture);
        _textureInformations = textureText;
    } else {
        std::cerr << "Invalid texture type" << std::endl;
    }
}
