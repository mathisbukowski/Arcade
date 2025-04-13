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
    /**
     * @class NcursesDisplayModule
     * This class is used to create a window using the ncurses library
     * It inherits from the IDisplayModule interface
     */
    class NcursesDisplayModule : public IDisplayModule {
    public:
        /**
         * Constructor
         * @param name const std::string & name Name of the display module. Default is "NCURSES"
         */
        NcursesDisplayModule(const std::string &name = "NCURSES");
        ~NcursesDisplayModule() override;
        /**
         * Initialize the SDL library
         * @param title const std::string & Title of the window
         * @param width size_t Width of the window
         * @param height size_t Height of the window
         */
        void init(const std::string& title, size_t width, size_t height) override;
        /**
         * Stop the SDL library
         */
        void stop() override;
        /**
         * Get the name of the library
         * @return const std::string & Name of the library
         */
        [[nodiscard]] const std::string &getName() const override { return _name; }
        /**
         * Set up the window properties
         * @param properties WindowProperties & Properties of the window
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
         * @param delta float Delta time
         */
        void updateWindow(float delta) override;
        /**
         * Check if the window is open
         * @return bool
         */
        bool isWindowOpen() override { return _isOpen; }
        /**
         * Draw a texture on the window
         * @param texture std::shared_ptr<ITexture> Texture to draw
         * @param position Vector<float> Position of the texture
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        /**
         * Get the keyboard
         * @return Keyboard &
         */
        [[nodiscard]] Keyboard &getKeyboard() override { return _keyboard; }
        /**
         * Get the mouse
         * @return Mouse &
         */
        [[nodiscard]] Mouse &getMouse() override { return _mouse; }

        /**
         * Get the window properties
         * @return WindowProperties
         */
        [[nodiscard]] WindowProperties& getWindowProperties() override { return _windowProperties; }

        /**
         * Get the scale factor Y
         * @return float
         */
        float getScaleFactorY() const;
        /**
         * get the scale factor X
         * @return float
         */
        float getScaleFactorX() const;

        /**
         * Process events
         */
        void processEvents();
        /**
         * Handle event
         * @param ch int Character code
         */
        void handleEvent(int ch);

    private:
        /**
         * Window properties
         */
        WindowProperties _windowProperties;
        /**
         * Name of the display module
         */
        std::string _name;
        /**
         * Check if the window is open
         */
        bool _isOpen;
        /**
         * Keyboard
         */
        Keyboard _keyboard;
        /**
         * Mouse
         */
        Mouse _mouse;
    };
};


#endif //NCURSES_DISPLAY_HPP
