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
     * @brief Keyboard input
     */
    class Keyboard
    {
    public:
        Keyboard() = default;
        ~Keyboard() = default;

        /**
         * @brief Key codes
         */
        enum KeyCode
        {
            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V,
            W, X, Y, Z, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
            UP, DOWN, LEFT, RIGHT, ESCAPE, UNKNOWN
        };
        static KeyCode keyCode;
        /**
         * @brief Check if a key is pressed
         * @param keyCode Key code
         * @return true if the key is pressed, false otherwise
         */
        bool isKeyPressed(KeyCode keyCode) const;
        /**
         * @brief Set a key state
         * @param keyCode Key code
         * @param isPressed Key state
         */
        void setKey(KeyCode keyCode, bool isPressed);

    private:
        std::unordered_map<KeyCode, bool> _keys;
    };

    /**
     * @brief Mouse input
     */
    class Mouse
    {
    public:
        Mouse() = default;
        ~Mouse() = default;
        [[nodiscard]] Vector<float> getPos() const;
        [[nodiscard]] bool isPressed() const;

        void setPos(Vector<float> newPos);
        void setPressed(bool pressed);
    private:
        Vector<float> _position {0, 0};
        bool _pressed = false;
    };
}