/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** SdlDisplayModule - Interface for SDL2 display
*/

#ifndef SDLDISPLAYMODULE_HPP
#define SDLDISPLAYMODULE_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_keycode.h>
#include <memory>
#include <string>
#include <utility>
#include <unordered_map>

#include "IDisplayModule.hpp"
#include "SdlRendererManager.hpp"
#include "SdlTextureManager.hpp"

namespace arcade {
    /**
     * @class SDLDisplayModule
     * @brief Implementation of the display module interface using SDL2
     */
    class SDLDisplayModule : public IDisplayModule {
    public:
        /**
         * @brief Constructor
         * @param rendererManager Reference to the SDL renderer manager
         */
        explicit SDLDisplayModule(SDLRendererManager& rendererManager);

        /**
         * @brief Destructor
         */
        ~SDLDisplayModule() override;

        /**
         * @brief Initialize the SDL display with specified parameters
         * @param title Window title
         * @param width Window width
         * @param height Window height
         */
        void init(const std::string& title, size_t width, size_t height) override;

        /**
         * @brief Stop and cleanup the SDL display
         */
        void stop() override;

        /**
         * @brief Get the name of the display module
         * @return Display module name
         */
        [[nodiscard]] const std::string &getName() const override { return _name; }

        /**
         * @brief Configure window properties
         * @param properties Window properties to set
         */
        void setupWindowProperties(WindowProperties &properties) override { _windowProperties = properties; }

        /**
         * @brief Open the window
         */
        void openWindow() override;

        /**
         * @brief Close the window
         */
        void closeWindow() override;

        /**
         * @brief Clear window with specified color
         * @param color Color to use for clearing
         */
        void clearWindow(Color color) override;

        /**
         * @brief Update window state and process events
         * @param delta Time since last update
         */
        void updateWindow(float delta) override;

        /**
         * @brief Check if window is currently open
         * @return True if window is open
         */
        bool isWindowOpen() override { return _isOpen; }

        /**
         * @brief Draw a texture at specified position
         * @param texture Texture to draw
         * @param position Position where to draw
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;

        /**
         * @brief Get keyboard input handler
         * @return Reference to keyboard handler
         */
        [[nodiscard]] Keyboard &getKeyboard() override;

        /**
         * @brief Get mouse input handler
         * @return Reference to mouse handler
         */
        [[nodiscard]] Mouse &getMouse() override;

        /**
         * @brief Get current window properties
         * @return Window properties
         */
        [[nodiscard]] WindowProperties& getWindowProperties() override { return _windowProperties; }

    private:
        /**
         * @brief Initialize SDL subsystems
         */
        void initializeSDL();

        /**
         * @brief Validate renderer and window creation
         */
        void validateRendererAndWindow();

        /**
         * @brief Clean up SDL resources
         */
        void cleanupResources();

        /**
         * @brief Draw text texture
         * @param texture SDL texture containing text
         * @param position Position where to draw
         */
        void drawTextTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position);

        /**
         * @brief Draw sprite texture
         * @param texture SDL texture containing sprite
         * @param position Position where to draw
         */
        void drawSpriteTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position);

        /**
         * @brief Calculate scaling factors for sprite
         * @param texture SDL texture to scale
         * @return Pair of scaling factors (x, y)
         */
        std::pair<float, float> calculateSpriteScale(SDL_Texture* texture);

        /**
         * @brief Calculate adjusted position based on cell size
         * @param position Original position
         * @return Adjusted position
         */
        std::pair<float, float> calculateAdjustedPosition(Vector<float> position);

        /**
         * @brief Process SDL events
         */
        void processEvents();

        /**
         * @brief Handle specific SDL event
         * @param event SDL event to handle
         */
        void handleEvent(const SDL_Event& event);

        /**
         * @brief Handle keyboard event
         * @param keyEvent SDL key event
         * @param isPressed True if key is pressed, false if released
         */
        void handleKeyboardEvent(const SDL_KeyboardEvent& keyEvent, bool isPressed);

        /**
         * @brief Handle mouse button event
         * @param mouseEvent SDL mouse button event
         * @param isPressed True if button is pressed, false if released
         */
        void handleMouseButtonEvent(const SDL_MouseButtonEvent& mouseEvent, bool isPressed);

        /**
         * @brief Handle mouse motion event
         * @param mouseEvent SDL mouse motion event
         */
        void handleMouseMotionEvent(const SDL_MouseMotionEvent& mouseEvent);

        /**
         * @brief Map SDL key code to arcade key code
         * @param key SDL key code
         * @return Corresponding arcade key code
         */
        Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key);

        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        std::shared_ptr<SDL_Window> _window = nullptr;
        WindowProperties _windowProperties;
        std::string _name = "SDL2";
        bool _isOpen;
        Keyboard _keyboard;
        Mouse _mouse;
        SDLRendererManager& _rendererManager;

        static constexpr float GRID_SIZE = 20.0f;
        static constexpr float CELL_SCALE_FACTOR = 1.0f;
    };
}

#endif //SDLDISPLAYMODULE_HPP
