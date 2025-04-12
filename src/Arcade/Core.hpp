/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core header file
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include "DLManager.hpp"
#include "IGameModule.hpp"
#include "IDisplayLibrary.hpp"
#include "ResolutionScaler.hpp"

namespace arcade {
    /**
     * @enum GameState
     * @brief Represents the current state of the game.
     */
    enum class GameState {
        MENU,
        GAME,
        EXIT
    };

    /**
     * @enum MenuSection
     * @brief Represents different sections in the menu
     */
    enum class MenuSection {
        GAMES,
        GRAPHICS,
        PLAYER_NAME
    };

    /**
     * @class Score
     * @brief Represents a player's score in a game.
     */
    class Score {
    public:
        std::string _playerName;
        std::string _gameName;
        int _score;

        /**
         * Constructor
         * @param name Player's name
         * @param game Game name
         * @param value Score value
         */
        Score(const std::string& name, const std::string& game, int value)
            : _playerName(name), _gameName(game), _score(value) {}
    };

    /**
     * @class Core
     * @brief Main class for the Arcade game engine.
     */
    class Core {
    public:
        /**
         * Constructor
         * @param initialLibPath Path to the initial library
         */
        Core(const std::string& initialLibPath);

        /**
         * Destructor
         */
        ~Core();

        /**
         * Main game loop
         */
        void run();

    private:
        // Game state
        GameState _state; /* State of the game */
        std::string _playerName; /* Player's name */
        std::vector<Score> _scores; /* Player's scores */

        // Libraries
        std::unique_ptr<DynamicLibraryManager> _libManager; /* Library manager */
        std::shared_ptr<IDisplayLibrary> _currentGraphicLib; /* Current graphic library */
        std::shared_ptr<IGameModule> _currentGame; /* Current game library */

        // Timing
        std::chrono::high_resolution_clock::time_point _lastFrameTime; /* Last frame time */
        float _deltaTime; /* Time since last frame */

        // Resolution scaling
        std::unique_ptr<ResolutionScaler> _resolutionScaler; /* Resolution scaler */

        // Menu navigation
        MenuSection _currentMenuSection = MenuSection::GAMES; /* Current menu section */
        int _selectedGameIndex = 0; /* Selected game index */
        int _selectedGraphicLibIndex = 0; /* Selected graphic library index */ 

        // Input handling
        bool _previousUpState = false; /* previous step of up move */
        bool _previousDownState = false; /* previous step of down move */
        bool _previousLeftState = false; /* previous step of left move */
        bool _previousRightState = false; /* previous step of right move */
        bool _previousEnterState = false; /* previous step of enter move */
        bool _previousAState = false; /* previous step of A move */
        bool _previousEscapeState = false; /* previous step of escape move */

        // Library initialization
        /**
         * Initialize the graphics library
         * @param path Path to the library
         */
        void initializeGraphicsLib(const std::string& path);
        /**
         * Initialize the game library
         */
        void initializeGameLib();

        /**
         * update the main programm
         */
        void updateDeltaTime();
        /**
         * update the menu
         */
        void updateMenu();
        /**
         * update the game state
         */
        void updateGame();
        /**
         * display the menu
         */
        void displayMenu();
        /**
        * display the game
        */
        void displayGame();

        // Score management
        /**
         * Load scores from a file
         */
        void loadScores();
        /**
         * Save new scores
         */
        void saveScores();

        /**
         * Switch to a different graphics library or game
         * @param libName Name of the graphics library  
        */
        void switchGraphicsLib(const std::string& libName);
        /**
         * Switch to a different game
         * @param gameName Name of the game
         */
        void switchGame(const std::string& gameName);
        /**
         * Restart the current game
         */
        void restartGame();
        /**
         * Try to restart the game
         */
        void tryRestartGame();
        /**
         * Try to switch to the next game
         */
        void trySwitchToNextGame();
        /**
         * Go to the menu of Arcade
         */
        void goToMenu();

