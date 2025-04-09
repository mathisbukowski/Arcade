/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** BaseSnakeGame
*/

#include "BaseSnakeGame.hpp"
#include "ITexture.hpp"
#include "IDisplayLibrary.hpp"
#include <iostream>
#include <filesystem>

namespace arcade {

BaseSnakeGame::GameState::GameState() :
    currentDirection(Direction::Right),
    nextDirection(Direction::Right),
    score(0),
    gameOver(false),
    moveTimer(0.0f),
    moveInterval(0.2f),
    bonusFoodTimer(0.0f),
    bonusFoodDuration(5.0f),
    level(1),
    timeRemaining(60.0f),
    mode(GameMode::Snake)
{
}

const std::deque<Vector<float>>& BaseSnakeGame::GameState::getSegments() const {
    return segments;
}

Direction BaseSnakeGame::GameState::getCurrentDirection() const {
    return currentDirection;
}

Direction BaseSnakeGame::GameState::getNextDirection() const {
    return nextDirection;
}

const std::vector<Vector<float>>& BaseSnakeGame::GameState::getBonusFoods() const {
    return bonusFoods;
}

const std::vector<std::vector<CellType>>& BaseSnakeGame::GameState::getGrid() const {
    return grid;
}

int BaseSnakeGame::GameState::getScore() const {
    return score;
}

bool BaseSnakeGame::GameState::isGameOver() const {
    return gameOver;
}

float BaseSnakeGame::GameState::getMoveTimer() const {
    return moveTimer;
}

float BaseSnakeGame::GameState::getMoveInterval() const {
    return moveInterval;
}

float BaseSnakeGame::GameState::getBonusFoodTimer() const {
    return bonusFoodTimer;
}

float BaseSnakeGame::GameState::getBonusFoodDuration() const {
    return bonusFoodDuration;
}

int BaseSnakeGame::GameState::getLevel() const {
    return level;
}

float BaseSnakeGame::GameState::getTimeRemaining() const {
    return timeRemaining;
}

const std::string& BaseSnakeGame::GameState::getPlayerName() const {
    return playerName;
}

GameMode BaseSnakeGame::GameState::getMode() const {
    return mode;
}

const std::vector<Vector<float>>& BaseSnakeGame::GameState::getFoods() const {
    return foods;
}

Vector<float> BaseSnakeGame::GameState::getHead() const {
    return segments.empty() ? Vector<float>(0, 0) : segments.front();
}

Vector<float> BaseSnakeGame::GameState::getTail() const {
    return segments.empty() ? Vector<float>(0, 0) : segments.back();
}

size_t BaseSnakeGame::GameState::getLength() const {
    return segments.size();
}

bool BaseSnakeGame::GameState::hasFoods() const {
    return !foods.empty();
}

bool BaseSnakeGame::GameState::hasBonusFoods() const {
    return !bonusFoods.empty();
}

void BaseSnakeGame::GameState::setCurrentDirection(Direction dir) {
    currentDirection = dir;
}

void BaseSnakeGame::GameState::setNextDirection(Direction dir) {
    nextDirection = dir;
}

void BaseSnakeGame::GameState::setScore(int newScore) {
    score = newScore;
}

void BaseSnakeGame::GameState::setGameOver(bool over) {
    gameOver = over;
}

void BaseSnakeGame::GameState::setMoveTimer(float timer) {
    moveTimer = timer;
}

void BaseSnakeGame::GameState::setMoveInterval(float interval) {
    moveInterval = interval;
}

void BaseSnakeGame::GameState::setBonusFoodTimer(float timer) {
    bonusFoodTimer = timer;
}

void BaseSnakeGame::GameState::setBonusFoodDuration(float duration) {
    bonusFoodDuration = duration;
}

void BaseSnakeGame::GameState::setLevel(int newLevel) {
    level = newLevel;
}

void BaseSnakeGame::GameState::setTimeRemaining(float time) {
    timeRemaining = time;
}

void BaseSnakeGame::GameState::setPlayerName(const std::string& name) {
    playerName = name;
}

void BaseSnakeGame::GameState::setMode(GameMode newMode) {
    mode = newMode;
}

void BaseSnakeGame::GameState::addSegment(const Vector<float>& segment) {
    segments.push_back(segment);
}

void BaseSnakeGame::GameState::prependSegment(const Vector<float>& segment) {
    segments.push_front(segment);
}

void BaseSnakeGame::GameState::removeLastSegment() {
    if (!segments.empty()) segments.pop_back();
}

void BaseSnakeGame::GameState::clearSegments() {
    segments.clear();
}

void BaseSnakeGame::GameState::addFood(const Vector<float>& food) {
    foods.push_back(food);
}

void BaseSnakeGame::GameState::removeFood(size_t index) {
    if (index < foods.size()) foods.erase(foods.begin() + index);
}

void BaseSnakeGame::GameState::clearFoods() {
    foods.clear();
}

void BaseSnakeGame::GameState::addBonusFood(const Vector<float>& food) {
    bonusFoods.push_back(food);
}

void BaseSnakeGame::GameState::removeBonusFood(size_t index) {
    if (index < bonusFoods.size()) bonusFoods.erase(bonusFoods.begin() + index);
}

void BaseSnakeGame::GameState::clearBonusFoods() {
    bonusFoods.clear();
}

void BaseSnakeGame::GameState::resizeGrid(size_t height, size_t width) {
    grid.resize(height, std::vector<CellType>(width, CellType::Empty));
}

void BaseSnakeGame::GameState::setCellType(size_t y, size_t x, CellType type) {
    if (y < grid.size() && x < grid[y].size())
        grid[y][x] = type;
}

void BaseSnakeGame::GameState::incrementScore(int points) {
    score += points;
}

void BaseSnakeGame::GameState::decrementTimeRemaining(float delta) {
    timeRemaining -= delta;
    if (timeRemaining < 0)
        timeRemaining = 0;
}

IDisplayLibrary& BaseSnakeGame::getDisplayLibrary() const {
    if (!displayLib.has_value())
        throw std::runtime_error("Display library not initialized");
    return displayLib->get();
}

bool BaseSnakeGame::hasDisplayLibrary() const noexcept {
    return displayLib.has_value();
}

BaseSnakeGame::BaseSnakeGame(GameMode mode)
    : displayLib(std::nullopt),
      rng(std::random_device()()),
      gridWidth(20),
      gridHeight(20),
      gridOffset(0, 0)
{
    if (mode == GameMode::Snake) {
        isCyclical = false;
        speedIncreases = true;
        hasWalls = false;
        useTimeLimit = false;
    } else {
        isCyclical = false;
        speedIncreases = true;
        hasWalls = true;
        useTimeLimit = true;
    }
    state.setMode(mode);
}

void BaseSnakeGame::init(std::shared_ptr<IDisplayLibrary> library) {
    try {
        displayLib = std::ref(*library);
        setupGame();
        loadTextures();
        loadSounds();
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to initialize game: " + std::string(e.what()));
    }
}

void BaseSnakeGame::setupGame() {
    initGrid();
    initSnake();
    spawnFood();
}

void BaseSnakeGame::loadTextures() {
    if (!hasDisplayLibrary())
        return;

    try {
        auto& textures = getDisplayLibrary().getTextures();
        loadBasicTextures(textures);

        if (hasWalls)
            loadWallTexture(textures);
    } catch (const std::exception& e) {
        std::cerr << "Error loading textures: " << e.what() << std::endl;
    }
}

void BaseSnakeGame::loadBasicTextures(ITextureManager& textures) {
    std::vector<std::pair<std::string, std::string>> texturesToLoad = {
        {"snake_head", "assets/snake/head.png"},
        {"snake_body", "assets/snake/body.png"},
        {"food", "assets/snake/food.png"},
        {"bonus_food", "assets/snake/bonus_food.png"}
    };

    for (const auto& [name, path] : texturesToLoad) {
        if (!std::filesystem::exists(path)) {
            std::cerr << "Warning: Texture file not found: " << path << std::endl;
            continue;
        }
        int id = textures.load(name, TextureImg(path));
        if (id < 0)
            std::cerr << "Failed to load texture: " << name << std::endl;
    }
}

void BaseSnakeGame::loadWallTexture(ITextureManager& textures) {
    int wallId = textures.load("wall", TextureImg("assets/snake/wall.png"));
    if (wallId < 0)
        std::cerr << "Failed to load wall texture" << std::endl;
}

void BaseSnakeGame::loadSounds() {
    if (!hasDisplayLibrary())
        return;

    try {
        auto& sounds = getDisplayLibrary().getSounds();
        int gameOverSoundId = sounds.load("game_over", SoundInfos("assets/sounds/game_over.wav"));
        int eatSoundId = sounds.load("eat", SoundInfos("assets/sounds/eat.wav"));
        int levelCompleteSoundId = sounds.load("level_complete", SoundInfos("assets/sounds/level_complete.wav"));

        if (gameOverSoundId < 0 || eatSoundId < 0 || levelCompleteSoundId < 0)
            std::cerr << "Warning: Some sounds failed to load" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error loading sounds: " << e.what() << std::endl;
    }
}

void BaseSnakeGame::initGrid() {
    state.resizeGrid(gridHeight, gridWidth);

    if (hasWalls && state.getMode() == GameMode::Nibbler) {
        for (size_t y = 0; y < gridHeight; ++y) {
            state.setCellType(y, 0, CellType::Wall);
            state.setCellType(y, gridWidth - 1, CellType::Wall);
        }
        for (size_t x = 0; x < gridWidth; ++x) {
            state.setCellType(0, x, CellType::Wall);
            state.setCellType(gridHeight - 1, x, CellType::Wall);
        }
        if (state.getLevel() == 1) {
            for (int y = 5; y < 10; ++y) {
                state.setCellType(y, 5, CellType::Wall);
                state.setCellType(y, 15, CellType::Wall);
            }
        }
    }
}

void BaseSnakeGame::initSnake() {
    state.clearSegments();

    int startX, startY;

    if (state.getMode() == GameMode::Snake) {
        startX = gridWidth / 2;
        startY = gridHeight / 2;
    } else {
        startX = gridWidth / 2;
        startY = gridHeight - 3;
    }
    state.setCurrentDirection(Direction::Right);
    state.setNextDirection(Direction::Right);
    state.prependSegment(Vector<float>(startX - 3, startY));
    state.prependSegment(Vector<float>(startX - 2, startY));
    state.prependSegment(Vector<float>(startX - 1, startY));
    state.prependSegment(Vector<float>(startX, startY));
    updateGrid();
}

bool BaseSnakeGame::spawnFood(bool isBonus) {
    auto emptyCells = findEmptyCells();

    if (emptyCells.empty()) {
        state.setGameOver(true);
        return false;
    }

    Vector<float> foodPos = chooseRandomCell(emptyCells);
    placeFood(foodPos, isBonus);

    return true;
}

std::vector<Vector<float>> BaseSnakeGame::findEmptyCells() {
    std::vector<Vector<float>> emptyCells;

    for (size_t y = 0; y < gridHeight; ++y) {
        for (size_t x = 0; x < gridWidth; ++x) {
            if (state.getGrid()[y][x] == CellType::Empty)
                emptyCells.emplace_back(static_cast<float>(x), static_cast<float>(y));
        }
    }
    return emptyCells;
}

Vector<float> BaseSnakeGame::chooseRandomCell(const std::vector<Vector<float>>& cells) {
    std::uniform_int_distribution<size_t> dist(0, cells.size() - 1);
    return cells[dist(rng)];
}

void BaseSnakeGame::placeFood(const Vector<float>& pos, bool isBonus) {
    size_t y = static_cast<size_t>(pos.getY());
    size_t x = static_cast<size_t>(pos.getX());

    if (isBonus) {
        state.addBonusFood(pos);
        state.setCellType(y, x, CellType::BonusFood);
    } else {
        state.addFood(pos);
        state.setCellType(y, x, CellType::Food);
    }
}

void BaseSnakeGame::trySpawnBonusFood() {
    if (state.getBonusFoods().empty() && (std::uniform_int_distribution<int>(1, BONUS_FOOD_CHANCE)(rng) == 1)) {
        spawnFood(true);
        state.setBonusFoodTimer(state.getBonusFoodDuration());
    }
}

void BaseSnakeGame::updateGrid() {
    auto grid = state.getGrid();
    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[y].size(); ++x) {
            if (grid[y][x] != CellType::Wall)
                state.setCellType(y, x, CellType::Empty);
        }
    }
    const auto& segments = state.getSegments();
    if (!segments.empty()) {
        Vector<float> head = segments.front();
        if (isInBounds(head))
            state.setCellType(static_cast<size_t>(head.getY()), static_cast<size_t>(head.getX()), CellType::SnakeHead);
        for (size_t i = 1; i < segments.size(); ++i) {
            Vector<float> segment = segments[i];
            if (isInBounds(segment))
                state.setCellType(static_cast<size_t>(segment.getY()), static_cast<size_t>(segment.getX()), CellType::Snake);
        }
    }
    for (const auto& food : state.getFoods()) {
        if (isInBounds(food))
            state.setCellType(static_cast<size_t>(food.getY()), static_cast<size_t>(food.getX()), CellType::Food);
    }
    for (const auto& bonusFood : state.getBonusFoods()) {
        if (isInBounds(bonusFood))
            state.setCellType(static_cast<size_t>(bonusFood.getY()), static_cast<size_t>(bonusFood.getX()), CellType::BonusFood);
    }
}

