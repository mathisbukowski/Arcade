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
        GameState _state;
        std::string _playerName;
        std::vector<Score> _scores;

        // Libraries
        std::unique_ptr<DynamicLibraryManager> _libManager;
        std::shared_ptr<IDisplayLibrary> _currentGraphicLib;
        std::shared_ptr<IGameModule> _currentGame;

        // Timing
        std::chrono::high_resolution_clock::time_point _lastFrameTime;
        float _deltaTime;

        // Resolution scaling
        std::unique_ptr<ResolutionScaler> _resolutionScaler;

        // Menu navigation
        MenuSection _currentMenuSection = MenuSection::GAMES;
        int _selectedGameIndex = 0;
        int _selectedGraphicLibIndex = 0;

        // Input handling
        bool _previousUpState = false;
        bool _previousDownState = false;
        bool _previousLeftState = false;
        bool _previousRightState = false;
        bool _previousEnterState = false;
        bool _previousAState = false;
        bool _previousEscapeState = false;

        // Library initialization
        void initializeGraphicsLib(const std::string& path);
        void initializeGameLib();

        // Update and display methods
        void updateDeltaTime();
        void updateMenu();
        void updateGame();
        void displayMenu();
        void displayGame();

        // Score management
        void loadScores();
        void saveScores();

        // Library switching
        void switchGraphicsLib(const std::string& libName);
        void switchGame(const std::string& gameName);
        void restartGame();
        void tryRestartGame();
        void trySwitchToNextGame();
        void goToMenu();

        // Menu display organization
        void prepareMenuDisplay();
        void drawMenuSectionBackgrounds();
        void drawMenuTitle();
        void renderMenuSections();
        void renderMenuInstructions();

        // Menu input processing
        bool processMenuKeyboardInput(Keyboard& keyboard);
        void handleMenuInput();
        void handleGameInput();
        bool isKeyJustPressed(Keyboard& keyboard, Keyboard::KeyCode key, bool& previousState);

        // Menu navigation
        void navigateMenuUp();
        void navigateMenuDown();
        void navigateMenuLeft();
        void navigateMenuRight();
        void navigateGamesListUp();
        void navigateGamesListDown();
        void navigateGraphicsListUp();
        void navigateGraphicsListDown();
        void handleMenuSelection();
        void selectGame();
        void selectGraphicsLib();

        // Menu rendering
        void renderGameList(float x, float y);
        void renderGraphicsList(float x, float y);
        void renderScores(float x, float y);
        void renderPlayerNameInput(float x, float y);
        void renderMenuListTitle(float x, float y, const std::string& title, MenuSection section, const std::string& textureName);
        void renderGameItems(float x, float y);
        void renderGraphicsItems(float x, float y);
        void renderMenuItem(const std::string& textureName, const std::string& text, Color color, float x, float y);
        void renderScoreItems(float x, float y);
        void drawMenuSection(float x, float y, float width, float height, const std::string& name, Color color);

        // Menu interaction utilities
        bool isItemHovered(float x, float y, float width, float height, const Vector<float>& mousePos) const;
        Color getItemTextColor(bool isSelected, bool isHovered, bool isCurrent) const;

        // Mouse input
        void checkMenuClicks(float mouseX, float mouseY);
        void checkGameListClicks(float mouseX, float mouseY);
        void checkGraphicsListClicks(float mouseX, float mouseY);
        void checkPlayerNameClick(float mouseX, float mouseY);
    };
}

#endif // CORE_HPP_
