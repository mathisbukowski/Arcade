/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Snake game implementation
*/

#include "SnakeGame.hpp"

namespace arcade {

SnakeGame::SnakeGame(bool cyclical)
    : BaseSnakeGame(GameMode::Snake)
{
    isCyclical = cyclical;
    speedIncreases = true;
    hasWalls = false;
    useTimeLimit = false;
    state.setMoveInterval(DEFAULT_SPEED);
}

Vector<float> SnakeGame::adjustPosition(const Vector<float>& pos) const
{
    if (isCyclical) {
        Vector<float> adjusted = pos;

        if (adjusted.getX() < 0) {
            adjusted.setX(static_cast<float>(gridWidth) - 1);
        } else if (adjusted.getX() >= gridWidth) {
            adjusted.setX(0);
        }

        if (adjusted.getY() < 0) {
            adjusted.setY(static_cast<float>(gridHeight) - 1);
        } else if (adjusted.getY() >= gridHeight) {
            adjusted.setY(0);
        }

        return adjusted;
    }
    return pos;
}

CollisionType SnakeGame::checkCollisions()
{
    if (state.getSegments().empty())
        return CollisionType::None;

    Vector<float> head = state.getHead();

    if (!isCyclical && (head.getX() < 0 || head.getX() >= gridWidth ||
                         head.getY() < 0 || head.getY() >= gridHeight)) {
        return CollisionType::Wall;
    }

    CellType cellType = checkCell(head);

    switch (cellType) {
        case CellType::Snake:
            return CollisionType::Self;
        case CellType::Food:
            return CollisionType::Food;
        case CellType::BonusFood:
            return CollisionType::BonusFood;
        default:
            return CollisionType::None;
    }
}

void SnakeGame::initGrid()
{
    state.resizeGrid(gridHeight, gridWidth);

    for (size_t y = 0; y < gridHeight; ++y) {
        for (size_t x = 0; x < gridWidth; ++x)
            state.setCellType(y, x, CellType::Empty);
    }
}

void SnakeGame::onGameOver()
{
    BaseSnakeGame::onGameOver();

    if (hasDisplayLibrary()) {
        try {
            int finalScore = state.getScore();
            int length = static_cast<int>(state.getLength());

            if (length > 10) {
                float multiplier = 1.0f + (length - 10) * 0.01f * SCORE_MULTIPLIER;
                finalScore = static_cast<int>(finalScore * multiplier);
                state.setScore(finalScore);
            }
        } catch (const std::exception&) {
        }
    }
}

std::string SnakeGame::getWindowTitle() const
{
    std::string title = "Snake";

    if (isCyclical)
        title += " (Cyclical)";

    title += " - Score: " + std::to_string(state.getScore());
    title += " - Length: " + std::to_string(state.getLength());

    return title;
}

void SnakeGame::update(float delta)
{
    BaseSnakeGame::update(delta);

    if (hasDisplayLibrary()) {
        try {
            auto& display = getDisplayLibrary().getDisplay();
            WindowProperties props("", 400, 400);
            display.setupWindowProperties(props);
            props.setTitle(getWindowTitle());
            display.setupWindowProperties(props);
        } catch (const std::exception&) {
        }
    }
}

}
