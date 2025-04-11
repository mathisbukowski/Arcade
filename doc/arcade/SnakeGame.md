---
generator: doxide
---


# SnakeGame

**class SnakeGame : public BaseSnakeGame**


This class implements the Snake game logic.
It inherits from BaseSnakeGame and provides specific functionalities for the Snake game.


## Variables

| Name | Description |
| ---- | ----------- |
| [DEFAULT_SPEED](#DEFAULT_SPEED) | Constants for the default game speed  |
| [SCORE_MULTIPLIER](#SCORE_MULTIPLIER) | Constants for the default game score multiplier  |
| [FOOD_SPAWN_FREQUENCY](#FOOD_SPAWN_FREQUENCY) | Constants for the default game food spawn frequency  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SnakeGame](#SnakeGame) | Constructor :material-location-enter: `cyclical` :    bool Whether the game has cyclical borders (snake can go through walls)  |
| [update](#update) | Destructor Updates the game state :material-location-enter: `delta` :    float Time elapsed since last update in seconds  |
| [adjustPosition](#adjustPosition) | Adjusts position for cyclical boundaries Snake can pass through walls and appear on the other side if enabled :material-location-enter: `pos` :    const Vector<float> & Position to adjust :material-keyboard-return: **Return** :    Vector<float> -Adjusted position  |
| [checkCollisions](#checkCollisions) | Checks collisions specific to Snake game In Snake, colliding with walls is fatal unless cyclical borders are enabled :material-keyboard-return: **Return** :    CollisionTypeType of collision detected  |
| [initGrid](#initGrid) | Initialize the grid for Snake Snake has a simple empty grid without obstacles  |
| [onGameOver](#onGameOver) | Handles the game over state Displays game over screen and plays sound  |
| [getWindowTitle](#getWindowTitle) | Creates the window title for Snake :material-keyboard-return: **Return** :    std::string Window title string  |

## Variable Details

### DEFAULT_SPEED<a name="DEFAULT_SPEED"></a>

!!! variable "static constexpr float DEFAULT_SPEED"

    Constants for the default game speed
    

### FOOD_SPAWN_FREQUENCY<a name="FOOD_SPAWN_FREQUENCY"></a>

!!! variable "static constexpr int FOOD_SPAWN_FREQUENCY"

    Constants for the default game food spawn frequency
    

### SCORE_MULTIPLIER<a name="SCORE_MULTIPLIER"></a>

!!! variable "static constexpr float SCORE_MULTIPLIER"

    Constants for the default game score multiplier
    

## Function Details

### SnakeGame<a name="SnakeGame"></a>
!!! function "explicit SnakeGame(bool cyclical = false)"

    Constructor
    
    :material-location-enter: `cyclical`
    :    bool Whether the game has cyclical borders (snake can go through walls)
    

### adjustPosition<a name="adjustPosition"></a>
!!! function "Vector&lt;float&gt; adjustPosition(const Vector&lt;float&gt;&amp; pos) const override"

    Adjusts position for cyclical boundaries
        Snake can pass through walls and appear on the other side if enabled
        
    :material-location-enter: `pos`
    :    const Vector<float> & Position to adjust
        
    :material-keyboard-return: **Return**
    :    Vector<float> -Adjusted position
    

### checkCollisions<a name="checkCollisions"></a>
!!! function "CollisionType checkCollisions() override"

    Checks collisions specific to Snake game
        In Snake, colliding with walls is fatal unless cyclical borders are enabled
        
    :material-keyboard-return: **Return**
    :    CollisionTypeType of collision detected
    

### getWindowTitle<a name="getWindowTitle"></a>
!!! function "std::string getWindowTitle() const"

    Creates the window title for Snake
        
    :material-keyboard-return: **Return**
    :    std::string Window title string
    

### initGrid<a name="initGrid"></a>
!!! function "void initGrid() override"

    Initialize the grid for Snake
        Snake has a simple empty grid without obstacles
    

### onGameOver<a name="onGameOver"></a>
!!! function "void onGameOver() override"

    Handles the game over state
        Displays game over screen and plays sound
    

### update<a name="update"></a>
!!! function "void update(float delta) override"

    Destructor
    Updates the game state
        
    :material-location-enter: `delta`
    :    float Time elapsed since last update in seconds
    

