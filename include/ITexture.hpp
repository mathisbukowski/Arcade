/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** ITexture
*/

#ifndef ITEXTURE_HPP_
#define ITEXTURE_HPP_

#include <IFont.hpp>

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


    class TextureBase {
    public:
        /**
         * Constructor for TextureBase
         * @param rect Rect properties
         */
        explicit TextureBase(const std::optional<Rect> &rect = std::nullopt)
            : rect(rect), _width(0), _height(0) {}

        virtual ~TextureBase() = default;

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

        /**
         * Get the Width object
         * @return uint32_t
         */
        [[nodiscard]] uint32_t getWidth() const { return _width; }

        /**
         * Set the Width object
         * @param width Width
         */
        void setWidth(uint32_t newWidth) { _width = newWidth; }

        /**
         * Get the Height object
         * @return uint32_t
         */
        [[nodiscard]] uint32_t getHeight() const { return _height; }

        /**
         * Set the Height object
         * @param height Height
         */
        void setHeight(uint32_t newHeight) { _height = newHeight; }

    private:
        std::optional<Rect> rect;
        uint32_t _width;
        uint32_t _height;
    };

    /**
     * Class for textured images
     */
    class TextureImg : public TextureBase {
    public:
        /**
         * Constructor for TextureImg
         * @param path Path to the image file
         * @param rect Rect properties
         */
        explicit TextureImg(std::string path, const std::optional<Rect> &rect = std::nullopt)
            : TextureBase(rect), path(std::move(path)) {}

        /**
         * Get the Path object
         * @return std::string
         */
        [[nodiscard]] std::string getPath() const { return path; }

    private:
        std::string path;
    };

    /**
     * Class for textured text
     */
    class TextureText : public TextureBase {
    public:
        /**
         * Constructor for TextureText
         * @param text Text
         * @param color Color of the text
         * @param rect Rect properties
         */
        explicit TextureText(std::string text = "", Color color = Color(0, 0, 0), const std::optional<Rect> &rect = std::nullopt)
            : TextureBase(rect), text(std::move(text)), color(color) {}

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
         *  Get the std::shared_ptr<IFont> object
         */
        [[nodiscard]] std::shared_ptr<IFont> getFont() const { return font; }

        /**
         * Set the Font object
         * @param std::shared_ptr<IFont> Font
         */
        void setFont(const std::shared_ptr<IFont> &newFont) { font = newFont; }

    private:
        std::string text;
        Color color;
        std::shared_ptr<IFont> font;
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
        [[nodiscard]] virtual int load(const std::string& name, const MyTexture& newTexture) = 0;
        /**
         * Get a texture
         * @param name Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        [[nodiscard]] virtual std::shared_ptr<ITexture> get(const std::string& name) const = 0;
    };
}

#endif /* !ITEXTURE_HPP_ */