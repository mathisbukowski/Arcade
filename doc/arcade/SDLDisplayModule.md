---
generator: doxide
---


# SDLDisplayModule

**class SDLDisplayModule : public IDisplayModule**



## Functions

| Name | Description |
| ---- | ----------- |
| [init](#init) | Initialize the SDL library  |
| [stop](#stop) | Stop the SDL library  |
| [getName](#getName) | Get the name of the library :material-keyboard-return: **Return** :    const std::string  |
| [setupWindowProperties](#setupWindowProperties) | Set up the window properties :material-location-enter: `properties` :    WindowProperties  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window with a color :material-location-enter: `color` :    Color  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    Delta time  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool  |
| [drawTexture](#drawTexture) | Draw a texture on the window :material-location-enter: `texture` :    Texture to draw :material-location-enter: `position` :    Position of the texture  |
| [getKeyboard](#getKeyboard) | Get the keyboard :material-keyboard-return: **Return** :    Keyboard  |
| [getMouse](#getMouse) | Get the mouse :material-keyboard-return: **Return** :    Mouse  |

## Function Details

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
    :    Texture to draw
        
    :material-location-enter: `position`
    :    Position of the texture
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "[[nodiscard]] Keyboard &amp;getKeyboard() override"

    Get the keyboard
        
    :material-keyboard-return: **Return**
    :    Keyboard
    

### getMouse<a name="getMouse"></a>
!!! function "[[nodiscard]] Mouse &amp;getMouse() override"

    Get the mouse
        
    :material-keyboard-return: **Return**
    :    Mouse
    

### getName<a name="getName"></a>
!!! function "[[nodiscard]] const std::string &amp;getName() const override"

    Get the name of the library
    
    :material-keyboard-return: **Return**
    :    const std::string
    

### init<a name="init"></a>
!!! function "void init(const std::string&amp; title, size_t width, size_t height) override"

    Initialize the SDL library
    

### isWindowOpen<a name="isWindowOpen"></a>
!!! function "bool isWindowOpen() override"

    Check if the window is open
        
    :material-keyboard-return: **Return**
    :    bool
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties &amp;properties) override"

    Set up the window properties
    
    :material-location-enter: `properties`
    :    WindowProperties
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the SDL library
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    Delta time
    

