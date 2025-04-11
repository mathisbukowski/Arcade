---
generator: doxide
---


# SDLDisplayModule

**class SDLDisplayModule : public IDisplayModule**


Implementation of the display module interface using SDL2
It inherits from IDisplayModule


## Variables

| Name | Description |
| ---- | ----------- |
| [_renderer](#_renderer) | SDL renderer manager reference  |
| [_window](#_window) | SDL window reference  |
| [_windowProperties](#_windowProperties) | Window properties  |
| [_name](#_name) | Name of the window  |
| [_isOpen](#_isOpen) | bool indicating if the window is open  |
| [_keyboard](#_keyboard) | Keyboard input handler  |
| [_mouse](#_mouse) | Mouse input handler  |
| [_rendererManager](#_rendererManager) | SDL renderer manager reference  |
| [GRID_SIZE](#GRID_SIZE) | Constants for grid size  |
| [CELL_SCALE_FACTOR](#CELL_SCALE_FACTOR) | Constants for cell scale factor  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLDisplayModule](#SDLDisplayModule) | Constructor :material-location-enter: `rendererManager` :    SDLRendererManager& Reference to the SDL renderer manager  |
| [~SDLDisplayModule](#_u007eSDLDisplayModule) | Destructor  |
| [init](#init) | Initialize the SDL display with specified parameters :material-location-enter: `title` :    const std::string & Window title :material-location-enter: `width` :    size_t Window width :material-location-enter: `height` :    size_t Window height  |
| [stop](#stop) | Stop and cleanup the SDL display  |
| [getName](#getName) | Get the name of the display module :material-keyboard-return: **Return** :    const std::string & Display module name  |
| [setupWindowProperties](#setupWindowProperties) | Configure window properties :material-location-enter: `properties` :    WindowProperties & Window properties to set  |
| [openWindow](#openWindow) | Open the window  |
| [closeWindow](#closeWindow) | Close the window  |
| [clearWindow](#clearWindow) | Clear window with specified color :material-location-enter: `color` :    Color to use for clearing  |
| [updateWindow](#updateWindow) | Update window state and process events :material-location-enter: `delta` :    float Time since last update  |
| [isWindowOpen](#isWindowOpen) | Check if window is currently open :material-keyboard-return: **Return** :    bool True if window is open  |
| [drawTexture](#drawTexture) | Draw a texture at specified position :material-location-enter: `texture` :    std::shared_ptr<ITexture> Texture to draw :material-location-enter: `position` :    Vector<float> Position where to draw  |
| [getKeyboard](#getKeyboard) | Get keyboard input handler :material-keyboard-return: **Return** :    Keyboard & Reference to keyboard handler  |
| [getMouse](#getMouse) | Get mouse input handler :material-keyboard-return: **Return** :    Mouse & Reference to mouse handler  |
| [getWindowProperties](#getWindowProperties) | Get current window properties :material-keyboard-return: **Return** :    WindowProperties & Window properties  |
| [initializeSDL](#initializeSDL) | Initialize SDL subsystems  |
| [validateRendererAndWindow](#validateRendererAndWindow) | Validate renderer and window creation  |
| [cleanupResources](#cleanupResources) | Clean up SDL resources  |
| [drawTextTexture](#drawTextTexture) | Draw text texture :material-location-enter: `texture` :    std::shared_ptr<SDLTexture> SDL texture containing text :material-location-enter: `position` :    Vector<float> Position where to draw  |
| [drawSpriteTexture](#drawSpriteTexture) | Draw sprite texture :material-location-enter: `texture` :    std::shared_ptr<SDLTexture> SDL texture containing sprite :material-location-enter: `position` :    Vector<float> Position where to draw  |
| [calculateSpriteScale](#calculateSpriteScale) | Calculate scaling factors for sprite :material-location-enter: `texture` :    SDL_Texture* SDL texture to scale :material-keyboard-return: **Return** :    std::pair<float, float> Pair of scaling factors (x, y)  |
| [calculateAdjustedPosition](#calculateAdjustedPosition) | Calculate adjusted position based on cell size :material-location-enter: `position` :    Vector<float> Original position :material-keyboard-return: **Return** :    std::pair<float, float> Adjusted position  |
| [processEvents](#processEvents) | Process SDL events  |
| [handleEvent](#handleEvent) | Handle specific SDL event :material-location-enter: `event` :    const SDL_Event & SDL event to handle  |
| [handleKeyboardEvent](#handleKeyboardEvent) | Handle keyboard event :material-location-enter: `keyEvent` :    const SDL_KeyboardEvent & SDL key event :material-location-enter: `isPressed` :    bool True if key is pressed, false if released  |
| [handleMouseButtonEvent](#handleMouseButtonEvent) | Handle mouse button event :material-location-enter: `mouseEvent` :    const SDL_MouseButtonEvent & SDL mouse button event :material-location-enter: `isPressed` :    bool True if button is pressed, false if released  |
| [handleMouseMotionEvent](#handleMouseMotionEvent) | Handle mouse motion event :material-location-enter: `mouseEvent` :    const SDL_MouseMotionEvent& SDL mouse motion event  |
| [mapSDLKeyToArcade](#mapSDLKeyToArcade) | Map SDL key code to arcade key code :material-location-enter: `key` :    SDL_Keycode SDL key code :material-keyboard-return: **Return** :    Keyboard::KeyCode Corresponding arcade key code  |

## Variable Details

### CELL_SCALE_FACTOR<a name="CELL_SCALE_FACTOR"></a>

!!! variable "static constexpr float CELL_SCALE_FACTOR"

    Constants for cell scale factor
    

### GRID_SIZE<a name="GRID_SIZE"></a>

!!! variable "static constexpr float GRID_SIZE"

    Constants for grid size
    

### _isOpen<a name="_isOpen"></a>

!!! variable "bool _isOpen"

    bool indicating if the window is open
    

### _keyboard<a name="_keyboard"></a>

!!! variable "Keyboard _keyboard"

    Keyboard input handler
    

### _mouse<a name="_mouse"></a>

!!! variable "Mouse _mouse"

    Mouse input handler
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Name of the window
    

### _renderer<a name="_renderer"></a>

!!! variable "std::shared_ptr&lt;SDL_Renderer&gt; _renderer"

    SDL renderer manager reference
    

### _rendererManager<a name="_rendererManager"></a>

!!! variable "SDLRendererManager&amp; _rendererManager"

    SDL renderer manager reference
    

### _window<a name="_window"></a>

!!! variable "std::shared_ptr&lt;SDL_Window&gt; _window"

    SDL window reference
    

### _windowProperties<a name="_windowProperties"></a>

!!! variable "WindowProperties _windowProperties"

    Window properties
    

## Function Details

### SDLDisplayModule<a name="SDLDisplayModule"></a>
!!! function "explicit SDLDisplayModule(SDLRendererManager&amp; rendererManager)"

    Constructor
    
    :material-location-enter: `rendererManager`
    :    SDLRendererManager& Reference to the SDL renderer manager
    

### calculateAdjustedPosition<a name="calculateAdjustedPosition"></a>
!!! function "std::pair&lt;float, float&gt; calculateAdjustedPosition(Vector&lt;float&gt; position)"

    Calculate adjusted position based on cell size
        
    :material-location-enter: `position`
    :    Vector<float> Original position
        
    :material-keyboard-return: **Return**
    :    std::pair<float, float> Adjusted position
    

### calculateSpriteScale<a name="calculateSpriteScale"></a>
!!! function "std::pair&lt;float, float&gt; calculateSpriteScale(SDL_Texture&#42; texture)"

    Calculate scaling factors for sprite
        
    :material-location-enter: `texture`
    :    SDL_Texture* SDL texture to scale
        
    :material-keyboard-return: **Return**
    :    std::pair<float, float> Pair of scaling factors (x, y)
    

### cleanupResources<a name="cleanupResources"></a>
!!! function "void cleanupResources()"

    Clean up SDL resources
    

### clearWindow<a name="clearWindow"></a>
!!! function "void clearWindow(Color color) override"

    Clear window with specified color
        
    :material-location-enter: `color`
    :    Color to use for clearing
    

### closeWindow<a name="closeWindow"></a>
!!! function "void closeWindow() override"

    Close the window
    

### drawSpriteTexture<a name="drawSpriteTexture"></a>
!!! function "void drawSpriteTexture(std::shared_ptr&lt;SDLTexture&gt; texture, Vector&lt;float&gt; position)"

    Draw sprite texture
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SDLTexture> SDL texture containing sprite
        
    :material-location-enter: `position`
    :    Vector<float> Position where to draw
    

### drawTextTexture<a name="drawTextTexture"></a>
!!! function "void drawTextTexture(std::shared_ptr&lt;SDLTexture&gt; texture, Vector&lt;float&gt; position)"

    Draw text texture
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SDLTexture> SDL texture containing text
        
    :material-location-enter: `position`
    :    Vector<float> Position where to draw
    

### drawTexture<a name="drawTexture"></a>
!!! function "void drawTexture(std::shared_ptr&lt;ITexture&gt; texture, Vector&lt;float&gt; position) override"

    Draw a texture at specified position
        
    :material-location-enter: `texture`
    :    std::shared_ptr<ITexture> Texture to draw
        
    :material-location-enter: `position`
    :    Vector<float> Position where to draw
    

### getKeyboard<a name="getKeyboard"></a>
!!! function "[[nodiscard]] Keyboard &amp;getKeyboard() override"

    Get keyboard input handler
        
    :material-keyboard-return: **Return**
    :    Keyboard & Reference to keyboard handler
    

### getMouse<a name="getMouse"></a>
!!! function "[[nodiscard]] Mouse &amp;getMouse() override"

    Get mouse input handler
        
    :material-keyboard-return: **Return**
    :    Mouse & Reference to mouse handler
    

### getName<a name="getName"></a>
!!! function "[[nodiscard]] const std::string &amp;getName() const override"

    Get the name of the display module
        
    :material-keyboard-return: **Return**
    :    const std::string & Display module name
    

### getWindowProperties<a name="getWindowProperties"></a>
!!! function "[[nodiscard]] WindowProperties&amp; getWindowProperties() override"

    Get current window properties
        
    :material-keyboard-return: **Return**
    :    WindowProperties & Window properties
    

### handleEvent<a name="handleEvent"></a>
!!! function "void handleEvent(const SDL_Event&amp; event)"

    Handle specific SDL event
        
    :material-location-enter: `event`
    :    const SDL_Event & SDL event to handle
    

### handleKeyboardEvent<a name="handleKeyboardEvent"></a>
!!! function "void handleKeyboardEvent(const SDL_KeyboardEvent&amp; keyEvent, bool isPressed)"

    Handle keyboard event
        
    :material-location-enter: `keyEvent`
    :    const SDL_KeyboardEvent & SDL key event
        
    :material-location-enter: `isPressed`
    :    bool True if key is pressed, false if released
    

### handleMouseButtonEvent<a name="handleMouseButtonEvent"></a>
!!! function "void handleMouseButtonEvent(const SDL_MouseButtonEvent&amp; mouseEvent, bool isPressed)"

    Handle mouse button event
        
    :material-location-enter: `mouseEvent`
    :    const SDL_MouseButtonEvent & SDL mouse button event
        
    :material-location-enter: `isPressed`
    :    bool True if button is pressed, false if released
    

### handleMouseMotionEvent<a name="handleMouseMotionEvent"></a>
!!! function "void handleMouseMotionEvent(const SDL_MouseMotionEvent&amp; mouseEvent)"

    Handle mouse motion event
        
    :material-location-enter: `mouseEvent`
    :    const SDL_MouseMotionEvent& SDL mouse motion event
    

### init<a name="init"></a>
!!! function "void init(const std::string&amp; title, size_t width, size_t height) override"

    Initialize the SDL display with specified parameters
        
    :material-location-enter: `title`
    :    const std::string & Window title
        
    :material-location-enter: `width`
    :    size_t Window width
        
    :material-location-enter: `height`
    :    size_t Window height
    

### initializeSDL<a name="initializeSDL"></a>
!!! function "void initializeSDL()"

    Initialize SDL subsystems
    

### isWindowOpen<a name="isWindowOpen"></a>
!!! function "bool isWindowOpen() override"

    Check if window is currently open
        
    :material-keyboard-return: **Return**
    :    bool True if window is open
    

### mapSDLKeyToArcade<a name="mapSDLKeyToArcade"></a>
!!! function "Keyboard::KeyCode mapSDLKeyToArcade(SDL_Keycode key)"

    Map SDL key code to arcade key code
        
    :material-location-enter: `key`
    :    SDL_Keycode SDL key code
        
    :material-keyboard-return: **Return**
    :    Keyboard::KeyCode Corresponding arcade key code
    

### openWindow<a name="openWindow"></a>
!!! function "void openWindow() override"

    Open the window
    

### processEvents<a name="processEvents"></a>
!!! function "void processEvents()"

    Process SDL events
    

### setupWindowProperties<a name="setupWindowProperties"></a>
!!! function "void setupWindowProperties(WindowProperties &amp;properties) override"

    Configure window properties
        
    :material-location-enter: `properties`
    :    WindowProperties & Window properties to set
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop and cleanup the SDL display
    

### updateWindow<a name="updateWindow"></a>
!!! function "void updateWindow(float delta) override"

    Update window state and process events
        
    :material-location-enter: `delta`
    :    float Time since last update
    

### validateRendererAndWindow<a name="validateRendererAndWindow"></a>
!!! function "void validateRendererAndWindow()"

    Validate renderer and window creation
    

### ~SDLDisplayModule<a name="_u007eSDLDisplayModule"></a>
!!! function "~SDLDisplayModule() override"

    Destructor
    

