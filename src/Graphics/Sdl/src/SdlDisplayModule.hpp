/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLDISPLAYMODULE_HPP
#define SDLDISPLAYMODULE_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_keycode.h>

#include "IDisplayModule.hpp"
#include "SdlRendererManager.hpp"

namespace arcade {
    /**
     * @class SDLDisplayModule
     * This class is used to create a library using the SDL2 library
     * It inherits from the IDisplayModule interface
     */
    class SDLDisplayModule : public IDisplayModule {
    public:
        /**
         * Construct a new SDLDisplayModule object
         * @param rendererManager SDLRendererManager&
         */
        SDLDisplayModule(SDLRendererManager& rendererManager);
        /**
         * Destroy the SDLDisplayModule object
         */
        ~SDLDisplayModule() override;
        /**
         * Initialize the SDL library
         * @param title std::string & Title of the window
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
         * @return const std::string &
         */
        [[nodiscard]] const std::string &getName() const override { return _name; }
        /**
         * Set up the window properties
         * @param properties WindowProperties &
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
        [[nodiscard]] Keyboard &getKeyboard() override;
        /**
         * Get the mouse
         * @return Mouse &
         */
        [[nodiscard]] Mouse &getMouse() override;

        [[nodiscard]] WindowProperties getWindowProperties() const { return _windowProperties; }

    private:
        /**
         * SDL Renderer Manager
         */
        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        /**
         * SDL Window
         */
        std::shared_ptr<SDL_Window> _window = nullptr;
        /**
         * Window properties
         */
        WindowProperties _windowProperties;
        /**
         * Window name
         */
        std::string _name = "SDL2";
        /**
         * Window is open
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
        /**
         * Map SDL key to arcade key
         * @param key SDL_Keycode
         * @return Keyboard::KeyCode
         */
        Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key);
        /**
         * SDL Renderer Manager
         */
        SDLRendererManager& _rendererManager;
    };
};



#endif //SDLDISPLAYMODULE_HPP
