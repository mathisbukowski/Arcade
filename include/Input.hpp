/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Input
*/

#include <unordered_map>
#include "Vector.hpp"

#ifndef INPUT_HPP_
#define INPUT_HPP_

namespace arcade
{
    /**
     * Keyboard input
     */
    class Keyboard
    {
    public:
        Keyboard() = default;
        ~Keyboard() = default;

        /**
         * Key codes
         */
        enum KeyCode
        {
            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V,
            W, X, Y, Z, ENTER, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
            UP, DOWN, LEFT, RIGHT, ESCAPE, UNKNOWN
        };
        static KeyCode keyCode;
        /**
         * Check if a key is pressed
         * @param code KeyCode Key code
         * @return true if the key is pressed, false otherwise (bool)
         */
         bool isKeyPressed(KeyCode code) const {
             auto it = _keys.find(code);
             return (it != _keys.end()) ? it->second : false;
         }
        /**
         * Set a key state
         * @param code KeyCode Key code
         * @param isPressed bool Key state
         */
        void setKey(KeyCode code, bool isPressed) { _keys[code] = isPressed; }
        /**
        * Clear all pressed keys
        */
        void clearPressedKeys() { _keys.clear(); }

    private:
        /**
         * Map of key codes and their pressed state
         */
        std::unordered_map<KeyCode, bool> _keys;
    };

    /**
     * Mouse input
     */
    class Mouse
    {
    public:
        /**
         * Mouse button codes
         */
        Mouse() = default;
        /**
         * Destroy the Mouse object
         */
        ~Mouse() = default;

        /**
         * Retrieves the current position of the mouse.
         * @return Vector<float> position of the mouse
         */
        [[nodiscard]] Vector<float> getPos() const { return _position; }

        /**
         * Checks if the mouse button is currently pressed.
         * @return bool true if the mouse button is pressed, false otherwise
         */
        [[nodiscard]] bool isPressed() const { return _pressed; }

        /**
         * Sets the position of the mouse.
         * @param newPos Vector<float> representing the new position of the mouse.
         */
        void setPos(Vector<float> newPos) { _position = newPos; }

        /**
         * Sets the pressed state of the mouse button.
         * @param pressed A boolean value indicating whether the mouse button is pressed.
         */
        void setPressed(bool pressed) { _pressed = pressed; }

    private:
        /**
         * Position of the mouse
         */
        Vector<float> _position {0, 0};
        /**
         * Pressed state of the mouse button
         */
        bool _pressed = false;
    };
}

#endif /* !INPUT_HPP_ */
