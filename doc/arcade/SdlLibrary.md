---
generator: doxide
---


# SdlLibrary

**class SdlLibrary : public IDisplayLibrary**

Sdl class to handle the SDL library for the display


## Functions

| Name | Description |
| ---- | ----------- |
| [SdlLibrary](#SdlLibrary) | Construct a new Sdl object  |
| [~SdlLibrary](#_u007eSdlLibrary) | Destroy the Sdl object  |
| [getDisplay](#getDisplay) | Get the Display object :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Get the Texture Manager object :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Get the Font Manager object :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Get the Sound Manager object :material-keyboard-return: **Return** :    ISoundManager&  |

## Function Details

### SdlLibrary<a name="SdlLibrary"></a>
!!! function "SdlLibrary()"

    Construct a new Sdl object
    

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
!!! function "virtual ISoundManager &amp;getSounds() override"

    Get the Sound Manager object
    
    :material-keyboard-return: **Return**
    :    ISoundManager&
    

### getTextures<a name="getTextures"></a>
!!! function "ITextureManager &amp;getTextures() override"

    Get the Texture Manager object
    
    :material-keyboard-return: **Return**
    :    ITextureManager&
    

### ~SdlLibrary<a name="_u007eSdlLibrary"></a>
!!! function "~SdlLibrary()"

    Destroy the Sdl object
    

