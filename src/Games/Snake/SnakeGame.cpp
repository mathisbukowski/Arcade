/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Snake game implementation
*/

#include "SnakeGame.hpp"
#include "IGameModule.hpp"
#include "Arcade.hpp"

namespace arcade {

    SnakeGame::SnakeGame(bool cyclical)
        : BaseSnakeGame(GameMode::Snake)
    {
        _isCyclical = cyclical;
        _speedIncreases = true;
        _hasWalls = false;
        _useTimeLimit = false;
        _state.setMoveInterval(DEFAULT_SPEED);
        _state.setGameOver(false);
    }

Vector<float> SnakeGame::adjustPosition(const Vector<float>& pos) const
{
    if (_isCyclical) {
        Vector<float> adjusted = pos;

        if (adjusted.getX() < 0) {
            adjusted.setX(static_cast<float>(_gridWidth) - 1);
        } else if (adjusted.getX() >= _gridWidth) {
            adjusted.setX(0);
        }

        if (adjusted.getY() < 0) {
            adjusted.setY(static_cast<float>(_gridHeight) - 1);
        } else if (adjusted.getY() >= _gridHeight) {
            adjusted.setY(0);
        }

        return adjusted;
    }
    return pos;
}

CollisionType SnakeGame::checkCollisions()
{
    if (_state.getSegments().empty())
        return CollisionType::None;

    Vector<float> head = _state.getHead();

    if (!_isCyclical && (head.getX() < 0 || head.getX() >= _gridWidth ||
                         head.getY() < 0 || head.getY() >= _gridHeight)) {
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
    _state.resizeGrid(_gridHeight, _gridWidth);

    for (size_t y = 0; y < _gridHeight; ++y) {
        for (size_t x = 0; x < _gridWidth; ++x)
            _state.setCellType(y, x, CellType::Empty);
    }
}

void SnakeGame::onGameOver()
{
    BaseSnakeGame::onGameOver();

    if (hasDisplayLibrary()) {
        try {
            int finalScore = _state.getScore();
            int length = static_cast<int>(_state.getLength());

            if (length > 10) {
                float multiplier = 1.0f + (length - 10) * 0.01f * SCORE_MULTIPLIER;
                finalScore = static_cast<int>(finalScore * multiplier);
                _state.setScore(finalScore);
            }
        } catch (const std::exception&) {
        }
    }
}

std::string SnakeGame::getWindowTitle() const
{
    std::string title = "Snake";

    if (_isCyclical)
        title += " (Cyclical)";

    title += " - Score: " + std::to_string(_state.getScore());
    title += " - Length: " + std::to_string(_state.getLength());

    return title;
}

void SnakeGame::update(float delta)
{
    BaseSnakeGame::update(delta);

    if (hasDisplayLibrary()) {
        try {
            auto& display = getDisplayLibrary().getDisplay();
            WindowProperties props("", 800, 600);
            display.setupWindowProperties(props);
            props.setTitle(getWindowTitle());
            display.setupWindowProperties(props);
        } catch (const std::exception&) {
        }
    }
}

extern "C" {
    arcade::IGameModule* entryPoint() {
        return new arcade::SnakeGame;
    }

    void destroy(arcade::IGameModule* game) {
        delete game;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::GAME;
    }

    std::string entryPointName() {
        return "Snake";
    }
}

}
