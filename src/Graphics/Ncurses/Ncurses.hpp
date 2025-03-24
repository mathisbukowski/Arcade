/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ncurses.hpp
*/

#ifndef ARCADE_NCURSES_HPP
    #define ARCADE_NCURSES_HPP

    #include <ncurses.h>
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
    class Ncurses : public IDisplayModule
    {
    public:
        Ncurses();
        ~Ncurses();
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
        WINDOW *_window;
        Keyboard _keyboard;
        Mouse _mouse;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
    };
}

extern "C" void *initDisplay();

extern "C" void destroyDisplay(void *display);


#endif //ARCADE_NCURSES_HPP
