/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLDISPLAYMODULE_HPP
#define SDLDISPLAYMODULE_HPP

#include "Arcade.hpp"
#include "IDisplayModule.hpp"

namespace arcade {
    class SDLDisplayModule : public IDisplayModule {
        SDLDisplayModule(const std::string &name = "SDL2");
        ~SDLDisplayModule() override;
        /**
         * Initialize the SDL library
         */
        void init() override;
        /**
         * Stop the SDL library
         */
        void stop() override;
        /**
         * Get the name of the library
         * @return const std::string
         */
        [[nodiscard]] const std::string &getName() const override;
        /**
         * Set up the window properties
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
         * Clear the window with a color
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
         * Draw a texture on the window
         * @param texture Texture to draw
         * @param position Position of the texture
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        /**
         * Get the keyboard
         * @return Keyboard
         */
        [[nodiscard]] Keyboard &getKeyboard() override;
        /**
         * Get the mouse
         * @return Mouse
         */
        [[nodiscard]] Mouse &getMouse() override;
    private:
        WindowProperties _windowProperties;
        std::string _name;
        bool _isOpen;
        Keyboard _keyboard;
        Mouse _mouse;
    };
};



#endif //SDLDISPLAYMODULE_HPP
