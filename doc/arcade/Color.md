---
generator: doxide
---


# Color

**class Color**

Color properties


## Functions

| Name | Description |
| ---- | ----------- |
| [Color](#Color) | Construct a new Color object :material-location-enter: `r` :    Red component (0-255) :material-location-enter: `g` :    Green component (0-255) :material-location-enter: `b` :    Blue component (0-255) :material-location-enter: `a` :    Alpha (opacity) component (0-255), default is 255  |
| [getR](#getR) | Get the red component :material-keyboard-return: **Return** :    uint8_t Red value (0-255)  |
| [getG](#getG) | Get the green component :material-keyboard-return: **Return** :    uint8_t Green value (0-255)  |
| [getB](#getB) | Get the blue component :material-keyboard-return: **Return** :    uint8_t Blue value (0-255)  |
| [getOpacity](#getOpacity) | Get the alpha (opacity) component :material-keyboard-return: **Return** :    uint8_t Alpha value (0-255)  |
| [setR](#setR) | Set the red component :material-location-enter: `r` :    Red value (0-255)  |
| [setG](#setG) | Set the green component :material-location-enter: `g` :    Green value (0-255)  |
| [setB](#setB) | Set the blue component :material-location-enter: `b` :    Blue value (0-255)  |
| [setOpacity](#setOpacity) | Set the alpha (opacity) component :material-location-enter: `newOpacity` :    Alpha value (0-255)  |

## Function Details

### Color<a name="Color"></a>
!!! function "Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)"

    Construct a new Color object
    
    :material-location-enter: `r`
    :    Red component (0-255)
        
    :material-location-enter: `g`
    :    Green component (0-255)
        
    :material-location-enter: `b`
    :    Blue component (0-255)
        
    :material-location-enter: `a`
    :    Alpha (opacity) component (0-255), default is 255
    

### getB<a name="getB"></a>
!!! function "[[nodiscard]] uint8_t getB() const"

    Get the blue component
        
    :material-keyboard-return: **Return**
    :    uint8_t Blue value (0-255)
    

### getG<a name="getG"></a>
!!! function "[[nodiscard]] uint8_t getG() const"

    Get the green component
        
    :material-keyboard-return: **Return**
    :    uint8_t Green value (0-255)
    

### getOpacity<a name="getOpacity"></a>
!!! function "[[nodiscard]] uint8_t getOpacity() const"

    Get the alpha (opacity) component
        
    :material-keyboard-return: **Return**
    :    uint8_t Alpha value (0-255)
    

### getR<a name="getR"></a>
!!! function "[[nodiscard]] uint8_t getR() const"

    Get the red component
        
    :material-keyboard-return: **Return**
    :    uint8_t Red value (0-255)
    

### setB<a name="setB"></a>
!!! function "void setB(const uint8_t b)"

    Set the blue component
        
    :material-location-enter: `b`
    :    Blue value (0-255)
    

### setG<a name="setG"></a>
!!! function "void setG(const uint8_t g)"

    Set the green component
        
    :material-location-enter: `g`
    :    Green value (0-255)
    

### setOpacity<a name="setOpacity"></a>
!!! function "void setOpacity(const uint8_t newOpacity)"

    Set the alpha (opacity) component
        
    :material-location-enter: `newOpacity`
    :    Alpha value (0-255)
    

### setR<a name="setR"></a>
!!! function "void setR(const uint8_t r)"

    Set the red component
        
    :material-location-enter: `r`
    :    Red value (0-255)
    

