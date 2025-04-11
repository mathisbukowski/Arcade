---
generator: doxide
---


# NibblerGame

**class NibblerGame : public BaseSnakeGame**

 class
This class implements the Nibbler game logic.
It inherits from BaseSnakeGame and provides specific functionalities for the Nibbler game.


## Variables

| Name | Description |
| ---- | ----------- |
| [DEFAULT_SPEED](#DEFAULT_SPEED) | Constants of the default game speed  |
| [LEVEL_SPEED_INCREASE](#LEVEL_SPEED_INCREASE) | Constants of the speed increase factor  |
| [MAX_LEVEL](#MAX_LEVEL) | Constants of the maximum level  |
| [BASE_TIME_LIMIT](#BASE_TIME_LIMIT) | Constants of the time limit for the game  |
| [TIME_BONUS_PER_FOOD](#TIME_BONUS_PER_FOOD) | Constants of the time bonus for each food eaten  |
| [_levelManager](#_levelManager) | LevelManager object to manage levels  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NibblerGame](#NibblerGame) | Constructor  |
| [update](#update) | Destructor update the game :material-location-enter: `delta` :    float Time since the last update  |
| [initGrid](#initGrid) | Initialize the grid  |
| [checkCollisions](#checkCollisions) | Check for collisions  |
| [handleAutomaticTurns](#handleAutomaticTurns) | Handle automatic turns :material-location-enter: `currentPosition` :    Vector<float> Current position of the snake :material-keyboard-return: **Return** :    Direction Direction to turn  |
| [getAvailableDirections](#getAvailableDirections) | Get all available directions :material-location-enter: `position` :    Vector<float> Current position of the snake :material-keyboard-return: **Return** :    std::vector<Direction> List of available directions  |
| [isTjunction](#isTjunction) | Check if the position is a T-junction :material-location-enter: `position` :    Vector<float> & Position to check :material-keyboard-return: **Return** :    bool True if it's a T-junction, false otherwise  |
| [loadLevel](#loadLevel) | Load the level :material-location-enter: `level` :    int Level number  |
| [onLevelComplete](#onLevelComplete) | Handle the level completion  |
| [onGameOver](#onGameOver) | Handle the game over state  |
| [getWindowTitle](#getWindowTitle) | Get the window title :material-keyboard-return: **Return** :    std::string Window title  |

## Variable Details

### BASE_TIME_LIMIT<a name="BASE_TIME_LIMIT"></a>

!!! variable "static constexpr float BASE_TIME_LIMIT"

    Constants of the time limit for the game
    

### DEFAULT_SPEED<a name="DEFAULT_SPEED"></a>

!!! variable "static constexpr float DEFAULT_SPEED"

    Constants of the default game speed
    

### LEVEL_SPEED_INCREASE<a name="LEVEL_SPEED_INCREASE"></a>

!!! variable "static constexpr float LEVEL_SPEED_INCREASE"

    Constants of the speed increase factor
    

### MAX_LEVEL<a name="MAX_LEVEL"></a>

!!! variable "static constexpr int MAX_LEVEL"

    Constants of the maximum level
    

### TIME_BONUS_PER_FOOD<a name="TIME_BONUS_PER_FOOD"></a>

!!! variable "static constexpr float TIME_BONUS_PER_FOOD"

    Constants of the time bonus for each food eaten
    

### _levelManager<a name="_levelManager"></a>

!!! variable "LevelManager _levelManager"

    LevelManager object to manage levels
    

## Function Details

### NibblerGame<a name="NibblerGame"></a>
!!! function "NibblerGame()"

    Constructor
    

### checkCollisions<a name="checkCollisions"></a>
!!! function "CollisionType checkCollisions() override"

    Check for collisions
    

### getAvailableDirections<a name="getAvailableDirections"></a>
!!! function "std::vector&lt;Direction&gt; getAvailableDirections(const Vector&lt;float&gt;&amp; position) const"

    Get all available directions
        
    :material-location-enter: `position`
    :    Vector<float> Current position of the snake
        
    :material-keyboard-return: **Return**
    :    std::vector<Direction> List of available directions
    

### getWindowTitle<a name="getWindowTitle"></a>
!!! function "std::string getWindowTitle() const"

    Get the window title
        
    :material-keyboard-return: **Return**
    :    std::string Window title
    

### handleAutomaticTurns<a name="handleAutomaticTurns"></a>
!!! function "Direction handleAutomaticTurns(const Vector&lt;float&gt;&amp; currentPosition)"

    Handle automatic turns
        
    :material-location-enter: `currentPosition`
    :    Vector<float> Current position of the snake
        
    :material-keyboard-return: **Return**
    :    Direction Direction to turn
    

### initGrid<a name="initGrid"></a>
!!! function "void initGrid() override"

    Initialize the grid
    

### isTjunction<a name="isTjunction"></a>
!!! function "bool isTjunction(const Vector&lt;float&gt;&amp; position) const"

    Check if the position is a T-junction
        
    :material-location-enter: `position`
    :    Vector<float> & Position to check
        
    :material-keyboard-return: **Return**
    :    bool True if it's a T-junction, false otherwise
    

### loadLevel<a name="loadLevel"></a>
!!! function "void loadLevel(int level)"

    Load the level
        
    :material-location-enter: `level`
    :    int Level number
    

### onGameOver<a name="onGameOver"></a>
!!! function "void onGameOver() override"

    Handle the game over state
    

### onLevelComplete<a name="onLevelComplete"></a>
!!! function "void onLevelComplete() override"

    Handle the level completion
    

### update<a name="update"></a>
!!! function "void update(float delta) override"

    Destructor
    update the game
    
    :material-location-enter: `delta`
    :    float Time since the last update
    