        /**
         * Prepare the menu
         */
        void prepareMenuDisplay();
        /**
         * draw the menu section
         */
        void drawMenuSectionBackgrounds();
        /**
         * draw the menu title
         */
        void drawMenuTitle();
        /**
         * render the menu sections
         */
        void renderMenuSections();
        /**
         * render the menu instructions
         */
        void renderMenuInstructions();

        /**
         * Process keyboard input for the menu
         * @param keyboard Keyboard object
         * @return true if the input was processed, false otherwise
         */
        bool processMenuKeyboardInput(Keyboard& keyboard);
        /**
         * Handle all input for the menu and game
         */
        void handleMenuInput();
        void handleGameInput();
        /**
         * Check if a key was just pressed
         * @param keyboard Keyboard object
         * @param key Key code
         * @param previousState Previous state of the key
         * @return true if the key was just pressed, false otherwise
         */
        bool isKeyJustPressed(Keyboard& keyboard, Keyboard::KeyCode key, bool& previousState);

        // Menu navigation
        /**
         * Navigate the menu up, down, left, right
         */
        void navigateMenuUp();
        void navigateMenuDown();
        void navigateMenuLeft();
        void navigateMenuRight();
        /**
         * Navigate the game and graphics lists up and down
         */
        void navigateGamesListUp();
        void navigateGamesListDown();
        void navigateGraphicsListUp();
        void navigateGraphicsListDown();
        /**
         * Handle selection in the menu
         */
        void handleMenuSelection();
        void selectGame();
        void selectGraphicsLib();

        /**
         * Render game list
         * @param x X position
         * @param y Y position
         */
        void renderGameList(float x, float y);
        /**
         * Render graphics list
         * @param x X position
         * @param y Y position
         */
        void renderGraphicsList(float x, float y);
        /**
         * Render scores
         * @param x X position
         * @param y Y position
         */
        void renderScores(float x, float y);
        /**
         * Render player name input
         * @param x X position
         * @param y Y position
         */
        void renderPlayerNameInput(float x, float y);
        /**
         * Render menu title
         * @param x X position
         * @param y Y position
         * @param title Title text
         * @param section Menu section
         * @param textureName Texture name
         */
        void renderMenuListTitle(float x, float y, const std::string& title, MenuSection section, const std::string& textureName);
        /**
         * Render game items
         * @param x X position
         * @param y Y position
         */
        void renderGameItems(float x, float y);
        /**
         * Render graphics items
         * @param x X position
         * @param y Y position
         */
        void renderGraphicsItems(float x, float y);
        /**
         * Render menu item
         * @param textureName Texture name
         * @param text Text to display
         * @param color Color of the text
         * @param x X position
         * @param y Y position
         */
        void renderMenuItem(const std::string& textureName, const std::string& text, Color color, float x, float y);
        /**
         * Render score items
         * @param x X position
         * @param y Y position
         */
        void renderScoreItems(float x, float y);
        /**
         * Draw Menu Section
         * @param x X position
         * @param y Y position
         * @param width Width of the section
         * @param height Height of the section
         * @param name Name of the section
         * @param color Color of the section
         */
        void drawMenuSection(float x, float y, float width, float height, const std::string& name, Color color);

        /**
         * Check if the mouse is hovering over an item
         * @param x X position
         * @param y Y position
         * @param width Width of the item
         * @param height Height of the item
         * @param mousePos Mouse position
         * @return true if the item is hovered, false otherwise
         */
        bool isItemHovered(float x, float y, float width, float height, const Vector<float>& mousePos) const;
        /**
         * Get the color of the item text based on its state
         * @param isSelected Is the item selected
         * @param isHovered Is the item hovered
         * @param isCurrent Is the item current
         * @return Color of the item text
         */
        Color getItemTextColor(bool isSelected, bool isHovered, bool isCurrent) const;

        // Mouse input
        /**
         * Check mouse clicks
         * @param mouseX X position of the mouse
         * @param mouseY Y position of the mouse
         */
        void checkMenuClicks(float mouseX, float mouseY);
        void checkGameListClicks(float mouseX, float mouseY);
        void checkGraphicsListClicks(float mouseX, float mouseY);
        void checkPlayerNameClick(float mouseX, float mouseY);
    };
}

#endif // CORE_HPP_
