---
generator: doxide
---


# NcursesLibrary

**class NcursesLibrary : public IDisplayLibrary**


This class is used to create a library using the ncurses library
It inherits from the IDisplayLibrary interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_textures](#_textures) | Texture Manager  |
| [_display](#_display) | Display Module  |
| [_fonts](#_fonts) | Font Manager  |
| [_sounds](#_sounds) | Sound Manager  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesLibrary](#NcursesLibrary) | Construct a new Ncurses object  |
| [~NcursesLibrary](#_u007eNcursesLibrary) | Destroy the Sfml object  |
| [getDisplay](#getDisplay) | Get the Display object :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Get the Texture Manager object :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Get the Font Manager object :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Get the Sound Manager object :material-keyboard-return: **Return** :    ISoundManager&  |

## Variable Details

### _display<a name="_display"></a>

!!! variable "NcursesDisplayModule _display"

    Display Module
    

### _fonts<a name="_fonts"></a>

!!! variable "NcursesFontManager _fonts"

    Font Manager
    

### _sounds<a name="_sounds"></a>

!!! variable "NcursesSoundManager _sounds"

    Sound Manager
    

### _textures<a name="_textures"></a>

!!! variable "NcursesTextureManager _textures"

    Texture Manager
    

## Function Details

### NcursesLibrary<a name="NcursesLibrary"></a>
!!! function "NcursesLibrary()"

    Construct a new Ncurses object
    

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
    

### ~NcursesLibrary<a name="_u007eNcursesLibrary"></a>
!!! function "virtual ~NcursesLibrary()"

    Destroy the Sfml object
    

