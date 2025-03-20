/*
** EPITECH PROJECT, 2025
** $
** File description:
** Misc
*/

#ifndef MISC_HPP_
#define MISC_HPP_

#include <cstdint>

namespace arcade
{
    /**
     * @brief Color properties
     */
    class Color {
        public:
            /**
             * @brief Construct a new Color object
             * @param r Red
             * @param g Green
             * @param b Blue
             * @param a Alpha
             * @return Color
             */
            Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255): r(r), g(g), b(b), a(a) {}
            ~Color() = default;
            std::uint8_t  r;
            std::uint8_t  g;
            std::uint8_t  b;
            std::uint8_t  a;
    };
}

#endif /* !MISC_HPP_ */
