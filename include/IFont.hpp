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
     * @brief Font properties
     */
    class Font {
    public:
        /**
         * @brief Construct a new Font object
         * @param path Path to the font file
         * @param color Color of the font
         * @param size Size of the font
         */
        Font(std::string path, Color color, std::size_t size = 12)
            : path(std::move(path)), color(color), size(size) {}
        /**
         * @brief Destroy the Font object
         */
        ~Font() = default;

        /**
         * @brief Get the path to the font file
         * @return const std::string&
         */
        [[nodiscard]] const std::string& getPath() const { return path; }

        /**
         * @brief Get the color of the font
         * @return Color
         */
        [[nodiscard]] Color getColor() const { return color; }

        /**
         * @brief Set the color of the font
         * @param newColor New color of the font
         */
        void setColor(Color newColor) { color = newColor; }

        /**
         * @brief Get the size of the font
         * @return std::size_t
         */
        [[nodiscard]] std::size_t getSize() const { return size; }

        /**
         * @brief Set the size of the font
         * @param newSize New size of the font
         */
        void setSize(std::size_t newSize) { size = newSize; }

    private:
        std::string path;
        Color color;
        std::size_t size;
    };

    /**
     * @brief Interface for the font
     */
    class IFont {
    public:
        /** 
         * @brief Destroy the IFont object
         */
        virtual ~IFont() = default;
        /**
         * @brief Get the font informations
         * @return const Font&
         */
        [[nodiscard]] virtual const Font& getInformations() const = 0;
    };


    /**
     * @brief Interface for the font manager
     */
    class IFontManager {
    public:
    /**
     * @brief Destroy the IFontManager object
     */
        virtual ~IFontManager() = default;
        /**
         * @brief Load a font
         * @param name Name of the font
         * @param texture Font properties
         * @return int
         */
        [[nodiscard]] virtual int load(const std::string& name, const Font texture) const = 0;
        /**
         * @brief Get a font
         * @param name Name of the font
         * @return std::shared_ptr<IFont>
         */
        [[nodiscard]] virtual std::shared_ptr<IFont> get(const std::string& name) const = 0;
    };
}

#endif /* !IFONT_HPP_ */
