/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** ILibrary
*/

#ifndef IDISPLAYLIBRARY_HPP_
#define IDISPLAYLIBRARY_HPP_

#include "IDisplayModule.hpp"
#include "ITexture.hpp"
#include "IFont.hpp"
#include "ISound.hpp"

namespace arcade
{
    /**
     * Interface for the display library
     */
    class IDisplayLibrary
    {
    public:
    /**
     * Destroy the IDisplayLibrary object
     */
        virtual ~IDisplayLibrary() = default;

        /**
         * Get the Display object
         * @return IDisplayModule&
         */
        virtual IDisplayModule& getDisplay() = 0;
        /**
         * Get the Texture Manager object
         * @return ITextureManager&
         */
        virtual ITextureManager& getTextures() = 0;
        /**
         * Get the Font Manager object
         * @return IFontManager&
         */
        virtual IFontManager& getFonts() = 0;
        /**
         * Get the Sound Manager object
         * @return ISoundManager&
         */
        virtual ISoundManager& getSounds() = 0;
    };
}

#endif /* !IDISPLAYLIBRARY_HPP_ */
