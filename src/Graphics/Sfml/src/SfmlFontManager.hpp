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
     * @class Implementation of IFont for SFML
     * This class is used to create a font using the SFML library
     * It inherits from the IFont interface
     */
    class SFMLFont : public IFont {
    public:
        /**
         * Constructor
         * @param fontInfo const Font& Font information
         */
        explicit SFMLFont(const Font& fontInfo);
        /**
         * Destructor
         */
        ~SFMLFont() override = default;

        /**
         * Get the font information
         * @return const Font& Font information
         */
        const Font& getInformations() const override;
        /**
         * Get the font
         * @return sf::Font& Font
         */
        sf::Font& getFont();

    private:
        /**
         * Font information
         */
        Font _info;
        /**
         * Font object
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
         * Constructor
         */
        SFMLFontManager() noexcept = default;
        /**
         * Destructor
         */
        ~SFMLFontManager() override = default;

        /**
         * Load font
         * @param name const std::string& Name of the font
         * @param font const Font& Font information
         * @return int 0 if success, -1 if error
         */
        int load(const std::string& name, Font& font) override;
        /**
         * Get font
         * @param name const std::string& Name of the font
         * @return std::shared_ptr<IFont> Font object
         */
        std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        /**
         * map of fonts
         */
        mutable std::map<std::string, std::shared_ptr<SFMLFont>> _fonts;
    };
}



#endif //SFMLFONTMANAGER_HPP
