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
     * @brief SDL implementation of textures for Arcade
     */
    class SDLTexture : public ITexture {
    public:
        /**
         * @brief Construct a new SDLTexture object
         * @param textureInfo Base texture information
         */
        explicit SDLTexture(const MyTexture& textureInfo);

        /**
         * @brief Destroy the SDLTexture object
         */
        ~SDLTexture() = default;

        /**
         * @brief Create or update the SDL texture from information
         * @param textureInfos Texture information to use
         * @param renderer SDL renderer to create the texture with
         * @return 0 on success, -1 on failure
         */
        int createTexture(const MyTexture& textureInfos, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * @brief Get the underlying texture information
         * @return Reference to texture information
         */
        [[nodiscard]] const MyTexture &getInformations() const override { return _textureInformations; }

        /**
         * @brief Update the texture information
         * @param newTexture New texture information
         */
        void set(MyTexture& newTexture) override { _textureInformations = newTexture; }

        /**
         * @brief Get the SDL texture object
         * @return Shared pointer to SDL_Texture
         */
        [[nodiscard]] std::shared_ptr<SDL_Texture> getTexture() const { return _texture; }

        /**
         * @brief Get the texture dimensions and position
         * @return SDL_Rect with texture properties
         */
        [[nodiscard]] SDL_Rect getRect() const { return _rect; }

        /**
         * @brief Set the texture rectangle properties
         * @param rect Arcade rectangle properties to apply
         */
        void setRect(Rect rect);

        /**
         * @brief Replace the SDL texture
         * @param texture New SDL texture
         */
        void setTexture(std::shared_ptr<SDL_Texture> texture) { _texture = std::move(texture); }

        /**
         * @brief Scale texture to fit game grid cells
         * @param gridWidth Width of game grid
         * @param gridHeight Height of game grid
         * @param windowWidth Width of the window
         * @param windowHeight Height of the window
         */
        void scaleToGameSize(int gridWidth, int gridHeight, int windowWidth, int windowHeight);

    private:
        /**
         * @brief Create a red X texture for error indication
         * @param renderer SDL renderer to use
         */
        void createErrorTexture(const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * @brief Create an empty transparent texture
         * @param renderer SDL renderer to use
         */
        void createEmptyTexture(const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * @brief Create texture from image
         * @param textureImg Image texture information
         * @param renderer SDL renderer to use
         * @return 0 on success, -1 on failure
         */
        int createImageTexture(const TextureImg& textureImg, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * @brief Create texture from text
         * @param textureText Text texture information
         * @param renderer SDL renderer to use
         * @return 0 on success, -1 on failure
         */
        int createTextTexture(const TextureText& textureText, const std::shared_ptr<SDL_Renderer>& renderer);

        /**
         * @brief Apply rectangle dimensions from texture information
         * @param info Texture information to read from
         */
        void applyRectFromTextureInfo(const TextureBase& info);

        /**
         * @brief Query texture dimensions from SDL texture
         * @return true on success, false on failure
         */
        bool queryTextureDimensions();

        // Member variables
        SDL_Rect _rect = {0, 0, 0, 0};
        std::shared_ptr<SDL_Texture> _texture = nullptr;
        MyTexture _textureInformations;

        // Constants
        static constexpr int ERROR_TEXTURE_SIZE = 32;
        static constexpr int EMPTY_TEXTURE_SIZE = 10;
    };

    /**
     * @class SDLTextureManager
     * @brief Manager for SDL textures in Arcade
     */
    class SDLTextureManager : public ITextureManager {
    public:
        /**
         * @brief Construct a new SDLTextureManager
         * @param renderer_manager Reference to SDL renderer manager
         */
        explicit SDLTextureManager(SDLRendererManager& renderer_manager);

        /**
         * @brief Destroy the SDLTextureManager
         */
        ~SDLTextureManager() override = default;

        /**
         * @brief Load a texture with given name and data
         * @param name Name to identify the texture
         * @param newTexture Texture information to load
         * @return 0 on success, -1 on failure
         */
        int load(const std::string& name, const MyTexture& newTexture) override;

        /**
         * @brief Get a texture by name
         * @param name Name of the texture to retrieve
         * @return Shared pointer to the texture, or nullptr if not found
         */
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;

    private:
        /**
         * @brief Create a new texture
         * @param name Name to identify the texture
         * @param newTexture Texture information to load
         * @return 0 on success, -1 on failure
         */
        int createTexture(const std::string& name, const MyTexture& newTexture);

        /**
         * @brief Update an existing texture
         * @param existingTexture Existing texture to update
         * @param newTexture New texture information
         * @return 0 on success, -1 on failure
         */
        int updateTexture(std::shared_ptr<SDLTexture> existingTexture, const MyTexture& newTexture);

        // Member variables
        SDLRendererManager& _renderer;
        std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
    };
};

#endif //SDLTEXTUREMANAGER_HPP
