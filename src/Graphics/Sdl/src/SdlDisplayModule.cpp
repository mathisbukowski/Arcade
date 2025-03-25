/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlDisplayModule.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

arcade::SDLDisplayModule::SDLDisplayModule(const std::string& name): _windowProperties("", 0, 0), _name(name), _isOpen(false) {}

arcade::SDLDisplayModule::~SDLDisplayModule()
{
    this->stop();
}

void arcade::SDLDisplayModule::init(const std::string& title, std::size_t width, std::size_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("Failed to initialize SDL");
    _windowProperties = WindowProperties(title, width, height);
    this->setupWindowProperties(_windowProperties);
    auto window = SDL_CreateWindow(_windowProperties.getTitle().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowProperties.getWidth(), _windowProperties.getHeight(), 0);
    if (!window)
        throw std::runtime_error("Failed to create window");
    this->_window.reset(window, SDL_DestroyWindow);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    this->_renderer.reset(renderer, SDL_DestroyRenderer);
}

void arcade::SDLDisplayModule::stop()
{
    _renderer.reset();
    _window.reset();
    SDL_Quit();
}

void arcade::SDLDisplayModule::openWindow()
{
    this->_isOpen = true;
}

void arcade::SDLDisplayModule::closeWindow()
{
    this->_isOpen = false;
}

void arcade::SDLDisplayModule::clearWindow(Color color)
{
    SDL_SetRenderDrawColor(_renderer.get(), color.getR(), color.getG(), color.getB(), color.getOpacity());
    SDL_RenderClear(_renderer.get());
}

void arcade::SDLDisplayModule::updateWindow(float delta)
{
    SDL_Event event;
    auto window = this->_window.get();

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            this->closeWindow();
            break;
        }
    }
    SDL_UpdateWindowSurface(window);
}
