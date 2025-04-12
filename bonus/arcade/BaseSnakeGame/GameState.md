---
generator: doxide
---


# GameState

**class GameState**

class GameState
Internal class that manages the state of the game.


## Functions

| Name | Description |
| ---- | ----------- |
| [GameState](#GameState) | Constructor Initializes the game state  |
| [getSegments](#getSegments) | Get snake segments :material-keyboard-return: **Return** :    const std::deque<Vector<float>>& Reference to snake segments  |
| [getCurrentDirection](#getCurrentDirection) | Get current direction :material-keyboard-return: **Return** :    Direction Current movement direction  |
| [getNextDirection](#getNextDirection) | Get next direction :material-keyboard-return: **Return** :    Direction Next movement direction  |
| [getBonusFoods](#getBonusFoods) | Get bonus foods :material-keyboard-return: **Return** :    const std::vector<Vector<float>>& Reference to bonus foods  |
| [getGrid](#getGrid) | Get grid :material-keyboard-return: **Return** :    const std::vector<std::vector<CellType>>& Reference to grid  |
| [getScore](#getScore) | Get score :material-keyboard-return: **Return** :    int Current score  |
| [isGameOver](#isGameOver) | Check if game is over :material-keyboard-return: **Return** :    bool True if game is over  |
| [getMoveTimer](#getMoveTimer) | Get move timer :material-keyboard-return: **Return** :    float Current move timer value  |
| [getMoveInterval](#getMoveInterval) | Get move interval :material-keyboard-return: **Return** :    float Current move interval value  |
| [getBonusFoodTimer](#getBonusFoodTimer) | Get bonus food timer :material-keyboard-return: **Return** :    float Current bonus food timer value  |
| [getBonusFoodDuration](#getBonusFoodDuration) | Get bonus food duration :material-keyboard-return: **Return** :    float Current bonus food duration  |
| [getLevel](#getLevel) | Get level :material-keyboard-return: **Return** :    int Current level  |
| [getTimeRemaining](#getTimeRemaining) | Get time remaining :material-keyboard-return: **Return** :    float Time remaining in seconds  |
| [getPlayerName](#getPlayerName) | Get player name :material-keyboard-return: **Return** :    const std::string& Reference to player name  |
| [getMode](#getMode) | Get game mode :material-keyboard-return: **Return** :    GameMode Current game mode  |
| [getHead](#getHead) | Get head position :material-keyboard-return: **Return** :    Vector<float> Position of snake head  |
| [getTail](#getTail) | Get tail position :material-keyboard-return: **Return** :    Vector<float> Position of snake tail  |
| [getLength](#getLength) | Get snake length :material-keyboard-return: **Return** :    size_t Length of the snake  |
| [hasFoods](#hasFoods) | Check if foods exist :material-keyboard-return: **Return** :    bool True if foods exist  |
| [hasBonusFoods](#hasBonusFoods) | Check if bonus foods exist :material-keyboard-return: **Return** :    bool True if bonus foods exist  |
| [getFoods](#getFoods) | Get foods :material-keyboard-return: **Return** :    const std::vector<Vector<float>>& Reference to foods  |
| [setCurrentDirection](#setCurrentDirection) | Set current direction :material-location-enter: `dir` :    Direction New current direction  |
| [setNextDirection](#setNextDirection) | Set next direction :material-location-enter: `dir` :    Direction New next direction  |
| [setScore](#setScore) | Set score :material-location-enter: `newScore` :    int New score value  |
| [setGameOver](#setGameOver) | Set game over state :material-location-enter: `over` :    bool New game over state  |
| [setMoveTimer](#setMoveTimer) | Set move timer :material-location-enter: `timer` :    float New move timer value  |
| [setMoveInterval](#setMoveInterval) | Set move interval :material-location-enter: `interval` :    float New move interval value  |
| [setBonusFoodTimer](#setBonusFoodTimer) | Set bonus food timer :material-location-enter: `timer` :    float New bonus food timer value  |
| [setBonusFoodDuration](#setBonusFoodDuration) | Set bonus food duration :material-location-enter: `duration` :    float New bonus food duration  |
| [setLevel](#setLevel) | Set level :material-location-enter: `newLevel` :    int New level value  |
| [setTimeRemaining](#setTimeRemaining) | Set time remaining :material-location-enter: `time` :    float New time remaining value  |
| [setPlayerName](#setPlayerName) | Set player name :material-location-enter: `name` :    const std::string& New player name  |
| [setMode](#setMode) | Set game mode :material-location-enter: `newMode` :    GameMode New game mode  |
| [addSegment](#addSegment) | Add segment to the snake :material-location-enter: `segment` :    const Vector<float>& Position of new segment  |
| [prependSegment](#prependSegment) | Prepend segment to the snake :material-location-enter: `segment` :    const Vector<float>& Position of new segment  |
| [removeLastSegment](#removeLastSegment) | Remove last segment of the snake  |
| [clearSegments](#clearSegments) | Clear all snake segments  |
| [addFood](#addFood) | Add food :material-location-enter: `food` :    const Vector<float>& Position of new food  |
| [removeFood](#removeFood) | Remove food at specific index :material-location-enter: `index` :    size_t Index of food to remove  |
| [clearFoods](#clearFoods) | Clear all foods  |
| [addBonusFood](#addBonusFood) | Add bonus food :material-location-enter: `food` :    const Vector<float>& Position of new bonus food  |
| [removeBonusFood](#removeBonusFood) | Remove bonus food at specific index :material-location-enter: `index` :    size_t Index of bonus food to remove  |
| [clearBonusFoods](#clearBonusFoods) | Clear all bonus foods  |
| [resizeGrid](#resizeGrid) | Resize grid :material-location-enter: `height` :    size_t New grid height :material-location-enter: `width` :    size_t New grid width  |
| [setCellType](#setCellType) | Set cell type :material-location-enter: `y` :    size_t Y coordinate :material-location-enter: `x` :    size_t X coordinate :material-location-enter: `type` :    CellType New cell type  |
| [incrementScore](#incrementScore) | Increment score :material-location-enter: `points` :    int Points to add  |
| [decrementTimeRemaining](#decrementTimeRemaining) | Decrement time remaining :material-location-enter: `delta` :    float Time to subtract  |

## Function Details

### GameState<a name="GameState"></a>
!!! function "GameState()"

    Constructor
    Initializes the game state
    

### addBonusFood<a name="addBonusFood"></a>
!!! function "void addBonusFood(const Vector&lt;float&gt;&amp; food)"

    Add bonus food
        
    :material-location-enter: `food`
    :    const Vector<float>& Position of new bonus food
    

### addFood<a name="addFood"></a>
!!! function "void addFood(const Vector&lt;float&gt;&amp; food)"

    Add food
        
    :material-location-enter: `food`
    :    const Vector<float>& Position of new food
    

### addSegment<a name="addSegment"></a>
!!! function "void addSegment(const Vector&lt;float&gt;&amp; segment)"

    Add segment to the snake
        
    :material-location-enter: `segment`
    :    const Vector<float>& Position of new segment
    

### clearBonusFoods<a name="clearBonusFoods"></a>
!!! function "void clearBonusFoods()"

    Clear all bonus foods
    

### clearFoods<a name="clearFoods"></a>
!!! function "void clearFoods()"

    Clear all foods
    

### clearSegments<a name="clearSegments"></a>
!!! function "void clearSegments()"

    Clear all snake segments
    

### decrementTimeRemaining<a name="decrementTimeRemaining"></a>
!!! function "void decrementTimeRemaining(float delta)"

    Decrement time remaining
        
    :material-location-enter: `delta`
    :    float Time to subtract
    

### getBonusFoodDuration<a name="getBonusFoodDuration"></a>
!!! function "float getBonusFoodDuration() const"

    Get bonus food duration
    
    :material-keyboard-return: **Return**
    :    float Current bonus food duration
    

### getBonusFoodTimer<a name="getBonusFoodTimer"></a>
!!! function "float getBonusFoodTimer() const"

    Get bonus food timer
    
    :material-keyboard-return: **Return**
    :    float Current bonus food timer value
    

### getBonusFoods<a name="getBonusFoods"></a>
!!! function "const std::vector&lt;Vector&lt;float&gt;&gt;&amp; getBonusFoods() const"

    Get bonus foods
    
    :material-keyboard-return: **Return**
    :    const std::vector<Vector<float>>& Reference to bonus foods
    

### getCurrentDirection<a name="getCurrentDirection"></a>
!!! function "Direction getCurrentDirection() const"

    Get current direction
    
    :material-keyboard-return: **Return**
    :    Direction Current movement direction
    

### getFoods<a name="getFoods"></a>
!!! function "const std::vector&lt;Vector&lt;float&gt;&gt;&amp; getFoods() const"

    Get foods
    
    :material-keyboard-return: **Return**
    :    const std::vector<Vector<float>>& Reference to foods
    

### getGrid<a name="getGrid"></a>
!!! function "const std::vector&lt;std::vector&lt;CellType&gt;&gt;&amp; getGrid() const"

    Get grid
    
    :material-keyboard-return: **Return**
    :    const std::vector<std::vector<CellType>>& Reference to grid
    

### getHead<a name="getHead"></a>
!!! function "Vector&lt;float&gt; getHead() const"

    Get head position
    
    :material-keyboard-return: **Return**
    :    Vector<float> Position of snake head
    

### getLength<a name="getLength"></a>
!!! function "size_t getLength() const"

    Get snake length
    
    :material-keyboard-return: **Return**
    :    size_t Length of the snake
    

### getLevel<a name="getLevel"></a>
!!! function "int getLevel() const"

    Get level
    
    :material-keyboard-return: **Return**
    :    int Current level
    

### getMode<a name="getMode"></a>
!!! function "GameMode getMode() const"

    Get game mode
    
    :material-keyboard-return: **Return**
    :    GameMode Current game mode
    

### getMoveInterval<a name="getMoveInterval"></a>
!!! function "float getMoveInterval() const"

    Get move interval
    
    :material-keyboard-return: **Return**
    :    float Current move interval value
    

### getMoveTimer<a name="getMoveTimer"></a>
!!! function "float getMoveTimer() const"

    Get move timer
    
    :material-keyboard-return: **Return**
    :    float Current move timer value
    

### getNextDirection<a name="getNextDirection"></a>
!!! function "Direction getNextDirection() const"

    Get next direction
    
    :material-keyboard-return: **Return**
    :    Direction Next movement direction
    

### getPlayerName<a name="getPlayerName"></a>
!!! function "const std::string&amp; getPlayerName() const"

    Get player name
    
    :material-keyboard-return: **Return**
    :    const std::string& Reference to player name
    

### getScore<a name="getScore"></a>
!!! function "int getScore() const"

    Get score
    
    :material-keyboard-return: **Return**
    :    int Current score
    

### getSegments<a name="getSegments"></a>
!!! function "const std::deque&lt;Vector&lt;float&gt;&gt;&amp; getSegments() const"

    Get snake segments
    
    :material-keyboard-return: **Return**
    :    const std::deque<Vector<float>>& Reference to snake segments
    

### getTail<a name="getTail"></a>
!!! function "Vector&lt;float&gt; getTail() const"

    Get tail position
    
    :material-keyboard-return: **Return**
    :    Vector<float> Position of snake tail
    

### getTimeRemaining<a name="getTimeRemaining"></a>
!!! function "float getTimeRemaining() const"

    Get time remaining
    
    :material-keyboard-return: **Return**
    :    float Time remaining in seconds
    

### hasBonusFoods<a name="hasBonusFoods"></a>
!!! function "bool hasBonusFoods() const"

    Check if bonus foods exist
    
    :material-keyboard-return: **Return**
    :    bool True if bonus foods exist
    

### hasFoods<a name="hasFoods"></a>
!!! function "bool hasFoods() const"

    Check if foods exist
    
    :material-keyboard-return: **Return**
    :    bool True if foods exist
    

### incrementScore<a name="incrementScore"></a>
!!! function "void incrementScore(int points)"

    Increment score
        
    :material-location-enter: `points`
    :    int Points to add
    

### isGameOver<a name="isGameOver"></a>
!!! function "bool isGameOver() const"

    Check if game is over
    
    :material-keyboard-return: **Return**
    :    bool True if game is over
    

### prependSegment<a name="prependSegment"></a>
!!! function "void prependSegment(const Vector&lt;float&gt;&amp; segment)"

    Prepend segment to the snake
        
    :material-location-enter: `segment`
    :    const Vector<float>& Position of new segment
    

### removeBonusFood<a name="removeBonusFood"></a>
!!! function "void removeBonusFood(size_t index)"

    Remove bonus food at specific index
        
    :material-location-enter: `index`
    :    size_t Index of bonus food to remove
    

### removeFood<a name="removeFood"></a>
!!! function "void removeFood(size_t index)"

    Remove food at specific index
        
    :material-location-enter: `index`
    :    size_t Index of food to remove
    

### removeLastSegment<a name="removeLastSegment"></a>
!!! function "void removeLastSegment()"

    Remove last segment of the snake
    

### resizeGrid<a name="resizeGrid"></a>
!!! function "void resizeGrid(size_t height, size_t width)"

    Resize grid
        
    :material-location-enter: `height`
    :    size_t New grid height
        
    :material-location-enter: `width`
    :    size_t New grid width
    

### setBonusFoodDuration<a name="setBonusFoodDuration"></a>
!!! function "void setBonusFoodDuration(float duration)"

    Set bonus food duration
        
    :material-location-enter: `duration`
    :    float New bonus food duration
    

### setBonusFoodTimer<a name="setBonusFoodTimer"></a>
!!! function "void setBonusFoodTimer(float timer)"

    Set bonus food timer
        
    :material-location-enter: `timer`
    :    float New bonus food timer value
    

### setCellType<a name="setCellType"></a>
!!! function "void setCellType(size_t y, size_t x, CellType type)"

    Set cell type
        
    :material-location-enter: `y`
    :    size_t Y coordinate
        
    :material-location-enter: `x`
    :    size_t X coordinate
        
    :material-location-enter: `type`
    :    CellType New cell type
    

### setCurrentDirection<a name="setCurrentDirection"></a>
!!! function "void setCurrentDirection(Direction dir)"

    Set current direction
    
    :material-location-enter: `dir`
    :    Direction New current direction
    

### setGameOver<a name="setGameOver"></a>
!!! function "void setGameOver(bool over)"

    Set game over state
        
    :material-location-enter: `over`
    :    bool New game over state
    

### setLevel<a name="setLevel"></a>
!!! function "void setLevel(int newLevel)"

    Set level
        
    :material-location-enter: `newLevel`
    :    int New level value
    

### setMode<a name="setMode"></a>
!!! function "void setMode(GameMode newMode)"

    Set game mode
        
    :material-location-enter: `newMode`
    :    GameMode New game mode
    

### setMoveInterval<a name="setMoveInterval"></a>
!!! function "void setMoveInterval(float interval)"

    Set move interval
        
    :material-location-enter: `interval`
    :    float New move interval value
    

### setMoveTimer<a name="setMoveTimer"></a>
!!! function "void setMoveTimer(float timer)"

    Set move timer
        
    :material-location-enter: `timer`
    :    float New move timer value
    

### setNextDirection<a name="setNextDirection"></a>
!!! function "void setNextDirection(Direction dir)"

    Set next direction
        
    :material-location-enter: `dir`
    :    Direction New next direction
    

### setPlayerName<a name="setPlayerName"></a>
!!! function "void setPlayerName(const std::string&amp; name)"

    Set player name
        
    :material-location-enter: `name`
    :    const std::string& New player name
    

### setScore<a name="setScore"></a>
!!! function "void setScore(int newScore)"

    Set score
        
    :material-location-enter: `newScore`
    :    int New score value
    

### setTimeRemaining<a name="setTimeRemaining"></a>
!!! function "void setTimeRemaining(float time)"

    Set time remaining
        
    :material-location-enter: `time`
    :    float New time remaining value
    

