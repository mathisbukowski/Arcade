---
generator: doxide
---


# SDLTexture

**class SDLTexture : public ITexture**


SDL implementation of textures for Arcade


## Variables

| Name | Description |
| ---- | ----------- |
| [_rect](#_rect) | SDL texture rectangle properties  |
| [_texture](#_texture) | SDL texture pointer  |
| [_textureInformations](#_textureInformations) | Texture information  |
| [ERROR_TEXTURE_SIZE](#ERROR_TEXTURE_SIZE) | Error texture size for invalid textures  |
| [EMPTY_TEXTURE_SIZE](#EMPTY_TEXTURE_SIZE) | Empty texture size for uninitialized textures  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLTexture](#SDLTexture) | Construct a new SDLTexture object :material-location-enter: `textureInfo` :    const MyTexture & Base texture information  |
| [createTexture](#createTexture) | Destroy the SDLTexture object Create or update the SDL texture from information :material-location-enter: `textureInfos` :    const MyTexture & Texture information to use :material-location-enter: `renderer` :    const std::shared_ptr<SDL_Renderer> & SDL renderer to create the texture with :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |
| [getInformations](#getInformations) | Get the underlying texture information :material-keyboard-return: **Return** :    const MyTexture & Reference to texture information  |
| [set](#set) | Update the texture information :material-location-enter: `newTexture` :    MyTexture & New texture information  |
| [getTexture](#getTexture) | Get the SDL texture object :material-keyboard-return: **Return** :    std::shared_ptr<SDL_Texture> Shared pointer to SDL_Texture  |
| [getRect](#getRect) | Get the texture dimensions and position :material-keyboard-return: **Return** :    SDL_Rect with texture properties  |
| [setRect](#setRect) | Set the texture rectangle properties :material-location-enter: `rect` :    Rect Arcade rectangle properties to apply  |
| [setTexture](#setTexture) | Replace the SDL texture :material-location-enter: `texture` :    std::shared_ptr<SDL_Texture> New SDL texture  |
| [scaleToGameSize](#scaleToGameSize) | Scale texture to fit game grid cells :material-location-enter: `gridWidth` :    int Width of game grid :material-location-enter: `gridHeight` :    int Height of game grid :material-location-enter: `windowWidth` :    int Width of the window :material-location-enter: `windowHeight` :    int Height of the window  |
| [createErrorTexture](#createErrorTexture) | Create a red X texture for error indication :material-location-enter: `renderer` :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use  |
| [createEmptyTexture](#createEmptyTexture) | Create an empty transparent texture :material-location-enter: `renderer` :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use  |
| [createImageTexture](#createImageTexture) | Create texture from image :material-location-enter: `textureImg` :    const TextureImg & Image texture information :material-location-enter: `renderer` :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |
| [createTextTexture](#createTextTexture) | Create texture from text :material-location-enter: `textureText` :    const TextureText & Text texture information :material-location-enter: `renderer` :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |
| [applyRectFromTextureInfo](#applyRectFromTextureInfo) | Apply rectangle dimensions from texture information :material-location-enter: `info` :    const TextureBase & Texture information to read from  |
| [queryTextureDimensions](#queryTextureDimensions) | Query texture dimensions from SDL texture :material-keyboard-return: **Return** :    bool true on success, false on failure  |

## Variable Details

### EMPTY_TEXTURE_SIZE<a name="EMPTY_TEXTURE_SIZE"></a>

!!! variable "static constexpr int EMPTY_TEXTURE_SIZE"

    Empty texture size for uninitialized textures
    

### ERROR_TEXTURE_SIZE<a name="ERROR_TEXTURE_SIZE"></a>

!!! variable "static constexpr int ERROR_TEXTURE_SIZE"

    Error texture size for invalid textures
    

### _rect<a name="_rect"></a>

!!! variable "SDL_Rect _rect"

    SDL texture rectangle properties
    

### _texture<a name="_texture"></a>

!!! variable "std::shared_ptr&lt;SDL_Texture&gt; _texture"

    SDL texture pointer
    

### _textureInformations<a name="_textureInformations"></a>

!!! variable "MyTexture _textureInformations"

    Texture information
    

## Function Details

### SDLTexture<a name="SDLTexture"></a>
!!! function "explicit SDLTexture(const MyTexture&amp; textureInfo)"

    Construct a new SDLTexture object
    
    :material-location-enter: `textureInfo`
    :    const MyTexture & Base texture information
    

### applyRectFromTextureInfo<a name="applyRectFromTextureInfo"></a>
!!! function "void applyRectFromTextureInfo(const TextureBase&amp; info)"

    Apply rectangle dimensions from texture information
        
    :material-location-enter: `info`
    :    const TextureBase & Texture information to read from
    

### createEmptyTexture<a name="createEmptyTexture"></a>
!!! function "void createEmptyTexture(const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Create an empty transparent texture
        
    :material-location-enter: `renderer`
    :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use
    

### createErrorTexture<a name="createErrorTexture"></a>
!!! function "void createErrorTexture(const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Create a red X texture for error indication
        
    :material-location-enter: `renderer`
    :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use
    

### createImageTexture<a name="createImageTexture"></a>
!!! function "int createImageTexture(const TextureImg&amp; textureImg, const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Create texture from image
        
    :material-location-enter: `textureImg`
    :    const TextureImg & Image texture information
        
    :material-location-enter: `renderer`
    :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

### createTextTexture<a name="createTextTexture"></a>
!!! function "int createTextTexture(const TextureText&amp; textureText, const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Create texture from text
        
    :material-location-enter: `textureText`
    :    const TextureText & Text texture information
        
    :material-location-enter: `renderer`
    :    const std::shared_ptr<SDL_Renderer> & SDL renderer to use
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

### createTexture<a name="createTexture"></a>
!!! function "int createTexture(const MyTexture&amp; textureInfos, const std::shared_ptr&lt;SDL_Renderer&gt;&amp; renderer)"

    Destroy the SDLTexture object
    Create or update the SDL texture from information
        
    :material-location-enter: `textureInfos`
    :    const MyTexture & Texture information to use
        
    :material-location-enter: `renderer`
    :    const std::shared_ptr<SDL_Renderer> & SDL renderer to create the texture with
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const MyTexture &amp;getInformations() const override"

    Get the underlying texture information
        
    :material-keyboard-return: **Return**
    :    const MyTexture & Reference to texture information
    

### getRect<a name="getRect"></a>
!!! function "[[nodiscard]] SDL_Rect getRect() const"

    Get the texture dimensions and position
        
    :material-keyboard-return: **Return**
    :    SDL_Rect with texture properties
    

### getTexture<a name="getTexture"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;SDL_Texture&gt; getTexture() const"

    Get the SDL texture object
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<SDL_Texture> Shared pointer to SDL_Texture
    

### queryTextureDimensions<a name="queryTextureDimensions"></a>
!!! function "bool queryTextureDimensions()"

    Query texture dimensions from SDL texture
        
    :material-keyboard-return: **Return**
    :    bool true on success, false on failure
    

### scaleToGameSize<a name="scaleToGameSize"></a>
!!! function "void scaleToGameSize(int gridWidth, int gridHeight, int windowWidth, int windowHeight)"

    Scale texture to fit game grid cells
        
    :material-location-enter: `gridWidth`
    :    int Width of game grid
        
    :material-location-enter: `gridHeight`
    :    int Height of game grid
        
    :material-location-enter: `windowWidth`
    :    int Width of the window
        
    :material-location-enter: `windowHeight`
    :    int Height of the window
    

### set<a name="set"></a>
!!! function "void set(MyTexture&amp; newTexture) override"

    Update the texture information
        
    :material-location-enter: `newTexture`
    :    MyTexture & New texture information
    

### setRect<a name="setRect"></a>
!!! function "void setRect(Rect rect)"

    Set the texture rectangle properties
        
    :material-location-enter: `rect`
    :    Rect Arcade rectangle properties to apply
    

### setTexture<a name="setTexture"></a>
!!! function "void setTexture(std::shared_ptr&lt;SDL_Texture&gt; texture)"

    Replace the SDL texture
        
    :material-location-enter: `texture`
    :    std::shared_ptr<SDL_Texture> New SDL texture
    

