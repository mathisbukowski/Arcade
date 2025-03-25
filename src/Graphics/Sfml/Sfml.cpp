/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

arcade::Sfml::Sfml()
{
    _name = "sfml";
    _window = nullptr;
    _keyboard = Keyboard();
    _mouse = Mouse();
    _textures = std::map<std::string, std::shared_ptr<ITexture>>();
}

arcade::Sfml::~Sfml()
{
}

void arcade::Sfml::init()
{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Arcade");
}

void arcade::Sfml::stop()
{
    _window->close();
}

const std::string &arcade::Sfml::getName() const
{
    return _name;
}

void arcade::Sfml::setupWindowProperties(WindowProperties &properties)
{
    properties.setWidth(800);
    properties.setHeight(600);
    properties.setTitle("Arcade");
}

void arcade::Sfml::openWindow()
{
    _window->create(sf::VideoMode(800, 600), "Arcade");
}

void arcade::Sfml::closeWindow()
{
    _window->close();
}

void arcade::Sfml::clearWindow(Color color)
{
    _window->clear(sf::Color(color.getR(), color.getG(), color.getB(), color.getOpacity()));
}

void arcade::Sfml::updateWindow(float delta)
{
    _window->display();
}

bool arcade::Sfml::isWindowOpen()
{
    return _window->isOpen();
}

void arcade::Sfml::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    auto textureInfo = texture->getInformations();
    if (std::holds_alternative<TextureImg>(textureInfo)) {
        auto textureImg = std::get<TextureImg>(textureInfo);
        sf::Texture sfTexture;
        sfTexture.loadFromFile(textureImg.getPath());
        sf::Sprite sprite(sfTexture);
        sprite.setPosition(position.getX(), position.getY());
        _window->draw(sprite);
    } else {
        auto textureText = std::get<TextureText>(textureInfo);
        sf::Font font;
        font.loadFromFile("assets/font.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(textureText.getText());
        text.setCharacterSize(24);
        text.setFillColor(sf::Color(textureText.getColor().getR(), textureText.getColor().getG(), textureText.getColor().getB(), textureText.getColor().getOpacity()));
        text.setPosition(position.getX(), position.getY());
        _window->draw(text);
    }
}

arcade::Keyboard &arcade::Sfml::getKeyboard()
{
    return _keyboard;
}

arcade::Mouse &arcade::Sfml::getMouse()
{
    return _mouse;
}

extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::Sfml();
    }
    arcade::LibType entryPointType() {
        return arcade::DISPLAY;
    }
    const char* entryPointName() {
        return "SFML";
    }
}