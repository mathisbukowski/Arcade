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
     * Properties of the window
     */
    class WindowProperties
    {
    public:
        WindowProperties(const std::string& title, std::size_t width, std::size_t height): width(width), height(height), title(title) {}
        ~WindowProperties() = default;
        /**
         * Get the width of the window
         * @return std::size_t Width of the window
         */
        std::size_t getWidth() const { return width; }

        /**
         * Set the width of the window
         * @param newWidth New width of the window
         */
        void setWidth(std::size_t newWidth) { width = newWidth; }

        /**
         * Get the height of the window
         * @return std::size_t Height of the window
         */
        std::size_t getHeight() const { return height; }

        /**
         * Set the height of the window
         * @param newHeight New height of the window
         */
        void setHeight(std::size_t newHeight) { height = newHeight; }

        /**
         * Get the title of the window
         * @return const std::string& Title of the window
         */
        const std::string &getTitle() const { return title; }

        /**
         * Set the title of the window
         * @param newTitle New title of the window
         */
        void setTitle(const std::string &newTitle) { title = newTitle; }

    private:
        std::size_t width; 
        std::size_t height;
        std::string title;
    };

    /**
     * Interface for the display module
     */
    class IDisplayModule {
    public:
    /**
     * Destroy the IDisplayModule object
     */
        virtual ~IDisplayModule () = default;
        /**
         * Initialize the display module
         */
        virtual void init(const std::string& title, size_t width, size_t height) = 0;
        /**
         * Stop the display module
         */
        virtual void stop() = 0;
        /**
         * Get the name of the display module
         * @return const std::string&
         */
        [[nodiscard]] virtual const std::string &getName() const = 0;
        /**
         * Set the window properties
         * @param windowProperties width, height and title of the window
         */
        virtual void setupWindowProperties(WindowProperties &windowProperties) = 0;
        /**
         * Open the window
         */
        virtual void openWindow() = 0;
        /**
         * Close the window
         */
        virtual void closeWindow() = 0;
        /**
         * Clear the window
         * @param color Color to clear the window with
         */
        virtual void clearWindow(Color color) = 0;
        /**
         * Update the window
         * @param delta Time since last update
         */
        virtual void updateWindow(float delta) = 0;
        /**
         * is the window open
         * @return true if the window is open
         */
        virtual bool isWindowOpen() = 0;
        /**
         * draw a texture
         * @param texture Texture to draw
         * @param position Position to draw the texture
         */
        virtual void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) = 0;
        /**
         * Return the keyboard class
         * @return Keyboard&
         */
        virtual Keyboard &getKeyboard() = 0;
        /**
         * Return the mouse class
         * @return Mouse&
         */
        virtual Mouse &getMouse() = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
