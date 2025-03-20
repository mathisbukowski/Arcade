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

        /**
         * @brief Get the mouse position on the x-axis
         * @return float
         */
        [[nodiscard]] float getX() const;
        /**
         * @brief Get the mouse position on the y-axis
         * @return float
         */
        [[nodiscard]] float getY() const;
        /**
         * @brief Check if the mouse button is pressed
         * @return true if the button is pressed, false otherwise
         */
        [[nodiscard]] bool isPressed() const;

        /**
         * @brief Set the mouse position on the x-axis
         * @param x Position
         */
        void setX(float x);
        /**
         * @brief Set the mouse position on the y-axis
         * @param y Position
         */
        void setY(float y);
        /**
         * @brief Set the mouse button state
         * @param pressed Button state
         */
        void setPressed(bool pressed);
    private:
        Vector<float> _position;
        bool _pressed;
    };
}