bool BaseSnakeGame::isInBounds(const Vector<float>& pos) const {
    return pos.getX() >= 0 && pos.getX() < gridWidth &&
           pos.getY() >= 0 && pos.getY() < gridHeight;
}

void BaseSnakeGame::handleInput() {
    if (!hasDisplayLibrary())
        return;

    try {
        auto& keyboard = getDisplayLibrary().getDisplay().getKeyboard();
        Direction currentDirection = state.getCurrentDirection();
        Direction nextDirection = state.getNextDirection();

        if (keyboard.isKeyPressed(Keyboard::KeyCode::UP) && currentDirection != Direction::Down) {
            nextDirection = Direction::Up;
        }
        else if (keyboard.isKeyPressed(Keyboard::KeyCode::RIGHT) && currentDirection != Direction::Left) {
            nextDirection = Direction::Right;
        }
        else if (keyboard.isKeyPressed(Keyboard::KeyCode::DOWN) && currentDirection != Direction::Up) {
            nextDirection = Direction::Down;
        }
        else if (keyboard.isKeyPressed(Keyboard::KeyCode::LEFT) && currentDirection != Direction::Right) {
            nextDirection = Direction::Left;
        }
        state.setNextDirection(nextDirection);

        float targetInterval = NORMAL_SPEED;
        if (keyboard.isKeyPressed(Keyboard::KeyCode::KEY_1))
            targetInterval = BOOST_SPEED;

        state.setMoveInterval(targetInterval);
    } catch (const std::exception& e) {
        std::cerr << "Error handling input: " << e.what() << std::endl;
    }
}

