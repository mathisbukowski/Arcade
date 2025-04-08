/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Nibbler game implementation
*/

#include "NibblerGame.hpp"
#include <algorithm>

namespace arcade {

NibblerGame::NibblerGame()
    : BaseSnakeGame(GameMode::Nibbler),
      _levelManager("assets/nibbler/levels.txt")
{
    isCyclical = false;
    speedIncreases = true;
    hasWalls = true;
    useTimeLimit = true;
    state.setMoveInterval(DEFAULT_SPEED);
    loadLevel(state.getLevel());
}

void NibblerGame::initGrid()
{
    state.resizeGrid(gridHeight, gridWidth);

    for (size_t y = 0; y < gridHeight; ++y) {
        for (size_t x = 0; x < gridWidth; ++x)
            state.setCellType(y, x, CellType::Empty);
    }
    loadLevel(state.getLevel());
}

void NibblerGame::loadLevel(int level)
{
    std::vector<std::string> layout = _levelManager.getLevel(level);

    for (size_t y = 0; y < layout.size() && y < gridHeight; ++y) {
        const std::string& row = layout[y];
        for (size_t x = 0; x < row.length() && x < gridWidth; ++x) {
            if (row[x] == '#')
                state.setCellType(y, x, CellType::Wall);
        }
    }
    float timeLimit = BASE_TIME_LIMIT + (level - 1) * 10.0f;
    state.setTimeRemaining(timeLimit);
    float speed = DEFAULT_SPEED - (level - 1) * LEVEL_SPEED_INCREASE;
    speed = std::max(0.05f, speed);
    state.setMoveInterval(speed);
}

CollisionType NibblerGame::checkCollisions()
{
    if (state.getSegments().empty())
        return CollisionType::None;

    Vector<float> head = state.getHead();

    if (head.getX() < 0 || head.getX() >= gridWidth ||
        head.getY() < 0 || head.getY() >= gridHeight)
        return CollisionType::Wall;

    CellType cellType = checkCell(head);

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
    Direction currentDir = state.getCurrentDirection();

    if (isTjunction(currentPosition))
        return currentDir;

    std::vector<Direction> availableDirections = getAvailableDirections(currentPosition);

    availableDirections.erase(
        std::remove_if(availableDirections.begin(), availableDirections.end(),
            [this, currentDir](Direction dir) {
                return areOppositeDirections(dir, currentDir);
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

    if (checkCell(posUp) != CellType::Wall && checkCell(posUp) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Up);
    if (checkCell(posRight) != CellType::Wall && checkCell(posRight) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Right);
    if (checkCell(posDown) != CellType::Wall && checkCell(posDown) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Down);
    if (checkCell(posLeft) != CellType::Wall && checkCell(posLeft) != CellType::OutOfBounds)
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

    if (checkCell(posUp) != CellType::Wall && checkCell(posUp) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Up);
    if (checkCell(posRight) != CellType::Wall && checkCell(posRight) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Right);
    if (checkCell(posDown) != CellType::Wall && checkCell(posDown) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Down);
    if (checkCell(posLeft) != CellType::Wall && checkCell(posLeft) != CellType::OutOfBounds)
        availableDirections.push_back(Direction::Left);
    return availableDirections.size() >= 3;
}

void NibblerGame::update(float delta)
{
    if (!state.isGameOver()) {
        Vector<float> head = state.getHead();
        Direction newDirection = handleAutomaticTurns(head);
        if (newDirection != state.getCurrentDirection() &&
            !areOppositeDirections(newDirection, state.getCurrentDirection())) {
            state.setNextDirection(newDirection);
        }
    }
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

void NibblerGame::onLevelComplete()
{
    int currentLevel = state.getLevel();
    int newLevel = std::min(currentLevel + 1, MAX_LEVEL);

    state.setLevel(newLevel);
    initGrid();
    initSnake();
    spawnFood();
    int remainingFood = state.getFoods().size();
    state.setTimeRemaining(BASE_TIME_LIMIT + remainingFood * TIME_BONUS_PER_FOOD);
    state.incrementScore(1000);
    if (newLevel == MAX_LEVEL)
        state.incrementScore(5000);
}

void NibblerGame::onGameOver()
{
    BaseSnakeGame::onGameOver();
    int levelBonus = (state.getLevel() - 1) * 500;
    state.incrementScore(levelBonus);
    int timeBonus = static_cast<int>(state.getTimeRemaining() * 10);
    state.incrementScore(timeBonus);
}

std::string NibblerGame::getWindowTitle() const
{
    std::string title = "Nibbler";
    title += " - Level: " + std::to_string(state.getLevel());
    title += " - Score: " + std::to_string(state.getScore());
    title += " - Time: " + std::to_string(static_cast<int>(state.getTimeRemaining()));
    return title;
}

}
