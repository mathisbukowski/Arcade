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
     * @class Implementation of IDisplayModule for SFML
     * This class is used to create a display using the SFML library
     * It inherits from the IDisplayModule interface
     */
    class SFMLDisplay : public IDisplayModule {
    public:
        /**
         * Constructor
         */
        SFMLDisplay();
        /**
         * Destructor
         */
        ~SFMLDisplay() override;

        /**
         * Initialize the display
         * @param title const std::string & Title of the window
         * @param width size_t Width of the window
         * @param height size_t Height of the window
         */
        void init(const std::string& title, size_t width, size_t height) override;
        /**
         * Stop the display
         */
        void stop() override;
        /**
         * Get the name of the display
         * @return const std::string & Name of the display
         */
        const std::string& getName() const override;
        /**
         * Set the window properties
         * @param properties WindowProperties & width, height and title of the window
         */
        void setupWindowProperties(WindowProperties& properties) override;
        /**
         * Open the window
         */
        void openWindow() override;
        /**
         * Close the window
         */
        void closeWindow() override;
        /**
         * Clear the window with a color
         * @param color Color Color to clear the window with
         */
        void clearWindow(Color color) override;
        /**
         * Update the window
         * @param delta float Time since the last update
         */
        void updateWindow(float delta) override;
        /**
         * Check if the window is open
         * @return bool True if the window is open, false otherwise
         */
        bool isWindowOpen() override;
        /**
         * Draw a texture
         * @param texture std::shared_ptr<ITexture> Texture to draw
         * @param position Vector<float> Position to draw the texture at
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        /**
         * Getter for the keyboard variable
         * @return Keyboard& Keyboard object
        */
        Keyboard& getKeyboard() override;
        /**
         * Getter for the mouse variable
         * @return Mouse& Mouse object
         */
        Mouse& getMouse() override;
        /**
         * Get the window properties
         * @return WindowProperties& Window properties
         */
        WindowProperties& getWindowProperties() override;

        /**
         * Function to process events
         */
        void processEvents();

    private:
        /**
         * Handle SFML events
         * @param event const sf::Event & Event to handle
         */
        void handleEvent(const sf::Event& event);
        /**
         * Handle key events
         * @param keyEvent const sf::Event::KeyEvent & Key event to handle
         * @param isPressed bool True if the key is pressed, false if released
         */
        void handleKeyEvent(const sf::Event::KeyEvent& keyEvent, bool isPressed);
        /**
         * Map SFML key to Arcade key
         * @param sfmlKey sf::Keyboard::Key SFML key to map
         * @return Keyboard::KeyCode Mapped Arcade key
         */
        Keyboard::KeyCode mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey);
        /**
         * Draw text
         * @param texture std::shared_ptr<SFMLTexture> Texture to draw
         * @param position Vector<float> Position to draw the texture at
         */
        void drawText(std::shared_ptr<SFMLTexture> texture, Vector<float> position);
        /**
         * Draw sprite
         * @param texture std::shared_ptr<SFMLTexture> Texture to draw
         * @param position Vector<float> Position to draw the texture at
         */
        void drawSprite(std::shared_ptr<SFMLTexture> texture, Vector<float> position);
        /**
         * Calculate the scale of the sprite
         * @param sprite const sf::Sprite & Sprite to calculate the scale for
         * @return std::pair<float, float> Scale of the sprite
         */
        std::pair<float, float> calculateSpriteScale(const sf::Sprite& sprite);
        /**
         * Calculate the adjusted position of the sprite
         * @param position Vector<float> Position to adjust
         * @return std::pair<float, float> Adjusted position of the sprite
         */
        std::pair<float, float> calculateAdjustedPosition(Vector<float> position);
        /**
         * Window name
         */
        std::string _name;
        /**
         * SFML window
         */
        std::shared_ptr<sf::RenderWindow> _window;
        /**
         * Keyboard object
         */
        Keyboard _keyboard;
        /**
         * Mouse object
         */
        Mouse _mouse;
        /**
         * Window properties
         */
        WindowProperties _properties;
    };
};


#endif //SFMLDISPLAYMODULE_HPP
