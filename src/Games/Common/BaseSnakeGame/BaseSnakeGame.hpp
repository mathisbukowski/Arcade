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
#include <optional>
#include <functional>
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
            GameState();

            // Getters
            const std::deque<Vector<float>>& getSegments() const;
            Direction getCurrentDirection() const;
            Direction getNextDirection() const;
            const std::vector<Vector<float>>& getBonusFoods() const;
            const std::vector<std::vector<CellType>>& getGrid() const;
            int getScore() const;
            bool isGameOver() const;
            float getMoveTimer() const;
            float getMoveInterval() const;
            float getBonusFoodTimer() const;
            float getBonusFoodDuration() const;
            int getLevel() const;
            float getTimeRemaining() const;
            const std::string& getPlayerName() const;
            GameMode getMode() const;
            Vector<float> getHead() const;
            Vector<float> getTail() const;
            size_t getLength() const;
            bool hasFoods() const;
            bool hasBonusFoods() const;
            const std::vector<Vector<float>>& getFoods() const;

            // Setters
            void setCurrentDirection(Direction dir);
            void setNextDirection(Direction dir);
            void setScore(int newScore);
            void setGameOver(bool over);
            void setMoveTimer(float timer);
            void setMoveInterval(float interval);
            void setBonusFoodTimer(float timer);
            void setBonusFoodDuration(float duration);
            void setLevel(int newLevel);
            void setTimeRemaining(float time);
            void setPlayerName(const std::string& name);
            void setMode(GameMode newMode);

            // Segment management
            void addSegment(const Vector<float>& segment);
            void prependSegment(const Vector<float>& segment);
            void removeLastSegment();
            void clearSegments();

            // Food management
            void addFood(const Vector<float>& food);
            void removeFood(size_t index);
            void clearFoods();
            void addBonusFood(const Vector<float>& food);
            void removeBonusFood(size_t index);
            void clearBonusFoods();

            // Grid management
            void resizeGrid(size_t height, size_t width);
            void setCellType(size_t y, size_t x, CellType type);

            // Game state updates
            void incrementScore(int points);
            void decrementTimeRemaining(float delta);

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
            // Constants
            static constexpr float NORMAL_SPEED = 0.2f;
            static constexpr float BOOST_SPEED = 0.1f;
            static constexpr float MIN_SPEED = 0.05f;
            static constexpr float SPEED_FACTOR = 0.15f;
            static constexpr float DEFAULT_TIME_LIMIT = 60.0f;
            static constexpr int BONUS_FOOD_CHANCE = 10;
            static constexpr int BONUS_SCORE = 50;
            static constexpr int REGULAR_SCORE = 10;

            std::optional<std::reference_wrapper<IDisplayLibrary>> displayLib;

            // Initialization
            void setupGame();
            void loadTextures();
            void loadBasicTextures(ITextureManager& textures);
            void loadWallTexture(ITextureManager& textures);
            void loadSounds();

            // Collision handlers
            void handleWallCollision();
            void handleSelfCollision();
            void handleFoodCollision();
            void handleBonusFoodCollision();
            void removeCollidedFood();
            void trySpawnBonusFood();

            // Update helpers
            void updateBonusFood(float delta);
            void updateTimeLimit(float delta);
            void checkLevelCompletion();

            // Food management helpers
            std::vector<Vector<float>> findEmptyCells();
            Vector<float> chooseRandomCell(const std::vector<Vector<float>>& cells);
            void placeFood(const Vector<float>& pos, bool isBonus);

            // Drawing helpers
            Vector<float> getScreenSize(IDisplayModule& display);
            void drawGrid(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
            void drawCell(IDisplayModule& display, ITextureManager& textures, CellType cellType, const Vector<float>& pos);
            void drawUI(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
            void drawScore(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
            void drawTimeRemaining(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
            void drawGameOver(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
            void drawBackground(ITextureManager& textures, IDisplayModule& display);
            void drawBorderIfNeeded(size_t x, size_t y, ITextureManager& textures, IDisplayModule& display, const Vector<float>& pos);
            void getElementDimensions(CellType cellType, float cellWidth, float cellHeight,
                                     float &elementWidth, float &elementHeight,
                                     float &offsetX, float &offsetY);
            std::string getTextureNameForCell(CellType cellType);
            std::shared_ptr<ITexture> getOrLoadTexture(ITextureManager& textures, const std::string& textureName);
            void updateTextureRect(std::shared_ptr<ITexture> texture, const Vector<float>& pos,
                                  float width, float height);
            void playSound(const std::string& soundName, float volume);

            // Snake movement and collision helpers
            Vector<float> calculateNewHeadPosition();
            void moveSnakeSegments(const Vector<float>& newHead);

    protected:
        // Library access
        [[nodiscard]] IDisplayLibrary& getDisplayLibrary() const;
        [[nodiscard]] bool hasDisplayLibrary() const noexcept;

        // Game state
        GameState state;
        std::mt19937 rng;

        // Game properties
        size_t gridWidth;
        size_t gridHeight;
        Vector<float> gridOffset;
        bool isCyclical;
        bool speedIncreases;
        bool hasWalls;
        bool useTimeLimit;

        // Core game logic - virtual for game-specific customization
        virtual void initGrid();
        virtual void initSnake();
        virtual bool spawnFood(bool isBonus = false);
        virtual CellType checkCell(const Vector<float>& pos) const;
        virtual void updateGrid();
        virtual void handleInput();
        virtual void moveSnake(float delta);
        virtual CollisionType checkCollisions();
        virtual void handleCollision(CollisionType collisionType);
        virtual void growSnake();
        virtual Vector<float> adjustPosition(const Vector<float>& pos) const;
        virtual bool isCellFree(const Vector<float>& pos) const;
        virtual void onLevelComplete();
        virtual void onGameOver();

        // Helper methods
        Vector<float> directionToVector(Direction dir) const;
        bool areOppositeDirections(Direction dir1, Direction dir2) const;
        Vector<float> findFreeCellNear(const Vector<float>& pos) const;
        bool isInBounds(const Vector<float>& pos) const;
    public:
        // Public interface
        BaseSnakeGame(GameMode mode);
        virtual ~BaseSnakeGame() = default;
        void init(std::shared_ptr<IDisplayLibrary> library) override;
        void update(float delta) override;
        void display() override;
        void stop() override;
        void setPlayerName(const std::string& name);
        std::string getPlayerName() const;
        int getScore() const;
    };
}

#endif /* !BASE_SNAKE_GAME_HPP_ */
