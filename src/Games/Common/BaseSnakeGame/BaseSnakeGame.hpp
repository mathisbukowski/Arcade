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
    /**
     * enum class CellType
     * Represents the different types of cells in the game grid.
     */
    enum class CellType {
        Empty,
        Snake,
        SnakeHead,
        Food,
        BonusFood,
        Wall,
        OutOfBounds
    };
    /**
     * enum class Direction
     * Represents the possible directions for snake movement.
     */
    enum class Direction {
        Up,
        Right,
        Down,
        Left
    };
    /**
     * enum class CollisionType
     * Represents the different types of collisions that can occur.
     */
    enum class CollisionType {
        None,
        Wall,
        Self,
        Food,
        BonusFood
    };
    /**
     * enum class GameMode
     * Represents the different game modes available.
     */
    enum class GameMode {
        Snake,
        Nibbler
    };
    /**
     * class BaseSnakeGame
     * Base class for snake-type games that implements the IGameModule interface.
     */
    class BaseSnakeGame : public IGameModule {
    protected:
        /**
         * class GameState
         * Internal class that manages the state of the game.
         */
        class GameState {
        public:
            /**
             * Constructor
             * Initializes the game state
             */
            GameState();
            /**
             * Get snake segments
             * @return const std::deque<Vector<float>>& Reference to snake segments
             */
            const std::deque<Vector<float>>& getSegments() const;
            /**
             * Get current direction
             * @return Direction Current movement direction
             */
            Direction getCurrentDirection() const;
            /**
             * Get next direction
             * @return Direction Next movement direction
             */
            Direction getNextDirection() const;
            /**
             * Get bonus foods
             * @return const std::vector<Vector<float>>& Reference to bonus foods
             */
            const std::vector<Vector<float>>& getBonusFoods() const;
            /**
             * Get grid
             * @return const std::vector<std::vector<CellType>>& Reference to grid
             */
            const std::vector<std::vector<CellType>>& getGrid() const;
            /**
             * Get score
             * @return int Current score
             */
            int getScore() const;
            /**
             * Check if game is over
             * @return bool True if game is over
             */
            bool isGameOver() const;
            /**
             * Get move timer
             * @return float Current move timer value
             */
            float getMoveTimer() const;
            /**
             * Get move interval
             * @return float Current move interval value
             */
            float getMoveInterval() const;
            /**
             * Get bonus food timer
             * @return float Current bonus food timer value
             */
            float getBonusFoodTimer() const;
            /**
             * Get bonus food duration
             * @return float Current bonus food duration
             */
            float getBonusFoodDuration() const;
            /**
             * Get level
             * @return int Current level
             */
            int getLevel() const;
            /**
             * Get time remaining
             * @return float Time remaining in seconds
             */
            float getTimeRemaining() const;
            /**
             * Get player name
             * @return const std::string& Reference to player name
             */
            const std::string& getPlayerName() const;
            /**
             * Get game mode
             * @return GameMode Current game mode
             */
            GameMode getMode() const;
            /**
             * Get head position
             * @return Vector<float> Position of snake head
             */
            Vector<float> getHead() const;
            /**
             * Get tail position
             * @return Vector<float> Position of snake tail
             */
            Vector<float> getTail() const;
            /**
             * Get snake length
             * @return size_t Length of the snake
             */
            size_t getLength() const;
            /**
             * Check if foods exist
             * @return bool True if foods exist
             */
            bool hasFoods() const;
            /**
             * Check if bonus foods exist
             * @return bool True if bonus foods exist
             */
            bool hasBonusFoods() const;
            /**
             * Get foods
             * @return const std::vector<Vector<float>>& Reference to foods
             */
            const std::vector<Vector<float>>& getFoods() const;
            /**
             * Set current direction
             * @param dir Direction New current direction
             */
            void setCurrentDirection(Direction dir);
            /**
             * Set next direction
             * @param dir Direction New next direction
             */
            void setNextDirection(Direction dir);
            /**
             * Set score
             * @param newScore int New score value
             */
            void setScore(int newScore);
            /**
             * Set game over state
             * @param over bool New game over state
             */
            void setGameOver(bool over);
            /**
             * Set move timer
             * @param timer float New move timer value
             */
            void setMoveTimer(float timer);
            /**
             * Set move interval
             * @param interval float New move interval value
             */
            void setMoveInterval(float interval);
            /**
             * Set bonus food timer
             * @param timer float New bonus food timer value
             */
            void setBonusFoodTimer(float timer);
            /**
             * Set bonus food duration
             * @param duration float New bonus food duration
             */
            void setBonusFoodDuration(float duration);
            /**
             * Set level
             * @param newLevel int New level value
             */
            void setLevel(int newLevel);
            /**
             * Set time remaining
             * @param time float New time remaining value
             */
            void setTimeRemaining(float time);
            /**
             * Set player name
             * @param name const std::string& New player name
             */
            void setPlayerName(const std::string& name);
            /**
             * Set game mode
             * @param newMode GameMode New game mode
             */
            void setMode(GameMode newMode);
            /**
             * Add segment to the snake
             * @param segment const Vector<float>& Position of new segment
             */
            void addSegment(const Vector<float>& segment);
            /**
             * Prepend segment to the snake
             * @param segment const Vector<float>& Position of new segment
             */
            void prependSegment(const Vector<float>& segment);
            /**
             * Remove last segment of the snake
             */
            void removeLastSegment();
            /**
             * Clear all snake segments
             */
            void clearSegments();
            /**
             * Add food
             * @param food const Vector<float>& Position of new food
             */
            void addFood(const Vector<float>& food);
            /**
             * Remove food at specific index
             * @param index size_t Index of food to remove
             */
            void removeFood(size_t index);
            /**
             * Clear all foods
             */
            void clearFoods();
            /**
             * Add bonus food
             * @param food const Vector<float>& Position of new bonus food
             */
            void addBonusFood(const Vector<float>& food);
            /**
             * Remove bonus food at specific index
             * @param index size_t Index of bonus food to remove
             */
            void removeBonusFood(size_t index);
            /**
             * Clear all bonus foods
             */
            void clearBonusFoods();
            /**
             * Resize grid
             * @param height size_t New grid height
             * @param width size_t New grid width
             */
            void resizeGrid(size_t height, size_t width);
            /**
             * Set cell type
             * @param y size_t Y coordinate
             * @param x size_t X coordinate
             * @param type CellType New cell type
             */
            void setCellType(size_t y, size_t x, CellType type);
            /**
             * Increment score
             * @param points int Points to add
             */
            void incrementScore(int points);
            /**
             * Decrement time remaining
             * @param delta float Time to subtract
             */
            void decrementTimeRemaining(float delta);

        private:
            std::deque<Vector<float>> _segments; /* All part of the snake*/
            Direction _currentDirection; /* Current movement direction */
            Direction _nextDirection; /* Next movement direction */
            std::vector<Vector<float>> _foods; /* All food positions */
            std::vector<Vector<float>> _bonusFoods; /* All bonus food positions */
            std::vector<std::vector<CellType>> _grid; /* Game grid */
            int _score; /* Current score */
            bool _gameOver; /* Game over state */ 
            float _moveTimer; /* Timer for snake movement */
            float _moveInterval; /* Interval between snake movements */
            float _bonusFoodTimer; /* Timer for bonus food */ 
            float _bonusFoodDuration; /* Duration of bonus food */
            int _level; /* Current level */
            float _timeRemaining; /* Time remaining in seconds */
            std::string _playerName; /* Player's name */ 
            GameMode _mode; /* Current game mode */
        };
    private:
        /**
         * Normal movement speed
         */
        static constexpr float NORMAL_SPEED = 0.2f;
        /**
         * Boosted movement speed
         */
        static constexpr float BOOST_SPEED = 0.1f;
        /**
         * Minimum movement speed
         */
        static constexpr float MIN_SPEED = 0.05f;
        /**
         * Speed increase factor
         */
        static constexpr float SPEED_FACTOR = 0.15f;
        /**
         * Default time limit in seconds
         */
        static constexpr float DEFAULT_TIME_LIMIT = 60.0f;
        /**
         * Chance to spawn bonus food (1 in BONUS_FOOD_CHANCE)
         */
        static constexpr int BONUS_FOOD_CHANCE = 10;
        /**
         * Points awarded for bonus food
         */
        static constexpr int BONUS_SCORE = 50;
        /**
         * Points awarded for regular food
         */
        static constexpr int REGULAR_SCORE = 10;
        /**
         * Display library reference
         */
        std::optional<std::reference_wrapper<IDisplayLibrary>> _displayLib;
        /**
         * Setup the game
         */
        void setupGame();
        /**
         * Load game textures
         */
        void loadTextures();
        /**
         * Load basic textures
         * @param textures ITextureManager& Texture manager
         */
        void loadBasicTextures(ITextureManager& textures);
        /**
         * Load wall texture
         * @param textures ITextureManager& Texture manager
         */
        void loadWallTexture(ITextureManager& textures);
        /**
         * Load game sounds
         */
        void loadSounds();
        /**
         * Handle wall collision
         */
        void handleWallCollision();
        /**
         * Handle self collision
         */
        void handleSelfCollision();
        /**
         * Handle food collision
         */
        void handleFoodCollision();
        /**
         * Handle bonus food collision
         */
        void handleBonusFoodCollision();
        /**
         * Remove collided food
         */
        void removeCollidedFood();
        /**
         * Try to spawn bonus food
         */
        void trySpawnBonusFood();
        /**
         * Update bonus food timer
         * @param delta float Time since last frame
         */
        void updateBonusFood(float delta);
        /**
         * Update time limit
         * @param delta float Time since last frame
         */
        void updateTimeLimit(float delta);
        /**
         * Check if level is completed
         */
        void checkLevelCompletion();
        /**
         * Find empty cells in grid
         * @return std::vector<Vector<float>> List of empty cell positions
         */
        std::vector<Vector<float>> findEmptyCells();
        /**
         * Choose random cell from list
         * @param cells const std::vector<Vector<float>>& List of cell positions
         * @return Vector<float> Selected cell position
         */
        Vector<float> chooseRandomCell(const std::vector<Vector<float>>& cells);
        /**
         * Place food on grid
         * @param pos const Vector<float>& Position to place food
         * @param isBonus bool True if placing bonus food
         */
        void placeFood(const Vector<float>& pos, bool isBonus);
        /**
         * Get screen size
         * @param display IDisplayModule& Display module
         * @return Vector<float> Screen dimensions
         */
        Vector<float> getScreenSize(IDisplayModule& display);
        /**
         * Draw game grid
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param screenSize const Vector<float>& Screen dimensions
         */
        void drawGrid(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        /**
         * Draw grid cell
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param cellType CellType Type of cell to draw
         * @param pos const Vector<float>& Position to draw cell
         */
        void drawCell(IDisplayModule& display, ITextureManager& textures, CellType cellType, const Vector<float>& pos);
        /**
         * Draw user interface
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param screenSize const Vector<float>& Screen dimensions
         */
        void drawUI(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        /**
         * Draw score display
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param screenSize const Vector<float>& Screen dimensions
         */
        void drawScore(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        /**
         * Draw time remaining display
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param screenSize const Vector<float>& Screen dimensions
         */
        void drawTimeRemaining(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        /**
         * Draw game over screen
         * @param display IDisplayModule& Display module
         * @param textures ITextureManager& Texture manager
         * @param screenSize const Vector<float>& Screen dimensions
         */
        void drawGameOver(IDisplayModule& display, ITextureManager& textures, const Vector<float>& screenSize);
        /**
         * Draw background
         * @param textures ITextureManager& Texture manager
         * @param display IDisplayModule& Display module
         */
        void drawBackground(ITextureManager& textures, IDisplayModule& display);
        /**
         * Draw border if needed
         * @param x size_t X coordinate
         * @param y size_t Y coordinate
         * @param textures ITextureManager& Texture manager
         * @param display IDisplayModule& Display module
         * @param pos const Vector<float>& Position to draw border
         */
        void drawBorderIfNeeded(size_t x, size_t y, ITextureManager& textures, IDisplayModule& display, const Vector<float>& pos);
        /**
         * Get element dimensions
         * @param cellType CellType Type of cell
         * @param cellWidth float Width of cell
         * @param cellHeight float Height of cell
         * @param elementWidth float& Output element width
         * @param elementHeight float& Output element height
         * @param offsetX float& Output X offset
         * @param offsetY float& Output Y offset
         */
        void getElementDimensions(CellType cellType, float cellWidth, float cellHeight,
                                  float &elementWidth, float &elementHeight,
                                  float &offsetX, float &offsetY);
        /**
         * Get texture name for cell type
         * @param cellType CellType Type of cell
         * @return std::string Texture name
         */
        std::string getTextureNameForCell(CellType cellType);
        /**
         * Get snake head texture name
         * @return std::string Texture name for snake head
         */
        std::string getSnakeHeadTextureName() const;
        /**
         * Get or load texture
         * @param textures ITextureManager& Texture manager
         * @param textureName const std::string& Name of texture
         * @return std::shared_ptr<ITexture> Loaded texture
         */
        std::shared_ptr<ITexture> getOrLoadTexture(ITextureManager& textures, const std::string& textureName);
        /**
         * Update texture rectangle
         * @param texture std::shared_ptr<ITexture> Texture to update
         * @param pos const Vector<float>& Position of texture
         * @param width float Width of texture
         * @param height float Height of texture
         */
        void updateTextureRect(std::shared_ptr<ITexture> texture, const Vector<float>& pos,
                               float width, float height);
        /**
         * Play sound effect
         * @param soundName const std::string& Name of sound
         * @param volume float Volume level
         */
        void playSound(const std::string& soundName, float volume);
        /**
         * Calculate new head position
         * @return Vector<float> New head position
         */
        Vector<float> calculateNewHeadPosition();
        /**
         * Move snake segments
         * @param newHead const Vector<float>& New head position
         */
        void moveSnakeSegments(const Vector<float>& newHead);

    protected:
        /**
         * Get display library
         * @return IDisplayLibrary& Reference to display library
         */
        [[nodiscard]] IDisplayLibrary& getDisplayLibrary() const;
        /**
         * Check if display library is available
         * @return bool True if display library is available
         */
        [[nodiscard]] bool hasDisplayLibrary() const noexcept;
        /**
         * Current game state
         */
        GameState _state;
        /**
         * Random number generator
         */
        std::mt19937 _rng;
        /**
         * Grid width in cells
         */
        size_t _gridWidth;
        /**
         * Grid height in cells
         */
        size_t _gridHeight;
        /**
         * Grid offset on screen
         */
        Vector<float> _gridOffset;
        /**
         * Flag for cyclical grid boundaries
         */
        bool _isCyclical;
        /**
         * Flag for speed increase on food collection
         */
        bool _speedIncreases;
        /**
         * Flag for wall presence
         */
        bool _hasWalls;
        /**
         * Flag for time limit usage
         */
        bool _useTimeLimit;
        /**
         * Initialize game grid
         */
        virtual void initGrid();
        /**
         * Initialize snake position
         */
        virtual void initSnake();
        /**
         * Spawn food on grid
         * @param isBonus bool True if spawning bonus food
         * @return bool True if food was successfully spawned
         */
        virtual bool spawnFood(bool isBonus = false);
        /**
         * Check cell type at position
         * @param pos const Vector<float>& Position to check
         * @return CellType Type of cell at position
         */
        virtual CellType checkCell(const Vector<float>& pos) const;
        /**
         * Update grid state
         */
        virtual void updateGrid();
        /**
         * Handle user input
         */
        virtual void handleInput();
        /**
         * Move snake based on current direction
         * @param delta float Time since last frame
         */
        virtual void moveSnake(float delta);
        /**
         * Check for collisions
         * @return CollisionType Type of collision detected
         */
        virtual CollisionType checkCollisions();
        /**
         * Handle collision event
         * @param collisionType CollisionType Type of collision
         */
        virtual void handleCollision(CollisionType collisionType);
        /**
         * Grow snake by adding segment
         */
        virtual void growSnake();
        /**
         * Adjust position for grid boundaries
         * @param pos const Vector<float>& Position to adjust
         * @return Vector<float> Adjusted position
         */
        virtual Vector<float> adjustPosition(const Vector<float>& pos) const;
        /**
         * Check if cell is free
         * @param pos const Vector<float>& Position to check
         * @return bool True if cell is free
         */
        virtual bool isCellFree(const Vector<float>& pos) const;
        /**
         * Handle level completion
         */
        virtual void onLevelComplete();
        /**
         * Handle game over
         */
        virtual void onGameOver();
        /**
         * Convert direction to vector
         * @param dir Direction Direction to convert
         * @return Vector<float> Vector representation of direction
         */
        Vector<float> directionToVector(Direction dir) const;
        /**
         * Check if directions are opposite
         * @param dir1 Direction First direction
         * @param dir2 Direction Second direction
         * @return bool True if directions are opposite
         */
        bool areOppositeDirections(Direction dir1, Direction dir2) const;
        /**
         * Find free cell near position
         * @param pos const Vector<float>& Starting position
         * @return Vector<float> Position of free cell
         */
        Vector<float> findFreeCellNear(const Vector<float>& pos) const;
        /**
         * Check if position is within grid bounds
         * @param pos const Vector<float>& Position to check
         * @return bool True if position is in bounds
         */
        bool isInBounds(const Vector<float>& pos) const;
    public:
        /**
         * Constructor
         * @param mode GameMode Game mode to initialize
         */
        BaseSnakeGame(GameMode mode);
        /**
         * Virtual destructor
         */
        virtual ~BaseSnakeGame() = default;
        /**
         * Initialize game with display library
         * @param library std::shared_ptr<IDisplayLibrary> Display library
         */
        void init(std::shared_ptr<IDisplayLibrary> library) override;
        /**
         * Update game state
         * @param delta float Time since last frame
         */
        void update(float delta) override;
        /**
         * Display game
         */
        void display() override;
        /**
         * Stop game
         */
        void stop() override;
        /**
         * Set player name
         * @param name const std::string& New player name
         */
        void setPlayerName(const std::string& name);
        /**
         * Get player name
         * @return std::string Current player name
         */
        std::string getPlayerName() const;
        /**
         * Get score
         * @return int Current score
         */
        int getScore() const;
    };
}

#endif /* !BASE_SNAKE_GAME_HPP_ */
