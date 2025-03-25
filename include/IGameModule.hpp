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
    /**
     * Interface for the game module
     */
    class IGameModule {
    public:
    /**
     * Destroy the IGameModule object
     */
        virtual ~IGameModule () = default;
        /**
         * Initialize the game module
         * @param displayLib Display library
         */
        virtual void init(IDisplayLibrary &displayLib) = 0;
        /**
         * Stop the game module
         */
        virtual void stop() = 0;
        /**
         * update the game module
         * @param delta Time since the last update
         */
        virtual void update(float delta) = 0;
        /**
         * Display the game module
         */
        virtual void display() = 0;
    };
}
#endif /* !IGAMEMODULE_HPP_ */