void BaseSnakeGame::moveSnake(float delta) {
    float moveTimer = state.getMoveTimer() + delta;
    state.setMoveTimer(moveTimer);

    if (moveTimer >= state.getMoveInterval()) {
        state.setMoveTimer(0);
        if (!areOppositeDirections(state.getCurrentDirection(), state.getNextDirection()))
            state.setCurrentDirection(state.getNextDirection());

        Vector<float> newHead = calculateNewHeadPosition();
        moveSnakeSegments(newHead);
        updateGrid();

        CollisionType collision = checkCollisions();
        handleCollision(collision);
    }
}

Vector<float> BaseSnakeGame::calculateNewHeadPosition() {
    Vector<float> head = state.getHead();
    Vector<float> movement = directionToVector(state.getCurrentDirection());
    Vector<float> newHead(head.getX() + movement.getX(), head.getY() + movement.getY());
    return adjustPosition(newHead);
}

void BaseSnakeGame::moveSnakeSegments(const Vector<float>& newHead) {
    state.prependSegment(newHead);
    state.removeLastSegment();
}

Vector<float> BaseSnakeGame::directionToVector(Direction dir) const {
    switch (dir) {
        case Direction::Up:
            return Vector<float>(0, -1);
        case Direction::Right:
            return Vector<float>(1, 0);
        case Direction::Down:
            return Vector<float>(0, 1);
        case Direction::Left:
            return Vector<float>(-1, 0);
        default:
            return Vector<float>(0, 0);
    }
}

