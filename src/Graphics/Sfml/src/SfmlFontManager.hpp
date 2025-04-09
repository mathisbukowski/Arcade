/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SFMLFONTMANAGER_HPP
#define SFMLFONTMANAGER_HPP

#include "IFont.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
    /**
     * @class SFMLFont
     * This class is used to create a font using the SFML library
     * It inherits from the IFont interface
     */
    class SFMLFont : public IFont {
    public:
        /**
         * Construct a new SFMLFont object
         * @param fontInfo const Font& Font information
         */
        explicit SFMLFont(const Font& fontInfo);
        /**
         * Destroy the SFMLFont object
         */
        ~SFMLFont() override = default;

        /**
         * Get the font information
         * @return const Font&
         */
        const Font& getInformations() const override;
        /**
         * Get the SFML font
         * @return sf::Font&
         */
        sf::Font& getFont();

    private:
        /**
         * Font information
         */
        Font _info;
        /**
         * SFML font
         */
        sf::Font _font;
    };


    /**
     * @class SFMLFontManager
     * This class is used to manage fonts using the SFML library
     * It inherits from the IFontManager interface
     */
    class SFMLFontManager : public IFontManager {
    public:
        /**
         * Construct a new SFMLFontManager object
         */
        SFMLFontManager() noexcept = default;
        /**
         * Destroy the SFMLFontManager object
         */
        ~SFMLFontManager() override = default;

        /**
         * Load a font
         * @param name const std::string& Name of the font
         * @param font const Font& Font information
         * @return int
         */
        int load(const std::string& name, const Font& font) override;
        /**
         * Get a font
         * @param name const std::string& Name of the font
         * @return std::shared_ptr<IFont>
         */
        std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        /**
         * Map of fonts
         */
        mutable std::map<std::string, std::shared_ptr<SFMLFont>> _fonts;
    };
}



#endif //SFMLFONTMANAGER_HPP
