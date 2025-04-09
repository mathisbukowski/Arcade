/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesDisplayModule.cpp
*/

#include "NcursesDisplayModule.hpp"

#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>

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
    mousemask(ALL_MOUSE_EVENTS, nullptr);
    start_color();
    nodelay(stdscr, TRUE);
    _isOpen = true;
}

void arcade::NcursesDisplayModule::stop()
{
    if (_isOpen) {
        endwin();
        _isOpen = false;
    }
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
    if (!_isOpen) return;

    if (color.getOpacity() != 0) {
        init_color(COLOR_BLACK, color.getR(), color.getG(), color.getB());
        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        clear();
        attroff(COLOR_PAIR(1));
    } else {
        clear();
    }
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
        refresh();
    } else
        throw std::runtime_error("Terminal does not support images");
}


void arcade::NcursesDisplayModule::updateWindow(float delta)
{
    static int frameCount = 0;
    static auto lastTimeCheck = std::chrono::high_resolution_clock::now();

    frameCount++;
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto elapsedSec = std::chrono::duration<float>(currentTime - lastTimeCheck).count();

    if (elapsedSec >= 1.0f) {
        frameCount = 0;
        lastTimeCheck = currentTime;
    }
    try {
        this->processEvents();
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Error in updateWindow: " << e.what() << std::endl;
    }
}

void arcade::NcursesDisplayModule::processEvents()
{
    if (!_isOpen) return;

    try {
        _keyboard.clearPressedKeys();
        int ch = getch();
        if (ch != ERR) {
            this->handleEvent(ch);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in processEvents: " << e.what() << std::endl;
    }
}

void arcade::NcursesDisplayModule::handleEvent(int ch)
{
    MEVENT event;

    switch (ch) {
        case KEY_UP:
            _keyboard.setKey(arcade::Keyboard::KeyCode::UP, true);
            break;
        case KEY_DOWN:
            _keyboard.setKey(arcade::Keyboard::KeyCode::DOWN, true);
            break;
        case KEY_LEFT:
            _keyboard.setKey(arcade::Keyboard::KeyCode::LEFT, true);
            break;
        case KEY_RIGHT:
            _keyboard.setKey(arcade::Keyboard::KeyCode::RIGHT, true);
            break;
        case 27:
            _keyboard.setKey(arcade::Keyboard::KeyCode::ESCAPE, true);
            break;
        case '\n':
            _keyboard.setKey(arcade::Keyboard::KeyCode::ENTER, true);
            break;
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_PRESSED) {
                    _mouse.setPressed(true);
                    _mouse.setPos(Vector<float>(event.x, event.y));
                } else if (event.bstate & BUTTON1_RELEASED) {
                    _mouse.setPressed(false);
                }
            }
        default:
            break;
    }
}