bool BaseSnakeGame::areOppositeDirections(Direction dir1, Direction dir2) const {
    return (dir1 == Direction::Up && dir2 == Direction::Down) ||
           (dir1 == Direction::Down && dir2 == Direction::Up) ||
           (dir1 == Direction::Left && dir2 == Direction::Right) ||
           (dir1 == Direction::Right && dir2 == Direction::Left);
}

Vector<float> BaseSnakeGame::adjustPosition(const Vector<float>& pos) const {
    if (!isCyclical)
        return pos;

    Vector<float> adjusted = pos;

    if (adjusted.getX() < 0) {
        adjusted.setX(gridWidth - 1);
    } else if (adjusted.getX() >= gridWidth) {
        adjusted.setX(0);
    }
    if (adjusted.getY() < 0) {
        adjusted.setY(gridHeight - 1);
    } else if (adjusted.getY() >= gridHeight) {
        adjusted.setY(0);
    }
    return adjusted;
}

CellType BaseSnakeGame::checkCell(const Vector<float>& pos) const {
    if (!isInBounds(pos))
        return CellType::OutOfBounds;
    return state.getGrid()[static_cast<size_t>(pos.getY())][static_cast<size_t>(pos.getX())];
}

CollisionType BaseSnakeGame::checkCollisions() {
    if (state.getSegments().empty())
        return CollisionType::None;

    Vector<float> head = state.getHead();

    if (!isCyclical && !isInBounds(head))
        return CollisionType::Wall;
    const auto& segments = state.getSegments();
    for (size_t i = 1; i < segments.size(); ++i) {
        if (head.getX() == segments[i].getX() && head.getY() == segments[i].getY()) {
            return CollisionType::Self;
        }
    }

    CellType cellType = checkCell(head);
    switch (cellType) {
        case CellType::Wall:
            return CollisionType::Wall;
        case CellType::Food:
            return CollisionType::Food;
        case CellType::BonusFood:
            return CollisionType::BonusFood;
        default:
            return CollisionType::None;
    }
}

