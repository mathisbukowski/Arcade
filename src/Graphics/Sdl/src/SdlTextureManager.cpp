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
    texture->load(newTexture, _renderer);
    if (_textures.find(name) != _textures.end())
        return -1;
    _textures.emplace(name, texture);
    return 0;
}

// Texture

int arcade::SDLTexture::load(const MyTexture& textureInfos, std::shared_ptr<SDL_Renderer> renderer)
{
    this->_textureInformations = textureInfos;

    if (std::holds_alternative<TextureImg>(this->_textureInformations)) {
        const TextureImg& textureImg = std::get<TextureImg>(this->_textureInformations);
        std::shared_ptr<SDL_Surface> surface(SDL_LoadBMP(textureImg.getPath().c_str()), SDL_FreeSurface);
        if (!surface) {
            std::cerr << "Failed to load image: " << textureImg.getPath() << " - " << SDL_GetError() << std::endl;
            return -1;
        }
        this->_texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer.get(), surface.get()), SDL_DestroyTexture);
        if (!this->_texture) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            return -1;
        }
        std::shared_ptr<uint32_t> format = std::make_shared<uint32_t>(0);
        std::shared_ptr<int> width = std::make_shared<int>(0);
        std::shared_ptr<int> height = std::make_shared<int>(0);
        std::shared_ptr<int> access = std::make_shared<int>(0);

        SDL_QueryTexture(this->_texture.get(), format.get(), access.get(), width.get(), height.get());

        this->_textureInformations.emplace<TextureImg>(TextureImg(
            textureImg.getPath(),
            textureImg.getRect()
        ));
        std::get<TextureImg>(this->_textureInformations).setWidth(width.operator*());
        std::get<TextureImg>(this->_textureInformations).setHeight(height.operator*());
        return 0;
    } else if (std::holds_alternative<TextureText>(this->_textureInformations)) {
    }
}

