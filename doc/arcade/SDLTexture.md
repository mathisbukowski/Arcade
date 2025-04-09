---
generator: doxide
---


# SDLTexture

**class SDLTexture : public ITexture**


This class is used to create a texture using the SDL2 library
It inherits from the ITexture interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_rect](#_rect) | SDL_Rect  |
| [_texture](#_texture) | SDL Texture  |
| [_textureInformations](#_textureInformations) | Texture information  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLTexture](#SDLTexture) | Construct a new SDLTexture object :material-location-enter: `textureInfo` :    MyTexture & Texture information  |
| [createTexture](#createTexture) | Destroy the SDLTexture object Create a new texture :material-location-enter: `textureInfos` :    MyTexture & Texture information :material-location-enter: `renderer` :    std::shared_ptr<SDL_Renderer> SDL Renderer :material-keyboard-return: **Return** :    int  |
| [getInformations](#getInformations) | Get the texture information :material-keyboard-return: **Return** :    const MyTexture &  |
| [set](#set) | Set the texture information :material-location-enter: `newTexture` :    MyTexture & Texture information  |
| [getTexture](#getTexture) | Get the texture :material-keyboard-return: **Return** :    std::shared_ptr<SDL_Texture>  |
| [getRect](#getRect) | Get the SDL_Rect :material-keyboard-return: **Return** :    SDL_Rect  |
| [setRect](#setRect) | Set the SDL_Rect :material-location-enter: `rect` :    SDL_Rect  |
| [setTexture](#setTexture) | Set the texture :material-location-enter: `texture` :    std::shared_ptr<SDL_Texture>  |

## Variable Details

### _rect<a name="_rect"></a>

!!! variable "SDL_Rect _rect"

    SDL_Rect
    

### _texture<a name="_texture"></a>

!!! variable "std::shared_ptr&lt;SDL_Texture&gt; _texture"

    SDL Texture
    

### _textureInformations<a name="_textureInformations"></a>

!!! variable "MyTexture _textureInformations"

    Texture information
    

## Function Details

### SDLTexture<a name="SDLTexture"></a>
!!! function "explicit SDLTexture(const MyTexture&amp; textureInfo)"

    Construct a new SDLTexture object
    
    :material-location-enter: `textureInfo`
    :    MyTexture & Texture information
    

### createTexture<a name="createTexture"></a>
!!! function "int createTexture(const MyTexture&amp; textureInfos, const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Destroy the SDLTexture object
    Create a new texture
        
    :material-location-enter: `textureInfos`
    :    MyTexture & Texture information
        
    :material-location-enter: `renderer`
    :    std::shared_ptr<SDL_Renderer> SDL Renderer
        
    :material-keyboard-return: **Return**
    :    int
    

### getInformations<a name="getInformations"></a>
!!! function "const MyTexture &amp;getInformations() const override"

    Get the texture information
        
    :material-keyboard-return: **Return**
    :    const MyTexture &
    

### getRect<a name="getRect"></a>
!!! function "[[nodiscard]] SDL_Rect getRect() const"

    Get the SDL_Rect
        
    :material-keyboard-return: **Return**
    :    SDL_Rect
    

### getTexture<a name="getTexture"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;SDL_Texture&gt; getTexture() const"

    Get the texture
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<SDL_Texture>
    

### set<a name="set"></a>
!!! function "void set(MyTexture&amp; newTexture) override"

    Set the texture information
        
    :material-location-enter: `newTexture`
    :    MyTexture & Texture information
    

### setRect<a name="setRect"></a>
!!! function "void setRect(Rect rect)"

    Set the SDL_Rect
        
    :material-location-enter: `rect`
    :    SDL_Rect
    

### setTexture<a name="setTexture"></a>
!!! function "void setTexture(std::shared_ptr&lt;SDL_Texture&gt; texture)"

    Set the texture
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SDL_Texture>
    

