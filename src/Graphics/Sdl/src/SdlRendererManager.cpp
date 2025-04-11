/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "SdlRendererManager.hpp"
#include "SDL.h"

void arcade::SDLRendererManager::initializeRenderer(const std::string& title, size_t width, size_t height)
{
    _window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    static_cast<int>(width), static_cast<int>(height), 0), SDL_DestroyWindow);
    if (!_window)
        throw std::runtime_error("Failed to create window");
    _renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0), SDL_DestroyRenderer);
    if (!_renderer)
        throw std::runtime_error("Failed to create renderer");
}
