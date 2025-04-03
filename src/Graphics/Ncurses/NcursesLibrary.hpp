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
#include "src/NcursesFontManager.hpp"
#include "src/NcursesSoundManager.hpp"
#include "src/NcursesTextureManager.hpp"

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
        NcursesDisplayModule _display;
        NcursesTextureManager _textures;
        NcursesFontManager _fonts;
        NcursesSoundManager _sounds;
    };
}

#endif //ARCADE_NCURSESLIBRARY_HPP
