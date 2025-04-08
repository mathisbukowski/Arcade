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
 * Implementation of IFont for SFML
 */
    class SFMLFont : public IFont {
    public:
        explicit SFMLFont(const Font& fontInfo);
        ~SFMLFont() override = default;

        const Font& getInformations() const override;
        sf::Font& getFont();

    private:
        Font _info;
        sf::Font _font;
    };

    /**
     * Implementation of IFontManager for SFML
     */
    class SFMLFontManager : public IFontManager {
    public:
        SFMLFontManager() noexcept = default;
        ~SFMLFontManager() override = default;

        int load(const std::string& name, const Font& font) override;
        std::shared_ptr<IFont> get(const std::string& name) const override;

    private:
        mutable std::map<std::string, std::shared_ptr<SFMLFont>> _fonts;
    };
}



#endif //SFMLFONTMANAGER_HPP
