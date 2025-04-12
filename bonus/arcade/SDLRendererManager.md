---
generator: doxide
---


# SDLRendererManager

**class SDLRendererManager**


This class is used to manage the SDL renderer and window


## Variables

| Name | Description |
| ---- | ----------- |
| [_renderer](#_renderer) | SDL Renderer  |
| [_window](#_window) | SDL Window  |

## Functions

| Name | Description |
| ---- | ----------- |
| [initializeRenderer](#initializeRenderer) | Construct a new SDLRendererManager object Destroy the SDLRendererManager object Initialize the SDL renderer and window :material-location-enter: `title` :    const std::string & Title of the window :material-location-enter: `width` :    size_t Width of the window :material-location-enter: `height` :    size_t Height of the window  |
| [getRenderer](#getRenderer) | Get the SDL renderer :material-keyboard-return: **Return** :    std::shared_ptr<SDL_Renderer>  |
| [getWindow](#getWindow) | Get the SDL window :material-keyboard-return: **Return** :    std::shared_ptr<SDL_Window>  |

## Variable Details

### _renderer<a name="_renderer"></a>

!!! variable "std::shared_ptr&lt;SDL_Renderer&gt; _renderer"

    SDL Renderer
    

### _window<a name="_window"></a>

!!! variable "std::shared_ptr&lt;SDL_Window&gt; _window"

    SDL Window
    

## Function Details

### getRenderer<a name="getRenderer"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;SDL_Renderer&gt; getRenderer() const"

    Get the SDL renderer
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<SDL_Renderer>
    

### getWindow<a name="getWindow"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;SDL_Window&gt; getWindow() const"

    Get the SDL window
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<SDL_Window>
    

### initializeRenderer<a name="initializeRenderer"></a>
!!! function "void initializeRenderer(const std::string&amp; title, size_t width, size_t height)"

    Construct a new SDLRendererManager object
    Destroy the SDLRendererManager object
    Initialize the SDL renderer and window
    
    :material-location-enter: `title`
    :    const std::string & Title of the window
        
    :material-location-enter: `width`
    :    size_t Width of the window
        
    :material-location-enter: `height`
    :    size_t Height of the window
    

