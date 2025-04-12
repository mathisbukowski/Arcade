/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SDLRENDERERMANAGER_HPP
#define SDLRENDERERMANAGER_HPP
#include <memory>
#include <SDL_render.h>
#include <string>


namespace arcade {
    /**
     * @class SDLRendererManager
     * This class is used to manage the SDL renderer and window
     */
    class SDLRendererManager {
    public:
        /**
         * Construct a new SDLRendererManager object
         */
        SDLRendererManager() = default;
        /**
         * Destroy the SDLRendererManager object
         */
        ~SDLRendererManager() = default;

        /**
         * Initialize the SDL renderer and window
         * @param title const std::string & Title of the window
         * @param width size_t Width of the window
         * @param height size_t Height of the window
         */
        void initializeRenderer(const std::string& title, size_t width, size_t height);

        /**
         * Get the SDL renderer
         * @return std::shared_ptr<SDL_Renderer>
         */
        [[nodiscard]] std::shared_ptr<SDL_Renderer> getRenderer() const { return _renderer; }

        /**
         * Get the SDL window
         * @return std::shared_ptr<SDL_Window>
         */
        [[nodiscard]] std::shared_ptr<SDL_Window> getWindow() const { return _window; }

    private:
        /**
         * SDL Renderer
         */
        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        /**
         * SDL Window
         */
        std::shared_ptr<SDL_Window> _window = nullptr;
    };
};


#endif //SDLRENDERERMANAGER_HPP
