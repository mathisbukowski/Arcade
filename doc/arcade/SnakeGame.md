---
generator: doxide
---


# SnakeGame

**class SnakeGame : public BaseSnakeGame**

@brief Implementation of the classic Snake game


## Functions

| Name | Description |
| ---- | ----------- |
| [SnakeGame](#SnakeGame) | @brief Constructor :material-location-enter: `cyclical` :    Whether the game has cyclical borders (snake can go through walls)  |
| [update](#update) | @brief Destructor @brief Updates the game state :material-location-enter: `delta` :    Time elapsed since last update in seconds  |
| [adjustPosition](#adjustPosition) | @brief Adjusts position for cyclical boundaries Snake can pass through walls and appear on the other side if enabled :material-location-enter: `pos` :    Position to adjust :material-keyboard-return: **Return** :    Adjusted position  |
| [checkCollisions](#checkCollisions) | @brief Checks collisions specific to Snake game In Snake, colliding with walls is fatal unless cyclical borders are enabled :material-keyboard-return: **Return** :    Type of collision detected  |
| [initGrid](#initGrid) | @brief Initialize the grid for Snake Snake has a simple empty grid without obstacles  |
| [onGameOver](#onGameOver) | @brief Handles the game over state Displays game over screen and plays sound  |
| [getWindowTitle](#getWindowTitle) | @brief Creates the window title for Snake :material-keyboard-return: **Return** :    Window title string  |

## Function Details

### SnakeGame<a name="SnakeGame"></a>
!!! function "explicit SnakeGame(bool cyclical = false)"

    @brief Constructor
    
    :material-location-enter: `cyclical`
    :    Whether the game has cyclical borders (snake can go through walls)
    

### adjustPosition<a name="adjustPosition"></a>
!!! function "Vector&lt;float&gt; adjustPosition(const Vector&lt;float&gt;&amp; pos) const override"

    @brief Adjusts position for cyclical boundaries
        Snake can pass through walls and appear on the other side if enabled
        
    :material-location-enter: `pos`
    :    Position to adjust
        
    :material-keyboard-return: **Return**
    :    Adjusted position
    

### checkCollisions<a name="checkCollisions"></a>
!!! function "CollisionType checkCollisions() override"

    @brief Checks collisions specific to Snake game
        In Snake, colliding with walls is fatal unless cyclical borders are enabled
        
    :material-keyboard-return: **Return**
    :    Type of collision detected
    

### getWindowTitle<a name="getWindowTitle"></a>
!!! function "std::string getWindowTitle() const"

    @brief Creates the window title for Snake
        
    :material-keyboard-return: **Return**
    :    Window title string
    

### initGrid<a name="initGrid"></a>
!!! function "void initGrid() override"

    @brief Initialize the grid for Snake
        Snake has a simple empty grid without obstacles
    

### onGameOver<a name="onGameOver"></a>
!!! function "void onGameOver() override"

    @brief Handles the game over state
        Displays game over screen and plays sound
    

### update<a name="update"></a>
!!! function "void update(float delta) override"

    @brief Destructor
    @brief Updates the game state
        
    :material-location-enter: `delta`
    :    Time elapsed since last update in seconds
    