void BaseSnakeGame::handleCollision(CollisionType collisionType) {
    switch (collisionType) {
        case CollisionType::Wall:
            handleWallCollision();
            break;
        case CollisionType::Self:
            handleSelfCollision();
            break;
        case CollisionType::Food:
            handleFoodCollision();
            break;
        case CollisionType::BonusFood:
            handleBonusFoodCollision();
            break;
        default:
            break;
    }
}

void BaseSnakeGame::handleWallCollision() {
    if (state.getMode() == GameMode::Snake || !hasWalls) {
        state.setGameOver(true);
        onGameOver();
    }
}

void BaseSnakeGame::handleSelfCollision() {
    state.setGameOver(true);
    onGameOver();
}

void BaseSnakeGame::handleFoodCollision() {
    growSnake();
    state.incrementScore(REGULAR_SCORE);
    playSound("eat", 100.0f);
    removeCollidedFood();
    spawnFood();
    trySpawnBonusFood();
}

void BaseSnakeGame::removeCollidedFood() {
    Vector<float> head = state.getHead();
    const auto& foods = state.getFoods();

    for (size_t i = 0; i < foods.size(); ++i) {
        if (foods[i].getX() == head.getX() && foods[i].getY() == head.getY()) {
            state.removeFood(i);
            break;
        }
    }
}

