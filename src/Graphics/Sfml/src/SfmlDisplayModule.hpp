/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SFMLDISPLAYMODULE_HPP
#define SFMLDISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
    /**
     * @class SFMLDisplay
     * This class is used to create a display using the SFML library
     * It inherits from the IDisplayModule interface
     */
    class SFMLDisplay : public IDisplayModule {
    public:
        /**
         * Construct a new SFMLDisplay object
         */
        SFMLDisplay();
        /**
         * Destroy the SFMLDisplay object
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
         * @return const std::string&
         */
        const std::string& getName() const override;
        /**
         * Setup the window properties
         * @param properties WindowProperties& Properties of the window
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
         * Clear the window
         * @param color Color Color to clear the window with
         */
        void clearWindow(Color color) override;
        /**
         * Update the window
         * @param delta float Delta time
         */
        void updateWindow(float delta) override;
        /**
         * Check if the window is open
         * @return bool
         */
        bool isWindowOpen() override;
        /**
         * Draw a texture on the window
         * @param texture std::shared_ptr<ITexture> Texture to draw
         * @param position Vector<float> Position to draw the texture at
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        /**
         * Get the keyboard object
         * @return Keyboard&
         */
        Keyboard& getKeyboard() override;
        /**
         * Get the mouse object
         * @return Mouse&
         */
        Mouse& getMouse() override;

        /**
         * Process events
         */
        void processEvents();

    private:
        /**
         * Handle events
         * @param event const sf::Event& Event to handle
         */
        void handleEvent(const sf::Event& event);
        /**
         * Handle key events
         * @param keyEvent const sf::Event::KeyEvent& Key event to handle
         * @param isPressed bool True if the key is pressed, false if it is released
         */
        void handleKeyEvent(const sf::Event::KeyEvent& keyEvent, bool isPressed);
        /**
         * Map SFML key to Arcade key
         * @param sfmlKey sf::Keyboard::Key SFML key to map
         * @return Keyboard::KeyCode Arcade key
         */
        Keyboard::KeyCode mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey);
        /**
         * Window name
         */
        std::string _name;
        /**
         * sf::RenderWindow object
         */
        std::shared_ptr<sf::RenderWindow> _window;
        /**
         * keyboard object
         */
        Keyboard _keyboard;
        /**
         * mouse object
         */
        Mouse _mouse;
        /**
         * Window properties
         */
        WindowProperties _properties;
    };
};


#endif //SFMLDISPLAYMODULE_HPP
