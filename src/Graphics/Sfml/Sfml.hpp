/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sfml.hpp
*/

#ifndef ARCADE_SFML_HPP
    #define ARCADE_SFML_HPP

    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <memory>
    #include "IDisplayModule.hpp"
    #include "IDisplayLibrary.hpp"
    #include "Vector.hpp"
    #include "Arcade.hpp"

namespace arcade
{
    /**
     * Sfml class to handle the SFML library for the display
     */
    class Sfml : public IDisplayModule, public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Sfml object
         */
        Sfml();
        /**
         * Destroy the Sfml object
         */
        ~Sfml();
        /**
         * Initialize the SFML library
         */
        void init() override;
        /**
         * Stop the SFML library
         */
        void stop() override;
        /**
         * Get the name of the library
         * @return const std::string
         */
        const std::string &getName() const override;
        /**
         * Setup the window properties
         * @param properties WindowProperties
         */
        void setupWindowProperties(WindowProperties &properties) override;
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
         * @param color Color
         */
        void clearWindow(Color color) override;
        /**
         * Update the window
         * @param delta Delta time
         */
        void updateWindow(float delta) override;
        /**
         * Check if the window is open
         * @return bool
         */
        bool isWindowOpen() override;
        /**
         * Draw a texture
         * @param texture Texture
         * @param position Position
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        /**
         * Get the keyboard
         * @return Keyboard
         */
        Keyboard &getKeyboard() override;
        /**
         * Get the mouse
         * @return Mouse
         */
        Mouse &getMouse() override;
        /**
         * Get the Display object
         * @return IDisplayModule&
         */
        IDisplayModule &getDisplay() override;
        /**
        * Get the Texture Manager object
        * @return ITextureManager&
        */
        ITextureManager &getTextures() override;
        /**
         * Get the Font Manager object
         * @return IFontManager&
         */
        IFontManager &getFonts() override;
        /**
         * Get the Sound Manager object
         * @return ISoundManager&
         */
        ISoundManager &getSounds() override;

    private:
        std::string _name;
        sf::RenderWindow *_window;
        Keyboard _keyboard;
        Mouse _mouse;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
    };
}

#endif //ARCADE_SFML_HPP
