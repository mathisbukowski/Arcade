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
        auto& imgTexture = std::get<TextureImg>(texture);
        _textureInformations = convertImageToText(imgTexture);
    }
    else if (std::holds_alternative<TextureText>(texture)) {
        auto textureText = std::get<TextureText>(texture);
        _textureInformations = textureText;
    } else {
        TextureText defaultText("?", Color(255, 255, 255));
        _textureInformations = defaultText;
    }
}

arcade::TextureText arcade::NcursesTexture::convertImageToText(const TextureImg& img)
{
    std::string path = img.getPath();
    Color color = Color(255, 255, 255);
    char representation = ' ';

    std::string lowerPath = path;
    for (auto& c : lowerPath) c = std::tolower(c);

    if (lowerPath.find("head") != std::string::npos) {
        if (lowerPath.find("up") != std::string::npos) {
            representation = 'U';
        } else if (lowerPath.find("down") != std::string::npos) {
            representation = 'D';
        } else if (lowerPath.find("left") != std::string::npos) {
            representation = 'L';
        } else if (lowerPath.find("right") != std::string::npos || lowerPath.find("head.png") != std::string::npos) {
            representation = 'R';
        } else {
            representation = 'O';
        }
    }
    else if (lowerPath.find("body") != std::string::npos) {
        representation = 'B';
    }
    else if (lowerPath.find("wall") != std::string::npos) {
        representation = '#';
    }
    else if (lowerPath.find("food") != std::string::npos) {
        representation = 'F';
    }
    else if (lowerPath.find("bonus_food") != std::string::npos) {
        representation = 'S';
    }
    else {
        representation = '?';
    }
    TextureText textTexture("", color);
    textTexture.setText(std::string(1, representation));

    return textTexture;
}
