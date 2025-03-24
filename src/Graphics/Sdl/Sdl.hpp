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
    class Sdl : public IDisplayModule
    {
    public:
        Sdl();
        ~Sdl();
        void init() override;
        void stop() override;
        const std::string &getName() const override;
        void setupWindowProperties(WindowProperties &properties) override;
        void openWindow() override;
        void closeWindow() override;
        void clearWindow(Color color) override;
        void updateWindow(float delta) override;
        bool isWindowOpen() override;
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        Keyboard &getKeyboard() override;
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

extern "C" void *initDisplay();
extern "C" void destroyDisplay(void *display);

#endif //ARCADE_SDL_HPP
