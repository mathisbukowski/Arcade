---
generator: doxide
---


# Core

**class Core**

class Core
    Main class for the Arcade game engine.


## Variables

| Name | Description |
| ---- | ----------- |
| [_state](#_state) | Current state of the game  |
| [_playerName](#_playerName) | Player's name  |
| [_scores](#_scores) | Scores vector  |
| [_libManager](#_libManager) | Library manager for loading dynamic libraries  |
| [_currentGraphicLib](#_currentGraphicLib) | Pointer to the current graphics library  |
| [_currentGame](#_currentGame) | Pointer to the current game library  |
| [_lastFrameTime](#_lastFrameTime) | chrono to keep track of the last frame time  |
| [_deltaTime](#_deltaTime) | Time since the last frame  |
| [_selectedGameIndex](#_selectedGameIndex) | index of the selected game  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Core](#Core) | Constructor :material-location-enter: `initialLibPath` :    const std::string & Path to the initial library  |
| [~Core](#_u007eCore) | Destructor of the Core class  |
| [run](#run) | Run the main loop of the game engine  |
| [initializeGraphicsLib](#initializeGraphicsLib) | Initialize the graphics library :material-location-enter: `path` :    const std::string & Path to the library  |
| [initializeGameLib](#initializeGameLib) | Initialize the game library  |
| [updateMenu](#updateMenu) | Update the menu state  |
| [updateGame](#updateGame) | Update the game state  |
| [displayMenu](#displayMenu) | Display the menu  |
| [displayGame](#displayGame) | Display the game  |
| [loadScores](#loadScores) | Load scores from a file  |
| [saveScores](#saveScores) | Save scores to a file  |
| [switchGraphicsLib](#switchGraphicsLib) | Switch the graphics library :material-location-enter: `libName` :    const std::string & Name of the library to switch to  |
| [switchGame](#switchGame) | Switch the game library :material-location-enter: `gameName` :    const std::string & Name of the game to switch to  |
| [restartGame](#restartGame) | Restart the current game  |
| [goToMenu](#goToMenu) | Go to the menu state  |
| [handleMenuInput](#handleMenuInput) | Handle input for the menu  |
| [handleGameInput](#handleGameInput) | Handle input for the game  |
| [updateDeltaTime](#updateDeltaTime) | update the delta time  |
| [renderGameList](#renderGameList) | Render the game list :material-location-enter: `x` :    int X position :material-location-enter: `y` :    int Y position  |
| [renderGraphicsList](#renderGraphicsList) | Render the graphics list :material-location-enter: `x` :    int X position :material-location-enter: `y` :    int Y position  |
| [renderScores](#renderScores) | Render the scores :material-location-enter: `x` :    int X position :material-location-enter: `y` :    int Y position  |
| [renderPlayerNameInput](#renderPlayerNameInput) | Render the player name input :material-location-enter: `x` :    int X position :material-location-enter: `y` :    int Y position  |
| [checkGameListClicks](#checkGameListClicks) | Check if the mouse is clicked on the game list :material-location-enter: `mouseX` :    float X position of the mouse :material-location-enter: `mouseY` :    float Y position of the mouse  |

## Variable Details

### _currentGame<a name="_currentGame"></a>

!!! variable "std::shared_ptr&lt;IGameModule&gt; _currentGame"

    Pointer to the current game library
    

### _currentGraphicLib<a name="_currentGraphicLib"></a>

!!! variable "std::shared_ptr&lt;IDisplayLibrary&gt; _currentGraphicLib"

    Pointer to the current graphics library
    

### _deltaTime<a name="_deltaTime"></a>

!!! variable "float _deltaTime"

    Time since the last frame
    

### _lastFrameTime<a name="_lastFrameTime"></a>

!!! variable "std::chrono::high_resolution_clock::time_point _lastFrameTime"

    chrono to keep track of the last frame time
    

### _libManager<a name="_libManager"></a>

!!! variable "std::unique_ptr&lt;DynamicLibraryManager&gt; _libManager"

    Library manager for loading dynamic libraries
    

### _playerName<a name="_playerName"></a>

!!! variable "std::string _playerName"

    Player's name
    

### _scores<a name="_scores"></a>

!!! variable "std::vector&lt;Score&gt; _scores"

    Scores vector
    

### _selectedGameIndex<a name="_selectedGameIndex"></a>

!!! variable "int _selectedGameIndex"

    index of the selected game
    

### _state<a name="_state"></a>

!!! variable "GameState _state"

    Current state of the game
    

## Function Details

### Core<a name="Core"></a>
!!! function "Core(const std::string&amp; initialLibPath)"

    Constructor
        
    :material-location-enter: `initialLibPath`
    :    const std::string & Path to the initial library
    

### checkGameListClicks<a name="checkGameListClicks"></a>
!!! function "void checkGameListClicks(float mouseX, float mouseY)"

    Check if the mouse is clicked on the game list
        
    :material-location-enter: `mouseX`
    :    float X position of the mouse
        
    :material-location-enter: `mouseY`
    :    float Y position of the mouse
    

### displayGame<a name="displayGame"></a>
!!! function "void displayGame()"

    Display the game
    

### displayMenu<a name="displayMenu"></a>
!!! function "void displayMenu()"

    Display the menu
    

### goToMenu<a name="goToMenu"></a>
!!! function "void goToMenu()"

    Go to the menu state
    

### handleGameInput<a name="handleGameInput"></a>
!!! function "void handleGameInput()"

    Handle input for the game
    

### handleMenuInput<a name="handleMenuInput"></a>
!!! function "void handleMenuInput()"

    Handle input for the menu
    

### initializeGameLib<a name="initializeGameLib"></a>
!!! function "void initializeGameLib()"

    Initialize the game library
    

### initializeGraphicsLib<a name="initializeGraphicsLib"></a>
!!! function "void initializeGraphicsLib(const std::string&amp; path)"

    Initialize the graphics library
        
    :material-location-enter: `path`
    :    const std::string & Path to the library
    

### loadScores<a name="loadScores"></a>
!!! function "void loadScores()"

    Load scores from a file
    

### renderGameList<a name="renderGameList"></a>
!!! function "void renderGameList(int x, int y)"

    Render the game list
        
    :material-location-enter: `x`
    :    int X position
        
    :material-location-enter: `y`
    :    int Y position
    

### renderGraphicsList<a name="renderGraphicsList"></a>
!!! function "void renderGraphicsList(int x, int y)"

    Render the graphics list
        
    :material-location-enter: `x`
    :    int X position
        
    :material-location-enter: `y`
    :    int Y position
    

### renderPlayerNameInput<a name="renderPlayerNameInput"></a>
!!! function "void renderPlayerNameInput(int x, int y)"

    Render the player name input
        
    :material-location-enter: `x`
    :    int X position
        
    :material-location-enter: `y`
    :    int Y position
    

### renderScores<a name="renderScores"></a>
!!! function "void renderScores(int x, int y)"

    Render the scores
        
    :material-location-enter: `x`
    :    int X position
        
    :material-location-enter: `y`
    :    int Y position
    

### restartGame<a name="restartGame"></a>
!!! function "void restartGame()"

    Restart the current game
    

### run<a name="run"></a>
!!! function "void run()"

    Run the main loop of the game engine
    

### saveScores<a name="saveScores"></a>
!!! function "void saveScores()"

    Save scores to a file
    

### switchGame<a name="switchGame"></a>
!!! function "void switchGame(const std::string&amp; gameName)"

    Switch the game library
        
    :material-location-enter: `gameName`
    :    const std::string & Name of the game to switch to
    

### switchGraphicsLib<a name="switchGraphicsLib"></a>
!!! function "void switchGraphicsLib(const std::string&amp; libName)"

    Switch the graphics library
        
    :material-location-enter: `libName`
    :    const std::string & Name of the library to switch to
    

### updateDeltaTime<a name="updateDeltaTime"></a>
!!! function "void updateDeltaTime()"

    update the delta time
    

### updateGame<a name="updateGame"></a>
!!! function "void updateGame()"

    Update the game state
    

### updateMenu<a name="updateMenu"></a>
!!! function "void updateMenu()"

    Update the menu state
    

### ~Core<a name="_u007eCore"></a>
!!! function "~Core()"

    Destructor of the Core class
    

