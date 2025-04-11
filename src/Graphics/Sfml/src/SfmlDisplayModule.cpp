/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "SfmlDisplayModule.hpp"
#include <filesystem>
#include <iostream>
#include "SfmlFontManager.hpp"
#include "SfmlTextureManager.hpp"

namespace arcade {
    SFMLDisplay::SFMLDisplay() : _name("SFML"), _window(nullptr), _properties(WindowProperties("", 0, 0))
    {}

    SFMLDisplay::~SFMLDisplay()
    {
        try {
            if (_window != nullptr) {
                _window->close();
                _window.reset();
                _window = nullptr;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in SFMLDisplay destructor: " << e.what() << std::endl;
        }
    }

    void SFMLDisplay::init(const std::string& title, size_t width, size_t height)
    {
        try {
            if (_window != nullptr) {
                _window->close();
                _window.reset();
                _window = nullptr;
            }
            _window = std::make_shared<sf::RenderWindow>(
               sf::VideoMode(width, height, 32),
               title,
               sf::Style::Titlebar | sf::Style::Close
           );
            if (!_window)
                throw std::runtime_error("Failed to create SFML window");
            _window->setFramerateLimit(60);
        } catch (const std::exception& e) {
            std::cerr << "Error in SFMLDisplay::init(): " << e.what() << std::endl;
            throw;
        }
    }

    void SFMLDisplay::stop()
    {
        try {
            if (_window != nullptr) {
                _window->close();
                _window.reset();
                _window = nullptr;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in SFMLDisplay::stop(): " << e.what() << std::endl;
        }
    }

    const std::string& SFMLDisplay::getName() const
    {
        return _name;
    }

    void SFMLDisplay::setupWindowProperties(WindowProperties& properties)
    {
        _properties = properties;
        if (_window != nullptr) {
            _window->setSize(sf::Vector2u(_properties.getWidth(), _properties.getHeight()));
            _window->setTitle(_properties.getTitle());
        }
    }

    void SFMLDisplay::openWindow()
    {
        try {
            if (_window == nullptr) {
                this->init(_properties.getTitle(), _properties.getWidth(), _properties.getHeight());
            } else if (!_window->isOpen()) {
                _window->create(
                    sf::VideoMode(_properties.getWidth(), _properties.getHeight()),
                    _properties.getTitle(),
                    sf::Style::Titlebar | sf::Style::Close
                );
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in openWindow: " << e.what() << std::endl;
            throw;
        }
    }

    void SFMLDisplay::closeWindow()
    {
        if (_window != nullptr)
            _window->close();
    }

    void SFMLDisplay::clearWindow(Color color)
    {
        if (_window != nullptr && _window->isOpen())
            _window->clear(sf::Color(color.getR(), color.getG(), color.getB(), color.getOpacity()));
    }

    void SFMLDisplay::updateWindow(float delta)
    {
        (void)delta;

        try {
            if (_window != nullptr && _window->isOpen()) {
                this->processEvents();
                _window->display();
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in updateWindow: " << e.what() << std::endl;
        }
    }

    bool SFMLDisplay::isWindowOpen()
    {
        return _window != nullptr && _window->isOpen();
    }

    void SFMLDisplay::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
    {
        if (_window == nullptr || !_window->isOpen())
            return;

        try {
            auto sfmlTexture = std::dynamic_pointer_cast<SFMLTexture>(texture);
            if (!sfmlTexture) {
                std::cerr << "Invalid texture type" << std::endl;
                return;
            }
            if (sfmlTexture->isText()) {
                drawText(sfmlTexture, position);
            } else {
                drawSprite(sfmlTexture, position);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in drawTexture: " << e.what() << std::endl;
        }
    }

    void SFMLDisplay::drawText(std::shared_ptr<SFMLTexture> texture, Vector<float> position)
    {
        sf::Text& text = texture->getText();
        text.setPosition(position.getX(), position.getY());
        _window->draw(text);
    }

    void SFMLDisplay::drawSprite(std::shared_ptr<SFMLTexture> texture, Vector<float> position)
    {
        sf::Sprite& sprite = texture->getSprite();
        sf::Vector2f originalScale = sprite.getScale();

        auto [scaleX, scaleY] = calculateSpriteScale(sprite);
        sprite.setScale(scaleX, scaleY);

        auto [x, y] = calculateAdjustedPosition(position);
        sprite.setPosition(x, y);

        _window->draw(sprite);
        sprite.setScale(originalScale);
    }

    std::pair<float, float> SFMLDisplay::calculateSpriteScale(const sf::Sprite& sprite)
    {
        float cellWidth = _properties.getWidth() / 20.0f;
        float cellHeight = _properties.getHeight() / 20.0f;
        float scaleFactor = 1.0f;

        sf::FloatRect bounds = sprite.getLocalBounds();
        if (bounds.width > 0 && bounds.height > 0) {
            float scaleX = (cellWidth * scaleFactor) / bounds.width;
            float scaleY = (cellHeight * scaleFactor) / bounds.height;
            return {scaleX, scaleY};
        }
        return {1.0f, 1.0f};
    }

    std::pair<float, float> SFMLDisplay::calculateAdjustedPosition(Vector<float> position)
    {
        float cellWidth = _properties.getWidth() / 20.0f;
        float cellHeight = _properties.getHeight() / 20.0f;
        float scaleFactor = 1.0f;

        float offsetX = (cellWidth * (1.0f - scaleFactor)) / 2.0f;
        float offsetY = (cellHeight * (1.0f - scaleFactor)) / 2.0f;

        return {position.getX() + offsetX, position.getY() + offsetY};
    }

    Keyboard& SFMLDisplay::getKeyboard()
    {
        return _keyboard;
    }

    Mouse& SFMLDisplay::getMouse()
    {
        return _mouse;
    }

    void SFMLDisplay::processEvents()
    {
        if (_window == nullptr || !_window->isOpen()) return;

        try {
            sf::Event event;
            while (_window->pollEvent(event))
                this->handleEvent(event);
        } catch (const std::exception& e) {
            std::cerr << "Error in processEvents: " << e.what() << std::endl;
        }
    }

    void SFMLDisplay::handleEvent(const sf::Event& event)
    {
        switch (event.type) {
            case sf::Event::Closed:
                _window->close();
                break;
            case sf::Event::KeyPressed:
                this->handleKeyEvent(event.key, true);
                break;
            case sf::Event::KeyReleased:
                this->handleKeyEvent(event.key, false);
                break;
            case sf::Event::MouseButtonPressed:
                _mouse.setPressed(true);
                _mouse.setPos(Vector<float>(event.mouseButton.x, event.mouseButton.y));
                break;
            case sf::Event::MouseButtonReleased:
                _mouse.setPressed(false);
                _mouse.setPos(Vector<float>(event.mouseButton.x, event.mouseButton.y));
                break;
            case sf::Event::MouseMoved:
                _mouse.setPos(Vector<float>(event.mouseMove.x, event.mouseMove.y));
                break;
            default:
                break;
        }
    }

    void SFMLDisplay::handleKeyEvent(const sf::Event::KeyEvent& keyEvent, bool isPressed)
    {
        Keyboard::KeyCode code = this->mapSfmlKeyToArcade(keyEvent.code);

        _keyboard.setKey(code, isPressed);
    }

    Keyboard::KeyCode SFMLDisplay::mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey)
    {
        static const std::unordered_map<sf::Keyboard::Key, Keyboard::KeyCode> keyMap = {
            {sf::Keyboard::A, Keyboard::KeyCode::A},
            {sf::Keyboard::B, Keyboard::KeyCode::B},
            {sf::Keyboard::C, Keyboard::KeyCode::C},
            {sf::Keyboard::D, Keyboard::KeyCode::D},
            {sf::Keyboard::E, Keyboard::KeyCode::E},
            {sf::Keyboard::F, Keyboard::KeyCode::F},
            {sf::Keyboard::G, Keyboard::KeyCode::G},
            {sf::Keyboard::H, Keyboard::KeyCode::H},
            {sf::Keyboard::I, Keyboard::KeyCode::I},
            {sf::Keyboard::J, Keyboard::KeyCode::J},
            {sf::Keyboard::K, Keyboard::KeyCode::K},
            {sf::Keyboard::L, Keyboard::KeyCode::L},
            {sf::Keyboard::M, Keyboard::KeyCode::M},
            {sf::Keyboard::N, Keyboard::KeyCode::N},
            {sf::Keyboard::O, Keyboard::KeyCode::O},
            {sf::Keyboard::P, Keyboard::KeyCode::P},
            {sf::Keyboard::Q, Keyboard::KeyCode::Q},
            {sf::Keyboard::R, Keyboard::KeyCode::R},
            {sf::Keyboard::S, Keyboard::KeyCode::S},
            {sf::Keyboard::T, Keyboard::KeyCode::T},
            {sf::Keyboard::U, Keyboard::KeyCode::U},
            {sf::Keyboard::V, Keyboard::KeyCode::V},
            {sf::Keyboard::W, Keyboard::KeyCode::W},
            {sf::Keyboard::X, Keyboard::KeyCode::X},
            {sf::Keyboard::Y, Keyboard::KeyCode::Y},
            {sf::Keyboard::Z, Keyboard::KeyCode::Z},
            {sf::Keyboard::Return, Keyboard::KeyCode::ENTER},
            {sf::Keyboard::Num1, Keyboard::KeyCode::KEY_1},
            {sf::Keyboard::Num2, Keyboard::KeyCode::KEY_2},
            {sf::Keyboard::Num3, Keyboard::KeyCode::KEY_3},
            {sf::Keyboard::Num4, Keyboard::KeyCode::KEY_4},
            {sf::Keyboard::Num5, Keyboard::KeyCode::KEY_5},
            {sf::Keyboard::Num6, Keyboard::KeyCode::KEY_6},
            {sf::Keyboard::Num7, Keyboard::KeyCode::KEY_7},
            {sf::Keyboard::Num8, Keyboard::KeyCode::KEY_8},
            {sf::Keyboard::Num9, Keyboard::KeyCode::KEY_9},
            {sf::Keyboard::Up, Keyboard::KeyCode::UP},
            {sf::Keyboard::Down, Keyboard::KeyCode::DOWN},
            {sf::Keyboard::Left, Keyboard::KeyCode::LEFT},
            {sf::Keyboard::Right, Keyboard::KeyCode::RIGHT},
            {sf::Keyboard::Escape, Keyboard::KeyCode::ESCAPE}
        };

        auto it = keyMap.find(sfmlKey);
        return (it != keyMap.end()) ? it->second : Keyboard::KeyCode::UNKNOWN;
    }

}
