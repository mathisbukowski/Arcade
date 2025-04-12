---
generator: doxide
---


# SFMLDisplay

**class SFMLDisplay : public IDisplayModule**

 of IDisplayModule for SFML
This class is used to create a display using the SFML library
It inherits from the IDisplayModule interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_name](#_name) | Window name  |
| [_window](#_window) | SFML window  |
| [_keyboard](#_keyboard) | Keyboard object  |
| [_mouse](#_mouse) | Mouse object  |
| [_properties](#_properties) | Window properties  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLDisplay](#SFMLDisplay) | Constructor  |
| [~SFMLDisplay](#_u007eSFMLDisplay) | Destructor  |
| [init](#init) | Initialize the display :material-location-enter: `title` :    const std::string & Title of the window :material-location-enter: `width` :    size_t Width of the window :material-location-enter: `height` :    size_t Height of the window  |
| [stop](#stop) | Stop the display  |
| [getName](#getName) | Get the name of the display :material-keyboard-return: **Return** :    const std::string & Name of the display  |
| [setupWindowProperties](#setupWindowProperties) | Set the window properties :material-location-enter: `properties` :    WindowProperties & width, height and title of the window  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window with a color :material-location-enter: `color` :    Color Color to clear the window with  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    float Time since the last update  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool True if the window is open, false otherwise  |
| [drawTexture](#drawTexture) | Draw a texture :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position to draw the texture at  |
| [getKeyboard](#getKeyboard) | Getter for the keyboard variable :material-keyboard-return: **Return** :    Keyboard& Keyboard object  |
| [getMouse](#getMouse) | Getter for the mouse variable :material-keyboard-return: **Return** :    Mouse& Mouse object  |
| [getWindowProperties](#getWindowProperties) | Get the window properties :material-keyboard-return: **Return** :    WindowProperties& Window properties  |
| [processEvents](#processEvents) | Function to process events  |
| [handleEvent](#handleEvent) | Handle SFML events :material-location-enter: `event` :    const sf::Event & Event to handle  |
| [handleKeyEvent](#handleKeyEvent) | Handle key events :material-location-enter: `keyEvent` :    const sf::Event::KeyEvent & Key event to handle :material-location-enter: `isPressed` :    bool True if the key is pressed, false if released  |
| [mapSfmlKeyToArcade](#mapSfmlKeyToArcade) | Map SFML key to Arcade key :material-location-enter: `sfmlKey` :    sf::Keyboard::Key SFML key to map :material-keyboard-return: **Return** :    Keyboard::KeyCode Mapped Arcade key  |
| [drawText](#drawText) | Draw text :material-location-enter: `texture` :    std::shared_ptr<SFMLTexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position to draw the texture at  |
| [drawSprite](#drawSprite) | Draw sprite :material-location-enter: `texture` :    std::shared_ptr<SFMLTexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position to draw the texture at  |
| [calculateSpriteScale](#calculateSpriteScale) | Calculate the scale of the sprite :material-location-enter: `sprite` :    const sf::Sprite & Sprite to calculate the scale for :material-keyboard-return: **Return** :    std::pair<float, float> Scale of the sprite  |
| [calculateAdjustedPosition](#calculateAdjustedPosition) | Calculate the adjusted position of the sprite :material-location-enter: `position` :    Vector<float> Position to adjust :material-keyboard-return: **Return** :    std::pair<float, float> Adjusted position of the sprite  |

## Variable Details

### _keyboard<a name="_keyboard"></a>

!!! variable "Keyboard _keyboard"

    Keyboard object
    

### _mouse<a name="_mouse"></a>

!!! variable "Mouse _mouse"

    Mouse object
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Window name
    

### _properties<a name="_properties"></a>

!!! variable "WindowProperties _properties"

    Window properties
    

### _window<a name="_window"></a>

!!! variable "std::shared_ptr&lt;sf::RenderWindow&gt; _window"

    SFML window
    

## Function Details

### SFMLDisplay<a name="SFMLDisplay"></a>
!!! function "SFMLDisplay()"

    Constructor
    

### calculateAdjustedPosition<a name="calculateAdjustedPosition"></a>
!!! function "std::pair&lt;float, float&gt; calculateAdjustedPosition(Vector&lt;float&gt; position)"

    Calculate the adjusted position of the sprite
        
    :material-location-enter: `position`
    :    Vector<float> Position to adjust
        
    :material-keyboard-return: **Return**
    :    std::pair<float, float> Adjusted position of the sprite
    

### calculateSpriteScale<a name="calculateSpriteScale"></a>
!!! function "std::pair&lt;float, float&gt; calculateSpriteScale(const sf::Sprite&amp; sprite)"

    Calculate the scale of the sprite
        
    :material-location-enter: `sprite`
    :    const sf::Sprite & Sprite to calculate the scale for
        
    :material-keyboard-return: **Return**
    :    std::pair<float, float> Scale of the sprite
    

### clearWindow<a name="clearWindow"></a>
!!! function "void clearWindow(Color color) override"

    Clear the window with a color
        
    :material-location-enter: `color`
    :    Color Color to clear the window with
    

### closeWindow<a name="closeWindow"></a>
!!! function "void closeWindow() override"

    Close the window
    

### drawSprite<a name="drawSprite"></a>
!!! function "void drawSprite(std::shared_ptr&lt;SFMLTexture&gt; texture, Vector&lt;float&gt; position)"

    Draw sprite
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SFMLTexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position to draw the texture at
    

### drawText<a name="drawText"></a>
!!! function "void drawText(std::shared_ptr&lt;SFMLTexture&gt; texture, Vector&lt;float&gt; position)"

    Draw text
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SFMLTexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position to draw the texture at
    

### drawTexture<a name="drawTexture"></a>
!!! function "void drawTexture(std::shared_ptr&lt;ITexture&gt; texture, Vector&lt;float&gt; position) override"

    Draw a texture
        
    :material-location-enter: `texture`
    :    std::shared_ptr<ITexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position to draw the texture at
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "Keyboard&amp; getKeyboard() override"

    Getter for the keyboard variable
        
    :material-keyboard-return: **Return**
    :    Keyboard& Keyboard object
    

### getMouse<a name="getMouse"></a>
!!! function "Mouse&amp; getMouse() override"

    Getter for the mouse variable
        
    :material-keyboard-return: **Return**
    :    Mouse& Mouse object
    

### getName<a name="getName"></a>
!!! function "const std::string&amp; getName() const override"

    Get the name of the display
        
    :material-keyboard-return: **Return**
    :    const std::string & Name of the display
    

### getWindowProperties<a name="getWindowProperties"></a>
!!! function "WindowProperties&amp; getWindowProperties() override"

    Get the window properties
        
    :material-keyboard-return: **Return**
    :    WindowProperties& Window properties
    

### handleEvent<a name="handleEvent"></a>
!!! function "void handleEvent(const sf::Event&amp; event)"

    Handle SFML events
        
    :material-location-enter: `event`
    :    const sf::Event & Event to handle
    

### handleKeyEvent<a name="handleKeyEvent"></a>
!!! function "void handleKeyEvent(const sf::Event::KeyEvent&amp; keyEvent, bool isPressed)"

    Handle key events
        
    :material-location-enter: `keyEvent`
    :    const sf::Event::KeyEvent & Key event to handle
        
    :material-location-enter: `isPressed`
    :    bool True if the key is pressed, false if released
    

### init<a name="init"></a>
!!! function "void init(const std::string&amp; title, size_t width, size_t height) override"

    Initialize the display
    
    :material-location-enter: `title`
    :    const std::string & Title of the window
        
    :material-location-enter: `width`
    :    size_t Width of the window
        
    :material-location-enter: `height`
    :    size_t Height of the window
    

### isWindowOpen<a name="isWindowOpen"></a>
!!! function "bool isWindowOpen() override"

    Check if the window is open
        
    :material-keyboard-return: **Return**
    :    bool True if the window is open, false otherwise
    

### mapSfmlKeyToArcade<a name="mapSfmlKeyToArcade"></a>
!!! function "Keyboard::KeyCode mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey)"

    Map SFML key to Arcade key
        
    :material-location-enter: `sfmlKey`
    :    sf::Keyboard::Key SFML key to map
        
    :material-keyboard-return: **Return**
    :    Keyboard::KeyCode Mapped Arcade key
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### processEvents<a name="processEvents"></a>
!!! function "void processEvents()"

    Function to process events
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties&amp; properties) override"

    Set the window properties
        
    :material-location-enter: `properties`
    :    WindowProperties & width, height and title of the window
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the display
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    float Time since the last update
    

### ~SFMLDisplay<a name="_u007eSFMLDisplay"></a>
!!! function "~SFMLDisplay() override"

    Destructor
    

