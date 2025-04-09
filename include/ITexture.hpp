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
     * @param position Vector<float> Position
     * @param width const float Width
     * @param height const float Height
     */
        Rect(Vector<float> position, const float width, const float height): _position(position.getX(), position.getY()), _width(width), _height(height) {}
        /**
         * Default constructor for Rect
         */
        ~Rect() = default;

        /**
         * Get the Position object
         * @return Vector<float> Position of the Rect
         */
        [[nodiscard]] Vector<float> getPosition() const { return _position; }
        /**
         * Get the Width object
         * @return float Width of the Rect
         */
        [[nodiscard]] float getWidth() const { return _width; }
        /**
         * Get the Height object
         * @return float Height of the Rect
         */
        [[nodiscard]] float getHeight() const { return _height; }
        /**
         * Set the Position object
         * @param newPosition const Vector <float> Position
         */
        void setPosition(const Vector<float> &newPosition) { _position = newPosition; }

        /**
         * Set the Width object
         * @param width float Width
         */
        void setWidth(float newWidth) { _width = newWidth; }

        /**
         * Set the Height object
         * @param height float Height
         */
        void setHeight(float newHeight) { _height = newHeight; }

        private:
        /**
         * Position of the Rect
         */
        Vector<float> _position;
        /**
         * Width of the Rect
         */
        float _width;
        /**
         * Height of the Rect
         */
        float _height;
    };


    class TextureBase {
    public:
        /**
         * Constructor for TextureBase
         * @param rect const std::optional<Rect> & Rect properties
         */
        explicit TextureBase(const std::optional<Rect> &rect = std::nullopt)
            : _rect(rect), _width(0), _height(0) {}

        /**
         * Destructor for TextureBase
         */
        virtual ~TextureBase() = default;

        /**
         * Get the Rect object
         * @return std::optional<Rect>
         */
        [[nodiscard]] std::optional<Rect> getRect() const { return _rect; }

        /**
         * Set the Rect object
         * @param rect const std::optional<Rect> Rect properties
         */
        void setRect(const std::optional<Rect> &newRect) { _rect = newRect; }

        /**
         * Get the Width object
         * @return uint32_t Width
         */
        [[nodiscard]] uint32_t getWidth() const { return _width; }

        /**
         * Set the Width object
         * @param newWidth uint32_t Width
         */
        void setWidth(uint32_t newWidth) { _width = newWidth; }

        /**
         * Get the Height object
         * @return uint32_t Height
         */
        [[nodiscard]] uint32_t getHeight() const { return _height; }

        /**
         * Set the Height object
         * @param height uint32_t Height
         */
        void setHeight(uint32_t newHeight) { _height = newHeight; }

    private:
        /**
         * Rect properties
         */
        std::optional<Rect> _rect;
        /**
         * Width of the texture
         */
        uint32_t _width;
        /**
         * Height of the texture
         */
        uint32_t _height;
    };

    /**
     * Class for textured images
     */
    class TextureImg : public TextureBase {
    public:
        /**
         * Constructor for TextureImg
         * @param path std::string Path to the image file
         * @param rect const std::optional <Rect> & Rect properties
         */
        explicit TextureImg(std::string path, const std::optional<Rect> &rect = std::nullopt)
            : TextureBase(rect), _path(std::move(path)) {}

        /**
         * Get the Path object
         * @return std::string
         */
        [[nodiscard]] std::string getPath() const { return _path; }

    private:
        /**
         * Path to the image file
         */
        std::string _path;
    };

    /**
     * Class for textured text
     */
    class TextureText : public TextureBase {
    public:
        /**
         * Constructor for TextureText
         * @param text std::string Text
         * @param color Color Text color
         * @param rect const std::optional<Rect> & Rect properties
         */
        explicit TextureText(std::string text = "", Color color = Color(0, 0, 0), const std::optional<Rect> &rect = std::nullopt)
            : TextureBase(rect), _text(std::move(text)), _color(color) {}

        /**
         * Get the Text object
         * @return std::string Text
         */
        [[nodiscard]] std::string getText() const { return _text; }

        /**
         * Set the Text object
         * @param newText const std::string & Text
         */
        void setText(const std::string &newText) { _text = newText; }

        /**
         * Get the Color object
         * @return const Color Color
         */
        [[nodiscard]] const Color getColor() const { return _color; }

        /**
         * Set the Color object
         * @param newColor const Color & Color
         */
        void setColor(const Color &newColor) { _color = newColor; }

    private:
        /**
         * Text to be displayed
         */
        std::string _text;
        /**
         * Color of the text
         */
        Color _color;
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
         * Get the texture infos
         * @return const MyTexture&
         */
        [[nodiscard]] virtual const MyTexture& getInformations() const = 0;

        /**
         * Set the texture infos
         * @param texture MyTexture &
         */
        virtual void set(MyTexture &texture) = 0;

    protected:
        /**
         * Constructor for ITexture
         * @param texture MyTexture &
         */
        explicit ITexture([[maybe_unused]]const MyTexture &texture) {}
    };

    /**
     * Interface for the texture manager
     */
    class ITextureManager {
    public:
        virtual ~ITextureManager() = default;
        /**
         * Load a texture
         * @param name const std::string & Name of the texture
         * @param newTexture const MyTexture & new texture
         * @return int 0 if success, -1 if error
         */
        [[nodiscard]] virtual int load(const std::string& name, const MyTexture &newTexture) = 0;
        /**
         * Get a texture
         * @param name const std::string & Name of the texture
         * @return std::shared_ptr<ITexture>
         */
        [[nodiscard]] virtual std::shared_ptr<ITexture> get(const std::string& name) const = 0;
    };
}

#endif /* !ITEXTURE_HPP_ */