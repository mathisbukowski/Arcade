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
    class SDLDisplayModule : public IDisplayModule {
    public:
        SDLDisplayModule(SDLRendererManager& rendererManager);
        ~SDLDisplayModule() override;
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
        [[nodiscard]] Keyboard &getKeyboard() override;
        /**
         * Get the mouse
         * @return Mouse
         */
        [[nodiscard]] Mouse &getMouse() override;

        [[nodiscard]] WindowProperties& getWindowProperties() override { return _windowProperties; }

    private:
        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        std::shared_ptr<SDL_Window> _window = nullptr;
        WindowProperties _windowProperties;
        std::string _name = "SDL2";
        bool _isOpen;
        Keyboard _keyboard;
        Mouse _mouse;
        Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key);
        SDLRendererManager& _rendererManager;
    };
};



#endif //SDLDISPLAYMODULE_HPP
