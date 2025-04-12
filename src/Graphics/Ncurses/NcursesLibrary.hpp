/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesLibrary.hpp
*/

#ifndef ARCADE_NCURSESLIBRARY_HPP
    #define ARCADE_NCURSESLIBRARY_HPP

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
#include "src/NcursesFontManager.hpp"
#include "src/NcursesSoundManager.hpp"
#include "src/NcursesTextureManager.hpp"

namespace arcade
{
    /**
     * @class NcursesLibrary
     * This class is used to create a library using the ncurses library
     * It inherits from the IDisplayLibrary interface
     */
    class NcursesLibrary : public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Ncurses object
         */
        NcursesLibrary();
        /**
         * Destroy the Sfml object
         */
        virtual ~NcursesLibrary();
        /**
         * Get the Display object
         * @return IDisplayModule&
         */
        IDisplayModule &getDisplay() override { return this->_display; }
        /**
        * Get the Texture Manager object
        * @return ITextureManager&
        */
        ITextureManager &getTextures() override { return this->_textures; }
        /**
         * Get the Font Manager object
         * @return IFontManager&
         */
        IFontManager &getFonts() override { return this->_fonts; }
        /**
         * Get the Sound Manager object
         * @return ISoundManager&
         */
        ISoundManager &getSounds() override { return this->_sounds; }

    private:
        /**
         * Texture Manager
         */
        NcursesTextureManager _textures;
        /**
         * Display Module
         */
        NcursesDisplayModule _display;
        /**
         * Font Manager
         */
        NcursesFontManager _fonts;
        /**
         * Sound Manager
         */
        NcursesSoundManager _sounds;
    };
}

#endif //ARCADE_NCURSESLIBRARY_HPP
