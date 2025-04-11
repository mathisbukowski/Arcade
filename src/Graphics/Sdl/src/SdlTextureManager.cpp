/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlTextureManager.hpp"
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>

#include "SdlFontManager.hpp"
#include "SdlRendererManager.hpp"

std::shared_ptr<arcade::ITexture> arcade::SDLTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);
    if (it == _textures.end())
        return nullptr;
    return it->second;
}

int arcade::SDLTextureManager::load(const std::string& name, const MyTexture& newTexture)
{
    auto texture = std::make_shared<SDLTexture>(newTexture);
    texture->createTexture(newTexture, _renderer.getRenderer());
    if (_textures.find(name) != _textures.end())
        return -1;
    _textures.emplace(name, texture);
    return 0;
}

// Texture

int arcade::SDLTexture::createTexture(const MyTexture& textureInfos, const std::shared_ptr<SDL_Renderer>& renderer)
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
            if (SDL_QueryTexture(this->_texture.get(), nullptr, nullptr, &_rect.w, &_rect.h) != 0) {
                std::cerr << "SDL_QueryTexture failed: " << SDL_GetError() << std::endl;
                return -1;
            }
        }
        return 0;
    }
    if (std::holds_alternative<TextureText>(this->_textureInformations)) {
        const TextureText& textureText = std::get<TextureText>(this->_textureInformations);

        std::shared_ptr<TTF_Font> font(TTF_OpenFont("assets/fonts/PixelFont.ttf", 24), TTF_CloseFont);
        if (!font) {
            std::cerr << "Failed to load default font: " << TTF_GetError() << std::endl;
            return -1;
        }
        SDL_Color color = {
            textureText.getColor().getR(),
            textureText.getColor().getG(),
            textureText.getColor().getB(),
            textureText.getColor().getOpacity()
        };
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(
            TTF_RenderText_Blended(font.get(), textureText.getText().c_str(), color),
            SDL_FreeSurface
        );

        if (!surface) {
            std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
            return -1;
        }
        this->_texture = std::shared_ptr<SDL_Texture>(
            SDL_CreateTextureFromSurface(renderer.get(), surface.get()),
            SDL_DestroyTexture
        );

        if (!this->_texture) {
            std::cerr << "Failed to create texture from text: " << SDL_GetError() << std::endl;
            return -1;
        }
        if (textureText.getRect().has_value()) {
            this->_rect.x = static_cast<int>(textureText.getRect().value().getPosition().getX());
            this->_rect.y = static_cast<int>(textureText.getRect().value().getPosition().getY());
            this->_rect.w = static_cast<int>(textureText.getRect().value().getWidth());
            this->_rect.h = static_cast<int>(textureText.getRect().value().getHeight());
        } else {
            SDL_QueryTexture(this->_texture.get(), nullptr, nullptr, &this->_rect.w, &this->_rect.h);
        }
        return 0;
    }
    return 0;
}

arcade::SDLTexture::SDLTexture(const MyTexture& textureInfo): ITexture(textureInfo), _textureInformations(textureInfo)
{
};

