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
#include <SDL2/SDL.h>

#include "ITexture.hpp"
#include "SdlFontManager.hpp"


namespace arcade {
    class SDLTexture : public ITexture {
    public:
        SDLTexture();
        ~SDLTexture() = default;
        int createTexture(const MyTexture& textureInfos, std::shared_ptr<SDL_Renderer> renderer);

        const MyTexture &getInformations() const override { return _textureInformations; }

        void set(MyTexture& newTexture) override { _textureInformations = newTexture; }

        [[nodiscard]] std::shared_ptr<SDL_Texture> getTexture() const { return _texture; }

        [[nodiscard]] SDL_Rect getRect() const { return _rect; }

        void setRect(Rect rect) { _rect = {static_cast<int>(rect.getPosition().getX()), static_cast<int>(rect.getPosition().getY()), static_cast<int>(rect.getWidth()), static_cast<int>(rect.getHeight())}; }

        void setTexture(std::shared_ptr<SDL_Texture> texture) { _texture = std::move(texture); }

    private:
        SDL_Rect _rect = {0, 0, 0, 0};
        std::shared_ptr<SDL_Texture> _texture = nullptr;
        MyTexture _textureInformations;
    };

    class SDLTextureManager : public ITextureManager {
    public:
        SDLTextureManager(std::shared_ptr<SDL_Renderer> renderer, std::shared_ptr<SDLFontManager> fontManager) : _renderer(std::move(renderer)), _fontManager(std::move(fontManager)) {}
        ~SDLTextureManager() override = default;
        int load(const std::string& name, const MyTexture& newTexture) override;
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        std::shared_ptr<SDL_Renderer> _renderer;
        std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
        std::shared_ptr<SDLFontManager> _fontManager;
    };
};



#endif //SDLTEXTUREMANAGER_HPP
