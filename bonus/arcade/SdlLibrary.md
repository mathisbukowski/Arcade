---
generator: doxide
---


# SdlLibrary

**class SdlLibrary : public IDisplayLibrary**


This class is used to create a library using the SDL2 library
It inherits from the IDisplayLibrary interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_rendererManager](#_rendererManager) | SDL Renderer Manager  |
| [_display](#_display) | Display Module  |
| [_fonts](#_fonts) | Font Manager  |
| [_textures](#_textures) | Texture Manager  |
| [_sounds](#_sounds) | Sound Manager  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SdlLibrary](#SdlLibrary) | Construct a new Sdl object  |
| [getDisplay](#getDisplay) | Destroy the Sdl object Get the Display object :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Get the Texture Manager object :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Get the Font Manager object :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Get the Sound Manager object :material-keyboard-return: **Return** :    ISoundManager&  |

## Variable Details

### _display<a name="_display"></a>

!!! variable "SDLDisplayModule _display"

    Display Module
    

### _fonts<a name="_fonts"></a>

!!! variable "SDLFontManager _fonts"

    Font Manager
    

### _rendererManager<a name="_rendererManager"></a>

!!! variable "SDLRendererManager _rendererManager"

    SDL Renderer Manager
    

### _sounds<a name="_sounds"></a>

!!! variable "SDLSoundManager _sounds"

    Sound Manager
    

### _textures<a name="_textures"></a>

!!! variable "SDLTextureManager _textures"

    Texture Manager
    

## Function Details

### SdlLibrary<a name="SdlLibrary"></a>
!!! function "SdlLibrary()"

    Construct a new Sdl object
    

### getDisplay<a name="getDisplay"></a>
!!! function "IDisplayModule &amp;getDisplay() override"

    Destroy the Sdl object
    Get the Display object
    
    :material-keyboard-return: **Return**
    :    IDisplayModule&
    

### getFonts<a name="getFonts"></a>
!!! function "IFontManager &amp;getFonts() override"

    Get the Font Manager object
    
    :material-keyboard-return: **Return**
    :    IFontManager&
    

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
    

