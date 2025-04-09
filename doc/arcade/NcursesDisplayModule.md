---
generator: doxide
---


# NcursesDisplayModule

**class NcursesDisplayModule : public IDisplayModule**


This class is used to create a window using the ncurses library
It inherits from the IDisplayModule interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_windowProperties](#_windowProperties) | Window properties  |
| [_name](#_name) | Name of the display module  |
| [_isOpen](#_isOpen) | Check if the window is open  |
| [_keyboard](#_keyboard) | Keyboard  |
| [_mouse](#_mouse) | Mouse  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesDisplayModule](#NcursesDisplayModule) | Constructor :material-location-enter: `name` :    const std::string & name Name of the display module. Default is "NCURSES"  |
| [init](#init) | Initialize the SDL library :material-location-enter: `title` :    const std::string & Title of the window :material-location-enter: `width` :    size_t Width of the window :material-location-enter: `height` :    size_t Height of the window  |
| [stop](#stop) | Stop the SDL library  |
| [getName](#getName) | Get the name of the library :material-keyboard-return: **Return** :    const std::string & Name of the library  |
| [setupWindowProperties](#setupWindowProperties) | Set up the window properties :material-location-enter: `properties` :    WindowProperties & Properties of the window  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window with a color :material-location-enter: `color` :    Color  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    float Delta time  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool  |
| [drawTexture](#drawTexture) | Draw a texture on the window :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position of the texture  |
| [getKeyboard](#getKeyboard) | Get the keyboard :material-keyboard-return: **Return** :    Keyboard &  |
| [getMouse](#getMouse) | Get the mouse :material-keyboard-return: **Return** :    Mouse &  |
| [getWindowProperties](#getWindowProperties) | Get the window properties :material-keyboard-return: **Return** :    WindowProperties  |
| [processEvents](#processEvents) | Process events  |
| [handleEvent](#handleEvent) | Handle event :material-location-enter: `ch` :    int Character code  |

## Variable Details

### _isOpen<a name="_isOpen"></a>

!!! variable "bool _isOpen"

    Check if the window is open
    

### _keyboard<a name="_keyboard"></a>

!!! variable "Keyboard _keyboard"

    Keyboard
    

### _mouse<a name="_mouse"></a>

!!! variable "Mouse _mouse"

    Mouse
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Name of the display module
    

### _windowProperties<a name="_windowProperties"></a>

!!! variable "WindowProperties _windowProperties"

    Window properties
    

## Function Details

### NcursesDisplayModule<a name="NcursesDisplayModule"></a>
!!! function "NcursesDisplayModule(const std::string &amp;name = &quot;NCURSES&quot;)"

    Constructor
    
    :material-location-enter: `name`
    :    const std::string & name Name of the display module. Default is "NCURSES"
    

### clearWindow<a name="clearWindow"></a>
!!! function "void clearWindow(Color color) override"

    Clear the window with a color
        
    :material-location-enter: `color`
    :    Color
    

### closeWindow<a name="closeWindow"></a>
!!! function "void closeWindow() override"

    Close the window
    

### drawTexture<a name="drawTexture"></a>
!!! function "void drawTexture(std::shared_ptr&lt;ITexture&gt; texture, Vector&lt;float&gt; position) override"

    Draw a texture on the window
        
    :material-location-enter: `texture`
    :    std::shared_ptr<ITexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position of the texture
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "[[nodiscard]] Keyboard &amp;getKeyboard() override"

    Get the keyboard
        
    :material-keyboard-return: **Return**
    :    Keyboard &
    

### getMouse<a name="getMouse"></a>
!!! function "[[nodiscard]] Mouse &amp;getMouse() override"

    Get the mouse
        
    :material-keyboard-return: **Return**
    :    Mouse &
    

### getName<a name="getName"></a>
!!! function "[[nodiscard]] const std::string &amp;getName() const override"

    Get the name of the library
        
    :material-keyboard-return: **Return**
    :    const std::string & Name of the library
    

### getWindowProperties<a name="getWindowProperties"></a>
!!! function "[[nodiscard]] WindowProperties getWindowProperties() const"

    Get the window properties
        
    :material-keyboard-return: **Return**
    :    WindowProperties
    

### handleEvent<a name="handleEvent"></a>
!!! function "void handleEvent(int ch)"

    Handle event
        
    :material-location-enter: `ch`
    :    int Character code
    

### init<a name="init"></a>
!!! function "void init(const std::string&amp; title, size_t width, size_t height) override"

    Initialize the SDL library
        
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
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### processEvents<a name="processEvents"></a>
!!! function "void processEvents()"

    Process events
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties &amp;properties) override"

    Set up the window properties
        
    :material-location-enter: `properties`
    :    WindowProperties & Properties of the window
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the SDL library
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    float Delta time
    