void BaseSnakeGame::handleBonusFoodCollision() {
    growSnake();
    state.incrementScore(BONUS_SCORE);
    playSound("eat", 100.0f);

    Vector<float> head = state.getHead();
    const auto& bonusFoods = state.getBonusFoods();

    for (size_t i = 0; i < bonusFoods.size(); ++i) {
        if (bonusFoods[i].getX() == head.getX() && bonusFoods[i].getY() == head.getY()) {
            state.removeBonusFood(i);
            break;
        }
    }
}

void BaseSnakeGame::growSnake() {
    Vector<float> tail = state.getTail();
    Vector<float> newTail = findFreeCellNear(tail);
    state.addSegment(newTail);
}

Vector<float> BaseSnakeGame::findFreeCellNear(const Vector<float>& pos) const {
    std::vector<Vector<float>> directions = {
        Vector<float>(0, -1),
        Vector<float>(1, 0),
        Vector<float>(0, 1),
        Vector<float>(-1, 0)
    };

    for (const auto& dir : directions) {
        Vector<float> newPos(pos.getX() + dir.getX(), pos.getY() + dir.getY());
        newPos = adjustPosition(newPos);
        if (isCellFree(newPos))
            return newPos;
    }
    return pos;
}

bool BaseSnakeGame::isCellFree(const Vector<float>& pos) const {
    CellType cellType = checkCell(pos);
    return cellType == CellType::Empty;
}

void BaseSnakeGame::update(float delta) {
    static bool firstUpdate = true;

    if (firstUpdate)
        firstUpdate = false;
    if (!hasDisplayLibrary() || state.isGameOver())
        return;

    handleInput();
    moveSnake(delta);
    updateBonusFood(delta);
    updateTimeLimit(delta);
    checkLevelCompletion();
}

void BaseSnakeGame::updateBonusFood(float delta) {
    if (!state.getBonusFoods().empty()) {
        float bonusFoodTimer = state.getBonusFoodTimer() - delta;
        state.setBonusFoodTimer(bonusFoodTimer);
        if (bonusFoodTimer <= 0.0f) {
            state.clearBonusFoods();
            updateGrid();
        }
    }
}

void BaseSnakeGame::updateTimeLimit(float delta) {
    if (useTimeLimit && state.getMode() == GameMode::Nibbler) {
        state.decrementTimeRemaining(delta);
        if (state.getTimeRemaining() <= 0.0f) {
            state.setGameOver(true);
            onGameOver();
        }
    }
}

void BaseSnakeGame::checkLevelCompletion() {
    if (state.getMode() == GameMode::Nibbler && !state.hasFoods())
        onLevelComplete();
}

void BaseSnakeGame::display() {
    if (!hasDisplayLibrary()) {
        std::cerr << "No display library available!" << std::endl;
        return;
    }

    try {
        auto& library = getDisplayLibrary();
        auto& display = library.getDisplay();
        auto& textures = library.getTextures();

        display.clearWindow(Color(0, 0, 0));
        Vector<float> screenSize = getScreenSize(display);
        drawGrid(display, textures, screenSize);
        drawUI(display, textures, screenSize);
    } catch (const std::exception& e) {
        std::cerr << "Error in display: " << e.what() << std::endl;
    }
}

Vector<float> BaseSnakeGame::getScreenSize(IDisplayModule& display) {
    WindowProperties props("", 800, 600);
    display.setupWindowProperties(props);

    float windowWidth = props.getWidth();
    float windowHeight = props.getHeight();
    gridOffset = Vector<float>(0, 0);
    return Vector<float>(windowWidth, windowHeight);
}

