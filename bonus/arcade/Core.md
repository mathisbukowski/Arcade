---
generator: doxide
---


# Core

**class Core**


    Main class for the Arcade game engine.


## Functions

| Name | Description |
| ---- | ----------- |
| [Core](#Core) | Constructor :material-location-enter: `initialLibPath` :    Path to the initial library  |
| [~Core](#_u007eCore) | Destructor  |
| [run](#run) | Main game loop  |
| [initializeGraphicsLib](#initializeGraphicsLib) | Initialize the graphics library :material-location-enter: `path` :    Path to the library  |
| [initializeGameLib](#initializeGameLib) | Initialize the game library  |
| [updateDeltaTime](#updateDeltaTime) | update the main programm  |
| [updateMenu](#updateMenu) | update the menu  |
| [updateGame](#updateGame) | update the game state  |
| [displayMenu](#displayMenu) | display the menu  |
| [displayGame](#displayGame) | display the game  |
| [loadScores](#loadScores) | Load scores from a file  |
| [saveScores](#saveScores) | Save new scores  |
| [switchGraphicsLib](#switchGraphicsLib) | Switch to a different graphics library or game :material-location-enter: `libName` :    Name of the graphics library  |
| [switchGame](#switchGame) | Switch to a different game :material-location-enter: `gameName` :    Name of the game  |
| [restartGame](#restartGame) | Restart the current game  |
| [tryRestartGame](#tryRestartGame) | Try to restart the game  |
| [trySwitchToNextGame](#trySwitchToNextGame) | Try to switch to the next game  |
| [goToMenu](#goToMenu) | Go to the menu of Arcade  |
| [prepareMenuDisplay](#prepareMenuDisplay) | Prepare the menu  |
| [drawMenuSectionBackgrounds](#drawMenuSectionBackgrounds) | draw the menu section  |
| [drawMenuTitle](#drawMenuTitle) | draw the menu title  |
| [renderMenuSections](#renderMenuSections) | render the menu sections  |
| [renderMenuInstructions](#renderMenuInstructions) | render the menu instructions  |
| [processMenuKeyboardInput](#processMenuKeyboardInput) | Process keyboard input for the menu :material-location-enter: `keyboard` :    Keyboard object :material-keyboard-return: **Return** :    true if the input was processed, false otherwise  |
| [handleMenuInput](#handleMenuInput) | Handle all input for the menu and game  |
| [isKeyJustPressed](#isKeyJustPressed) | Check if a key was just pressed :material-location-enter: `keyboard` :    Keyboard object :material-location-enter: `key` :    Key code :material-location-enter: `previousState` :    Previous state of the key :material-keyboard-return: **Return** :    true if the key was just pressed, false otherwise  |
| [navigateMenuUp](#navigateMenuUp) | Navigate the menu up, down, left, right  |
| [navigateGamesListUp](#navigateGamesListUp) | Navigate the game and graphics lists up and down  |
| [handleMenuSelection](#handleMenuSelection) | Handle selection in the menu  |
| [renderGameList](#renderGameList) | Render game list :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderGraphicsList](#renderGraphicsList) | Render graphics list :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderScores](#renderScores) | Render scores :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderPlayerNameInput](#renderPlayerNameInput) | Render player name input :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderMenuListTitle](#renderMenuListTitle) | Render menu title :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position :material-location-enter: `title` :    Title text :material-location-enter: `section` :    Menu section :material-location-enter: `textureName` :    Texture name  |
| [renderGameItems](#renderGameItems) | Render game items :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderGraphicsItems](#renderGraphicsItems) | Render graphics items :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderMenuItem](#renderMenuItem) | Render menu item :material-location-enter: `textureName` :    Texture name :material-location-enter: `text` :    Text to display :material-location-enter: `color` :    Color of the text :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [renderScoreItems](#renderScoreItems) | Render score items :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position  |
| [drawMenuSection](#drawMenuSection) | Draw Menu Section :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position :material-location-enter: `width` :    Width of the section :material-location-enter: `height` :    Height of the section :material-location-enter: `name` :    Name of the section :material-location-enter: `color` :    Color of the section  |
| [isItemHovered](#isItemHovered) | Check if the mouse is hovering over an item :material-location-enter: `x` :    X position :material-location-enter: `y` :    Y position :material-location-enter: `width` :    Width of the item :material-location-enter: `height` :    Height of the item :material-location-enter: `mousePos` :    Mouse position :material-keyboard-return: **Return** :    true if the item is hovered, false otherwise  |
| [getItemTextColor](#getItemTextColor) | Get the color of the item text based on its state :material-location-enter: `isSelected` :    Is the item selected :material-location-enter: `isHovered` :    Is the item hovered :material-location-enter: `isCurrent` :    Is the item current :material-keyboard-return: **Return** :    Color of the item text  |
| [checkMenuClicks](#checkMenuClicks) | Check mouse clicks :material-location-enter: `mouseX` :    X position of the mouse :material-location-enter: `mouseY` :    Y position of the mouse  |

## Function Details

### Core<a name="Core"></a>
!!! function "Core(const std::string&amp; initialLibPath)"

    Constructor
        
    :material-location-enter: `initialLibPath`
    :    Path to the initial library
    

### checkMenuClicks<a name="checkMenuClicks"></a>
!!! function "void checkMenuClicks(float mouseX, float mouseY)"

    Check mouse clicks
        
    :material-location-enter: `mouseX`
    :    X position of the mouse
        
    :material-location-enter: `mouseY`
    :    Y position of the mouse
    

### displayGame<a name="displayGame"></a>
!!! function "void displayGame()"

    display the game
    

### displayMenu<a name="displayMenu"></a>
!!! function "void displayMenu()"

    display the menu
    

### drawMenuSection<a name="drawMenuSection"></a>
!!! function "void drawMenuSection(float x, float y, float width, float height, const std::string&amp; name, Color color)"

    Draw Menu Section
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
        
    :material-location-enter: `width`
    :    Width of the section
        
    :material-location-enter: `height`
    :    Height of the section
        
    :material-location-enter: `name`
    :    Name of the section
        
    :material-location-enter: `color`
    :    Color of the section
    

### drawMenuSectionBackgrounds<a name="drawMenuSectionBackgrounds"></a>
!!! function "void drawMenuSectionBackgrounds()"

    draw the menu section
    

### drawMenuTitle<a name="drawMenuTitle"></a>
!!! function "void drawMenuTitle()"

    draw the menu title
    

### getItemTextColor<a name="getItemTextColor"></a>
!!! function "Color getItemTextColor(bool isSelected, bool isHovered, bool isCurrent) const"

    Get the color of the item text based on its state
        
    :material-location-enter: `isSelected`
    :    Is the item selected
        
    :material-location-enter: `isHovered`
    :    Is the item hovered
        
    :material-location-enter: `isCurrent`
    :    Is the item current
        
    :material-keyboard-return: **Return**
    :    Color of the item text
    

### goToMenu<a name="goToMenu"></a>
!!! function "void goToMenu()"

    Go to the menu of Arcade
    

### handleMenuInput<a name="handleMenuInput"></a>
!!! function "void handleMenuInput()"

    Handle all input for the menu and game
    

### handleMenuSelection<a name="handleMenuSelection"></a>
!!! function "void handleMenuSelection()"

    Handle selection in the menu
    

### initializeGameLib<a name="initializeGameLib"></a>
!!! function "void initializeGameLib()"

    Initialize the game library
    

### initializeGraphicsLib<a name="initializeGraphicsLib"></a>
!!! function "void initializeGraphicsLib(const std::string&amp; path)"

    Initialize the graphics library
        
    :material-location-enter: `path`
    :    Path to the library
    

### isItemHovered<a name="isItemHovered"></a>
!!! function "bool isItemHovered(float x, float y, float width, float height, const Vector&lt;float&gt;&amp; mousePos) const"

    Check if the mouse is hovering over an item
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
        
    :material-location-enter: `width`
    :    Width of the item
        
    :material-location-enter: `height`
    :    Height of the item
        
    :material-location-enter: `mousePos`
    :    Mouse position
        
    :material-keyboard-return: **Return**
    :    true if the item is hovered, false otherwise
    

### isKeyJustPressed<a name="isKeyJustPressed"></a>
!!! function "bool isKeyJustPressed(Keyboard&amp; keyboard, Keyboard::KeyCode key, bool&amp; previousState)"

    Check if a key was just pressed
        
    :material-location-enter: `keyboard`
    :    Keyboard object
        
    :material-location-enter: `key`
    :    Key code
        
    :material-location-enter: `previousState`
    :    Previous state of the key
        
    :material-keyboard-return: **Return**
    :    true if the key was just pressed, false otherwise
    

### loadScores<a name="loadScores"></a>
!!! function "void loadScores()"

    Load scores from a file
    

### navigateGamesListUp<a name="navigateGamesListUp"></a>
!!! function "void navigateGamesListUp()"

    Navigate the game and graphics lists up and down
    

### navigateMenuUp<a name="navigateMenuUp"></a>
!!! function "void navigateMenuUp()"

    Navigate the menu up, down, left, right
    

### prepareMenuDisplay<a name="prepareMenuDisplay"></a>
!!! function "void prepareMenuDisplay()"

    Prepare the menu
    

### processMenuKeyboardInput<a name="processMenuKeyboardInput"></a>
!!! function "bool processMenuKeyboardInput(Keyboard&amp; keyboard)"

    Process keyboard input for the menu
        
    :material-location-enter: `keyboard`
    :    Keyboard object
        
    :material-keyboard-return: **Return**
    :    true if the input was processed, false otherwise
    

### renderGameItems<a name="renderGameItems"></a>
!!! function "void renderGameItems(float x, float y)"

    Render game items
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderGameList<a name="renderGameList"></a>
!!! function "void renderGameList(float x, float y)"

    Render game list
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderGraphicsItems<a name="renderGraphicsItems"></a>
!!! function "void renderGraphicsItems(float x, float y)"

    Render graphics items
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderGraphicsList<a name="renderGraphicsList"></a>
!!! function "void renderGraphicsList(float x, float y)"

    Render graphics list
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderMenuInstructions<a name="renderMenuInstructions"></a>
!!! function "void renderMenuInstructions()"

    render the menu instructions
    

### renderMenuItem<a name="renderMenuItem"></a>
!!! function "void renderMenuItem(const std::string&amp; textureName, const std::string&amp; text, Color color, float x, float y)"

    Render menu item
        
    :material-location-enter: `textureName`
    :    Texture name
        
    :material-location-enter: `text`
    :    Text to display
        
    :material-location-enter: `color`
    :    Color of the text
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderMenuListTitle<a name="renderMenuListTitle"></a>
!!! function "void renderMenuListTitle(float x, float y, const std::string&amp; title, MenuSection section, const std::string&amp; textureName)"

    Render menu title
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
        
    :material-location-enter: `title`
    :    Title text
        
    :material-location-enter: `section`
    :    Menu section
        
    :material-location-enter: `textureName`
    :    Texture name
    

### renderMenuSections<a name="renderMenuSections"></a>
!!! function "void renderMenuSections()"

    render the menu sections
    

### renderPlayerNameInput<a name="renderPlayerNameInput"></a>
!!! function "void renderPlayerNameInput(float x, float y)"

    Render player name input
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderScoreItems<a name="renderScoreItems"></a>
!!! function "void renderScoreItems(float x, float y)"

    Render score items
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### renderScores<a name="renderScores"></a>
!!! function "void renderScores(float x, float y)"

    Render scores
        
    :material-location-enter: `x`
    :    X position
        
    :material-location-enter: `y`
    :    Y position
    

### restartGame<a name="restartGame"></a>
!!! function "void restartGame()"

    Restart the current game
    

### run<a name="run"></a>
!!! function "void run()"

    Main game loop
    

### saveScores<a name="saveScores"></a>
!!! function "void saveScores()"

    Save new scores
    

### switchGame<a name="switchGame"></a>
!!! function "void switchGame(const std::string&amp; gameName)"

    Switch to a different game
        
    :material-location-enter: `gameName`
    :    Name of the game
    

### switchGraphicsLib<a name="switchGraphicsLib"></a>
!!! function "void switchGraphicsLib(const std::string&amp; libName)"

    Switch to a different graphics library or game
        
    :material-location-enter: `libName`
    :    Name of the graphics library
    

### tryRestartGame<a name="tryRestartGame"></a>
!!! function "void tryRestartGame()"

    Try to restart the game
    

### trySwitchToNextGame<a name="trySwitchToNextGame"></a>
!!! function "void trySwitchToNextGame()"

    Try to switch to the next game
    

### updateDeltaTime<a name="updateDeltaTime"></a>
!!! function "void updateDeltaTime()"

    update the main programm
    

### updateGame<a name="updateGame"></a>
!!! function "void updateGame()"

    update the game state
    

### updateMenu<a name="updateMenu"></a>
!!! function "void updateMenu()"

    update the menu
    

### ~Core<a name="_u007eCore"></a>
!!! function "~Core()"

    Destructor
    

