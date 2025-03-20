/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Input
*/

#include <unordered_map>

namespace arcade
{
    class Keyboard
    {
    public:
        Keyboard() = default;
        ~Keyboard() = default;

        enum KeyCode
        {
            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V,
            W, X, Y, Z, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
            UP, DOWN, LEFT, RIGHT, ESCAPE, UNKNOWN
        };

        bool isKeyPressed(KeyCode keyCode) const;
        void setKey(KeyCode keyCode, bool isPressed);

    private:
        std::unordered_map<KeyCode, bool> _keys;
    };

    class Mouse
    {
    public:
        Mouse() = default;
        ~Mouse() = default;

        [[nodiscard]] float getX() const;
        [[nodiscard]] float getY() const;
        [[nodiscard]] float isPressed() const;

        void setX(float x);
        void setY(float y);
        void setPressed(bool pressed);
    private:
        float _x;
        float _y;
        bool _pressed;
    };
}