void BaseSnakeGame::drawGrid(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize) {
    float cellWidth = screenSize.getX() / gridWidth;
    float cellHeight = screenSize.getY() / gridHeight;

    drawBackground(textures, display);

    const auto& grid = state.getGrid();
    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[y].size(); ++x) {
            Vector<float> pos(x * cellWidth, y * cellHeight);
            drawBorderIfNeeded(x, y, textures, display, pos);
            drawCell(display, textures, grid[y][x], pos);
        }
    }
}

void BaseSnakeGame::drawBackground(ITextureManager& textures, IDisplayModule& display) {
    auto bgColor = MyTexture(TextureText("", Color(20, 20, 20)));
    int bgId = textures.load("grid_bg", bgColor);

    if (bgId >= 0) {
        auto bgTexture = textures.get("grid_bg");
        display.drawTexture(bgTexture, Vector<float>(0, 0));
    }
}

void BaseSnakeGame::drawBorderIfNeeded(size_t x, size_t y, ITextureManager& textures, IDisplayModule& display, const Vector<float>& pos) {
    if (x == 0 || x == gridWidth - 1 || y == 0 || y == gridHeight - 1) {
        auto borderColor = MyTexture(TextureText("", Color(50, 50, 50)));
        int borderResult = textures.load("border_" + std::to_string(y * gridWidth + x), borderColor);
        if (borderResult >= 0) {
            auto borderTexture = textures.get("border_" + std::to_string(y * gridWidth + x));
            display.drawTexture(borderTexture, pos);
        }
    }
}

void BaseSnakeGame::drawCell(IDisplayModule& display, ITextureManager& textures, CellType cellType, const Vector<float>& pos) {
    if (cellType == CellType::Empty)
        return;

    std::string textureName;
    Vector<float> screenSize = getScreenSize(display);
    float cellWidth = screenSize.getX() / gridWidth;
    float cellHeight = screenSize.getY() / gridHeight;
    float elementWidth, elementHeight, offsetX, offsetY;
    getElementDimensions(cellType, cellWidth, cellHeight, elementWidth, elementHeight, offsetX, offsetY);
    Vector<float> adjustedPos(pos.getX() + offsetX, pos.getY() + offsetY);

    textureName = getTextureNameForCell(cellType);
    if (textureName.empty())
        return;

    try {
        auto texture = getOrLoadTexture(textures, textureName);
        if (!texture)
            return;
        updateTextureRect(texture, adjustedPos, elementWidth, elementHeight);
        display.drawTexture(texture, adjustedPos);
    } catch (const std::exception& e) {
        std::cerr << "Failed to draw texture '" << textureName << "': " << e.what() << std::endl;
    }
}

void BaseSnakeGame::getElementDimensions(CellType cellType, float cellWidth, float cellHeight, float &elementWidth, float &elementHeight, float &offsetX, float &offsetY) {
    if (cellType == CellType::SnakeHead || cellType == CellType::Snake) {
        elementWidth = cellWidth;
        elementHeight = cellHeight;
        offsetX = 0;
        offsetY = 0;
    } else {
        elementWidth = cellWidth * 0.7f;
        elementHeight = cellHeight * 0.7f;
        offsetX = (cellWidth - elementWidth) / 2;
        offsetY = (cellHeight - elementHeight) / 2;
    }
}

std::string BaseSnakeGame::getTextureNameForCell(CellType cellType) {
    switch (cellType) {
        case CellType::SnakeHead:
            return "snake_head";
        case CellType::Snake:
            return "snake_body";
        case CellType::Food:
            return "food";
        case CellType::BonusFood:
            return "bonus_food";
        case CellType::Wall:
            return hasWalls ? "wall" : "";
        default:
            return "";
    }
}

std::shared_ptr<ITexture> BaseSnakeGame::getOrLoadTexture(ITextureManager& textures, const std::string& textureName) {
    auto texture = textures.get(textureName);
    if (!texture) {
        TextureImg newTexture(textureName + ".png");
        int result = textures.load(textureName, newTexture);
        if (result < 0) {
            std::cerr << "Failed to load texture: " << textureName << std::endl;
            return nullptr;
        }
        texture = textures.get(textureName);
        if (!texture) {
            std::cerr << "Texture still not available after loading: " << textureName << std::endl;
            return nullptr;
        }
    }
    return texture;
}

