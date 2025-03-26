/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesDisplayModule.cpp
*/

#include "NcursesDisplayModule.hpp"
#include <ncurses.h>

arcade::NcursesDisplayModule::NcursesDisplayModule(const std::string &name): _windowProperties("", 0, 0), _name(name), _isOpen(false) {}

arcade::NcursesDisplayModule::~NcursesDisplayModule()
{
    this->stop();
}

void arcade::NcursesDisplayModule::init(const std::string &title, size_t width, size_t height)
{
    _windowProperties.setTitle(title);
    _windowProperties.setWidth(width);
    _windowProperties.setHeight(height);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
}

void arcade::NcursesDisplayModule::stop()
{
    endwin();
}

void arcade::NcursesDisplayModule::openWindow()
{
    _isOpen = true;
}

void arcade::NcursesDisplayModule::closeWindow()
{
    _isOpen = false;
}

void arcade::NcursesDisplayModule::clearWindow(arcade::Color color)
{
}

void arcade::NcursesDisplayModule::updateWindow(float delta)
{
    while (_isOpen) {
        int ch = getch();
        if (ch == 27)
            _isOpen = false;
    }
}