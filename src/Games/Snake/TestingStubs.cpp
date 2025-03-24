/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Testing stubs for input classes
*/

#include "Input.hpp"

namespace arcade {
    Keyboard::KeyCode Keyboard::keyCode = Keyboard::KeyCode::UNKNOWN;

    bool Keyboard::isKeyPressed(KeyCode) const {
        return false;
    }

    void Keyboard::setKey(KeyCode keyCode, bool isPressed) {
        static_cast<void>(keyCode);
        static_cast<void>(isPressed);
    }

    Vector<float> Mouse::getPos() const {
        return _position;
    }

    bool Mouse::isPressed() const {
        return _pressed;
    }

    void Mouse::setPos(Vector<float> newPos) {
        _position = newPos;
    }

    void Mouse::setPressed(bool pressed) {
        _pressed = pressed;
    }
}
