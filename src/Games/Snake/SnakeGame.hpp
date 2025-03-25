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
 * @brief Implementation of the classic Snake game
 */
class SnakeGame : public BaseSnakeGame {
public:
    /**
     * @brief Constructor
     * @param cyclical Whether the game has cyclical borders (snake can go through walls)
     */
    explicit SnakeGame(bool cyclical = false);

    /**
     * @brief Destructor
     */
    ~SnakeGame() override = default;

    /**
     * @brief Updates the game state
     * @param delta Time elapsed since last update in seconds
     */
    void update(float delta) override;


private:
    /**
     * @brief Adjusts position for cyclical boundaries
     * Snake can pass through walls and appear on the other side if enabled
     * @param pos Position to adjust
     * @return Adjusted position
     */
    Vector<float> adjustPosition(const Vector<float>& pos) const override;

    /**
     * @brief Checks collisions specific to Snake game
     * In Snake, colliding with walls is fatal unless cyclical borders are enabled
     * @return Type of collision detected
     */
    CollisionType checkCollisions() override;

    /**
     * @brief Initialize the grid for Snake
     * Snake has a simple empty grid without obstacles
     */
    void initGrid() override;

    /**
     * @brief Handles the game over state
     * Displays game over screen and plays sound
     */
    void onGameOver() override;

    /**
     * @brief Creates the window title for Snake
     * @return Window title string
     */
    std::string getWindowTitle() const;

    static constexpr float DEFAULT_SPEED = 0.18f;
    static constexpr float SCORE_MULTIPLIER = 1.2f;
    static constexpr int FOOD_SPAWN_FREQUENCY = 1;
};

}

#endif // SNAKE_GAME_HPP_
