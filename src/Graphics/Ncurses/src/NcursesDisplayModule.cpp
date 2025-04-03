/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesDisplayModule.cpp
*/

#include "NcursesDisplayModule.hpp"
#include <ncurses.h>

#include "NcursesTextureManager.hpp"

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
    if (!has_colors()) {
        this->stop();
        throw std::runtime_error("Terminal does not support colors");
    }
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

void arcade::NcursesDisplayModule::clearWindow(Color color)
{
    if (!can_change_color())
        throw std::runtime_error("Terminal does not support colors");
    init_color(COLOR_BLACK, color.getR(), color.getG(), color.getB());
    bkgd(COLOR_BLACK(color.getOpacity()));
    refresh();
}

void arcade::NcursesDisplayModule::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    auto texturePtr = texture.get();
    auto textureInformations = texturePtr->getInformations();

    if (std::holds_alternative<TextureText>(textureInformations)) {
        auto &textureText = std::get<TextureText>(textureInformations);
        attron(COLOR_PAIR(textureText.getColor().getOpacity()));
        mvprintw(static_cast<int>(position.getY()), static_cast<int>(position.getX()), textureText.getText().c_str());
        attroff(COLOR_PAIR(textureText.getColor().getOpacity()));
    } else
        throw std::runtime_error("Terminal does not support images");
}


void arcade::NcursesDisplayModule::updateWindow(float delta)
{
    while (_isOpen) {
        int ch = getch();
        if (ch == 27)
            _isOpen = false;
    }
}