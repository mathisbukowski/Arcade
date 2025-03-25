/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Input
*/

#include <unordered_map>
#include "Vector.hpp"

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
            W, X, Y, Z, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
            UP, DOWN, LEFT, RIGHT, ESCAPE, UNKNOWN
        };
        static KeyCode keyCode;
        /**
         * Check if a key is pressed
         * @param keyCode Key code
         * @return true if the key is pressed, false otherwise
         */
        bool isKeyPressed(KeyCode code) const { return _keys.at(code);  }
        /**
         * Set a key state
         * @param keyCode Key code
         * @param isPressed Key state
         */
        void setKey(KeyCode code, bool isPressed) { _keys[code] = isPressed; }
        /**
        * Clear all pressed keys
        */
        void clearPressedKeys() { _keys.clear(); }

    private:
        std::unordered_map<KeyCode, bool> _keys;
    };

    /**
     * Mouse input
     */
    class Mouse
    {
    public:
        Mouse() = default;
        ~Mouse() = default;

        /**
         * Retrieves the current position of the mouse.
         *
         * @return A Vector<float> representing the current position of the mouse.
         */
        [[nodiscard]] Vector<float> getPos() const { return _position; }

        /**
         * Checks if the mouse button is currently pressed.
         *
         * @return A boolean value indicating whether the mouse button is pressed.
         */
        [[nodiscard]] bool isPressed() const { return _pressed; }

        /**
         * Sets the position of the mouse.
         *
         * @param newPos A Vector<float> representing the new position of the mouse.
         */
        void setPos(Vector<float> newPos) { _position = newPos; }

        /**
         * Sets the pressed state of the mouse button.
         *
         * @param pressed A boolean value indicating whether the mouse button is pressed.
         */
        void setPressed(bool pressed) { _pressed = pressed; }

    private:
        Vector<float> _position {0, 0};
        bool _pressed = false;
    };
}