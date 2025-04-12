/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SFMLTEXTUREMANAGER_HPP
#define SFMLTEXTUREMANAGER_HPP

#include "ITexture.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

namespace arcade {
    /**
     * @class SFMLTexture
     * This class is used to create a texture using the SFML library
     * It inherits from the ITexture interface
     */
    class SFMLTexture : public ITexture {
    public:
        /**
         * Construct a new SFMLTexture object
         * @param textureInfo const MyTexture& Texture information
         */
        explicit SFMLTexture(const MyTexture& textureInfo);
        /**
         * Destroy the SFMLTexture object
         */
        ~SFMLTexture() override = default;

        /**
         * get the texture information
         * @return const MyTexture&
         */
        const MyTexture& getInformations() const override;
        /**
         * set the texture information
         * @param newTexture MyTexture& New texture information
         */
        void set(MyTexture& newTexture) override;
        /**
         * get the SFML sprite
         * @return sf::Sprite&
         */
        sf::Sprite& getSprite();
        /**
         * get the SFML text
         * @return sf::Text&
         */
        sf::Text& getText();
        /**
         * check if the texture is a text
         * @return bool
         */
        bool isText() const;

    private:
        /**
         * Load texture from image
         * @param textureImg const TextureImg& Texture image information
         */
        void loadFromImage(const TextureImg& textureImg);
        /**
         * Load texture from text
         * @param textureText const TextureText& Texture text information
         */
        void loadFromText(const TextureText& textureText);

        /**
         * Create an error texture
         */
        void createErrorTexture();

        /**
         * Texture information
         */
        MyTexture _info;
        /**
         * SFML drawable object (sprite or text)
         */
        std::variant<sf::Sprite, sf::Text> _drawable;
        /**
         * SFML texture object
         */
        sf::Texture _texture;
        /**
         * SFML font object
         */
        std::shared_ptr<sf::Font> _font;
    };

    /**
     * @class SFMLTextureManager
     * This class is used to manage textures using the SFML library
     * It inherits from the ITextureManager interface
     */
    class SFMLTextureManager : public ITextureManager {
    public:
        /**
         * Construct a new SFMLTextureManager object
         */
        SFMLTextureManager() noexcept = default;
        /**
         * Destroy the SFMLTextureManager object
         */
        ~SFMLTextureManager() override = default;

        /**
         * Load a texture
         * @param name const std::string& Name of the texture
         * @param newTexture const MyTexture& Texture information
         * @return int
         */
        int load(const std::string& name, const MyTexture& newTexture) override;
        /**
         * Get a texture
         * @param name const std::string& Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        std::shared_ptr<ITexture> get(const std::string& name) const override;

    private:
        /**
         * Map of textures
         */
        mutable std::map<std::string, std::shared_ptr<SFMLTexture>> _textures;
    };

}



#endif //SFMLTEXTUREMANAGER_HPP
