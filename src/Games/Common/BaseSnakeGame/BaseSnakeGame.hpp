/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Base class
*/

#ifndef BASE_SNAKE_GAME_HPP_
#define BASE_SNAKE_GAME_HPP_

#include "IGameModule.hpp"
#include "Vector.hpp"
#include <vector>
#include <deque>
#include <random>
#include <memory>
#include <optional>
#include <functional>
#include <stdexcept>
#include <string>

namespace arcade
{
    enum class CellType {
        Empty,
        Snake,
        SnakeHead,
        Food,
        BonusFood,
        Wall,
        OutOfBounds
    };
    enum class Direction {
        Up,
        Right,
        Down,
        Left
    };
    enum class CollisionType {
        None,
        Wall,
        Self,
        Food,
        BonusFood
    };
    enum class GameMode {
        Snake,
        Nibbler
    };

    class BaseSnakeGame : public IGameModule {
    protected:
        class GameState {
        public:
            GameState() :
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
                mode(GameMode::Snake) {}

            const std::deque<Vector<float>>& getSegments() const { return segments; }
            Direction getCurrentDirection() const { return currentDirection; }
            Direction getNextDirection() const { return nextDirection; }
            const std::vector<Vector<float>>& getBonusFoods() const { return bonusFoods; }
            const std::vector<std::vector<CellType>>& getGrid() const { return grid; }
            int getScore() const { return score; }
            bool isGameOver() const { return gameOver; }
            float getMoveTimer() const { return moveTimer; }
            float getMoveInterval() const { return moveInterval; }
            float getBonusFoodTimer() const { return bonusFoodTimer; }
            float getBonusFoodDuration() const { return bonusFoodDuration; }
            int getLevel() const { return level; }
            float getTimeRemaining() const { return timeRemaining; }
            const std::string& getPlayerName() const { return playerName; }
            GameMode getMode() const { return mode; }

            void setCurrentDirection(Direction dir) { currentDirection = dir; }
            void setNextDirection(Direction dir) { nextDirection = dir; }
            void setScore(int newScore) { score = newScore; }
            void setGameOver(bool over) { gameOver = over; }
            void setMoveTimer(float timer) { moveTimer = timer; }
            void setMoveInterval(float interval) { moveInterval = interval; }
            void setBonusFoodTimer(float timer) { bonusFoodTimer = timer; }
            void setBonusFoodDuration(float duration) { bonusFoodDuration = duration; }
            void setLevel(int newLevel) { level = newLevel; }
            void setTimeRemaining(float time) { timeRemaining = time; }
            void setPlayerName(const std::string& name) { playerName = name; }
            void setMode(GameMode newMode) { mode = newMode; }

            void addSegment(const Vector<float>& segment) { segments.push_back(segment); }
            void prependSegment(const Vector<float>& segment) { segments.push_front(segment); }
            void removeLastSegment() { if (!segments.empty()) segments.pop_back(); }
            void clearSegments() { segments.clear(); }

            void addFood(const Vector<float>& food) { foods.push_back(food); }
            void removeFood(size_t index) { if (index < foods.size()) foods.erase(foods.begin() + index); }
            const std::vector<Vector<float>>& getFoods() const { return foods; }
            void clearFoods() { foods.clear(); }
            void addBonusFood(const Vector<float>& food) { bonusFoods.push_back(food); }
            void removeBonusFood(size_t index) {
                if (index < bonusFoods.size())
                    bonusFoods.erase(bonusFoods.begin() + index);
            }
            void clearBonusFoods() { bonusFoods.clear(); }
            void resizeGrid(size_t height, size_t width) {
                grid.resize(height, std::vector<CellType>(width, CellType::Empty));
            }
            void setCellType(size_t y, size_t x, CellType type) {
                if (y < grid.size() && x < grid[y].size())
                    grid[y][x] = type;
            }

