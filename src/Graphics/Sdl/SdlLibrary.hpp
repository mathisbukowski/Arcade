/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SdlLibrary.hpp
*/

#ifndef ARCADE_SDL_HPP
    #define ARCADE_SDL_HPP

    #include <SDL2/SDL.h>
    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <memory>
    #include "IDisplayModule.hpp"
    #include "IDisplayLibrary.hpp"
    #include "src/SdlDisplayModule.hpp"
    #include "Vector.hpp"
    #include "Arcade.hpp"
#include "src/SdlFontManager.hpp"
#include "src/SdlTextureManager.hpp"

namespace arcade
{
    /**
     * Sdl class to handle the SDL library for the display
     */
    class SdlLibrary : public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Sdl object
         */
        SdlLibrary();
        /**
         * Destroy the Sdl object
         */
        ~SdlLibrary();
        /**
         * Get the Display object
         * @return IDisplayModule&
         */
         IDisplayModule &getDisplay() override { return this->_display; }
         /**
         * Get the Texture Manager object
         * @return ITextureManager&
         */
         ITextureManager &getTextures() override {return this->_textures;}
        /**
         * Get the Font Manager object
         * @return IFontManager&
         */
        IFontManager &getFonts() override { return this->_fonts; }
        /**
         * Get the Sound Manager object
         * @return ISoundManager&
         */
        virtual ISoundManager &getSounds();

    private:
        SDLDisplayModule _display;
        SDLFontManager _fonts;
        SDLTextureManager _textures;
    };
}

#endif //ARCADE_SDL_HPP
