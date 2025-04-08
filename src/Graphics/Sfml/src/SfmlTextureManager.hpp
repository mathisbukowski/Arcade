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
    class SFMLTexture : public ITexture {
    public:
        explicit SFMLTexture(const MyTexture& textureInfo);
        ~SFMLTexture() override = default;

        const MyTexture& getInformations() const override;
        void set(MyTexture& newTexture) override;
        sf::Sprite& getSprite();
        sf::Text& getText();
        bool isText() const;

    private:
        void loadFromImage(const TextureImg& textureImg);
        void loadFromText(const TextureText& textureText);

        void createErrorTexture();

        MyTexture _info;
        std::variant<sf::Sprite, sf::Text> _drawable;
        sf::Texture _texture;
        std::shared_ptr<sf::Font> _font;
    };

    /**
     * Implementation of ITextureManager for SFML
     */
    class SFMLTextureManager : public ITextureManager {
    public:
        /**
         * Constructor of Texture Manager
         */
        SFMLTextureManager() noexcept = default;
        ~SFMLTextureManager() override = default;

        int load(const std::string& name, const MyTexture& newTexture) override;
        std::shared_ptr<ITexture> get(const std::string& name) const override;

    private:
        mutable std::map<std::string, std::shared_ptr<SFMLTexture>> _textures;
    };

}



#endif //SFMLTEXTUREMANAGER_HPP
