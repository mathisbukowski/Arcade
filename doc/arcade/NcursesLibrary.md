---
generator: doxide
---


# NcursesLibrary

**class NcursesLibrary : public IDisplayLibrary**

Sfml class to handle the SFML library for the display


## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesLibrary](#NcursesLibrary) | Construct a new Ncurses object  |
| [~NcursesLibrary](#_u007eNcursesLibrary) | Destroy the Sfml object  |
| [getDisplay](#getDisplay) | Get the Display object :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Get the Texture Manager object :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Get the Font Manager object :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Get the Sound Manager object :material-keyboard-return: **Return** :    ISoundManager&  |

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
    

