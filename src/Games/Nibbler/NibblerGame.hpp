/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Nibbler game implementation
*/

#ifndef NIBBLER_GAME_HPP_
#define NIBBLER_GAME_HPP_

#include "BaseSnakeGame.hpp"
#include "LevelManager.hpp"
#include <vector>

namespace arcade {
    /**
     * @class NibblerGame class
     * This class implements the Nibbler game logic.
     * It inherits from BaseSnakeGame and provides specific functionalities for the Nibbler game.
     */
    class NibblerGame : public BaseSnakeGame {
        public:
        /**
         * Constructor
         */
        NibblerGame();
        /**
         * Destructor
         */
        ~NibblerGame() override = default;
        /**
         * update the game
         * @param delta float Time since the last update
         */
        void update(float delta) override;

        private:
        /**
         * Initialize the grid
         */
        void initGrid() override;
        /**
         * Check for collisions
         */
        CollisionType checkCollisions() override;
        /**
         * Handle automatic turns
         * @param currentPosition Vector<float> Current position of the snake
         * @return Direction Direction to turn
         */
        Direction handleAutomaticTurns(const Vector<float>& currentPosition);
        /**
         * Get all available directions
         * @param position Vector<float> Current position of the snake
         * @return std::vector<Direction> List of available directions
         */
        std::vector<Direction> getAvailableDirections(const Vector<float>& position) const;
        /**
         * Check if the position is a T-junction
         * @param position Vector<float> & Position to check
         * @return bool True if it's a T-junction, false otherwise
         */
        bool isTjunction(const Vector<float>& position) const;
        /**
         * Load the level
         * @param level int Level number
         */
        void loadLevel(int level);
        /**
         * Handle the level completion
         */
        void onLevelComplete() override;
        /**
         * Handle the game over state
         */
        void onGameOver() override;
        /**
         * Get the window title
         * @return std::string Window title
         */
        std::string getWindowTitle() const;
        /**
         * Constants of the default game speed
         */
        static constexpr float DEFAULT_SPEED = 0.15f;
        /**
         * Constants of the speed increase factor
         */
        static constexpr float LEVEL_SPEED_INCREASE = 0.02f;
        /**
         * Constants of the maximum level
         */
        static constexpr int MAX_LEVEL = 5;
        /**
         * Constants of the time limit for the game
         */
        static constexpr float BASE_TIME_LIMIT = 60.0f;
        /**
         * Constants of the time bonus for each food eaten
         */
        static constexpr float TIME_BONUS_PER_FOOD = 5.0f;

        /**
         * LevelManager object to manage levels
         */
        LevelManager _levelManager;
    };
}

#endif // NIBBLER_GAME_HPP_
