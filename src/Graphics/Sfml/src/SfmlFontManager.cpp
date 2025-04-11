/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "SfmlFontManager.hpp"
#include <iostream>
#include <filesystem>

namespace arcade {
    SFMLFont::SFMLFont(const Font& fontInfo) : _info(fontInfo)
    {
        try {
            if (!std::filesystem::exists(fontInfo.getPath())) {
                throw std::runtime_error("Font file not found");
            }

            if (!_font.loadFromFile(fontInfo.getPath())) {
                throw std::runtime_error("Failed to load font");
            }
        } catch (const std::exception& e) {
            std::cerr << "Error creating font: " << e.what() << std::endl;
        }
    }

    const Font& SFMLFont::getInformations() const
    {
        return _info;
    }

    sf::Font& SFMLFont::getFont()
    {
        return _font;
    }

    int SFMLFontManager::load(const std::string& name, Font& font)
    {
        try {
            _fonts[name] = std::make_shared<SFMLFont>(font);
            return 0;
        } catch (const std::exception& e) {
            std::cerr << "Failed to load font: " << e.what() << std::endl;
            return -1;
        }
    }

    std::shared_ptr<IFont> SFMLFontManager::get(const std::string& name) const
    {
        auto it = _fonts.find(name);

        if (it != _fonts.end())
            return it->second;
        throw std::runtime_error("Font not found: " + name);
    }
};