            Vector<float> getHead() const {
                return segments.empty() ? Vector<float>(0, 0) : segments.front();
            }
            Vector<float> getTail() const {
                return segments.empty() ? Vector<float>(0, 0) : segments.back();
            }
            size_t getLength() const {
                return segments.size();
            }
            bool hasFoods() const {
                return !foods.empty();
            }
            bool hasBonusFoods() const {
                return !bonusFoods.empty();
            }
            void incrementScore(int points) {
                score += points;
            }
            void decrementTimeRemaining(float delta) {
                timeRemaining -= delta;
                if (timeRemaining < 0)
                    timeRemaining = 0;
            }
        private:
            std::deque<Vector<float>> segments;
            Direction currentDirection;
            Direction nextDirection;
            std::vector<Vector<float>> foods;
            std::vector<Vector<float>> bonusFoods;
            std::vector<std::vector<CellType>> grid;
            int score;
            bool gameOver;
            float moveTimer;
            float moveInterval;
            float bonusFoodTimer;
            float bonusFoodDuration;
            int level;
            float timeRemaining;
            std::string playerName;
            GameMode mode;
        };

    private:
        static constexpr float NORMAL_SPEED = 0.2f;
        static constexpr float BOOST_SPEED = 0.1f;
        static constexpr float MIN_SPEED = 0.05f;
        static constexpr float SPEED_FACTOR = 0.15f;
        static constexpr float DEFAULT_TIME_LIMIT = 60.0f;
        static constexpr int BONUS_FOOD_CHANCE = 10;
        static constexpr int BONUS_SCORE = 50;
        static constexpr int REGULAR_SCORE = 10;

        std::optional<std::reference_wrapper<IDisplayLibrary>> displayLib;

        void setupGame();
        void loadTextures();
        void loadBasicTextures(ITextureManager& textures);
        void loadWallTexture(ITextureManager& textures);

        void handleWallCollision();
        void handleSelfCollision();
        void handleFoodCollision();
        void handleBonusFoodCollision();
        void removeCollidedFood();
        void trySpawnBonusFood();

        std::vector<Vector<float>> findEmptyCells();
        Vector<float> chooseRandomCell(const std::vector<Vector<float>>& cells);
        void placeFood(const Vector<float>& pos, bool isBonus);
        Vector<float> getScreenSize(IDisplayModule& display);
        void drawGrid(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        void drawCell(IDisplayModule& display, ITextureManager& textures, CellType cellType, const Vector<float>& pos);
        void drawUI(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        void drawScore(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        void drawTimeRemaining(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        void drawGameOver(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);

    protected:
        [[nodiscard]] IDisplayLibrary& getDisplayLibrary() const {
            if (!displayLib.has_value()) {
                throw std::runtime_error("Display library not initialized");
            }
            return displayLib->get();
        }

        [[nodiscard]] bool hasDisplayLibrary() const noexcept {
            return displayLib.has_value();
        }

        GameState state;
        std::mt19937 rng;

        size_t gridWidth;
        size_t gridHeight;

        bool isCyclical;
        bool speedIncreases;
        bool hasWalls;
        bool useTimeLimit;

        virtual void initGrid();
        virtual void initSnake();
        virtual bool spawnFood(bool isBonus = false);
        virtual CellType checkCell(const Vector<float>& pos) const;
        virtual void updateGrid();
        virtual void handleInput();
        virtual void moveSnake(float delta);
        virtual CollisionType checkCollisions();
        virtual void growSnake();
        Vector<float> directionToVector(Direction dir) const;
        bool areOppositeDirections(Direction dir1, Direction dir2) const;
        virtual Vector<float> adjustPosition(const Vector<float>& pos) const;
        virtual bool isCellFree(const Vector<float>& pos) const;
        virtual void handleCollision(CollisionType collisionType);
        Vector<float> findFreeCellNear(const Vector<float>& pos) const;
        virtual void onLevelComplete();
        virtual void onGameOver();

    public:
        BaseSnakeGame(GameMode mode);
        virtual ~BaseSnakeGame() = default;
        void init(IDisplayLibrary &library) override;
        void update(float delta) override;
        void display() override;
        void stop() override;
        void setPlayerName(const std::string& name);
        std::string getPlayerName() const;
        int getScore() const;
    };
}

#endif /* !BASE_SNAKE_GAME_HPP_ */
