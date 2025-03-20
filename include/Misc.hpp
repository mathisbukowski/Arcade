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
    class Color {
        public:
            Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255): r(r), g(g), b(b), a(a) {}
            ~Color() = default;
            std::uint8_t  r;
            std::uint8_t  g;
            std::uint8_t  b;
            std::uint8_t  a;
    };
}

#endif /* !MISC_HPP_ */
