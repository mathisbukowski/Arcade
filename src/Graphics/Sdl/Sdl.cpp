/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl.cpp
*/

#include "Sdl.hpp"

arcade::Sdl::Sdl()
{
    _name = "sdl";
    _window = nullptr;
    _renderer = nullptr;
    _keyboard = Keyboard();
    _mouse = Mouse();
    _textures = std::map<std::string, std::shared_ptr<ITexture>>();
}

arcade::Sdl::~Sdl()
{
}

void arcade::Sdl::init()
{
    SDL_Init(SDL_INIT_VIDEO);
}

void arcade::Sdl::stop()
{
    SDL_Quit();
}

const std::string &arcade::Sdl::getName() const
{
    return _name;
}

void arcade::Sdl::setupWindowProperties(WindowProperties &properties)
{
    properties.setWidth(800);
    properties.setHeight(600);
    properties.setTitle("Arcade");
}

void arcade::Sdl::openWindow()
{
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void arcade::Sdl::closeWindow()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

void arcade::Sdl::clearWindow(Color color)
{
    SDL_SetRenderDrawColor(_renderer, color.getR(), color.getG(), color.getB(), color.getOpacity());
    SDL_RenderClear(_renderer);
}

void arcade::Sdl::updateWindow(float delta)
{
    SDL_RenderPresent(_renderer);
}

bool arcade::Sdl::isWindowOpen()
{
    return true;
}

void arcade::Sdl::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    SDL_Rect rect = {static_cast<int>(position.getX()), static_cast<int>(position.getY()), static_cast<int>(texture->getWidth()), static_cast<int>(texture->getHeight())};
    SDL_RenderCopy(_renderer, nullptr, nullptr, &rect);
}

arcade::Keyboard &arcade::Sdl::getKeyboard()
{
    return _keyboard;
}

arcade::Mouse &arcade::Sdl::getMouse()
{
    return _mouse;
}

extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::Sdl();
    }
    arcade::LibType entryPointType() {
        return arcade::DISPLAY;
    }
    const char* entryPointName() {
        return "SDL";
    }
}
