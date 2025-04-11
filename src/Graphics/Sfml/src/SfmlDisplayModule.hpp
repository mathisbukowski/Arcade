/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SFMLDISPLAYMODULE_HPP
#define SFMLDISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "SfmlTextureManager.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
    /**
 * Implementation of IDisplayModule for SFML
 */
    class SFMLDisplay : public IDisplayModule {
    public:
        SFMLDisplay();
        ~SFMLDisplay() override;

        void init(const std::string& title, size_t width, size_t height) override;
        void stop() override;
        const std::string& getName() const override;
        void setupWindowProperties(WindowProperties& properties) override;
        void openWindow() override;
        void closeWindow() override;
        void clearWindow(Color color) override;
        void updateWindow(float delta) override;
        bool isWindowOpen() override;
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        Keyboard& getKeyboard() override;
        Mouse& getMouse() override;

        void processEvents();

    private:
        void handleEvent(const sf::Event& event);
        void handleKeyEvent(const sf::Event::KeyEvent& keyEvent, bool isPressed);
        Keyboard::KeyCode mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey);
        void drawText(std::shared_ptr<SFMLTexture> texture, Vector<float> position);
        void drawSprite(std::shared_ptr<SFMLTexture> texture, Vector<float> position);
        std::pair<float, float> calculateSpriteScale(const sf::Sprite& sprite);
        std::pair<float, float> calculateAdjustedPosition(Vector<float> position);
        std::string _name;
        std::shared_ptr<sf::RenderWindow> _window;
        Keyboard _keyboard;
        Mouse _mouse;
        WindowProperties _properties;
    };
};


#endif //SFMLDISPLAYMODULE_HPP
