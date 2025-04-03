---
generator: doxide
---


# Font

**class Font**

Font properties


## Functions

| Name | Description |
| ---- | ----------- |
| [Font](#Font) | Construct a new Font object :material-location-enter: `path` :    Path to the font file :material-location-enter: `color` :    Color of the font :material-location-enter: `size` :    Size of the font  |
| [getPath](#getPath) | Destroy the Font object Get the path to the font file :material-keyboard-return: **Return** :    const std::string&  |
| [getColor](#getColor) | Get the color of the font :material-keyboard-return: **Return** :    Color  |
| [setColor](#setColor) | Set the color of the font :material-location-enter: `newColor` :    New color of the font  |
| [getSize](#getSize) | Get the size of the font :material-keyboard-return: **Return** :    std::size_t  |
| [setSize](#setSize) | Set the size of the font :material-location-enter: `newSize` :    New size of the font  |

## Function Details

### Font<a name="Font"></a>
!!! function "Font(std::string path, Color color, std::size_t size = 12)"

    Construct a new Font object
    
    :material-location-enter: `path`
    :    Path to the font file
        
    :material-location-enter: `color`
    :    Color of the font
        
    :material-location-enter: `size`
    :    Size of the font
    

### getColor<a name="getColor"></a>
!!! function "[[nodiscard]] Color getColor() const"

    Get the color of the font
        
    :material-keyboard-return: **Return**
    :    Color
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] const std::string&amp; getPath() const"

    Destroy the Font object
    Get the path to the font file
        
    :material-keyboard-return: **Return**
    :    const std::string&
    

### getSize<a name="getSize"></a>
!!! function "[[nodiscard]] std::size_t getSize() const"

    Get the size of the font
        
    :material-keyboard-return: **Return**
    :    std::size_t
    

### setColor<a name="setColor"></a>
!!! function "void setColor(Color newColor)"

    Set the color of the font
        
    :material-location-enter: `newColor`
    :    New color of the font
    

### setSize<a name="setSize"></a>
!!! function "void setSize(std::size_t newSize)"

    Set the size of the font
        
    :material-location-enter: `newSize`
    :    New size of the font
    

