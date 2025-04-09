---
generator: doxide
---


# SFMLDisplay

**class SFMLDisplay : public IDisplayModule**


This class is used to create a display using the SFML library
It inherits from the IDisplayModule interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_name](#_name) | Window name  |
| [_window](#_window) | sf::RenderWindow object  |
| [_keyboard](#_keyboard) | keyboard object  |
| [_mouse](#_mouse) | mouse object  |
| [_properties](#_properties) | Window properties  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLDisplay](#SFMLDisplay) | Construct a new SFMLDisplay object  |
| [~SFMLDisplay](#_u007eSFMLDisplay) | Destroy the SFMLDisplay object  |
| [init](#init) | Initialize the display :material-location-enter: `title` :    const std::string & Title of the window :material-location-enter: `width` :    size_t Width of the window :material-location-enter: `height` :    size_t Height of the window  |
| [stop](#stop) | Stop the display  |
| [getName](#getName) | Get the name of the display :material-keyboard-return: **Return** :    const std::string&  |
| [setupWindowProperties](#setupWindowProperties) | Setup the window properties :material-location-enter: `properties` :    WindowProperties& Properties of the window  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window :material-location-enter: `color` :    Color Color to clear the window with  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    float Delta time  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool  |
| [drawTexture](#drawTexture) | Draw a texture on the window :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position to draw the texture at  |
| [getKeyboard](#getKeyboard) | Get the keyboard object :material-keyboard-return: **Return** :    Keyboard&  |
| [getMouse](#getMouse) | Get the mouse object :material-keyboard-return: **Return** :    Mouse&  |
| [processEvents](#processEvents) | Process events  |
| [handleEvent](#handleEvent) | Handle events :material-location-enter: `event` :    const sf::Event& Event to handle  |
| [handleKeyEvent](#handleKeyEvent) | Handle key events :material-location-enter: `keyEvent` :    const sf::Event::KeyEvent& Key event to handle :material-location-enter: `isPressed` :    bool True if the key is pressed, false if it is released  |
| [mapSfmlKeyToArcade](#mapSfmlKeyToArcade) | Map SFML key to Arcade key :material-location-enter: `sfmlKey` :    sf::Keyboard::Key SFML key to map :material-keyboard-return: **Return** :    Keyboard::KeyCode Arcade key  |

## Variable Details

### _keyboard<a name="_keyboard"></a>

!!! variable "Keyboard _keyboard"

    keyboard object
    

### _mouse<a name="_mouse"></a>

!!! variable "Mouse _mouse"

    mouse object
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Window name
    

### _properties<a name="_properties"></a>

!!! variable "WindowProperties _properties"

    Window properties
    

### _window<a name="_window"></a>

!!! variable "std::shared_ptr&lt;sf::RenderWindow&gt; _window"

    sf::RenderWindow object
    

## Function Details

### SFMLDisplay<a name="SFMLDisplay"></a>
!!! function "SFMLDisplay()"

    Construct a new SFMLDisplay object
    

### clearWindow<a name="clearWindow"></a>
!!! function "void clearWindow(Color color) override"

    Clear the window
        
    :material-location-enter: `color`
    :    Color Color to clear the window with
    

### closeWindow<a name="closeWindow"></a>
!!! function "void closeWindow() override"

    Close the window
    

### drawTexture<a name="drawTexture"></a>
!!! function "void drawTexture(std::shared_ptr&lt;ITexture&gt; texture, Vector&lt;float&gt; position) override"

    Draw a texture on the window
        
    :material-location-enter: `texture`
    :    std::shared_ptr<ITexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position to draw the texture at
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "Keyboard&amp; getKeyboard() override"

    Get the keyboard object
        
    :material-keyboard-return: **Return**
    :    Keyboard&
    

### getMouse<a name="getMouse"></a>
!!! function "Mouse&amp; getMouse() override"

    Get the mouse object
        
    :material-keyboard-return: **Return**
    :    Mouse&
    

### getName<a name="getName"></a>
!!! function "const std::string&amp; getName() const override"

    Get the name of the display
        
    :material-keyboard-return: **Return**
    :    const std::string&
    

### handleEvent<a name="handleEvent"></a>
!!! function "void handleEvent(const sf::Event&amp; event)"

    Handle events
        
    :material-location-enter: `event`
    :    const sf::Event& Event to handle
    

### handleKeyEvent<a name="handleKeyEvent"></a>
!!! function "void handleKeyEvent(const sf::Event::KeyEvent&amp; keyEvent, bool isPressed)"

    Handle key events
        
    :material-location-enter: `keyEvent`
    :    const sf::Event::KeyEvent& Key event to handle
        
    :material-location-enter: `isPressed`
    :    bool True if the key is pressed, false if it is released
    

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
    :    bool
    

### mapSfmlKeyToArcade<a name="mapSfmlKeyToArcade"></a>
!!! function "Keyboard::KeyCode mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey)"

    Map SFML key to Arcade key
        
    :material-location-enter: `sfmlKey`
    :    sf::Keyboard::Key SFML key to map
        
    :material-keyboard-return: **Return**
    :    Keyboard::KeyCode Arcade key
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### processEvents<a name="processEvents"></a>
!!! function "void processEvents()"

    Process events
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties&amp; properties) override"

    Setup the window properties
        
    :material-location-enter: `properties`
    :    WindowProperties& Properties of the window
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the display
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    float Delta time
    

### ~SFMLDisplay<a name="_u007eSFMLDisplay"></a>
!!! function "~SFMLDisplay() override"

    Destroy the SFMLDisplay object
    

