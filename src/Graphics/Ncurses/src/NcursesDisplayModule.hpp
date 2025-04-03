/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesDisplayModule.hpp
*/

#ifndef NCURSES_DISPLAY_HPP
    #define NCURSES_DISPLAY_HPP

#include <ncurses.h>

#include "IDisplayModule.hpp"

namespace arcade {
    class NcursesDisplayModule : public IDisplayModule {
    public:
        NcursesDisplayModule(const std::string &name = "SDL2");
        ~NcursesDisplayModule() override;
        /**
         * Initialize the SDL library
         */
        void init(const std::string& title, size_t width, size_t height) override;
        /**
         * Stop the SDL library
         */
        void stop() override;
        /**
         * Get the name of the library
         * @return const std::string
         */
        [[nodiscard]] const std::string &getName() const override { return _name; }
        /**
         * Set up the window properties
         * @param properties WindowProperties
         */
        void setupWindowProperties(WindowProperties &properties) override { _windowProperties = properties; }
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
        bool isWindowOpen() override { return _isOpen; }
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
        [[nodiscard]] Keyboard &getKeyboard() override { return _keyboard; }
        /**
         * Get the mouse
         * @return Mouse
         */
        [[nodiscard]] Mouse &getMouse() override { return _mouse; }

        [[nodiscard]] std::shared_ptr<WINDOW> getRenderer() const { return _renderer; }
        [[nodiscard]] std::shared_ptr<WINDOW> getWindow() const { return _window; }
        [[nodiscard]] WindowProperties getWindowProperties() const { return _windowProperties; }

    private:
        std::shared_ptr<WINDOW> _renderer = nullptr;
        std::shared_ptr<WINDOW> _window = nullptr;
        WindowProperties _windowProperties;
        std::string _name;
        bool _isOpen;
        Keyboard _keyboard;
        Mouse _mouse;
    };
};


#endif //NCURSES_DISPLAY_HPP
