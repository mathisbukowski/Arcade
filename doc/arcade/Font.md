---
generator: doxide
---


# Font

**class Font**

Font properties


## Variables

| Name | Description |
| ---- | ----------- |
| [_path](#_path) | Path to the font file  |
| [_color](#_color) | Color of the font  |
| [_size](#_size) | Size of the font  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Font](#Font) | Construct a new Font object :material-location-enter: `path` :    std::string Path to the font file :material-location-enter: `color` :    Color Font color :material-location-enter: `size` :    std::size_t Size of the font  |
| [getPath](#getPath) | Destroy the Font object Get the path to the font file :material-keyboard-return: **Return** :    const std::string& Path to the font file  |
| [getColor](#getColor) | Get the color of the font :material-keyboard-return: **Return** :    Color Color of the font  |
| [setColor](#setColor) | Set the color of the font :material-location-enter: `newColor` :    Color New color of the font  |
| [getSize](#getSize) | Get the size of the font :material-keyboard-return: **Return** :    std::size_t Size of the font  |
| [setSize](#setSize) | Set the size of the font :material-location-enter: `newSize` :    std::size_t New size of the font  |

## Variable Details

### _color<a name="_color"></a>

!!! variable "Color _color"

    Color of the font
    

### _path<a name="_path"></a>

!!! variable "std::string _path"

    Path to the font file
    

### _size<a name="_size"></a>

!!! variable "std::size_t _size"

    Size of the font
    

## Function Details

### Font<a name="Font"></a>
!!! function "Font(std::string path, Color color, std::size_t size = 12)"

    Construct a new Font object
    
    :material-location-enter: `path`
    :    std::string Path to the font file
        
    :material-location-enter: `color`
    :    Color Font color
        
    :material-location-enter: `size`
    :    std::size_t Size of the font
    

### getColor<a name="getColor"></a>
!!! function "[[nodiscard]] Color getColor() const"

    Get the color of the font
        
    :material-keyboard-return: **Return**
    :    Color Color of the font
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] const std::string&amp; getPath() const"

    Destroy the Font object
    Get the path to the font file
        
    :material-keyboard-return: **Return**
    :    const std::string& Path to the font file
    

### getSize<a name="getSize"></a>
!!! function "[[nodiscard]] std::size_t getSize() const"

    Get the size of the font
        
    :material-keyboard-return: **Return**
    :    std::size_t Size of the font
    

### setColor<a name="setColor"></a>
!!! function "void setColor(Color newColor)"

    Set the color of the font
        
    :material-location-enter: `newColor`
    :    Color New color of the font
    

### setSize<a name="setSize"></a>
!!! function "void setSize(std::size_t newSize)"

    Set the size of the font
        
    :material-location-enter: `newSize`
    :    std::size_t New size of the font
    

