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
         * Constructor
         * @param informations Font & Font to create
         */
        SDLFont(const Font &informations): _font(nullptr), _fontInformations(informations) {};
        /**
         * Create a font
         * @param informations Font & Font to create
         * @return int 0 if success, -1 if error
         */
        int createFont(const Font &informations);
        /**
         * Destroy the SDLFont object
         */
        ~SDLFont() override = default;
        /**
         * Get the font informations
         * @return const Font & Font informations
         */
        [[nodiscard]] const Font &getInformations() const override { return _fontInformations; }
        /**
         * Get the font
         * @return const std::shared_ptr<TTF_Font> & Font
         */
        [[nodiscard]] const std::shared_ptr<TTF_Font> &getFont() const { return _font; }
        /**
         * Set the font
         * @param font const std::shared_ptr<TTF_Font> & Font
         */
        void setFont(const std::shared_ptr<TTF_Font> &font) { _font = font; };
    private:
        /**
         * Font
         */
        std::shared_ptr<TTF_Font> _font;
        /**
         * Font informations
         */
        Font _fontInformations;
    };

    /**
     * @class SDLFontManager
     * This class is used to manage fonts using the SDL2 library
     * It inherits from the IFontManager interface
     */
    class SDLFontManager : public IFontManager {
    public:
        /**
         * Constructor
         */
        SDLFontManager()
        {
            if (TTF_Init() == -1)
                throw std::runtime_error("Failed to initialize TTF");
        };
        /**
         * Destructor
         */
        ~SDLFontManager() override = default;
        /**
         * Load a font
         * @param name const std::string & Name of the font
         * @param newFont Font & Font to load
         * @return int 0 if success, -1 if error
         */
        int load(const std::string& name, Font& newFont) override;
        /**
         * Get a font
         * @param name const std::string & Name of the font
         * @return std::shared_ptr<IFont> Font
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
