/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLTEXTUREMANAGER_HPP
#define SDLTEXTUREMANAGER_HPP


#include <map>
#include <memory>
#include <utility>
#include <SDL2/SDL_render.h>

#include "ITexture.hpp"


namespace arcade {
    class SDLTexture : public ITexture {
    public:
        SDLTexture();
        ~SDLTexture() = default;
        int load(const MyTexture& textureInfos, std::shared_ptr<SDL_Renderer> renderer);
        const MyTexture &getInformations() const override { return _textureInformations; }
        std::uint32_t getWidth() const override { return _width; }
        std::uint32_t getHeight() const override { return _height; }
        void setHeight(std::uint32_t newHeight) { _height = newHeight; }
        void setWidth(std::uint32_t newWidth) { _width = newWidth; }
    private:
        std::uint32_t _width;
        std::uint32_t _height;
        std::shared_ptr<SDL_Texture> _texture = nullptr;
        MyTexture _textureInformations;
    };

    class SDLTextureManager : public ITextureManager {
    public:
        SDLTextureManager(std::shared_ptr<SDL_Renderer> renderer) : _renderer(std::move(renderer)) {}
        ~SDLTextureManager() = default;
        int load(const std::string& name, const MyTexture& newTexture) override;
        std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        std::shared_ptr<SDL_Renderer> _renderer;
        std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
    };
};



#endif //SDLTEXTUREMANAGER_HPP
