---
generator: doxide
---


# SFMLLibrary

**class SFMLLibrary : public IDisplayLibrary**


This class is used to create a library using the SFML library
It inherits from the IDisplayLibrary interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_display](#_display) | Display module  |
| [_textureManager](#_textureManager) | Texture manager  |
| [_fontManager](#_fontManager) | Font manager  |
| [_soundManager](#_soundManager) | Sound manager  |

## Functions

| Name | Description |
| ---- | ----------- |
| [getDisplay](#getDisplay) | Construct a new SFMLLibrary object Destroy the SFMLLibrary object Return the display module :material-keyboard-return: **Return** :    IDisplayModule&  |
| [getTextures](#getTextures) | Return the texture manager :material-keyboard-return: **Return** :    ITextureManager&  |
| [getFonts](#getFonts) | Return the font manager :material-keyboard-return: **Return** :    IFontManager&  |
| [getSounds](#getSounds) | Return the sound manager :material-keyboard-return: **Return** :    ISoundManager&  |

## Variable Details

### _display<a name="_display"></a>

!!! variable "SFMLDisplay _display"

    Display module
    

### _fontManager<a name="_fontManager"></a>

!!! variable "SFMLFontManager _fontManager"

    Font manager
    

### _soundManager<a name="_soundManager"></a>

!!! variable "SFMLSoundManager _soundManager"

    Sound manager
    

### _textureManager<a name="_textureManager"></a>

!!! variable "SFMLTextureManager _textureManager"

    Texture manager
    

## Function Details

### getDisplay<a name="getDisplay"></a>
!!! function "IDisplayModule&amp; getDisplay() override"

    Construct a new SFMLLibrary object
    Destroy the SFMLLibrary object
    Return the display module
    
    :material-keyboard-return: **Return**
    :    IDisplayModule&
    

### getFonts<a name="getFonts"></a>
!!! function "IFontManager&amp; getFonts() override"

    Return the font manager
    
    :material-keyboard-return: **Return**
    :    IFontManager&
    

### getSounds<a name="getSounds"></a>
!!! function "ISoundManager&amp; getSounds() override"

    Return the sound manager
    
    :material-keyboard-return: **Return**
    :    ISoundManager&
    

### getTextures<a name="getTextures"></a>
!!! function "ITextureManager&amp; getTextures() override"

    Return the texture manager
    
    :material-keyboard-return: **Return**
    :    ITextureManager&
    

