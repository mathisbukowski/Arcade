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
    /**
     * @class NcursesFont
     * This class is used to create a font using the ncurses library
     * It inherits from the IFont interface
     */
    class NcursesFont : public IFont {
    public:
        /**
         * Constructor
         * @param font Font & Font to create
         */
        NcursesFont(const Font& font) : _fontInformations(font) {}
        /**
         * Get the font informations
         * @return const Font & Font informations
         */
        [[nodiscard]] const Font& getInformations() const override { return _fontInformations; }

    private:
        /**
         * Font informations
         */
        Font _fontInformations;
    };

    /**
     * @class NcursesFontManager
     * This class is used to manage fonts using the ncurses library
     * It inherits from the IFontManager interface
     */
    class NcursesFontManager : public IFontManager {
    public:
        /**
         * Function to load a font
         * @param name const std::string & Name of the font
         * @param font Font & Font to load
         * @return int 0 if success, -1 if error
         */
        int load(const std::string& name, const Font& font) override;
        /**
         * Function to get a font
         * @param name const std::string & Name of the font
         * @return std::shared_ptr<IFont> Font
         */
        std::shared_ptr<IFont> get(const std::string& name) const override;
    private:
        /**
         * Map of fonts
         */
        std::map<std::string, std::shared_ptr<NcursesFont>> _fonts;
    };
};


#endif //NCURSESFONTMANAGER_HPP
