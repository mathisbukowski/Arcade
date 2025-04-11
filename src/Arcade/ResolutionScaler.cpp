/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "ResolutionScaler.hpp"

arcade::ResolutionScaler::ResolutionScaler(IDisplayModule& display)
{
    _isTextBased = display.getName() == "NCURSES";

    if (_isTextBased) {
        _scaleX = NCURSES_REF_WIDTH / static_cast<float>(display.getWindowProperties().getWidth());
        _scaleY = NCURSES_REF_HEIGHT / static_cast<float>(display.getWindowProperties().getHeight());
        _scaleFontSize = 1.0f;
    } else {
        _scaleX = 1.0f;
        _scaleY = 1.0f;
        _scaleFontSize = 24.0f;
    }
}
