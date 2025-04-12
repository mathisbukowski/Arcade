---
generator: doxide
---


# BaseSnakeGame

**class BaseSnakeGame : public IGameModule**

class BaseSnakeGame
Base class for snake-type games that implements the IGameModule interface.


## Types

| Name | Description |
| ---- | ----------- |
| [GameState](BaseSnakeGame/GameState.md) | class GameState Internal class that manages the state of the game. |

## Variables

| Name | Description |
| ---- | ----------- |
| [NORMAL_SPEED](#NORMAL_SPEED) | Normal movement speed  |
| [BOOST_SPEED](#BOOST_SPEED) | Boosted movement speed  |
| [MIN_SPEED](#MIN_SPEED) | Minimum movement speed  |
| [SPEED_FACTOR](#SPEED_FACTOR) | Speed increase factor  |
| [DEFAULT_TIME_LIMIT](#DEFAULT_TIME_LIMIT) | Default time limit in seconds  |
| [BONUS_FOOD_CHANCE](#BONUS_FOOD_CHANCE) | Chance to spawn bonus food (1 in BONUS_FOOD_CHANCE)  |
| [BONUS_SCORE](#BONUS_SCORE) | Points awarded for bonus food  |
| [REGULAR_SCORE](#REGULAR_SCORE) | Points awarded for regular food  |
| [_displayLib](#_displayLib) | Display library reference  |
| [_state](#_state) | Current game state  |
| [_rng](#_rng) | Random number generator  |
| [_gridWidth](#_gridWidth) | Grid width in cells  |
| [_gridHeight](#_gridHeight) | Grid height in cells  |
| [_gridOffset](#_gridOffset) | Grid offset on screen  |
| [_isCyclical](#_isCyclical) | Flag for cyclical grid boundaries  |
| [_speedIncreases](#_speedIncreases) | Flag for speed increase on food collection  |
| [_hasWalls](#_hasWalls) | Flag for wall presence  |
| [_useTimeLimit](#_useTimeLimit) | Flag for time limit usage  |

## Functions

| Name | Description |
| ---- | ----------- |
| [setupGame](#setupGame) | Setup the game  |
| [loadTextures](#loadTextures) | Load game textures  |
| [loadBasicTextures](#loadBasicTextures) | Load basic textures :material-location-enter: `textures` :    ITextureManager& Texture manager  |
| [loadWallTexture](#loadWallTexture) | Load wall texture :material-location-enter: `textures` :    ITextureManager& Texture manager  |
| [loadSounds](#loadSounds) | Load game sounds  |
| [handleWallCollision](#handleWallCollision) | Handle wall collision  |
| [handleSelfCollision](#handleSelfCollision) | Handle self collision  |
| [handleFoodCollision](#handleFoodCollision) | Handle food collision  |
| [handleBonusFoodCollision](#handleBonusFoodCollision) | Handle bonus food collision  |
| [removeCollidedFood](#removeCollidedFood) | Remove collided food  |
| [trySpawnBonusFood](#trySpawnBonusFood) | Try to spawn bonus food  |
| [updateBonusFood](#updateBonusFood) | Update bonus food timer :material-location-enter: `delta` :    float Time since last frame  |
| [updateTimeLimit](#updateTimeLimit) | Update time limit :material-location-enter: `delta` :    float Time since last frame  |
| [checkLevelCompletion](#checkLevelCompletion) | Check if level is completed  |
| [findEmptyCells](#findEmptyCells) | Find empty cells in grid :material-keyboard-return: **Return** :    std::vector<Vector<float>> List of empty cell positions  |
| [chooseRandomCell](#chooseRandomCell) | Choose random cell from list :material-location-enter: `cells` :    const std::vector<Vector<float>>& List of cell positions :material-keyboard-return: **Return** :    Vector<float> Selected cell position  |
| [placeFood](#placeFood) | Place food on grid :material-location-enter: `pos` :    const Vector<float>& Position to place food :material-location-enter: `isBonus` :    bool True if placing bonus food  |
| [getScreenSize](#getScreenSize) | Get screen size :material-location-enter: `display` :    IDisplayModule& Display module :material-keyboard-return: **Return** :    Vector<float> Screen dimensions  |
| [drawGrid](#drawGrid) | Draw game grid :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `screenSize` :    const Vector<float>& Screen dimensions  |
| [drawCell](#drawCell) | Draw grid cell :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `cellType` :    CellType Type of cell to draw :material-location-enter: `pos` :    const Vector<float>& Position to draw cell  |
| [drawUI](#drawUI) | Draw user interface :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `screenSize` :    const Vector<float>& Screen dimensions  |
| [drawScore](#drawScore) | Draw score display :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `screenSize` :    const Vector<float>& Screen dimensions  |
| [drawTimeRemaining](#drawTimeRemaining) | Draw time remaining display :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `screenSize` :    const Vector<float>& Screen dimensions  |
| [drawGameOver](#drawGameOver) | Draw game over screen :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `screenSize` :    const Vector<float>& Screen dimensions  |
| [drawBackground](#drawBackground) | Draw background :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `display` :    IDisplayModule& Display module  |
| [drawBorderIfNeeded](#drawBorderIfNeeded) | Draw border if needed :material-location-enter: `x` :    size_t X coordinate :material-location-enter: `y` :    size_t Y coordinate :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `display` :    IDisplayModule& Display module :material-location-enter: `pos` :    const Vector<float>& Position to draw border  |
| [getElementDimensions](#getElementDimensions) | Get element dimensions :material-location-enter: `cellType` :    CellType Type of cell :material-location-enter: `cellWidth` :    float Width of cell :material-location-enter: `cellHeight` :    float Height of cell :material-location-enter: `elementWidth` :    float& Output element width :material-location-enter: `elementHeight` :    float& Output element height :material-location-enter: `offsetX` :    float& Output X offset :material-location-enter: `offsetY` :    float& Output Y offset  |
| [getTextureNameForCell](#getTextureNameForCell) | Get texture name for cell type :material-location-enter: `cellType` :    CellType Type of cell :material-keyboard-return: **Return** :    std::string Texture name  |
| [getSnakeHeadTextureName](#getSnakeHeadTextureName) | Get snake head texture name :material-keyboard-return: **Return** :    std::string Texture name for snake head  |
| [getOrLoadTexture](#getOrLoadTexture) | Get or load texture :material-location-enter: `textures` :    ITextureManager& Texture manager :material-location-enter: `textureName` :    const std::string& Name of texture :material-keyboard-return: **Return** :    std::shared_ptr<ITexture> Loaded texture  |
| [updateTextureRect](#updateTextureRect) | Update texture rectangle :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to update :material-location-enter: `pos` :    const Vector<float>& Position of texture :material-location-enter: `width` :    float Width of texture :material-location-enter: `height` :    float Height of texture  |
| [playSound](#playSound) | Play sound effect :material-location-enter: `soundName` :    const std::string& Name of sound :material-location-enter: `volume` :    float Volume level  |
| [calculateNewHeadPosition](#calculateNewHeadPosition) | Calculate new head position :material-keyboard-return: **Return** :    Vector<float> New head position  |
| [moveSnakeSegments](#moveSnakeSegments) | Move snake segments :material-location-enter: `newHead` :    const Vector<float>& New head position  |
| [getDisplayLibrary](#getDisplayLibrary) | Get display library :material-keyboard-return: **Return** :    IDisplayLibrary& Reference to display library  |
| [hasDisplayLibrary](#hasDisplayLibrary) | Check if display library is available :material-keyboard-return: **Return** :    bool True if display library is available  |
| [initGrid](#initGrid) | Initialize game grid  |
| [initSnake](#initSnake) | Initialize snake position  |
| [spawnFood](#spawnFood) | Spawn food on grid :material-location-enter: `isBonus` :    bool True if spawning bonus food :material-keyboard-return: **Return** :    bool True if food was successfully spawned  |
| [checkCell](#checkCell) | Check cell type at position :material-location-enter: `pos` :    const Vector<float>& Position to check :material-keyboard-return: **Return** :    CellType Type of cell at position  |
| [updateGrid](#updateGrid) | Update grid state  |
| [handleInput](#handleInput) | Handle user input  |
| [moveSnake](#moveSnake) | Move snake based on current direction :material-location-enter: `delta` :    float Time since last frame  |
| [checkCollisions](#checkCollisions) | Check for collisions :material-keyboard-return: **Return** :    CollisionType Type of collision detected  |
| [handleCollision](#handleCollision) | Handle collision event :material-location-enter: `collisionType` :    CollisionType Type of collision  |
| [growSnake](#growSnake) | Grow snake by adding segment  |
| [adjustPosition](#adjustPosition) | Adjust position for grid boundaries :material-location-enter: `pos` :    const Vector<float>& Position to adjust :material-keyboard-return: **Return** :    Vector<float> Adjusted position  |
| [isCellFree](#isCellFree) | Check if cell is free :material-location-enter: `pos` :    const Vector<float>& Position to check :material-keyboard-return: **Return** :    bool True if cell is free  |
| [onLevelComplete](#onLevelComplete) | Handle level completion  |
| [onGameOver](#onGameOver) | Handle game over  |
| [directionToVector](#directionToVector) | Convert direction to vector :material-location-enter: `dir` :    Direction Direction to convert :material-keyboard-return: **Return** :    Vector<float> Vector representation of direction  |
| [areOppositeDirections](#areOppositeDirections) | Check if directions are opposite :material-location-enter: `dir1` :    Direction First direction :material-location-enter: `dir2` :    Direction Second direction :material-keyboard-return: **Return** :    bool True if directions are opposite  |
| [findFreeCellNear](#findFreeCellNear) | Find free cell near position :material-location-enter: `pos` :    const Vector<float>& Starting position :material-keyboard-return: **Return** :    Vector<float> Position of free cell  |
| [isInBounds](#isInBounds) | Check if position is within grid bounds :material-location-enter: `pos` :    const Vector<float>& Position to check :material-keyboard-return: **Return** :    bool True if position is in bounds  |
| [BaseSnakeGame](#BaseSnakeGame) | Constructor :material-location-enter: `mode` :    GameMode Game mode to initialize  |
| [init](#init) | Virtual destructor Initialize game with display library :material-location-enter: `library` :    std::shared_ptr<IDisplayLibrary> Display library  |
| [update](#update) | Update game state :material-location-enter: `delta` :    float Time since last frame  |
| [display](#display) | Display game  |
| [stop](#stop) | Stop game  |
| [setPlayerName](#setPlayerName) | Set player name :material-location-enter: `name` :    const std::string& New player name  |
| [getPlayerName](#getPlayerName) | Get player name :material-keyboard-return: **Return** :    std::string Current player name  |
| [getScore](#getScore) | Get score :material-keyboard-return: **Return** :    int Current score  |

## Variable Details

### BONUS_FOOD_CHANCE<a name="BONUS_FOOD_CHANCE"></a>

!!! variable "static constexpr int BONUS_FOOD_CHANCE"

    Chance to spawn bonus food (1 in BONUS_FOOD_CHANCE)
    

### BONUS_SCORE<a name="BONUS_SCORE"></a>

!!! variable "static constexpr int BONUS_SCORE"

    Points awarded for bonus food
    

### BOOST_SPEED<a name="BOOST_SPEED"></a>

!!! variable "static constexpr float BOOST_SPEED"

    Boosted movement speed
    

### DEFAULT_TIME_LIMIT<a name="DEFAULT_TIME_LIMIT"></a>

!!! variable "static constexpr float DEFAULT_TIME_LIMIT"

    Default time limit in seconds
    

### MIN_SPEED<a name="MIN_SPEED"></a>

!!! variable "static constexpr float MIN_SPEED"

    Minimum movement speed
    

### NORMAL_SPEED<a name="NORMAL_SPEED"></a>

!!! variable "static constexpr float NORMAL_SPEED"

    Normal movement speed
    

### REGULAR_SCORE<a name="REGULAR_SCORE"></a>

!!! variable "static constexpr int REGULAR_SCORE"

    Points awarded for regular food
    

### SPEED_FACTOR<a name="SPEED_FACTOR"></a>

!!! variable "static constexpr float SPEED_FACTOR"

    Speed increase factor
    

### _displayLib<a name="_displayLib"></a>

!!! variable "std::optional&lt;std::reference_wrapper&lt;IDisplayLibrary&gt;&gt; _displayLib"

    Display library reference
    

### _gridHeight<a name="_gridHeight"></a>

!!! variable "size_t _gridHeight"

    Grid height in cells
    

### _gridOffset<a name="_gridOffset"></a>

!!! variable "Vector&lt;float&gt; _gridOffset"

    Grid offset on screen
    

### _gridWidth<a name="_gridWidth"></a>

!!! variable "size_t _gridWidth"

    Grid width in cells
    

### _hasWalls<a name="_hasWalls"></a>

!!! variable "bool _hasWalls"

    Flag for wall presence
    

### _isCyclical<a name="_isCyclical"></a>

!!! variable "bool _isCyclical"

    Flag for cyclical grid boundaries
    

### _rng<a name="_rng"></a>

!!! variable "std::mt19937 _rng"

    Random number generator
    

### _speedIncreases<a name="_speedIncreases"></a>

!!! variable "bool _speedIncreases"

    Flag for speed increase on food collection
    

### _state<a name="_state"></a>

!!! variable "GameState _state"

    Current game state
    

### _useTimeLimit<a name="_useTimeLimit"></a>

!!! variable "bool _useTimeLimit"

    Flag for time limit usage
    

## Function Details

### BaseSnakeGame<a name="BaseSnakeGame"></a>
!!! function "BaseSnakeGame(GameMode mode)"

    Constructor
        
    :material-location-enter: `mode`
    :    GameMode Game mode to initialize
    

### adjustPosition<a name="adjustPosition"></a>
!!! function "virtual Vector&lt;float&gt; adjustPosition(const Vector&lt;float&gt;&amp; pos) const"

    Adjust position for grid boundaries
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to adjust
        
    :material-keyboard-return: **Return**
    :    Vector<float> Adjusted position
    

### areOppositeDirections<a name="areOppositeDirections"></a>
!!! function "bool areOppositeDirections(Direction dir1, Direction dir2) const"

    Check if directions are opposite
        
    :material-location-enter: `dir1`
    :    Direction First direction
        
    :material-location-enter: `dir2`
    :    Direction Second direction
        
    :material-keyboard-return: **Return**
    :    bool True if directions are opposite
    

### calculateNewHeadPosition<a name="calculateNewHeadPosition"></a>
!!! function "Vector&lt;float&gt; calculateNewHeadPosition()"

    Calculate new head position
        
    :material-keyboard-return: **Return**
    :    Vector<float> New head position
    

### checkCell<a name="checkCell"></a>
!!! function "virtual CellType checkCell(const Vector&lt;float&gt;&amp; pos) const"

    Check cell type at position
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to check
        
    :material-keyboard-return: **Return**
    :    CellType Type of cell at position
    

### checkCollisions<a name="checkCollisions"></a>
!!! function "virtual CollisionType checkCollisions()"

    Check for collisions
        
    :material-keyboard-return: **Return**
    :    CollisionType Type of collision detected
    

### checkLevelCompletion<a name="checkLevelCompletion"></a>
!!! function "void checkLevelCompletion()"

    Check if level is completed
    

### chooseRandomCell<a name="chooseRandomCell"></a>
!!! function "Vector&lt;float&gt; chooseRandomCell(const std::vector&lt;Vector&lt;float&gt;&gt;&amp; cells)"

    Choose random cell from list
        
    :material-location-enter: `cells`
    :    const std::vector<Vector<float>>& List of cell positions
        
    :material-keyboard-return: **Return**
    :    Vector<float> Selected cell position
    

### directionToVector<a name="directionToVector"></a>
!!! function "Vector&lt;float&gt; directionToVector(Direction dir) const"

    Convert direction to vector
        
    :material-location-enter: `dir`
    :    Direction Direction to convert
        
    :material-keyboard-return: **Return**
    :    Vector<float> Vector representation of direction
    

### display<a name="display"></a>
!!! function "void display() override"

    Display game
    

### drawBackground<a name="drawBackground"></a>
!!! function "void drawBackground(ITextureManager&amp; textures, IDisplayModule&amp; display)"

    Draw background
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
    

### drawBorderIfNeeded<a name="drawBorderIfNeeded"></a>
!!! function "void drawBorderIfNeeded(size_t x, size_t y, ITextureManager&amp; textures, IDisplayModule&amp; display, const Vector&lt;float&gt;&amp; pos)"

    Draw border if needed
        
    :material-location-enter: `x`
    :    size_t X coordinate
        
    :material-location-enter: `y`
    :    size_t Y coordinate
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to draw border
    

### drawCell<a name="drawCell"></a>
!!! function "void drawCell(IDisplayModule&amp; display, ITextureManager&amp; textures, CellType cellType, const Vector&lt;float&gt;&amp; pos)"

    Draw grid cell
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `cellType`
    :    CellType Type of cell to draw
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to draw cell
    

### drawGameOver<a name="drawGameOver"></a>
!!! function "void drawGameOver(IDisplayModule&amp; display, ITextureManager&amp; textures, const Vector&lt;float&gt;&amp; screenSize)"

    Draw game over screen
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `screenSize`
    :    const Vector<float>& Screen dimensions
    

### drawGrid<a name="drawGrid"></a>
!!! function "void drawGrid(IDisplayModule&amp; display, ITextureManager&amp; textures, const Vector&lt;float&gt;&amp; screenSize)"

    Draw game grid
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `screenSize`
    :    const Vector<float>& Screen dimensions
    

### drawScore<a name="drawScore"></a>
!!! function "void drawScore(IDisplayModule&amp; display, ITextureManager&amp; textures, const Vector&lt;float&gt;&amp; screenSize)"

    Draw score display
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `screenSize`
    :    const Vector<float>& Screen dimensions
    

### drawTimeRemaining<a name="drawTimeRemaining"></a>
!!! function "void drawTimeRemaining(IDisplayModule&amp; display, ITextureManager&amp; textures, const Vector&lt;float&gt;&amp; screenSize)"

    Draw time remaining display
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `screenSize`
    :    const Vector<float>& Screen dimensions
    

### drawUI<a name="drawUI"></a>
!!! function "void drawUI(IDisplayModule&amp; display, ITextureManager&amp; textures, const Vector&lt;float&gt;&amp; screenSize)"

    Draw user interface
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `screenSize`
    :    const Vector<float>& Screen dimensions
    

### findEmptyCells<a name="findEmptyCells"></a>
!!! function "std::vector&lt;Vector&lt;float&gt;&gt; findEmptyCells()"

    Find empty cells in grid
        
    :material-keyboard-return: **Return**
    :    std::vector<Vector<float>> List of empty cell positions
    

### findFreeCellNear<a name="findFreeCellNear"></a>
!!! function "Vector&lt;float&gt; findFreeCellNear(const Vector&lt;float&gt;&amp; pos) const"

    Find free cell near position
        
    :material-location-enter: `pos`
    :    const Vector<float>& Starting position
        
    :material-keyboard-return: **Return**
    :    Vector<float> Position of free cell
    

### getDisplayLibrary<a name="getDisplayLibrary"></a>
!!! function "[[nodiscard]] IDisplayLibrary&amp; getDisplayLibrary() const"

    Get display library
        
    :material-keyboard-return: **Return**
    :    IDisplayLibrary& Reference to display library
    

### getElementDimensions<a name="getElementDimensions"></a>
!!! function "void getElementDimensions(CellType cellType, float cellWidth, float cellHeight, float &amp;elementWidth, float &amp;elementHeight, float &amp;offsetX, float &amp;offsetY)"

    Get element dimensions
        
    :material-location-enter: `cellType`
    :    CellType Type of cell
        
    :material-location-enter: `cellWidth`
    :    float Width of cell
        
    :material-location-enter: `cellHeight`
    :    float Height of cell
        
    :material-location-enter: `elementWidth`
    :    float& Output element width
        
    :material-location-enter: `elementHeight`
    :    float& Output element height
        
    :material-location-enter: `offsetX`
    :    float& Output X offset
        
    :material-location-enter: `offsetY`
    :    float& Output Y offset
    

### getOrLoadTexture<a name="getOrLoadTexture"></a>
!!! function "std::shared_ptr&lt;ITexture&gt; getOrLoadTexture(ITextureManager&amp; textures, const std::string&amp; textureName)"

    Get or load texture
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
        
    :material-location-enter: `textureName`
    :    const std::string& Name of texture
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ITexture> Loaded texture
    

### getPlayerName<a name="getPlayerName"></a>
!!! function "std::string getPlayerName() const"

    Get player name
        
    :material-keyboard-return: **Return**
    :    std::string Current player name
    

### getScore<a name="getScore"></a>
!!! function "int getScore() const"

    Get score
        
    :material-keyboard-return: **Return**
    :    int Current score
    

### getScreenSize<a name="getScreenSize"></a>
!!! function "Vector&lt;float&gt; getScreenSize(IDisplayModule&amp; display)"

    Get screen size
        
    :material-location-enter: `display`
    :    IDisplayModule& Display module
        
    :material-keyboard-return: **Return**
    :    Vector<float> Screen dimensions
    

### getSnakeHeadTextureName<a name="getSnakeHeadTextureName"></a>
!!! function "std::string getSnakeHeadTextureName() const"

    Get snake head texture name
        
    :material-keyboard-return: **Return**
    :    std::string Texture name for snake head
    

### getTextureNameForCell<a name="getTextureNameForCell"></a>
!!! function "std::string getTextureNameForCell(CellType cellType)"

    Get texture name for cell type
        
    :material-location-enter: `cellType`
    :    CellType Type of cell
        
    :material-keyboard-return: **Return**
    :    std::string Texture name
    

### growSnake<a name="growSnake"></a>
!!! function "virtual void growSnake()"

    Grow snake by adding segment
    

### handleBonusFoodCollision<a name="handleBonusFoodCollision"></a>
!!! function "void handleBonusFoodCollision()"

    Handle bonus food collision
    

### handleCollision<a name="handleCollision"></a>
!!! function "virtual void handleCollision(CollisionType collisionType)"

    Handle collision event
        
    :material-location-enter: `collisionType`
    :    CollisionType Type of collision
    

### handleFoodCollision<a name="handleFoodCollision"></a>
!!! function "void handleFoodCollision()"

    Handle food collision
    

### handleInput<a name="handleInput"></a>
!!! function "virtual void handleInput()"

    Handle user input
    

### handleSelfCollision<a name="handleSelfCollision"></a>
!!! function "void handleSelfCollision()"

    Handle self collision
    

### handleWallCollision<a name="handleWallCollision"></a>
!!! function "void handleWallCollision()"

    Handle wall collision
    

### hasDisplayLibrary<a name="hasDisplayLibrary"></a>
!!! function "[[nodiscard]] bool hasDisplayLibrary() const noexcept"

    Check if display library is available
        
    :material-keyboard-return: **Return**
    :    bool True if display library is available
    

### init<a name="init"></a>
!!! function "void init(std::shared_ptr&lt;IDisplayLibrary&gt; library) override"

    Virtual destructor
    Initialize game with display library
        
    :material-location-enter: `library`
    :    std::shared_ptr<IDisplayLibrary> Display library
    

### initGrid<a name="initGrid"></a>
!!! function "virtual void initGrid()"

    Initialize game grid
    

### initSnake<a name="initSnake"></a>
!!! function "virtual void initSnake()"

    Initialize snake position
    

### isCellFree<a name="isCellFree"></a>
!!! function "virtual bool isCellFree(const Vector&lt;float&gt;&amp; pos) const"

    Check if cell is free
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to check
        
    :material-keyboard-return: **Return**
    :    bool True if cell is free
    

### isInBounds<a name="isInBounds"></a>
!!! function "bool isInBounds(const Vector&lt;float&gt;&amp; pos) const"

    Check if position is within grid bounds
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to check
        
    :material-keyboard-return: **Return**
    :    bool True if position is in bounds
    

### loadBasicTextures<a name="loadBasicTextures"></a>
!!! function "void loadBasicTextures(ITextureManager&amp; textures)"

    Load basic textures
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
    

### loadSounds<a name="loadSounds"></a>
!!! function "void loadSounds()"

    Load game sounds
    

### loadTextures<a name="loadTextures"></a>
!!! function "void loadTextures()"

    Load game textures
    

### loadWallTexture<a name="loadWallTexture"></a>
!!! function "void loadWallTexture(ITextureManager&amp; textures)"

    Load wall texture
        
    :material-location-enter: `textures`
    :    ITextureManager& Texture manager
    

### moveSnake<a name="moveSnake"></a>
!!! function "virtual void moveSnake(float delta)"

    Move snake based on current direction
        
    :material-location-enter: `delta`
    :    float Time since last frame
    

### moveSnakeSegments<a name="moveSnakeSegments"></a>
!!! function "void moveSnakeSegments(const Vector&lt;float&gt;&amp; newHead)"

    Move snake segments
        
    :material-location-enter: `newHead`
    :    const Vector<float>& New head position
    

### onGameOver<a name="onGameOver"></a>
!!! function "virtual void onGameOver()"

    Handle game over
    

### onLevelComplete<a name="onLevelComplete"></a>
!!! function "virtual void onLevelComplete()"

    Handle level completion
    

### placeFood<a name="placeFood"></a>
!!! function "void placeFood(const Vector&lt;float&gt;&amp; pos, bool isBonus)"

    Place food on grid
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to place food
        
    :material-location-enter: `isBonus`
    :    bool True if placing bonus food
    

### playSound<a name="playSound"></a>
!!! function "void playSound(const std::string&amp; soundName, float volume)"

    Play sound effect
        
    :material-location-enter: `soundName`
    :    const std::string& Name of sound
        
    :material-location-enter: `volume`
    :    float Volume level
    

### removeCollidedFood<a name="removeCollidedFood"></a>
!!! function "void removeCollidedFood()"

    Remove collided food
    

### setPlayerName<a name="setPlayerName"></a>
!!! function "void setPlayerName(const std::string&amp; name)"

    Set player name
        
    :material-location-enter: `name`
    :    const std::string& New player name
    

### setupGame<a name="setupGame"></a>
!!! function "void setupGame()"

    Setup the game
    

### spawnFood<a name="spawnFood"></a>
!!! function "virtual bool spawnFood(bool isBonus = false)"

    Spawn food on grid
        
    :material-location-enter: `isBonus`
    :    bool True if spawning bonus food
        
    :material-keyboard-return: **Return**
    :    bool True if food was successfully spawned
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop game
    

### trySpawnBonusFood<a name="trySpawnBonusFood"></a>
!!! function "void trySpawnBonusFood()"

    Try to spawn bonus food
    

### update<a name="update"></a>
!!! function "void update(float delta) override"

    Update game state
        
    :material-location-enter: `delta`
    :    float Time since last frame
    

### updateBonusFood<a name="updateBonusFood"></a>
!!! function "void updateBonusFood(float delta)"

    Update bonus food timer
        
    :material-location-enter: `delta`
    :    float Time since last frame
    

### updateGrid<a name="updateGrid"></a>
!!! function "virtual void updateGrid()"

    Update grid state
    

### updateTextureRect<a name="updateTextureRect"></a>
!!! function "void updateTextureRect(std::shared_ptr&lt;ITexture&gt; texture, const Vector&lt;float&gt;&amp; pos, float width, float height)"

    Update texture rectangle
        
    :material-location-enter: `texture`
    :    std::shared_ptr<ITexture> Texture to update
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position of texture
        
    :material-location-enter: `width`
    :    float Width of texture
        
    :material-location-enter: `height`
    :    float Height of texture
    

### updateTimeLimit<a name="updateTimeLimit"></a>
!!! function "void updateTimeLimit(float delta)"

    Update time limit
        
    :material-location-enter: `delta`
    :    float Time since last frame
    

