---
generator: doxide
---


# SDLFont

**class SDLFont : public IFont**


This class is used to create a font using the SDL2 library
It inherits from the IFont interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_font](#_font) | Font  |
| [_fontInformations](#_fontInformations) | Font informations  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLFont](#SDLFont) | Constructor :material-location-enter: `informations` :    Font & Font to create  |
| [createFont](#createFont) | Create a font :material-location-enter: `informations` :    Font & Font to create :material-keyboard-return: **Return** :    int 0 if success, -1 if error  |
| [getInformations](#getInformations) | Destroy the SDLFont object Get the font informations :material-keyboard-return: **Return** :    const Font & Font informations  |
| [getFont](#getFont) | Get the font :material-keyboard-return: **Return** :    const std::shared_ptr<TTF_Font> & Font  |
| [setFont](#setFont) | Set the font :material-location-enter: `font` :    const std::shared_ptr<TTF_Font> & Font  |

## Variable Details

### _font<a name="_font"></a>

!!! variable "std::shared_ptr&lt;TTF_Font&gt; _font"

    Font
    

### _fontInformations<a name="_fontInformations"></a>

!!! variable "Font _fontInformations"

    Font informations
    

## Function Details

### SDLFont<a name="SDLFont"></a>
!!! function "SDLFont(const Font &amp;informations)"

    Constructor
    
    :material-location-enter: `informations`
    :    Font & Font to create
    

### createFont<a name="createFont"></a>
!!! function "int createFont(const Font &amp;informations)"

    Create a font
        
    :material-location-enter: `informations`
    :    Font & Font to create
        
    :material-keyboard-return: **Return**
    :    int 0 if success, -1 if error
    

### getFont<a name="getFont"></a>
!!! function "[[nodiscard]] const std::shared_ptr&lt;TTF_Font&gt; &amp;getFont() const"

    Get the font
        
    :material-keyboard-return: **Return**
    :    const std::shared_ptr<TTF_Font> & Font
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const Font &amp;getInformations() const override"

    Destroy the SDLFont object
    Get the font informations
        
    :material-keyboard-return: **Return**
    :    const Font & Font informations
    

### setFont<a name="setFont"></a>
!!! function "void setFont(const std::shared_ptr&lt;TTF_Font&gt; &amp;font)"

    Set the font
        
    :material-location-enter: `font`
    :    const std::shared_ptr<TTF_Font> & Font
    

