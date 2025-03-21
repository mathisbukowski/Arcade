/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <string>
#include "ITexture.hpp"
#include "Input.hpp"
#include "Vector.hpp"

namespace arcade
{
    /**
     * @brief Properties of the window
     */
    class WindowProperties
    {
    public:
        /**
         * @brief Get the width of the window
         * @return std::size_t Width of the window
         */
        std::size_t getWidth() const { return width; }

        /**
         * @brief Set the width of the window
         * @param newWidth New width of the window
         */
        void setWidth(std::size_t newWidth) { width = newWidth; }

        /**
         * @brief Get the height of the window
         * @return std::size_t Height of the window
         */
        std::size_t getHeight() const { return height; }

        /**
         * @brief Set the height of the window
         * @param newHeight New height of the window
         */
        void setHeight(std::size_t newHeight) { height = newHeight; }

        /**
         * @brief Get the title of the window
         * @return const std::string& Title of the window
         */
        const std::string &getTitle() const { return title; }

        /**
         * @brief Set the title of the window
         * @param newTitle New title of the window
         */
        void setTitle(const std::string &newTitle) { title = newTitle; }

    private:
        std::size_t width; 
        std::size_t height;
        std::string title;
    };

    /**
     * @brief Interface for the display module
     */
    class IDisplayModule {
    public:
    /**
     * @brief Destroy the IDisplayModule object
     */
        virtual ~IDisplayModule () = default;
        /**
         * @brief Initialize the display module
         */
        virtual void init() = 0;
        /**
         * @brief Stop the display module
         */
        virtual void stop() = 0;
        /**
         * @brief Get the name of the display module
         * @return const std::string&
         */
        [[nodiscard]] virtual const std::string &getName() const = 0;
        /**
         * @brief Get the window properties
         * @param windowProperties width, height and title of the window
         */
        virtual void setupWindowProperties(WindowProperties &windowProperties) = 0;
        /**
         * @brief Open the window
         */
        virtual void openWindow() = 0;
        /**
         * @brief Close the window
         */
        virtual void closeWindow() = 0;
        /**
         * @brief Clear the window
         * @param color Color to clear the window with
         */
        virtual void clearWindow(Color color) = 0;
        /**
         * @brief Update the window
         * @param delta Time since last update
         */
        virtual void updateWindow(float delta) = 0;
        /**
         * @brief is the window open
         * @return true if the window is open
         */
        virtual bool isWindowOpen() = 0;
        /**
         * @brief draw a texture
         * @param texture Texture to draw
         * @param position Position to draw the texture
         */
        virtual void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) = 0;
        /**
         * @brief Return the keyboard class
         * @return Keyboard&
         */
        virtual Keyboard &getKeyboard() = 0;
        /**
         * @brief Return the mouse class
         * @return Mouse&
         */
        virtual Mouse &getMouse() = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
