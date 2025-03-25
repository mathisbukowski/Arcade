/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ncurses.hpp
*/

#ifndef ARCADE_NCURSES_HPP
    #define ARCADE_NCURSES_HPP

    #include <ncurses.h>
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
     * Ncurses class to handle the Ncurses library for the display
     */
    class Ncurses : public IDisplayModule, public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Ncurses object
         */
        Ncurses();
        /**
         * Destroy the Ncurses object
         */
        ~Ncurses();
        /**
         * Initialize the Ncurses library
         */
        void init() override;
        /**
         * Stop the Ncurses library
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
        WINDOW *_window;
        Keyboard _keyboard;
        Mouse _mouse;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
    };
}

#endif //ARCADE_NCURSES_HPP
