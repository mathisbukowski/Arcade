/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef RESOLUTIONSCALER_HPP
#define RESOLUTIONSCALER_HPP

#include "Vector.hpp"
#include "IDisplayModule.hpp"

namespace arcade {
    /**
     * @class ResolutionScaler
     * Class to scale the resolution of the display.
     */
    class ResolutionScaler {
    public:
        /**
         * Constructor
         * @param display IDisplayModule& Reference to the display module
         */
        explicit ResolutionScaler(IDisplayModule& display);

        /**
         * Function to scale the position to the scaled resolution
         * @param pos const Vector<float>& Position to scale
         * @return Vector<float> Scaled position
         */
        [[nodiscard]] Vector<float> toScreenPosition(const Vector<float>& pos) const {return {pos.getX() * _scaleX, pos.getY() * _scaleY};}

        /**
         * Function to scale the size to the scaled resolution
         * @param size const Vector<float>& Size to scale
         * @return Vector<float> Scaled size
         */
        [[nodiscard]] Vector<float> toScreenSize(const Vector<float>& size) const {return {size.getX() * _scaleX, size.getY() * _scaleY};}

        /**
         * Function to call toScreenPosition and toScreenSize to build a Rect at the scaled resolution
         * @param logicalPos const Vector<float>& Logical position
         * @param logicalSize const Vector<float>& Logical size
         * @return Rect Scaled Rect
         */
        [[nodiscard]] Rect buildScreenRect(const Vector<float>& logicalPos, const Vector<float>& logicalSize) const {    return {toScreenPosition(logicalPos), toScreenSize(logicalSize).getX(), toScreenSize(logicalSize).getY()};}

        bool isTextBased() const { return _isTextBased; }

    private:
        /**
         * Scale factors for X axis
         */
        float _scaleX;
        /**
         * Scale factors for Y axis
         */
        float _scaleY;
        /**
         * Boolean to check if the display is text based
         */
        bool _isTextBased;
        /**
         * Scale factor for font size
         */
        float _scaleFontSize;

        /**
         * Reference width for the display
         */
        static constexpr float REF_WIDTH = 800;
        /**
         * Reference height for the display
         */
        static constexpr float REF_HEIGHT = 600;
        /**
         * Reference width for the ncurses based display
         */
        static constexpr float NCURSES_REF_WIDTH = 80;
        /**
         * Reference height for the ncurses based display
         */
        static constexpr float NCURSES_REF_HEIGHT = 24;
    };
};



#endif //RESOLUTIONSCALER_HPP
