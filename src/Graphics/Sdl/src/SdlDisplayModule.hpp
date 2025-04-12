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
     * Implementation of the display module interface using SDL2
     * It inherits from IDisplayModule
     */
    class SDLDisplayModule : public IDisplayModule {
    public:
        /**
         * Constructor
         * @param rendererManager SDLRendererManager& Reference to the SDL renderer manager
         */
        explicit SDLDisplayModule(SDLRendererManager& rendererManager);

        /**
         * Destructor
         */
        ~SDLDisplayModule() override;

        /**
         * Initialize the SDL display with specified parameters
         * @param title const std::string & Window title
         * @param width size_t Window width
         * @param height size_t Window height
         */
        void init(const std::string& title, size_t width, size_t height) override;

        /**
         * Stop and cleanup the SDL display
         */
        void stop() override;

        /**
         * Get the name of the display module
         * @return const std::string & Display module name
         */
        [[nodiscard]] const std::string &getName() const override { return _name; }

        /**
         * Configure window properties
         * @param properties WindowProperties & Window properties to set
         */
        void setupWindowProperties(WindowProperties &properties) override { _windowProperties = properties; }

        /**
         * Open the window
         */
        void openWindow() override;

        /**
         * Close the window
         */
        void closeWindow() override;

        /**
         * Clear window with specified color
         * @param color Color to use for clearing
         */
        void clearWindow(Color color) override;

        /**
         * Update window state and process events
         * @param delta float Time since last update
         */
        void updateWindow(float delta) override;

        /**
         * Check if window is currently open
         * @return bool True if window is open
         */
        bool isWindowOpen() override { return _isOpen; }

        /**
         * Draw a texture at specified position
         * @param texture std::shared_ptr<ITexture> Texture to draw
         * @param position Vector<float> Position where to draw
         */
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;

        /**
         * Get keyboard input handler
         * @return Keyboard & Reference to keyboard handler
         */
        [[nodiscard]] Keyboard &getKeyboard() override;

        /**
         * Get mouse input handler
         * @return Mouse & Reference to mouse handler
         */
        [[nodiscard]] Mouse &getMouse() override;

        /**
         * Get current window properties
         * @return WindowProperties & Window properties
         */
        [[nodiscard]] WindowProperties& getWindowProperties() override { return _windowProperties; }

    private:
        /**
         * Initialize SDL subsystems
         */
        void initializeSDL();

        /**
         * Validate renderer and window creation
         */
        void validateRendererAndWindow();

        /**
         * Clean up SDL resources
         */
        void cleanupResources();

        /**
         * Draw text texture
         * @param texture std::shared_ptr<SDLTexture> SDL texture containing text
         * @param position Vector<float> Position where to draw
         */
        void drawTextTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position);

        /**
         * Draw sprite texture
         * @param texture std::shared_ptr<SDLTexture> SDL texture containing sprite
         * @param position Vector<float> Position where to draw
         */
        void drawSpriteTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position);

        /**
         * Calculate scaling factors for sprite
         * @param texture SDL_Texture* SDL texture to scale
         * @return std::pair<float, float> Pair of scaling factors (x, y)
         */
        std::pair<float, float> calculateSpriteScale(SDL_Texture* texture);

        /**
         * Calculate adjusted position based on cell size
         * @param position Vector<float> Original position
         * @return std::pair<float, float> Adjusted position
         */
        std::pair<float, float> calculateAdjustedPosition(Vector<float> position);

        /**
         * Process SDL events
         */
        void processEvents();

        /**
         * Handle specific SDL event
         * @param event const SDL_Event & SDL event to handle
         */
        void handleEvent(const SDL_Event& event);

        /**
         * Handle keyboard event
         * @param keyEvent const SDL_KeyboardEvent & SDL key event
         * @param isPressed bool True if key is pressed, false if released
         */
        void handleKeyboardEvent(const SDL_KeyboardEvent& keyEvent, bool isPressed);

        /**
         * Handle mouse button event
         * @param mouseEvent const SDL_MouseButtonEvent & SDL mouse button event
         * @param isPressed bool True if button is pressed, false if released
         */
        void handleMouseButtonEvent(const SDL_MouseButtonEvent& mouseEvent, bool isPressed);

        /**
         * Handle mouse motion event
         * @param mouseEvent const SDL_MouseMotionEvent& SDL mouse motion event
         */
        void handleMouseMotionEvent(const SDL_MouseMotionEvent& mouseEvent);

        /**
         * Map SDL key code to arcade key code
         * @param key SDL_Keycode SDL key code
         * @return Keyboard::KeyCode Corresponding arcade key code
         */
        Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key);

        /**
         * SDL renderer manager reference
         */
        std::shared_ptr<SDL_Renderer> _renderer = nullptr;
        /**
         * SDL window reference
         */
        std::shared_ptr<SDL_Window> _window = nullptr;
        /**
         * Window properties
         */
        WindowProperties _windowProperties;
        /**
         * Name of the window
         */
        std::string _name = "SDL2";
        /**
         * bool indicating if the window is open
         */
        bool _isOpen;
        /**
         * Keyboard input handler
         */
        Keyboard _keyboard;
        /**
         * Mouse input handler
         */
        Mouse _mouse;
        /**
         * SDL renderer manager reference
         */
        SDLRendererManager& _rendererManager;

        /**
         * Constants for grid size
         */
        static constexpr float GRID_SIZE = 20.0f;
        /**
         * Constants for cell scale factor
         */
        static constexpr float CELL_SCALE_FACTOR = 1.0f;
    };
}

#endif //SDLDISPLAYMODULE_HPP
