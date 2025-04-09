/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core
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

namespace arcade {
    /**
     * enum class GameState
     * Represents the current state of the game.
     */
    enum class GameState {
        MENU,
        GAME,
        EXIT
    };

    /**
     * struct Score
     * Represents a player's score in a game.
     */
    struct Score {
        /**
         * Player's name
         */
        std::string playerName;
        /**
         * Game name
         */
        std::string gameName;
        /**
         * Score value
         */
        int score;

        /**
         * Constructor
         * @param name const std::string & Player's name
         * @param game const std::string & Game name
         * @param value int Score value
         */
        Score(const std::string& name, const std::string& game, int value)
            : playerName(name), gameName(game), score(value) {}
    };

    /**
     * class Core
     * Main class for the Arcade game engine.
     */
    class Core {
    public:
        /**
         * Constructor
         * @param initialLibPath const std::string & Path to the initial library
         */
        Core(const std::string& initialLibPath);
        /**
         * Destructor of the Core class
         */
        ~Core();

        /**
         * Run the main loop of the game engine
         */
        void run();

    private:
        /**
         * Current state of the game
         */
        GameState _state;
        /**
         * Player's name
         */
        std::string _playerName;
        /**
         * Scores vector
         */
        std::vector<Score> _scores;
        /**
         * Library manager for loading dynamic libraries
         */
        std::unique_ptr<DynamicLibraryManager> _libManager;

        /**
         * Pointer to the current graphics library
         */
        std::shared_ptr<IDisplayLibrary> _currentGraphicLib;
        /**
         * Pointer to the current game library
         */
        std::shared_ptr<IGameModule> _currentGame;

        /**
         * chrono to keep track of the last frame time
         */
        std::chrono::high_resolution_clock::time_point _lastFrameTime;
        /**
         * Time since the last frame
         */
        float _deltaTime;

        /**
         * Initialize the graphics library
         * @param path const std::string & Path to the library
         */
        void initializeGraphicsLib(const std::string& path);
        /**
         * Initialize the game library
         */
        void initializeGameLib();

        /**
         * Update the menu state
         */
        void updateMenu();
        /**
         * Update the game state
         */
        void updateGame();
        /**
         * Display the menu
         */
        void displayMenu();
        /**
         * Display the game
         */
        void displayGame();

        /**
         * Load scores from a file
         */
        void loadScores();
        /**
         * Save scores to a file
         */
        void saveScores();
        /**
         * Switch the graphics library
         * @param libName const std::string & Name of the library to switch to
         */
        void switchGraphicsLib(const std::string& libName);
        /**
         * Switch the game library
         * @param gameName const std::string & Name of the game to switch to
         */
        void switchGame(const std::string& gameName);
        /**
         * Restart the current game
         */
        void restartGame();
        /**
         * Go to the menu state
         */
        void goToMenu();
        /**
         * Handle input for the menu
         */
        void handleMenuInput();
        /**
         * Handle input for the game
         */
        void handleGameInput();
        /**
         * update the delta time
         */
        void updateDeltaTime();
        /**
         * Render the game list
         * @param x int X position
         * @param y int Y position
         */
        void renderGameList(int x, int y);
        /**
         * Render the graphics list
         * @param x int X position
         * @param y int Y position
         */
        void renderGraphicsList(int x, int y);
        /**
         * Render the scores
         * @param x int X position
         * @param y int Y position
         */
        void renderScores(int x, int y);
        /**
         * Render the player name input
         * @param x int X position
         * @param y int Y position
         */
        void renderPlayerNameInput(int x, int y);

        /**
         * Check if the mouse is clicked on the game list
         * @param mouseX float X position of the mouse
         * @param mouseY float Y position of the mouse
         */
        void checkGameListClicks(float mouseX, float mouseY);
        /**
         * index of the selected game
         */
        int _selectedGameIndex;
    };
}

#endif // CORE_HPP_