void BaseSnakeGame::updateTextureRect(std::shared_ptr<ITexture> texture, const Vector<float>& pos, float width, float height) {
    Rect textureRect(pos, width, height);
    MyTexture textureInfo = texture->getInformations();

    if (std::holds_alternative<TextureImg>(textureInfo)) {
        TextureImg& img = std::get<TextureImg>(textureInfo);
        img.setRect(std::optional<Rect>(textureRect));
        texture->set(textureInfo);
    } else if (std::holds_alternative<TextureText>(textureInfo)) {
        TextureText& text = std::get<TextureText>(textureInfo);
        text.setRect(std::optional<Rect>(textureRect));
        texture->set(textureInfo);
    }
}

void BaseSnakeGame::drawUI(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize) {
    drawScore(display, textures, screenSize);

    if (useTimeLimit && state.getMode() == GameMode::Nibbler)
        drawTimeRemaining(display, textures, screenSize);

    if (state.isGameOver())
        drawGameOver(display, textures, screenSize);
}

void BaseSnakeGame::drawScore(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize) {
    std::string scoreText = "Score: " + std::to_string(state.getScore());
    TextureText scoreTextureText(scoreText, Color(255, 255, 255));
    MyTexture scoreTexture = scoreTextureText;

    int scoreTextId = textures.load("score_text", scoreTexture);
    if (scoreTextId >= 0) {
        auto texture = textures.get("score_text");
        display.drawTexture(texture, Vector<float>(10, screenSize.getY() - 30));
    }
}

void BaseSnakeGame::drawTimeRemaining(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize) {
    std::string timeText = "Time: " + std::to_string(static_cast<int>(state.getTimeRemaining()));
    TextureText timeTextureText(timeText, Color(255, 255, 255));
    MyTexture timeTexture = timeTextureText;

    int timeTextId = textures.load("time_text", timeTexture);
    if (timeTextId >= 0) {
        auto texture = textures.get("time_text");
        display.drawTexture(texture, Vector<float>(screenSize.getX() - 100, screenSize.getY() - 30));
    }
}

void BaseSnakeGame::drawGameOver(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize) {
    std::string gameOverText = "GAME OVER - Press ESC to return to menu";
    TextureText gameOverTextureText(gameOverText, Color(255, 0, 0));
    MyTexture gameOverTexture = gameOverTextureText;

    int gameOverTextId = textures.load("gameover_text", gameOverTexture);
    if (gameOverTextId >= 0) {
        auto texture = textures.get("gameover_text");
        Vector<float> textPos((screenSize.getX() - gameOverText.length() * 8) / 2, screenSize.getY() / 2);
        display.drawTexture(texture, textPos);
    }
}

void BaseSnakeGame::onLevelComplete() {
    playSound("level_complete", 100.0f);
    state.setLevel(state.getLevel() + 1);

    if (useTimeLimit)
        state.setTimeRemaining(DEFAULT_TIME_LIMIT);

    initGrid();

    if (state.getMode() == GameMode::Nibbler)
        initSnake();

    spawnFood();
}

void BaseSnakeGame::onGameOver() {
    playSound("game_over", 100.0f);
}

void BaseSnakeGame::playSound(const std::string& soundName, float volume) {
    if (hasDisplayLibrary()) {
        try {
            auto& sounds = getDisplayLibrary().getSounds();
            sounds.playSound(soundName, volume);
        } catch (const std::exception& e) {
            std::cerr << "Exception playing sound " << soundName << ": " << e.what() << std::endl;
        }
    }
}

void BaseSnakeGame::stop() {}

void BaseSnakeGame::setPlayerName(const std::string& name) {
    state.setPlayerName(name);
}

std::string BaseSnakeGame::getPlayerName() const {
    return state.getPlayerName();
}

int BaseSnakeGame::getScore() const {
    return state.getScore();
}

}
