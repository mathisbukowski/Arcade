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
