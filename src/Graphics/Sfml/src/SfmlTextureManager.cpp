/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "SfmlTextureManager.hpp"
#include <filesystem>

namespace arcade {
    SFMLTexture::SFMLTexture(const MyTexture& textureInfo) : _info(textureInfo),
                                                         _font(std::make_shared<sf::Font>()),
    ITexture(textureInfo)
    {
        try {
            if (std::holds_alternative<TextureImg>(textureInfo)) {
                this->loadFromImage(std::get<TextureImg>(textureInfo));
            } else {
                this->loadFromText(std::get<TextureText>(textureInfo));
            }
        } catch (const std::exception& e) {
            std::cerr << "Error creating texture: " << e.what() << std::endl;
           this->createErrorTexture();
        }
    }

    void SFMLTexture::loadFromImage(const TextureImg& textureImg)
    {
        if (!std::filesystem::exists(textureImg.getPath())) {
            throw std::runtime_error("Texture file not found");
        }
        if (!_texture.loadFromFile(textureImg.getPath())) {
            throw std::runtime_error("Failed to load texture");
        }
        sf::Sprite sprite;
        sprite.setTexture(_texture);
        _drawable = sprite;
        auto& mutableImg = const_cast<TextureImg&>(std::get<TextureImg>(_info));
        mutableImg.setWidth(_texture.getSize().x);
        mutableImg.setHeight(_texture.getSize().y);
    }

    void SFMLTexture::loadFromText(const TextureText& textureText)
    {
        if (!std::filesystem::exists("assets/fonts/PixelFont.ttf")) {
            throw std::runtime_error("Font file not found");
        }

        if (!_font->loadFromFile("assets/fonts/PixelFont.ttf")) {
            throw std::runtime_error("Failed to load required font");
        }

        sf::Text text;
        text.setFont(_font.operator*());
        text.setString(textureText.getText());
        text.setFillColor(sf::Color(
            textureText.getColor().getR(),
            textureText.getColor().getG(),
            textureText.getColor().getB(),
            textureText.getColor().getOpacity()
        ));

        if (textureText.getRect().has_value()) {
            auto rect = textureText.getRect().value();
            text.setPosition(rect.getPosition().getX(), rect.getPosition().getY());
        }

        _drawable = text;
        auto& mutableText = const_cast<TextureText&>(std::get<TextureText>(_info));
        mutableText.setWidth(text.getLocalBounds().width);
        mutableText.setHeight(text.getLocalBounds().height);
    }

    void SFMLTexture::createErrorTexture()
    {
        sf::Sprite sprite;
        _texture.create(32, 32);

        std::vector<sf::Uint8> pixels(32 * 32 * 4, 0);

        for (int y = 0; y < 32; y++) {
            for (int x = 0; x < 32; x++) {
                int index = (y * 32 + x) * 4;
                pixels[index] = 0;
                pixels[index+1] = 0;
                pixels[index+2] = 0;
                pixels[index+3] = 0;
                if (x == y || x == (31 - y)) {
                    pixels[index] = 255;
                    pixels[index+1] = 0;
                    pixels[index+2] = 0;
                    pixels[index+3] = 255;
                }
            }
        }

        _texture.update(pixels.data());
        sprite.setTexture(_texture);
        _drawable = sprite;

        if (std::holds_alternative<TextureImg>(_info)) {
            auto& mutableImg = const_cast<TextureImg&>(std::get<TextureImg>(_info));
            mutableImg.setWidth(32);
            mutableImg.setHeight(32);
        } else {
            auto& mutableText = const_cast<TextureText&>(std::get<TextureText>(_info));
            mutableText.setWidth(32);
            mutableText.setHeight(32);
        }
    }

    const MyTexture& SFMLTexture::getInformations() const
    {
        return _info;
    }

    sf::Sprite& SFMLTexture::getSprite()
    {
        if (!std::holds_alternative<sf::Sprite>(_drawable))
            throw std::runtime_error("Texture is not a sprite");
        return std::get<sf::Sprite>(_drawable);
    }

    sf::Text& SFMLTexture::getText()
    {
        if (!std::holds_alternative<sf::Text>(_drawable))
            throw std::runtime_error("Texture is not a text");
        return std::get<sf::Text>(_drawable);
    }

    bool SFMLTexture::isText() const
    {
        return std::holds_alternative<sf::Text>(_drawable);
    }

    int SFMLTextureManager::load(const std::string& name, const MyTexture& newTexture)
    {
        try {
            _textures[name] = std::make_shared<SFMLTexture>(newTexture);
            return 0;
        } catch (const std::exception& e) {
            std::cerr << "Failed to load texture: " << e.what() << std::endl;
            return -1;
        }
    }

    void SFMLTexture::set(MyTexture& newTexture)
    {
        this->_info = newTexture;

        if (std::holds_alternative<TextureImg>(newTexture)) {
            this->loadFromImage(std::get<TextureImg>(newTexture));
        } else if (std::holds_alternative<TextureText>(newTexture)) {
            this->loadFromText(std::get<TextureText>(newTexture));
        } else {
            this->createErrorTexture();
        }
    }

    std::shared_ptr<ITexture> SFMLTextureManager::get(const std::string& name) const
    {
        auto it = _textures.find(name);

        if (it != _textures.end())
            return it->second;
        throw std::runtime_error("Texture not found: " + name);
    }
};
