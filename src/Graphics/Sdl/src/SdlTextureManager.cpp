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

#include "SdlFontManager.hpp"

// TEXTURE MANAGER
std::shared_ptr<arcade::ITexture> arcade::SDLTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);
    if (it == _textures.end())
        return nullptr;
    return it->second;
}

int arcade::SDLTextureManager::load(const std::string& name, std::shared_ptr<arcade::ITexture> newTexture)
{
    if (_textures.find(name) != _textures.end())
        return -1;
    _textures.emplace(name, std::move(newTexture));
    return 0;
}

// Texture

int arcade::SDLTexture::load(const MyTexture& textureInfos, std::shared_ptr<SDL_Renderer> renderer)
{
    if (_texture) {
        SDL_DestroyTexture(_texture.get());
        _texture = nullptr;
    }
    if (std::holds_alternative<TextureImg>(textureInfos)) {
        auto texture = std::get<TextureImg>(textureInfos);
        _texture = std::shared_ptr<SDL_Texture>(SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, this->getWidth(), this->getHeight()), SDL_DestroyTexture);
        if (!_texture)
            return -1;
    } else if (std::holds_alternative<TextureText>(textureInfos)) {
        auto texture = std::get<TextureText>(textureInfos);

        std::shared_ptr<SDL_Surface> surface(TTF_RenderText_Solid(nullptr, texture.getText().c_str(), {texture.getColor().getR(), texture.getColor().getG(), texture.getColor().getB(), texture.getColor().getOpacity()}));
        if (!surface)
            return -1;
        _texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer.get(), surface.get()), SDL_DestroyTexture);
        SDL_FreeSurface(surface.get());
        if (!_texture)
            return -1;
    }
}

