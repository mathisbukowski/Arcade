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
    
    /**
     * Font properties
     */
    class Font {
    public:
        /**
         * Construct a new Font object
         * @param path std::string Path to the font file
         * @param color Color Font color
         * @param size std::size_t Size of the font
         */
        Font(std::string path, Color color, std::size_t size = 12)
            : _path(std::move(path)), _color(color), _size(size) {}
        /**
         * Destroy the Font object
         */
        ~Font() = default;

        /**
         * Get the path to the font file
         * @return const std::string& Path to the font file
         */
        [[nodiscard]] const std::string& getPath() const { return _path; }

        /**
         * Get the color of the font
         * @return Color Color of the font
         */
        [[nodiscard]] Color getColor() const { return _color; }

        /**
         * Set the color of the font
         * @param newColor Color New color of the font
         */
        void setColor(Color newColor) { _color = newColor; }

        /**
         * Get the size of the font
         * @return std::size_t Size of the font
         */
        [[nodiscard]] std::size_t getSize() const { return _size; }

        /**
         * Set the size of the font
         * @param newSize std::size_t New size of the font
         */
        void setSize(std::size_t newSize) { _size = newSize; }

    private:
        /**
         * Path to the font file
         */
        std::string _path;
        /**
         * Color of the font
         */
        Color _color;
        /**
         * Size of the font
         */
        std::size_t _size;
    };

    /**
     * Interface for the font
     */
    class IFont {
    public:
        /** 
         * Destroy the IFont object
         */
        virtual ~IFont() = default;
        /**
         * Get the font informations
         * @return const Font& Font properties
         */
        [[nodiscard]] virtual const Font& getInformations() const = 0;
    };


    /**
     * Interface for the font manager
     */
    class IFontManager {
    public:
    /**
     * Destroy the IFontManager object
     */
        virtual ~IFontManager() = default;
        /**
         * Load a font
         * @param name const std::string & Name of the font
         * @param font const Font & Font properties
         * @return int 0 if success, -1 if error
         */
        [[nodiscard]] virtual int load(const std::string& name, Font& font) = 0;
        /**
         * Get a font
         * @param name const std::string &Name of the font
         * @return std::shared_ptr<IFont> Font object
         */
        [[nodiscard]] virtual std::shared_ptr<IFont> get(const std::string& name) const = 0;
    };
}

#endif /* !IFONT_HPP_ */
