/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** SDL Texture Manager - Header
*/

#ifndef SDLTEXTUREMANAGER_HPP
#define SDLTEXTUREMANAGER_HPP

#include <map>
#include <memory>
#include <string>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <optional>

#include "ITexture.hpp"
#include "SdlFontManager.hpp"

namespace arcade {
    class SDLRendererManager;

    /**
     * @class SDLTexture
     * SDL implementation of textures for Arcade
     */
    class SDLTexture : public ITexture {
    public:
        /**
         * Construct a new SDLTexture object
         * @param textureInfo const MyTexture & Base texture information
         */
        explicit SDLTexture(const MyTexture& textureInfo);

        /**
         * Destroy the SDLTexture object
         */
        ~SDLTexture() = default;

        /**
         * Create or update the SDL texture from information
         * @param textureInfos const MyTexture & Texture information to use
         * @param renderer const std::shared_ptr<SDL_Renderer> & SDL renderer to create the texture with
         * @return int 0 on success, -1 on failure
         */
        int createTexture(const MyTexture& textureInfos, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Get the underlying texture information
         * @return const MyTexture & Reference to texture information
         */
        [[nodiscard]] const MyTexture &getInformations() const override { return _textureInformations; }

        /**
         * Update the texture information
         * @param newTexture MyTexture & New texture information
         */
        void set(MyTexture& newTexture) override { _textureInformations = newTexture; }

        /**
         * Get the SDL texture object
         * @return std::shared_ptr<SDL_Texture> Shared pointer to SDL_Texture
         */
        [[nodiscard]] std::shared_ptr<SDL_Texture> getTexture() const { return _texture; }

        /**
         * Get the texture dimensions and position
         * @return SDL_Rect with texture properties
         */
        [[nodiscard]] SDL_Rect getRect() const { return _rect; }

        /**
         * Set the texture rectangle properties
         * @param rect Rect Arcade rectangle properties to apply
         */
        void setRect(Rect rect);

        /**
         * Replace the SDL texture
         * @param texture std::shared_ptr<SDL_Texture> New SDL texture
         */
        void setTexture(std::shared_ptr<SDL_Texture> texture) { _texture = std::move(texture); }

        /**
         * Scale texture to fit game grid cells
         * @param gridWidth int Width of game grid
         * @param gridHeight int Height of game grid
         * @param windowWidth int Width of the window
         * @param windowHeight int Height of the window
         */
        void scaleToGameSize(int gridWidth, int gridHeight, int windowWidth, int windowHeight);

    private:
        /**
         * Create a red X texture for error indication
         * @param renderer const std::shared_ptr<SDL_Renderer> & SDL renderer to use
         */
        void createErrorTexture(const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Create an empty transparent texture
         * @param renderer const std::shared_ptr<SDL_Renderer> & SDL renderer to use
         */
        void createEmptyTexture(const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Create texture from image
         * @param textureImg const TextureImg & Image texture information
         * @param renderer const std::shared_ptr<SDL_Renderer> & SDL renderer to use
         * @return int 0 on success, -1 on failure
         */
        int createImageTexture(const TextureImg& textureImg, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Create texture from text
         * @param textureText const TextureText & Text texture information
         * @param renderer const std::shared_ptr<SDL_Renderer> & SDL renderer to use
         * @return int 0 on success, -1 on failure
         */
        int createTextTexture(const TextureText& textureText, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * Apply rectangle dimensions from texture information
         * @param info const TextureBase & Texture information to read from
         */
        void applyRectFromTextureInfo(const TextureBase& info);

        /**
         * Query texture dimensions from SDL texture
         * @return bool true on success, false on failure
         */
        bool queryTextureDimensions();

        /**
         * SDL texture rectangle properties
         */
        SDL_Rect _rect = {0, 0, 0, 0};
        /**
         * SDL texture pointer
         */
        std::shared_ptr<SDL_Texture> _texture = nullptr;
        /**
         * Texture information
         */
        MyTexture _textureInformations;

        /**
         * Error texture size for invalid textures
         */
        static constexpr int ERROR_TEXTURE_SIZE = 32;
        /**
         * Empty texture size for uninitialized textures
         */
        static constexpr int EMPTY_TEXTURE_SIZE = 10;
    };

    /**
     * @class SDLTextureManager
     * Manager for SDL textures in Arcade
     */
    class SDLTextureManager : public ITextureManager {
    public:
        /**
         * Construct a new SDLTextureManager
         * @param renderer_manager SDLRendererManager & Reference to SDL renderer manager
         */
        explicit SDLTextureManager(SDLRendererManager& renderer_manager);

        /**
         * Destroy the SDLTextureManager
         */
        ~SDLTextureManager() override = default;

        /**
         *  Load a texture with given name and data
         * @param name const std::string & Name to identify the texture
         * @param newTexture const MyTexture & Texture information to load
         * @return int 0 on success, -1 on failure
         */
        int load(const std::string& name, const MyTexture& newTexture) override;

        /**
         * Get a texture by name
         * @param name const std::string & Name of the texture to retrieve
         * @return std::shared_ptr<ITexture> Shared pointer to the texture, or nullptr if not found
         */
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;

    private:
        /**
         * Create a new texture
         * @param name const std::string & Name to identify the texture
         * @param newTexture MyTexture & Texture information to load
         * @return int 0 on success, -1 on failure
         */
        int createTexture(const std::string& name, const MyTexture& newTexture);

        /**
         * Update an existing texture
         * @param existingTexture std::shared_ptr<SDLTexture  Existing texture to update
         * @param newTexture const MyTexture & New texture information
         * @return int 0 on success, -1 on failure
         */
        int updateTexture(std::shared_ptr<SDLTexture> existingTexture, const MyTexture& newTexture);

        /**
         * SDL renderer manager reference
         */
        SDLRendererManager& _renderer;
        /**
         * Map of loaded textures
         */
        std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
    };
};

#endif //SDLTEXTUREMANAGER_HPP
