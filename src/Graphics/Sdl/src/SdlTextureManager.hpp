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
    /**
     * @class SDLTexture
     * This class is used to create a texture using the SDL2 library
     * It inherits from the ITexture interface
     */
    class SDLRendererManager;

    /**
     * @class SDLTexture
     * This class is used to create a texture using the SDL2 library
     * It inherits from the ITexture interface
     */
    class SDLTexture : public ITexture {
    public:
        /**
         * Construct a new SDLTexture object
         * @param textureInfo MyTexture & Texture information
         */
        explicit SDLTexture(const MyTexture& textureInfo);
        /**
         * Destroy the SDLTexture object
         */
        ~SDLTexture() = default;
        /**
         * Create a new texture
         * @param textureInfos MyTexture & Texture information
         * @param renderer std::shared_ptr<SDL_Renderer> SDL Renderer
         * @return int
         */
        int createTexture(const MyTexture& textureInfos, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Get the texture information
         * @return const MyTexture &
         */
        const MyTexture &getInformations() const override { return _textureInformations; }

        /**
         * Set the texture information
         * @param newTexture MyTexture & Texture information
         */
        void set(MyTexture& newTexture) override { _textureInformations = newTexture; }

        /**
         * Get the texture
         * @return std::shared_ptr<SDL_Texture>
         */
        [[nodiscard]] std::shared_ptr<SDL_Texture> getTexture() const { return _texture; }

        /**
         * Get the SDL_Rect
         * @return SDL_Rect
         */
        [[nodiscard]] SDL_Rect getRect() const { return _rect; }

        /**
         * Set the SDL_Rect
         * @param rect SDL_Rect
         */
        void setRect(Rect rect) { _rect = {static_cast<int>(rect.getPosition().getX()), static_cast<int>(rect.getPosition().getY()), static_cast<int>(rect.getWidth()), static_cast<int>(rect.getHeight())}; }

        /**
         * Set the texture
         * @param texture std::shared_ptr<SDL_Texture>
         */
        void setTexture(std::shared_ptr<SDL_Texture> texture) { _texture = std::move(texture); }

    private:
        /**
         * SDL_Rect
         */
        SDL_Rect _rect = {0, 0, 0, 0};
        /**
         * SDL Texture
         */
        std::shared_ptr<SDL_Texture> _texture = nullptr;
        /**
         * Texture information
         */
        MyTexture _textureInformations;
    };

    /**
     * @class SDLTextureManager
     * This class is used to create a texture manager using the SDL2 library
     * It inherits from the ITextureManager interface
     */
    class SDLTextureManager : public ITextureManager {
    public:
        /**
         * Construct a new SDLTextureManager object
         * @param renderer_manager SDLRendererManager&
         */
        SDLTextureManager(SDLRendererManager& renderer_manager) :  _renderer(renderer_manager) {}
        /**
         * Destroy the SDLTextureManager object
         */
        ~SDLTextureManager() override = default;
        /**
         * Load a new texture
         * @param name const std::string & Name of the texture
         * @param newTexture MyTexture & Texture information
         * @return int
         */
        int load(const std::string& name, const MyTexture& newTexture) override;
        /**
         * Get a texture
         * @param name const std::string & Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        /**
         * SDL Renderer Manager
         */
        SDLRendererManager& _renderer;
        /**
         * Map of textures
         */
        std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
    };
};



#endif //SDLTEXTUREMANAGER_HPP
