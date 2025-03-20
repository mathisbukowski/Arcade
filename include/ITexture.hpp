/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** ITexture
*/

#ifndef ITEXTURE_HPP_
#define ITEXTURE_HPP_

#include "Misc.hpp"
#include <string>
#include <memory>
#include <optional>
#include <variant>


namespace arcade {
    class Rect {
    public:
        Rect(const float x, const float y, const float width, const float height):
            x(x), y(y), width(width), height(height) {}
        float x;
        float y;
        float width;
        float height;
    };

    class TextureImg
    {
    public:
        TextureImg(std::string path, const std::optional<Rect> &rect = std::nullopt):
            path(std::move(path)), rect(rect) {};
        ~TextureImg() = default;
        std::string path;
        std::optional<Rect> rect;
    };

    class TextureText
    {
    public:
        TextureText(std::string text = "", Color color = Color(0, 0, 0), const std::optional<Rect> &rect):
            text(std::move(text)), color (color), rect(rect) {}
        ~TextureText() = default;
        std::string text;
        Color color;
        std::optional<Rect> rect = std::nullopt;
    };

    using MyTexture = std::variant<TextureImg, TextureText>;

    class ITexture {
    public:
        virtual ~ITexture() = default;
        [[nodiscard]] virtual const MyTexture& getInformations() const = 0;
        [[nodiscard]] virtual uint32_t getWidth() const = 0;
        [[nodiscard]] virtual uint32_t getHeight() const = 0;
    };


    class ITextureManager {
    public:
        virtual ~ITextureManager() = default;

        [[nodiscard]] virtual int load(const std::string& name, const MyTexture texture) const = 0;
        [[nodiscard]] virtual std::shared_ptr<ITexture> get(const std::string& name) const = 0;
    };
}

#endif /* !ITEXTURE_HPP_ */
