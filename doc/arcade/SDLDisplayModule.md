---
generator: doxide
---


# SDLDisplayModule

**class SDLDisplayModule : public IDisplayModule**


This class is used to create a library using the SDL2 library
It inherits from the IDisplayModule interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_renderer](#_renderer) | SDL Renderer Manager  |
| [_window](#_window) | SDL Window  |
| [_windowProperties](#_windowProperties) | Window properties  |
| [_name](#_name) | Window name  |
| [_isOpen](#_isOpen) | Window is open  |
| [_keyboard](#_keyboard) | Keyboard  |
| [_mouse](#_mouse) | Mouse  |
| [_rendererManager](#_rendererManager) | SDL Renderer Manager  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLDisplayModule](#SDLDisplayModule) | Construct a new SDLDisplayModule object :material-location-enter: `rendererManager` :    SDLRendererManager&  |
| [~SDLDisplayModule](#_u007eSDLDisplayModule) | Destroy the SDLDisplayModule object  |
| [init](#init) | Initialize the SDL library :material-location-enter: `title` :    std::string & Title of the window :material-location-enter: `width` :    size_t Width of the window :material-location-enter: `height` :    size_t Height of the window  |
| [stop](#stop) | Stop the SDL library  |
| [getName](#getName) | Get the name of the library :material-keyboard-return: **Return** :    const std::string &  |
| [setupWindowProperties](#setupWindowProperties) | Set up the window properties :material-location-enter: `properties` :    WindowProperties &  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear the window with a color :material-location-enter: `color` :    Color  |
| [updateWindow](#updateWindow) | Update the window :material-location-enter: `delta` :    float Delta time  |
| [isWindowOpen](#isWindowOpen) | Check if the window is open :material-keyboard-return: **Return** :    bool  |
| [drawTexture](#drawTexture) | Draw a texture on the window :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position of the texture  |
| [getKeyboard](#getKeyboard) | Get the keyboard :material-keyboard-return: **Return** :    Keyboard &  |
| [getMouse](#getMouse) | Get the mouse :material-keyboard-return: **Return** :    Mouse &  |
| [mapSDLKeyToArcade](#mapSDLKeyToArcade) | Map SDL key to arcade key :material-location-enter: `key` :    SDL_Keycode :material-keyboard-return: **Return** :    Keyboard::KeyCode  |

## Variable Details

### _isOpen<a name="_isOpen"></a>

!!! variable "bool _isOpen"

    Window is open
    

### _keyboard<a name="_keyboard"></a>

!!! variable "Keyboard _keyboard"

    Keyboard
    

### _mouse<a name="_mouse"></a>

!!! variable "Mouse _mouse"

    Mouse
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Window name
    

### _renderer<a name="_renderer"></a>

!!! variable "std::shared_ptr&lt;SDL_Renderer&gt; _renderer"

    SDL Renderer Manager
    

### _rendererManager<a name="_rendererManager"></a>

!!! variable "SDLRendererManager&amp; _rendererManager"

    SDL Renderer Manager
    

### _window<a name="_window"></a>

!!! variable "std::shared_ptr&lt;SDL_Window&gt; _window"

    SDL Window
    

### _windowProperties<a name="_windowProperties"></a>

!!! variable "WindowProperties _windowProperties"

    Window properties
    

## Function Details

### SDLDisplayModule<a name="SDLDisplayModule"></a>
!!! function "SDLDisplayModule(SDLRendererManager&amp; rendererManager)"

    Construct a new SDLDisplayModule object
    
    :material-location-enter: `rendererManager`
    :    SDLRendererManager&
    

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
    :    const std::string &
    

### init<a name="init"></a>
!!! function "void init(const std::string&amp; title, size_t width, size_t height) override"

    Initialize the SDL library
        
    :material-location-enter: `title`
    :    std::string & Title of the window
        
    :material-location-enter: `width`
    :    size_t Width of the window
        
    :material-location-enter: `height`
    :    size_t Height of the window
    

### isWindowOpen<a name="isWindowOpen"></a>
!!! function "bool isWindowOpen() override"

    Check if the window is open
        
    :material-keyboard-return: **Return**
    :    bool
    

### mapSDLKeyToArcade<a name="mapSDLKeyToArcade"></a>
!!! function "Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key)"

    Map SDL key to arcade key
        
    :material-location-enter: `key`
    :    SDL_Keycode
        
    :material-keyboard-return: **Return**
    :    Keyboard::KeyCode
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties &amp;properties) override"

    Set up the window properties
        
    :material-location-enter: `properties`
    :    WindowProperties &
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the SDL library
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update the window
        
    :material-location-enter: `delta`
    :    float Delta time
    

### ~SDLDisplayModule<a name="_u007eSDLDisplayModule"></a>
!!! function "~SDLDisplayModule() override"

    Destroy the SDLDisplayModule object
    

