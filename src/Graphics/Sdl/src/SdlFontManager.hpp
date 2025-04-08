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
    class SDLFont : public IFont {
    public:
        SDLFont(const Font &informations): _font(nullptr), _fontInformations(informations) {};
        int createFont(const Font &informations);
        ~SDLFont() override = default;
        [[nodiscard]] const Font &getInformations() const override { return _fontInformations; }
        [[nodiscard]] const std::shared_ptr<TTF_Font> &getFont() const { return _font; }
        void setFont(const std::shared_ptr<TTF_Font> &font) { _font = font; };
    private:
        std::shared_ptr<TTF_Font> _font;
        Font _fontInformations;
    };

    class SDLFontManager : public IFontManager {
    public:
        SDLFontManager()
        {
            if (TTF_Init() == -1)
                throw std::runtime_error("Failed to initialize TTF");
        };
        ~SDLFontManager() override = default;
        int load(const std::string& name, const Font& newFont) override;
        [[nodiscard]] std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
    };
}



#endif //SDLFONTMANAGER_HPP
