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
#include "src/SdlSoundManager.hpp"
#include "src/SdlTextureManager.hpp"

namespace arcade
{
    /**
     * @class SdlLibrary
     * This class is used to create a library using the SDL2 library
     * It inherits from the IDisplayLibrary interface
     */
    class SdlLibrary : public IDisplayLibrary
    {
    public:
        /**
         * Construct a new Sdl object
         */
        SdlLibrary() : _rendererManager(), _display(SDLDisplayModule(this->_rendererManager)), _textures(SDLTextureManager(this->_rendererManager)) {}
        /**
         * Destroy the Sdl object
         */
        virtual ~SdlLibrary() = default;
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
        ISoundManager &getSounds() override { return this->_sounds; }

    private:
        /**
         * SDL Renderer Manager
         */
        SDLRendererManager _rendererManager;
        /**
         * Display Module
         */
        SDLDisplayModule _display;
        /**
         * Font Manager
         */
        SDLFontManager _fonts;
        /**
         * Texture Manager
         */
        SDLTextureManager _textures;
        /**
         * Sound Manager
         */
        SDLSoundManager _sounds;
    };
}

#endif //ARCADE_SDL_HPP
