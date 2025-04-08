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
    class SDLRendererManager {
    public:
        SDLRendererManager() = default;
        ~SDLRendererManager() = default;

        void initializeRenderer(const std::string& title, size_t width, size_t height);

        [[nodiscard]] std::shared_ptr<SDL_Renderer> getRenderer() const {
            return _renderer;
        }

        [[nodiscard]] std::shared_ptr<SDL_Window> getWindow() const { return _window; }

    private:
        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        std::shared_ptr<SDL_Window> _window = nullptr;
    };
};


#endif //SDLRENDERERMANAGER_HPP
