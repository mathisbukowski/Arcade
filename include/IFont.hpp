/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** IFont
*/

#ifndef IFONT_HPP_
#define IFONT_HPP_

#include "Misc.hpp"
#include <string>
#include <memory>
#include <optional>
#include <variant>


namespace arcade {
    
    class Font {
    public:
        Font(std::string path, Color color, std::size_t size = 12)
            : path(std::move(path)), color(color), size(size) {}
        ~Font() = default;

        std::string path;
        Color color;
        std::size_t size;
    };
   
    using MyFont = Font;

    class IFont {
    public:
        virtual ~IFont() = default;
        [[nodiscard]] virtual const MyFont& getInformations() const = 0;
        [[nodiscard]] virtual uint32_t getWidth() const = 0;
        [[nodiscard]] virtual uint32_t getHeight() const = 0;
    };


    class IFontManager {
    public:
        virtual ~IFontManager() = default;

        [[nodiscard]] virtual int load(const std::string& name, const MyFont texture) const = 0;
        [[nodiscard]] virtual std::shared_ptr<IFont> get(const std::string& name) const = 0;
    };
}

#endif /* !IFONT_HPP_ */
