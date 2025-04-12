---
generator: doxide
---


# NcursesTexture

**class NcursesTexture : public ITexture**


This class is used to create a texture using the ncurses library
It inherits from the ITexture interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_textureInformations](#_textureInformations) | Texture informations  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesTexture](#NcursesTexture) | Constructor :material-location-enter: `texture` :    MyTexture & Texture to create  |
| [getInformations](#getInformations) | Get the texture informations :material-keyboard-return: **Return** :    const MyTexture & Texture informations  |
| [set](#set) | Set the texture informations :material-location-enter: `texture` :    MyTexture & Texture to set  |

## Variable Details

### _textureInformations<a name="_textureInformations"></a>

!!! variable "MyTexture _textureInformations"

    Texture informations
    

## Function Details

### NcursesTexture<a name="NcursesTexture"></a>
!!! function "NcursesTexture(const MyTexture &amp;texture)"

    Constructor
    
    :material-location-enter: `texture`
    :    MyTexture & Texture to create
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const MyTexture&amp; getInformations() const override"

    Get the texture informations
        
    :material-keyboard-return: **Return**
    :    const MyTexture & Texture informations
    

### set<a name="set"></a>
!!! function "void set(MyTexture&amp; texture) override"

    Set the texture informations
        
    :material-location-enter: `texture`
    :    MyTexture & Texture to set
    

