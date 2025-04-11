/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Snake game implementation
*/

#ifndef SNAKE_GAME_HPP_
#define SNAKE_GAME_HPP_

#include "BaseSnakeGame.hpp"

namespace arcade {

/**
* @class SnakeGame
* This class implements the Snake game logic.
* It inherits from BaseSnakeGame and provides specific functionalities for the Snake game.
*/
class SnakeGame : public BaseSnakeGame {
public:
    /**
     * Constructor
     * @param cyclical bool Whether the game has cyclical borders (snake can go through walls)
     */
    explicit SnakeGame(bool cyclical = false);

    /**
     * Destructor
     */
    ~SnakeGame() override = default;

    /**
     * Updates the game state
     * @param delta float Time elapsed since last update in seconds
     */
    void update(float delta) override;


private:
    /**
     * Adjusts position for cyclical boundaries
     * Snake can pass through walls and appear on the other side if enabled
     * @param pos const Vector<float> & Position to adjust
     * @return Vector<float> -Adjusted position
     */
    Vector<float> adjustPosition(const Vector<float>& pos) const override;

    /**
     * Checks collisions specific to Snake game
     * In Snake, colliding with walls is fatal unless cyclical borders are enabled
     * @return CollisionTypeType of collision detected
     */
    CollisionType checkCollisions() override;

    /**
     * Initialize the grid for Snake
     * Snake has a simple empty grid without obstacles
     */
    void initGrid() override;

    /**
     * Handles the game over state
     * Displays game over screen and plays sound
     */
    void onGameOver() override;

    /**
     * Creates the window title for Snake
     * @return std::string Window title string
     */
    std::string getWindowTitle() const;

    /**
     * Constants for the default game speed
     */
    static constexpr float DEFAULT_SPEED = 0.18f;
    /**
     * Constants for the default game score multiplier
     */
    static constexpr float SCORE_MULTIPLIER = 1.2f;
    /**
     * Constants for the default game food spawn frequency
     */
    static constexpr int FOOD_SPAWN_FREQUENCY = 1;
};

}

#endif // SNAKE_GAME_HPP_
