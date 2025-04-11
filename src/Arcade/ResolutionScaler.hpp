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
    class ResolutionScaler {
    public:
        explicit ResolutionScaler(IDisplayModule& display);

        [[nodiscard]] Vector<float> toScreenPosition(const Vector<float>& pos) const {return {pos.getX() * _scaleX, pos.getY() * _scaleY};}

        [[nodiscard]] Vector<float> toScreenSize(const Vector<float>& size) const {return {size.getX() * _scaleX, size.getY() * _scaleY};}

        [[nodiscard]] Rect buildScreenRect(const Vector<float>& logicalPos, const Vector<float>& logicalSize) const {    return {toScreenPosition(logicalPos), toScreenSize(logicalSize).getX(), toScreenSize(logicalSize).getY()};}
    private:
        float _scaleX;
        float _scaleY;
        bool _isTextBased;
        float _scaleFontSize;

        static constexpr float REF_WIDTH = 800;
        static constexpr float REF_HEIGHT = 600;
        static constexpr float NCURSES_REF_WIDTH = 80;
        static constexpr float NCURSES_REF_HEIGHT = 24;
    };
};



#endif //RESOLUTIONSCALER_HPP
