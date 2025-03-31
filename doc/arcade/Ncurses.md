---
generator: doxide
---


# Ncurses

**class Ncurses : public IDisplayModule, public IDisplayLibrary**

Ncurses class to handle the Ncurses library for the display


## Functions

| Name | Description |
| ---- | ----------- |
| [Ncurses](#Ncurses) | Construct a new Ncurses object  |
| [~Ncurses](#_u007eNcurses) | Destroy the Ncurses object  |
| [init](#init) | Initialize the Ncurses library  |
| [stop](#stop) | Stop the Ncurses library  |
| [getName](#getName) | Get the name of the library :material-keyboard-return: **Return** :    const std::string  |
| [setupWindowProperties](#setupWindowProperties) | Setup the window properties :material-location-enter: `properties` :    WindowProperties  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window :material-location-enter: `color` :    Color  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    Delta time  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool  |
| [drawTexture](#drawTexture) | Draw a texture :material-location-enter: `texture` :    Texture :material-location-enter: `position` :    Position  |
| [getKeyboard](#getKeyboard) | Get the keyboard :material-keyboard-return: **Return** :    Keyboard  |
| [getMouse](#getMouse) | Get the mouse :material-keyboard-return: **Return** :    Mouse  |
| [getDisplay](#getDisplay) | Get the Display object :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Get the Texture Manager object :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Get the Font Manager object :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Get the Sound Manager object :material-keyboard-return: **Return** :    ISoundManager&  |

## Function Details

### Ncurses<a name="Ncurses"></a>
!!! function "Ncurses()"

    Construct a new Ncurses object
    

### clearWindow<a name="clearWindow"></a>
!!! function "void clearWindow(Color color) override"

    Clear the window
        
    :material-location-enter: `color`
    :    Color
    

### closeWindow<a name="closeWindow"></a>
!!! function "void closeWindow() override"

    Close the window
    

### drawTexture<a name="drawTexture"></a>
!!! function "void drawTexture(std::shared_ptr&lt;ITexture&gt; texture, Vector&lt;float&gt; position) override"

    Draw a texture
        
    :material-location-enter: `texture`
    :    Texture
        
    :material-location-enter: `position`
    :    Position
    

### getDisplay<a name="getDisplay"></a>
!!! function "IDisplayModule &amp;getDisplay() override"

    Get the Display object
        
    :material-keyboard-return: **Return**
    :    IDisplayModule&
    

### getFonts<a name="getFonts"></a>
!!! function "IFontManager &amp;getFonts() override"

    Get the Font Manager object
        
    :material-keyboard-return: **Return**
    :    IFontManager&
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "Keyboard &amp;getKeyboard() override"

    Get the keyboard
        
    :material-keyboard-return: **Return**
    :    Keyboard
    

### getMouse<a name="getMouse"></a>
!!! function "Mouse &amp;getMouse() override"

    Get the mouse
        
    :material-keyboard-return: **Return**
    :    Mouse
    

### getName<a name="getName"></a>
!!! function "const std::string &amp;getName() const override"

    Get the name of the library
    
    :material-keyboard-return: **Return**
    :    const std::string
    

### getSounds<a name="getSounds"></a>
!!! function "ISoundManager &amp;getSounds() override"

    Get the Sound Manager object
        
    :material-keyboard-return: **Return**
    :    ISoundManager&
    

### getTextures<a name="getTextures"></a>
!!! function "ITextureManager &amp;getTextures() override"

    Get the Texture Manager object
        
    :material-keyboard-return: **Return**
    :    ITextureManager&
    

### init<a name="init"></a>
!!! function "void init() override"

    Initialize the Ncurses library
    

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

    Setup the window properties
    
    :material-location-enter: `properties`
    :    WindowProperties
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the Ncurses library
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    Delta time
    

### ~Ncurses<a name="_u007eNcurses"></a>
!!! function "~Ncurses()"

    Destroy the Ncurses object
    

