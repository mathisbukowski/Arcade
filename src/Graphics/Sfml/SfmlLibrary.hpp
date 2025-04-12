/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Sfml.hpp
*/

#ifndef ARCADE_SFML_HPP
    #define ARCADE_SFML_HPP

#include "IDisplayLibrary.hpp"
#include "IDisplayModule.hpp"
#include "src/SfmlDisplayModule.hpp"
#include "src/SfmlTextureManager.hpp"
#include "src/SfmlFontManager.hpp"
#include "src/SfmlSoundManager.hpp"


namespace arcade {
    /**
    * @class SFMLLibrary
    * This class is used to create a library using the SFML library
    * It inherits from the IDisplayLibrary interface
    */
    class SFMLLibrary : public IDisplayLibrary {
    public:
        /**
        * Construct a new SFMLLibrary object
        */
        SFMLLibrary() = default;
        /**
        * Destroy the SFMLLibrary object
        */
        ~SFMLLibrary() override = default;
        /**
        * Return the display module
        * @return IDisplayModule&
        */
        IDisplayModule& getDisplay() override { return this->_display; }
        /**
        * Return the texture manager
        * @return ITextureManager&
        */
        ITextureManager& getTextures() override { return this->_textureManager; }
        /**
        * Return the font manager
        * @return IFontManager&
        */
        IFontManager& getFonts() override { return this->_fontManager; }
        /**
        * Return the sound manager
        * @return ISoundManager&
        */
        ISoundManager& getSounds() override { return this->_soundManager; }

    private:
        /**
         * Display module
         */
        SFMLDisplay _display;
        /**
         * Texture manager
         */
        SFMLTextureManager _textureManager;
        /**
         * Font manager
         */
        SFMLFontManager _fontManager;
        /**
         * Sound manager
         */
        SFMLSoundManager _soundManager;
    };
}
#endif //ARCADE_SFML_HPP
