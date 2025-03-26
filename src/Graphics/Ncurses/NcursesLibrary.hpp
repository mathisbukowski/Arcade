/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesLibrary.hpp
*/

#ifndef ARCADE_NCURSESLIBRARY_HPP
    #define ARCADE_NCURSESLIBRARY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "IDisplayModule.hpp"
#include "IDisplayLibrary.hpp"
#include "src/NcursesDisplayModule.hpp"
#include "Vector.hpp"
#include "Arcade.hpp"

namespace arcade
{
    /**
     * Sfml class to handle the SFML library for the display
     */
    class NcursesLibrary : public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Sfml object
         */
        NcursesLibrary();
        /**
         * Destroy the Sfml object
         */
        ~NcursesLibrary();
        /**
         * Get the Display object
         * @return IDisplayModule&
         */
        IDisplayModule &getDisplay() override { return this->_display; }
        /**
        * Get the Texture Manager object
        * @return ITextureManager&
        */
        virtual ITextureManager &getTextures();
        /**
         * Get the Font Manager object
         * @return IFontManager&
         */
        virtual IFontManager &getFonts();
        /**
         * Get the Sound Manager object
         * @return ISoundManager&
         */
        virtual ISoundManager &getSounds();

    private:
        NcursesDisplayModule _display;
    };
}

#endif //ARCADE_NCURSESLIBRARY_HPP
