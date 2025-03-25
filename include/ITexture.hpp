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
     * Rect properties
     */
    class Rect {
    public:
    /**
     * Construct a new Rect object
     * @param position Position
     * @param width Width
     * @param height Height
     * @return Rect
     */
        Rect(Vector<float> position, const float width, const float height): position(position.getX(), position.getY()), width(width), height(height) {}
        ~Rect() = default;

        /**
         * Get the Position object
         * @return Vector<float>
         */
        [[nodiscard]] Vector<float> getPosition() const { return position; }
        /**
         * Get the Width object
         * @return float
         */
        [[nodiscard]] float getWidth() const { return width; }
        /**
         * Get the Height object
         * @return float
         */
        [[nodiscard]] float getHeight() const { return height; }

        private:
        Vector<float> position;
        float width;
        float height;
    };


    /**
     * TextureImg properties
     */
    class TextureImg
    {
    public:
    /**
     * Construct a new Texture Img object
     * @param path Path to the image file
     * @param rect Rect properties
     * @return TextureImg
     */
        TextureImg(std::string path, const std::optional<Rect> &rect = std::nullopt):
            path(std::move(path)), rect(rect) {}
        ~TextureImg() = default;
        /**
         * Get the Path object
         * @return std::string
         */
        [[nodiscard]] std::string getPath() const { return path; }
        /**
         * Get the Rect object
         * @return std::optional<Rect>
         */
        [[nodiscard]] std::optional<Rect> getRect() const { return rect; }

        /**
         * Set the Rect object
         * @param rect Rect properties
         */
        void setRect(const std::optional<Rect> &newRect) { rect = newRect; }

        private:
            std::string path;
            std::optional<Rect> rect;
    };

    /**
     * TextureText properties
     */
    class TextureText
    {
    public:
    /**
     * Construct a new Texture Text object
     * @param text Text
     * @param color Color of the text
     * @param rect Rect properties
     * @return TextureText
     */
        TextureText(std::string text = "", Color color = Color(0, 0, 0), const std::optional<Rect> &rect = std::nullopt):
            text(std::move(text)), color(color), rect(rect) {}
        ~TextureText() = default;

        /**
         * Get the Text object
         * @return std::string
         */
        [[nodiscard]] std::string getText() const { return text; }

        /**
         * Set the Text object
         * @param text Text
         */
        void setText(const std::string &newText) { text = newText; }

        /**
         * Get the Color object
         * @return Color
         */
        [[nodiscard]] Color getColor() const { return color; }

        /**
         * Set the Color object
         * @param color Color
         */
        void setColor(const Color &newColor) { color = newColor; }

        /**
         * Get the Rect object
         * @return std::optional<Rect>
         */
        [[nodiscard]] std::optional<Rect> getRect() const { return rect; }

        /**
         * Set the Rect object
         * @param rect Rect properties
         */
        void setRect(const std::optional<Rect> &newRect) { rect = newRect; }

    private:
        std::string text;
        Color color;
        std::optional<Rect> rect = std::nullopt;
    };

    /**
     * MyTexture type
     * Contains TextureImg or TextureText
     */

    using MyTexture = std::variant<TextureImg, TextureText>;

    /**
     * Interface for the texture
     */
    class ITexture {
    public:
        virtual ~ITexture() = default;
        /**
         * Get the texture informations
         * @return const MyTexture&
         */
        [[nodiscard]] virtual const MyTexture& getInformations() const = 0;
        /**
         * Get the width of the texture
         * @return uint32_t
         */
        [[nodiscard]] virtual uint32_t getWidth() const = 0;
        /**
         * Get the height of the texture
         * @return uint32_t
         */
        [[nodiscard]] virtual uint32_t getHeight() const = 0;
    };

    /**
     * Interface for the texture manager
     */
    class ITextureManager {
    public:
        virtual ~ITextureManager() = default;
        /**
         * Load a texture
         * @param name Name of the texture
         * @param newTexture new texture
         * @return int
         */
        [[nodiscard]] virtual int load(const std::string& name, std::shared_ptr<ITexture> newTexture) const = 0;
        /**
         * Get a texture
         * @param name Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        [[nodiscard]] virtual std::shared_ptr<ITexture> get(const std::string& name) const = 0;
    };
}

#endif /* !ITEXTURE_HPP_ */
