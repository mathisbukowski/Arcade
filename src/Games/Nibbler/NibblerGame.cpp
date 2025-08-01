/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Nibbler game implementation
*/

#include "NibblerGame.hpp"
#include "Arcade.hpp"
#include <algorithm>

namespace arcade {

NibblerGame::NibblerGame()
    : BaseSnakeGame(GameMode::Nibbler),
      _levelManager("assets/nibbler/levels.txt")
{
    _isCyclical = false;
    _speedIncreases = true;
    _hasWalls = true;
    _useTimeLimit = true;
    _state.setMoveInterval(DEFAULT_SPEED);
    this->loadLevel(_state.getLevel());
    _state.setGameOver(false);
}

void NibblerGame::initGrid()
{
    _state.resizeGrid(_gridHeight, _gridWidth);

    for (size_t y = 0; y < _gridHeight; ++y) {
        for (size_t x = 0; x < _gridWidth; ++x)
            _state.setCellType(y, x, CellType::Empty);
    }
    this->loadLevel(_state.getLevel());
}

void NibblerGame::loadLevel(int level)
{
    _state.resizeGrid(_gridHeight, _gridWidth);
    for (size_t y = 0; y <= _gridHeight; ++y) {
        for (size_t x = 0; x <= _gridWidth; ++x)
            _state.setCellType(y, x, CellType::Empty);
    }
    std::vector<std::string> layout = _levelManager.getLevel(level);
    float scaleY = static_cast<float>(_gridHeight) / layout.size();
    float scaleX = static_cast<float>(_gridWidth) / layout[0].length();

    for (size_t y = 0; y < layout.size(); ++y) {
        const std::string& row = layout[y];
        for (size_t x = 0; x < row.length(); ++x) {
            size_t scaledY = static_cast<size_t>(y * scaleY);
            size_t scaledX = static_cast<size_t>(x * scaleX);

            if (scaledY < _gridHeight && scaledX < _gridWidth && row[x] == '#') {
                _state.setCellType(scaledY, scaledX, CellType::Wall);
            }
        }
    }
    float timeLimit = BASE_TIME_LIMIT + (level - 1) * 10.0f;
    _state.setTimeRemaining(timeLimit);
    float speed = DEFAULT_SPEED - (level - 1) * LEVEL_SPEED_INCREASE;
    speed = std::max(0.05f, speed);
    _state.setMoveInterval(speed);
}

CollisionType NibblerGame::checkCollisions()
{
    if (_state.getSegments().empty())
        return CollisionType::None;

    Vector<float> head = _state.getHead();

    if (head.getX() < 0 || head.getX() >= _gridWidth ||
        head.getY() < 0 || head.getY() >= _gridHeight)
        return CollisionType::Wall;

    CellType cellType = this->checkCell(head);

    switch (cellType) {
        case CellType::Wall:
            return CollisionType::Wall;
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

Direction NibblerGame::handleAutomaticTurns(const Vector<float>& currentPosition)
{
    Direction currentDir = _state.getCurrentDirection();

    if (this->isTjunction(currentPosition))
        return currentDir;

    std::vector<Direction> availableDirections = this->getAvailableDirections(currentPosition);

    availableDirections.erase(
        std::remove_if(availableDirections.begin(), availableDirections.end(),
            [this, currentDir](Direction dir) {
                return this->areOppositeDirections(dir, currentDir);
            }),
        availableDirections.end()
    );
    if (std::find(availableDirections.begin(), availableDirections.end(), currentDir) != availableDirections.end())
        return currentDir;
    if (!availableDirections.empty()) {
        for (Direction dir : availableDirections) {
            if (currentDir == Direction::Right && dir == Direction::Up) return dir;
            if (currentDir == Direction::Right && dir == Direction::Down) return dir;
            if (currentDir == Direction::Left && dir == Direction::Up) return dir;
            if (currentDir == Direction::Left && dir == Direction::Down) return dir;
            if (currentDir == Direction::Up && dir == Direction::Left) return dir;
            if (currentDir == Direction::Up && dir == Direction::Right) return dir;
            if (currentDir == Direction::Down && dir == Direction::Left) return dir;
            if (currentDir == Direction::Down && dir == Direction::Right) return dir;
        }
        return availableDirections.front();
    }
    return currentDir;
}

std::vector<Direction> NibblerGame::getAvailableDirections(const Vector<float>& position) const
{
    std::vector<Direction> availableDirections;

    Vector<float> posUp(position.getX(), position.getY() - 1);
    Vector<float> posRight(position.getX() + 1, position.getY());
    Vector<float> posDown(position.getX(), position.getY() + 1);
    Vector<float> posLeft(position.getX() - 1, position.getY());

    if (this->checkCell(posUp) != CellType::Wall && this->checkCell(posUp) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Up);
    if (this->checkCell(posRight) != CellType::Wall && this->checkCell(posRight) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Right);
    if (this->checkCell(posDown) != CellType::Wall && this->checkCell(posDown) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Down);
    if (this->checkCell(posLeft) != CellType::Wall && this->checkCell(posLeft) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Left);
    return availableDirections;
}

bool NibblerGame::isTjunction(const Vector<float>& position) const
{
    std::vector<Direction> availableDirections;
    Vector<float> posUp(position.getX(), position.getY() - 1);
    Vector<float> posRight(position.getX() + 1, position.getY());
    Vector<float> posDown(position.getX(), position.getY() + 1);
    Vector<float> posLeft(position.getX() - 1, position.getY());

    if (this->checkCell(posUp) != CellType::Wall && this->checkCell(posUp) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Up);
    if (this->checkCell(posRight) != CellType::Wall && this->checkCell(posRight) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Right);
    if (this->checkCell(posDown) != CellType::Wall && this->checkCell(posDown) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Down);
    if (this->checkCell(posLeft) != CellType::Wall && this->checkCell(posLeft) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Left);
    return availableDirections.size() >= 3;
}

void NibblerGame::update(float delta)
{
    if (!_state.isGameOver()) {
        Vector<float> head = _state.getHead();
        Direction newDirection = this->handleAutomaticTurns(head);
        if (newDirection != _state.getCurrentDirection() &&
            !this->areOppositeDirections(newDirection, _state.getCurrentDirection())) {
            _state.setNextDirection(newDirection);
        }
    }
    BaseSnakeGame::update(delta);
    if (this->hasDisplayLibrary()) {
        try {
            auto& display = this->getDisplayLibrary().getDisplay();
            WindowProperties props("", 800, 600);
            display.setupWindowProperties(props);
            props.setTitle(this->getWindowTitle());
            display.setupWindowProperties(props);
        } catch (const std::exception&) {
        }
    }
}

void NibblerGame::onLevelComplete()
{
    int currentLevel = _state.getLevel();
    int newLevel = std::min(currentLevel + 1, MAX_LEVEL);

    _state.setLevel(newLevel);
    this->initGrid();
    this->initSnake();
    this->spawnFood();
    int remainingFood = _state.getFoods().size();
    _state.setTimeRemaining(BASE_TIME_LIMIT + remainingFood * TIME_BONUS_PER_FOOD);
    _state.incrementScore(1000);
    if (newLevel == MAX_LEVEL)
        _state.incrementScore(5000);
}

void NibblerGame::onGameOver()
{
    BaseSnakeGame::onGameOver();
    int levelBonus = (_state.getLevel() - 1) * 500;
    _state.incrementScore(levelBonus);
    int timeBonus = static_cast<int>(_state.getTimeRemaining() * 10);
    _state.incrementScore(timeBonus);
}

std::string NibblerGame::getWindowTitle() const
{
    std::string title = "Nibbler";
    title += " - Level: " + std::to_string(_state.getLevel());
    title += " - Score: " + std::to_string(_state.getScore());
    title += " - Time: " + std::to_string(static_cast<int>(_state.getTimeRemaining()));
    return title;
}

extern "C" {
    arcade::IGameModule* entryPoint() {
        return new arcade::NibblerGame;
    }

    void destroy(arcade::IGameModule* game) {
        delete game;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::GAME;
    }

    std::string entryPointName() {
        return "Nibbler";
    }
}


}
