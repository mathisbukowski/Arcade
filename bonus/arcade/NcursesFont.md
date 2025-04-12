---
generator: doxide
---


# NcursesFont

**class NcursesFont : public IFont**


This class is used to create a font using the ncurses library
It inherits from the IFont interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_fontInformations](#_fontInformations) | Font informations  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesFont](#NcursesFont) | Constructor :material-location-enter: `font` :    Font & Font to create  |
| [getInformations](#getInformations) | Get the font informations :material-keyboard-return: **Return** :    const Font & Font informations  |

## Variable Details

### _fontInformations<a name="_fontInformations"></a>

!!! variable "Font _fontInformations"

    Font informations
    

## Function Details

### NcursesFont<a name="NcursesFont"></a>
!!! function "NcursesFont(const Font&amp; font)"

    Constructor
    
    :material-location-enter: `font`
    :    Font & Font to create
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const Font&amp; getInformations() const override"

    Get the font informations
        
    :material-keyboard-return: **Return**
    :    const Font & Font informations
    

