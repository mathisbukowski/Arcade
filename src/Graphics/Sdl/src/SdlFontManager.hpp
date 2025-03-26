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
#include <SDL2/SDL_ttf.h>

#include "Arcade.hpp"
#include "IFont.hpp"

namespace arcade {
    class SDLFont : public IFont {
    public:
        SDLFont(const Font &informations): _font(nullptr), _fontInformations(informations) {};
        ~SDLFont() = default;
        [[nodiscard]] const Font &getInformations() const override { return _fontInformations; }
    private:
        std::shared_ptr<TTF_Font> _font;
        Font _fontInformations;
    };

    class SDLFontManager : public IFontManager {
    public:
        SDLFontManager(std::shared_ptr<SDL_Renderer> renderer) : _renderer(std::move(renderer)) {};
        ~SDLFontManager() override = default;
        int load(const std::string& name, const Font& texture) override;
        std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        std::shared_ptr<SDL_Renderer> _renderer;
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
    };
}



#endif //SDLFONTMANAGER_HPP
