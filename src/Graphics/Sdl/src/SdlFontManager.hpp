/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLFONTMANAGER_HPP
#define SDLFONTMANAGER_HPP

#include <SDL2/SDL_render.h>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Arcade.hpp"
#include "IFont.hpp"

namespace arcade {
    /**
     * @class SDLFont
     * This class is used to create a font using the SDL2 library
     * It inherits from the IFont interface
     */
    class SDLFont : public IFont {
    public:
        /**
         * Construct a new SDLFont object
         * @param informations Font & Font information
         */
        SDLFont(const Font &informations): _font(nullptr), _fontInformations(informations) {};
        /**
         * Create a new font
         * @param informations Font & Font information
         * @return int
         */
        int createFont(const Font &informations);
        /**
         * Destroy the SDLFont object
         */
        ~SDLFont() override = default;
        /**
         * Get the font information
         * @return const Font &
         */
        [[nodiscard]] const Font &getInformations() const override { return _fontInformations; }
        /**
         * Get the font
         * @return const std::shared_ptr<TTF_Font> &
         */
        [[nodiscard]] const std::shared_ptr<TTF_Font> &getFont() const { return _font; }
        /**
         * Set the font
         * @param font const std::shared_ptr<TTF_Font> &
         */
        void setFont(const std::shared_ptr<TTF_Font> &font) { _font = font; };
    private:
        /**
         * Font
         */
        std::shared_ptr<TTF_Font> _font;
        /**
         * Font information
         */
        Font _fontInformations;
    };

    /**
     * @class SDLFontManager
     * This class is used to create a font manager using the SDL2 library
     * It inherits from the IFontManager interface
     */
    class SDLFontManager : public IFontManager {
    public:
        /**
         * Construct a new SDLFontManager object
         */
        SDLFontManager();
        /**
         * Destroy the SDLFontManager object
         */
        ~SDLFontManager() override = default;
        /**
         * Load a font
         * @param name const std::string & Name of the font
         * @param newFont Font & Font information
         * @return int
         */
        int load(const std::string& name, const Font& newFont) override;
        /**
         * Get a font
         * @param name const std::string & Name of the font
         * @return std::shared_ptr<IFont>
         */
        [[nodiscard]] std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        /**
         * Map of fonts
         */
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
    };
}



#endif //SDLFONTMANAGER_HPP
