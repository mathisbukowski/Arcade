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
#include "Vector.hpp"


namespace arcade {
    /**
     * @brief Rect properties
     */
    class Rect {
    public:
    /**
     * @brief Construct a new Rect object
     * @param position Position
     * @param width Width
     * @param height Height
     * @return Rect
     */
        Rect(Vector<float> position, const float width, const float height): position(position.getX(), position.getY()), width(width), height(height) {}
        Vector<float> position;
        float width;
        float height;
    };


    /**
     * @brief TextureImg properties
     */
    class TextureImg
    {
    public:
    /**
     * @brief Construct a new Texture Img object
     * @param path Path to the image file
     * @param rect Rect properties
     * @return TextureImg
     */
        TextureImg(std::string path, const std::optional<Rect> &rect = std::nullopt):
            path(std::move(path)), rect(rect) {};
        ~TextureImg() = default;
        std::string path;
        std::optional<Rect> rect;
    };

    /**
     * @brief TextureText properties
     */
    class TextureText
    {
    public:
    /**
     * @brief Construct a new Texture Text object
     * @param text Text
     * @param color Color of the text
     * @param rect Rect properties
     * @return TextureText
     */
        TextureText(std::string text = "", Color color = Color(0, 0, 0), const std::optional<Rect> &rect = std::nullopt):
            text(std::move(text)), color (color), rect(rect) {}
        ~TextureText() = default;
        std::string text;
        Color color;
        std::optional<Rect> rect = std::nullopt;
    };

    /**
     * @brief MyTexture type
     * Contains TextureImg or TextureText
     */

    using MyTexture = std::variant<TextureImg, TextureText>;

    /**
     * @brief Interface for the texture
     */
    class ITexture {
    public:
        virtual ~ITexture() = default;
        /**
         * @brief Get the texture informations
         * @return const MyTexture&
         */
        [[nodiscard]] virtual const MyTexture& getInformations() const = 0;
        /**
         * @brief Get the width of the texture
         * @return uint32_t
         */
        [[nodiscard]] virtual uint32_t getWidth() const = 0;
        /**
         * @brief Get the height of the texture
         * @return uint32_t
         */
        [[nodiscard]] virtual uint32_t getHeight() const = 0;
    };

    /**
     * @brief Interface for the texture manager
     */
    class ITextureManager {
    public:
        virtual ~ITextureManager() = default;
        /**
         * @brief Load a texture
         * @param name Name of the texture
         * @param texture Texture
         * @return int
         */
        [[nodiscard]] virtual int load(const std::string& name, const MyTexture texture) const = 0;
        /**
         * @brief Get a texture
         * @param name Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        [[nodiscard]] virtual std::shared_ptr<ITexture> get(const std::string& name) const = 0;
    };
}

#endif /* !ITEXTURE_HPP_ */
