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
    class WindowProperties
    {
    public:
        std::size_t width;
        std::size_t height;
        std::string title;
    };

    class IDisplayModule {
    public:
        virtual ~IDisplayModule () = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        [[nodiscard]] virtual const std::string &getName() const = 0;

        virtual void setupWindowProperties(WindowProperties &windowProperties) = 0;
        virtual void openWindow() = 0;
        virtual void closeWindow() = 0;
        virtual void clearWindow(Color color) = 0;
        virtual void updateWindow(float delta) = 0;
        virtual bool isWindowOpen() = 0;

        virtual void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) = 0;

        virtual Keyboard &getKeyboard() = 0;
        virtual Mouse &getMouse() = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
