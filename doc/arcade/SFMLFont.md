---
generator: doxide
---


# SFMLFont

**class SFMLFont : public IFont**


This class is used to create a font using the SFML library
It inherits from the IFont interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_info](#_info) | Font information  |
| [_font](#_font) | SFML font  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLFont](#SFMLFont) | Construct a new SFMLFont object :material-location-enter: `fontInfo` :    const Font& Font information  |
| [getInformations](#getInformations) | Destroy the SFMLFont object Get the font information :material-keyboard-return: **Return** :    const Font&  |
| [getFont](#getFont) | Get the SFML font :material-keyboard-return: **Return** :    sf::Font&  |

## Variable Details

### _font<a name="_font"></a>

!!! variable "sf::Font _font"

    SFML font
    

### _info<a name="_info"></a>

!!! variable "Font _info"

    Font information
    

## Function Details

### SFMLFont<a name="SFMLFont"></a>
!!! function "explicit SFMLFont(const Font&amp; fontInfo)"

    Construct a new SFMLFont object
    
    :material-location-enter: `fontInfo`
    :    const Font& Font information
    

### getFont<a name="getFont"></a>
!!! function "sf::Font&amp; getFont()"

    Get the SFML font
        
    :material-keyboard-return: **Return**
    :    sf::Font&
    

### getInformations<a name="getInformations"></a>
!!! function "const Font&amp; getInformations() const override"

    Destroy the SFMLFont object
    Get the font information
        
    :material-keyboard-return: **Return**
    :    const Font&
    

