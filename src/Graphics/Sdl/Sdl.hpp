/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl.hpp
*/

#ifndef ARCADE_SDL_HPP
    #define ARCADE_SDL_HPP

    #include <SDL2/SDL.h>
    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <memory>
    #include "IDisplayModule.hpp"
    #include "IDisplayLibrary.hpp"
    #include "Vector.hpp"

namespace arcade
{
    /**
     * Sdl class to handle the SDL library for the display
     */
    class Sdl : public IDisplayModule
    {
    public:
        /**
         * Construct a new Sdl object
         */
        Sdl();
        /**
         * Destroy the Sdl object
         */
        ~Sdl();
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
        Keyboard &getKeyboard() override;
        /**
         * Get the mouse
         * @return Mouse
         */
        Mouse &getMouse() override;

    private:
        std::string _name;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        Keyboard _keyboard;
        Mouse _mouse;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
    };
}

/**
 * Initialize the display
 * @return void*
 */
extern "C" void *initDisplay();
/**
 * Destroy the display
 * @param display Display to destroy
 */
extern "C" void destroyDisplay(void *display);

#endif //ARCADE_SDL_HPP
