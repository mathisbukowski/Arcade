/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** IGame
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "IDisplayLibrary.hpp"
#include "Vector.hpp"

namespace arcade {
    class IGameModule {
        public:
            virtual ~IGameModule() = default;
    
            virtual void init(IDisplayLibrary &displayLib) = 0;

            virtual void onKeyPressed(IDisplayLibrary& displayLib, Keyboard key, bool isShifted) = 0;

            virtual void onMouseEvent(IDisplayLibrary& displayLib, Mouse mouse, Vector<float> position) = 0;

            virtual void update(IDisplayLibrary& displayLib, float delta) = 0;

            virtual void display(IDisplayLibrary& displayLib) = 0;
    };
}

#endif /* !IGAMEMODULE_HPP_ */

