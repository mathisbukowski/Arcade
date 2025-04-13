/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** SDL Texture Manager - Implementation
*/

#include "SdlTextureManager.hpp"
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <filesystem>

#include "SdlFontManager.hpp"
#include "SdlRendererManager.hpp"

namespace arcade {

SDLTextureManager::SDLTextureManager(SDLRendererManager& renderer_manager)
    : _renderer(renderer_manager)
{ }

std::shared_ptr<ITexture> SDLTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);

    if (it == _textures.end())
        return nullptr;
    return it->second;
}

int SDLTextureManager::load(const std::string& name, const MyTexture& newTexture)
{
    auto existingTexture = _textures.find(name);

    if (existingTexture != _textures.end())
        return this->updateTexture(existingTexture->second, newTexture);
    return this->createTexture(name, newTexture);
}

int SDLTextureManager::createTexture(const std::string& name, const MyTexture& newTexture)
{
    auto texture = std::make_shared<SDLTexture>(newTexture);
    int result = texture->createTexture(newTexture, _renderer.getRenderer());

    if (result < 0)
        return -1;
    _textures.emplace(name, texture);
    return 0;
}

int SDLTextureManager::updateTexture(std::shared_ptr<SDLTexture> existingTexture, const MyTexture& newTexture)
{
    existingTexture->set(const_cast<MyTexture&>(newTexture));

    return existingTexture->createTexture(newTexture, _renderer.getRenderer());
}

SDLTexture::SDLTexture(const MyTexture& textureInfo)
    : ITexture(textureInfo), _textureInformations(textureInfo)
{ }

void SDLTexture::setRect(Rect rect)
{
    _rect = {
        static_cast<int>(rect.getPosition().getX()),
        static_cast<int>(rect.getPosition().getY()),
        static_cast<int>(rect.getWidth()),
        static_cast<int>(rect.getHeight())
    };
}

void SDLTexture::scaleToGameSize(int gridWidth, int gridHeight, int windowWidth, int windowHeight)
{
    float cellWidth = static_cast<float>(windowWidth) / gridWidth;
    float cellHeight = static_cast<float>(windowHeight) / gridHeight;

    _rect.w = static_cast<int>(cellWidth * 1.0f);
    _rect.h = static_cast<int>(cellHeight * 1.0f);
}

int SDLTexture::createTexture(const MyTexture& textureInfos, const std::shared_ptr<SDL_Renderer>& renderer)
{
    this->_textureInformations = textureInfos;

    if (std::holds_alternative<TextureImg>(this->_textureInformations)) {
        return this->createImageTexture(std::get<TextureImg>(this->_textureInformations), renderer);
    }
    else if (std::holds_alternative<TextureText>(this->_textureInformations)) {
        return this->createTextTexture(std::get<TextureText>(this->_textureInformations), renderer);
    }

    this->createErrorTexture(renderer);
    return 0;
}

int SDLTexture::createImageTexture(const TextureImg& textureImg, const std::shared_ptr<SDL_Renderer>& renderer)
{
    if (textureImg.getPath().empty() || !std::filesystem::exists(std::filesystem::path(textureImg.getPath()))) {
        this->createErrorTexture(renderer);
        return 0;
    }
    this->_texture = std::shared_ptr<SDL_Texture>(
        IMG_LoadTexture(renderer.get(), textureImg.getPath().c_str()),
        SDL_DestroyTexture
    );
    if (!this->_texture) {
        std::cerr << "Failed to load texture image: " << textureImg.getPath() << " - " << IMG_GetError() << std::endl;
        this->createErrorTexture(renderer);
        return 0;
    }
    this->applyRectFromTextureInfo(textureImg);

    if (!this->_rect.w || !this->_rect.h) {
        if (!this->queryTextureDimensions()) {
            this->createErrorTexture(renderer);
            return 0;
        }
    }
    return 0;
}

