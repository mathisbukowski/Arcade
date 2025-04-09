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
             * @param r uint8_t Red component (0-255)
             * @param g uint8_t Green component (0-255)
             * @param b uint8_t Blue component (0-255)
             * @param a uint8_t Alpha (opacity) component (0-255), default is 255
             */
            Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)
                : _red(r), _green(g), _blue(b), _alpha(a) {}

            /**
             * Default constructor for Color
             */
            ~Color() = default;

            /**
             * Get the red component
             * @return uint8_t Red value (0-255)
             */
            [[nodiscard]] uint8_t getR() const { return _red; }

            /**
             * Get the green component
             * @return uint8_t Green value (0-255)
             */
            [[nodiscard]] uint8_t getG() const { return _green; }

            /**
             * Get the blue component
             * @return uint8_t Blue value (0-255)
             */
            [[nodiscard]] uint8_t getB() const { return _blue; }

            /**
             * Get the alpha (opacity) component
             * @return uint8_t Alpha value (0-255)
             */
            [[nodiscard]] uint8_t getOpacity() const { return _alpha; }

            /**
             * Set the red component
             * @param r Red value (0-255)
             */
            void setR(const uint8_t r) { _red = r; }

            /**
             * Set the green component
             * @param g Green value (0-255)
             */
            void setG(const uint8_t g) { _green = g; }

            /**
             * Set the blue component
             * @param b Blue value (0-255)
             */
            void setB(const uint8_t b) { _blue = b; }

            /**
             * Set the alpha (opacity) component
             * @param newOpacity Alpha value (0-255)
             */
            void setOpacity(const uint8_t newOpacity) { _alpha = newOpacity; }

        private:
            /**
             * Red component
             */
            uint8_t _red;
            /**
             * Green component
             */
            uint8_t _green;
            /**
             * Blue component
             */
            uint8_t _blue;
            /**
             * Alpha (opacity) component
             */
            uint8_t _alpha;
    };;
}

#endif /* !MISC_HPP_ */
