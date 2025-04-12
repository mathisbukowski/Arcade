---
generator: doxide
---


# SFMLFont

**class SFMLFont : public IFont**

 of IFont for SFML
This class is used to create a font using the SFML library
It inherits from the IFont interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_info](#_info) | Font information  |
| [_font](#_font) | Font object  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLFont](#SFMLFont) | Constructor :material-location-enter: `fontInfo` :    const Font& Font information  |
| [getInformations](#getInformations) | Destructor Get the font information :material-keyboard-return: **Return** :    const Font& Font information  |
| [getFont](#getFont) | Get the font :material-keyboard-return: **Return** :    sf::Font& Font  |

## Variable Details

### _font<a name="_font"></a>

!!! variable "sf::Font _font"

    Font object
    

### _info<a name="_info"></a>

!!! variable "Font _info"

    Font information
    

## Function Details

### SFMLFont<a name="SFMLFont"></a>
!!! function "explicit SFMLFont(const Font&amp; fontInfo)"

    Constructor
    
    :material-location-enter: `fontInfo`
    :    const Font& Font information
    

### getFont<a name="getFont"></a>
!!! function "sf::Font&amp; getFont()"

    Get the font
        
    :material-keyboard-return: **Return**
    :    sf::Font& Font
    

### getInformations<a name="getInformations"></a>
!!! function "const Font&amp; getInformations() const override"

    Destructor
    Get the font information
        
    :material-keyboard-return: **Return**
    :    const Font& Font information
    