int SDLTexture::createTextTexture(const TextureText& textureText, const std::shared_ptr<SDL_Renderer>& renderer)
{
    if (textureText.getText().empty()) {
        this->createEmptyTexture(renderer);
        return 0;
    }

    std::shared_ptr<TTF_Font> font;
    std::string fontPath = "assets/fonts/PixelFont.ttf";

    font = std::shared_ptr<TTF_Font>(TTF_OpenFont(fontPath.c_str(), 16), TTF_CloseFont);

    if (!font) {
        std::cerr << "Failed to load font: " << fontPath << " - " << TTF_GetError() << std::endl;
        this->createErrorTexture(renderer);
        return 0;
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
        std::cerr << "Failed to render text '" << textureText.getText() << "': " << TTF_GetError() << std::endl;
        this->createErrorTexture(renderer);
        return 0;
    }
    this->_texture = std::shared_ptr<SDL_Texture>(
        SDL_CreateTextureFromSurface(renderer.get(), surface.get()),
        SDL_DestroyTexture
    );

    if (!this->_texture) {
        std::cerr << "Failed to create texture from text: " << SDL_GetError() << std::endl;
        this->createErrorTexture(renderer);
        return 0;
    }

    this->applyRectFromTextureInfo(textureText);

    if (!this->_rect.w || !this->_rect.h) {
        if (!queryTextureDimensions()) {
            this->createErrorTexture(renderer);
            return 0;
        }
    }
    return 0;
}

void SDLTexture::applyRectFromTextureInfo(const TextureBase& info)
{
    if (info.getRect().has_value()) {
        std::optional<Rect> rectOpt = info.getRect();
        const auto& rect = rectOpt.value();
        this->_rect.x = static_cast<int>(rect.getPosition().getX());
        this->_rect.y = static_cast<int>(rect.getPosition().getY());
        this->_rect.w = static_cast<int>(rect.getWidth());
        this->_rect.h = static_cast<int>(rect.getHeight());
    } else {
        this->_rect.x = 0;
        this->_rect.y = 0;
        this->_rect.w = 0;
        this->_rect.h = 0;
    }
}

bool SDLTexture::queryTextureDimensions()
{
    if (!this->_texture)
        return false;

    return SDL_QueryTexture(this->_texture.get(), nullptr, nullptr, &_rect.w, &_rect.h) == 0;
}

void SDLTexture::createErrorTexture(const std::shared_ptr<SDL_Renderer>& renderer)
{
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(
        SDL_CreateRGBSurface(0, ERROR_TEXTURE_SIZE, ERROR_TEXTURE_SIZE, 32, 0, 0, 0, 0),
        SDL_FreeSurface
    );

    if (!surface) {
        std::cerr << "Failed to create error texture surface: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_FillRect(surface.get(), nullptr, SDL_MapRGBA(surface->format, 0, 0, 0, 0));
    SDL_Rect pixelRect = {0, 0, 1, 1};
    Uint32 redColor = SDL_MapRGBA(surface->format, 255, 0, 0, 255);

    for (int y = 0; y < ERROR_TEXTURE_SIZE; y++) {
        for (int x = 0; x < ERROR_TEXTURE_SIZE; x++) {
            if (x == y || x == (ERROR_TEXTURE_SIZE - 1 - y)) {
                pixelRect.x = x;
                pixelRect.y = y;
                SDL_FillRect(surface.get(), &pixelRect, redColor);
            }
        }
    }
    this->_texture = std::shared_ptr<SDL_Texture>(
        SDL_CreateTextureFromSurface(renderer.get(), surface.get()),
        SDL_DestroyTexture
    );
    this->_rect = {0, 0, ERROR_TEXTURE_SIZE, ERROR_TEXTURE_SIZE};
}

void SDLTexture::createEmptyTexture(const std::shared_ptr<SDL_Renderer>& renderer)
{
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(
        SDL_CreateRGBSurface(0, EMPTY_TEXTURE_SIZE, EMPTY_TEXTURE_SIZE, 32, 0, 0, 0, 0),
        SDL_FreeSurface
    );

    if (!surface) {
        std::cerr << "Failed to create empty texture surface: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_FillRect(surface.get(), nullptr, SDL_MapRGBA(surface->format, 0, 0, 0, 0));
    this->_texture = std::shared_ptr<SDL_Texture>(
        SDL_CreateTextureFromSurface(renderer.get(), surface.get()),
        SDL_DestroyTexture
    );
    this->_rect = {0, 0, EMPTY_TEXTURE_SIZE, EMPTY_TEXTURE_SIZE};
}

}
