/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef NCURSESFONTMANAGER_HPP
#define NCURSESFONTMANAGER_HPP

#include "IFont.hpp"
#include <map>

namespace arcade {
    class NcursesFont : public IFont {
    public:
        NcursesFont(const Font& font) : _fontInformations(font) {}
        [[nodiscard]] const Font& getInformations() const override { return _fontInformations; }

    private:
        Font _fontInformations;
    };

    class NcursesFontManager : public IFontManager {
    public:
        int load(const std::string& name, const Font& font) override;
        std::shared_ptr<IFont> get(const std::string& name) const override;
    private:
        std::map<std::string, std::shared_ptr<NcursesFont>> _fonts;
    };
};


#endif //NCURSESFONTMANAGER_HPP
