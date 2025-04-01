/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlTextureManager.hpp"
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>

#include "SdlFontManager.hpp"

// TEXTURE MANAGER
std::shared_ptr<arcade::ITexture> arcade::SDLTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);
    if (it == _textures.end())
        return nullptr;
    return it->second;
}

int arcade::SDLTextureManager::load(const std::string& name, const MyTexture& newTexture)
{
    auto texture = std::make_shared<SDLTexture>();
    texture->createTexture(newTexture, _renderer);
    if (_textures.find(name) != _textures.end())
        return -1;
    _textures.emplace(name, texture);
    return 0;
}

// Texture

int arcade::SDLTexture::createTexture(const MyTexture& textureInfos, std::shared_ptr<SDL_Renderer> renderer)
{
    this->_textureInformations = textureInfos;

    if (std::holds_alternative<TextureImg>(this->_textureInformations)) {
        const TextureImg& textureImg = std::get<TextureImg>(this->_textureInformations);
        this->_texture = std::shared_ptr<SDL_Texture>(
            IMG_LoadTexture(renderer.get(), textureImg.getPath().c_str()),
            SDL_DestroyTexture
        );
        if (!this->_texture) {
            std::cerr << "Failed to load texture: " << textureImg.getPath() << " - " << IMG_GetError() << std::endl;
            return -1;
        }
        if (textureImg.getRect().has_value()) {
            this->_rect.x = static_cast<int>(textureImg.getRect().value().getPosition().getX());
            this->_rect.y = static_cast<int>(textureImg.getRect().value().getPosition().getY());
            this->_rect.w = static_cast<int>(textureImg.getRect().value().getWidth());
            this->_rect.h = static_cast<int>(textureImg.getRect().value().getHeight());
        } else {
            SDL_QueryTexture(this->_texture.get(), nullptr, nullptr, &this->_rect.w, &this->_rect.h);
        }
        return 0;
    }
    return  0;
}

