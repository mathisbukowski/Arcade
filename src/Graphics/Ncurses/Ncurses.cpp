/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ncurses.cpp
*/

#include "Ncurses.hpp"

arcade::Ncurses::Ncurses()
{
    _name = "ncurses";
    _window = nullptr;
    _keyboard = Keyboard();
    _mouse = Mouse();
    _textures = std::map<std::string, std::shared_ptr<ITexture>>();
}

arcade::Ncurses::~Ncurses()
{
}

void arcade::Ncurses::init()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
}

void arcade::Ncurses::stop()
{
    endwin();
}

const std::string &arcade::Ncurses::getName() const
{
    return _name;
}

void arcade::Ncurses::setupWindowProperties(WindowProperties &properties)
{
    properties.setWidth(800);
    properties.setHeight(600);
    properties.setTitle("Arcade");
}

void arcade::Ncurses::openWindow()
{
    _window = newwin(600, 800, 0, 0);
}

void arcade::Ncurses::closeWindow()
{
    delwin(_window);
}

void arcade::Ncurses::clearWindow(Color color)
{
    wclear(_window);
    wbkgd(_window, COLOR_PAIR(1));
    wrefresh(_window);
}

void arcade::Ncurses::updateWindow(float delta)
{
    (void)delta;
    wrefresh(_window);
}

bool arcade::Ncurses::isWindowOpen()
{
    return true;
}

void arcade::Ncurses::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    (void)texture;
    (void)position;
}

arcade::Keyboard &arcade::Ncurses::getKeyboard()
{
    return _keyboard;
}

arcade::Mouse &arcade::Ncurses::getMouse()
{
    return _mouse;
}

extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::Ncurses();
    }
    arcade::LibType entryPointType() {
        return arcade::DISPLAY;
    }
    const char* entryPointName() {
        return "NCURSES";
    }
}