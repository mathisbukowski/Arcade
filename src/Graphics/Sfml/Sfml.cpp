/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SFML implementation for arcade
*/

#include "Sfml.hpp"
#include <iostream>
#include <filesystem>

namespace arcade {

SFMLTexture::SFMLTexture(const MyTexture& textureInfo) : _info(textureInfo)
{
    if (std::holds_alternative<TextureImg>(textureInfo)) {
        loadFromImage(std::get<TextureImg>(textureInfo));
    } else {
        loadFromText(std::get<TextureText>(textureInfo));
    }
}

void SFMLTexture::loadFromImage(const TextureImg& textureImg)
{
    if (!std::filesystem::exists(textureImg.getPath())) {
        createDefaultSprite();
        std::cerr << "Texture file not found: " << textureImg.getPath() << std::endl;
        return;
    }
    if (!_texture.loadFromFile(textureImg.getPath())) {
        createDefaultSprite();
        std::cerr << "Failed to load texture: " << textureImg.getPath() << std::endl;
        return;
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
    sf::Text text;
    sf::Font font;

    if (!loadFontForText(font)) {
        createDefaultSprite();
        return;
    }
    text.setFont(font);
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

bool SFMLTexture::loadFontForText(sf::Font& font)
{
    const std::vector<std::string> possibleFonts = {
        "assets/fonts/PixelFont.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
    };
    for (const auto& fontPath : possibleFonts) {
        if (std::filesystem::exists(fontPath) && font.loadFromFile(fontPath))
            return true;
    }
    std::cerr << "Failed to load any font, text rendering might not work" << std::endl;
    return false;
}

void SFMLTexture::createDefaultSprite()
{
    sf::Sprite sprite;
    _texture.create(32, 32);
    std::vector<sf::Uint8> pixels(32 * 32 * 4, 255);
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
    return std::get<sf::Sprite>(_drawable);
}

sf::Text& SFMLTexture::getText()
{
    return std::get<sf::Text>(_drawable);
}

bool SFMLTexture::isText() const
{
    return std::holds_alternative<sf::Text>(_drawable);
}

SFMLFont::SFMLFont(const Font& fontInfo) : _info(fontInfo)
{
    if (std::filesystem::exists(fontInfo.getPath())) {
        if (!_font.loadFromFile(fontInfo.getPath())) {
            std::cerr << "Failed to load font: " << fontInfo.getPath() << std::endl;
            loadFallbackFont();
        }
    } else {
        std::cerr << "Font file not found: " << fontInfo.getPath() << std::endl;
        loadFallbackFont();
    }
}

void SFMLFont::loadFallbackFont()
{
    const std::vector<std::string> possibleFonts = {
        "assets/fonts/PixelFont.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
    };

    for (const auto& fontPath : possibleFonts) {
        if (std::filesystem::exists(fontPath) && _font.loadFromFile(fontPath)) {
            return;
        }
    }
}

const Font& SFMLFont::getInformations() const
{
    return _info;
}

sf::Font& SFMLFont::getFont()
{
    return _font;
}
}
