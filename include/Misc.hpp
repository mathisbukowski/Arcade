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
     * Color properties
     */
    class Color {
        public:
            /**
             * Construct a new Color object
             * @param r Red component (0-255)
             * @param g Green component (0-255)
             * @param b Blue component (0-255)
             * @param a Alpha (opacity) component (0-255), default is 255
             */
            Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)
                : red(r), green(g), blue(b), alpha(a) {}
            ~Color() = default;

            /**
             * Get the red component
             * @return uint8_t Red value (0-255)
             */
            [[nodiscard]] uint8_t getR() const { return red; }

            /**
             * Get the green component
             * @return uint8_t Green value (0-255)
             */
            [[nodiscard]] uint8_t getG() const { return green; }

            /**
             * Get the blue component
             * @return uint8_t Blue value (0-255)
             */
            [[nodiscard]] uint8_t getB() const { return blue; }

            /**
             * Get the alpha (opacity) component
             * @return uint8_t Alpha value (0-255)
             */
            [[nodiscard]] uint8_t getOpacity() const { return alpha; }

            /**
             * Set the red component
             * @param r Red value (0-255)
             */
            void setR(const uint8_t r) { red = r; }

            /**
             * Set the green component
             * @param g Green value (0-255)
             */
            void setG(const uint8_t g) { green = g; }

            /**
             * Set the blue component
             * @param b Blue value (0-255)
             */
            void setB(const uint8_t b) { blue = b; }

            /**
             * Set the alpha (opacity) component
             * @param newOpacity Alpha value (0-255)
             */
            void setOpacity(const uint8_t newOpacity) { alpha = newOpacity; }

        private:
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            uint8_t alpha;
    };;
}

#endif /* !MISC_HPP_ */
