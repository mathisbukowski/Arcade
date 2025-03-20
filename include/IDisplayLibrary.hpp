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
    class IDisplayLibrary
    {
    public:
        virtual ~IDisplayLibrary() = default;

        virtual IDisplayModule& getDisplay() = 0;
        virtual ITextureManager& getTextures() = 0;
        virtual IFontManager& getFonts() = 0;
        virtual ISoundManager& getSounds() = 0;
    };
}

#endif /* !IDISPLAYLIBRARY_HPP_ */
