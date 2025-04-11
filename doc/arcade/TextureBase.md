---
generator: doxide
---


# TextureBase

**class TextureBase**



## Variables

| Name | Description |
| ---- | ----------- |
| [_rect](#_rect) | Rect properties  |
| [_width](#_width) | Width of the texture  |
| [_height](#_height) | Height of the texture  |

## Functions

| Name | Description |
| ---- | ----------- |
| [TextureBase](#TextureBase) | Constructor for TextureBase :material-location-enter: `rect` :    const std::optional<Rect> & Rect properties  |
| [getRect](#getRect) | Destructor for TextureBase Get the Rect object :material-keyboard-return: **Return** :    std::optional<Rect>  |
| [setRect](#setRect) | Set the Rect object :material-location-enter: `rect` :    const std::optional<Rect> Rect properties  |
| [getWidth](#getWidth) | Get the Width object :material-keyboard-return: **Return** :    uint32_t Width  |
| [setWidth](#setWidth) | Set the Width object :material-location-enter: `newWidth` :    uint32_t Width  |
| [getHeight](#getHeight) | Get the Height object :material-keyboard-return: **Return** :    uint32_t Height  |
| [setHeight](#setHeight) | Set the Height object :material-location-enter: `height` :    uint32_t Height  |

## Variable Details

### _height<a name="_height"></a>

!!! variable "uint32_t _height"

    Height of the texture
    

### _rect<a name="_rect"></a>

!!! variable "std::optional&lt;Rect&gt; _rect"

    Rect properties
    

### _width<a name="_width"></a>

!!! variable "uint32_t _width"

    Width of the texture
    

## Function Details

### TextureBase<a name="TextureBase"></a>
!!! function "explicit TextureBase(const std::optional&lt;Rect&gt; &amp;rect = std::nullopt)"

    Constructor for TextureBase
        
    :material-location-enter: `rect`
    :    const std::optional<Rect> & Rect properties
    

### getHeight<a name="getHeight"></a>
!!! function "[[nodiscard]] uint32_t getHeight() const"

    Get the Height object
        
    :material-keyboard-return: **Return**
    :    uint32_t Height
    

### getRect<a name="getRect"></a>
!!! function "[[nodiscard]] std::optional&lt;Rect&gt; getRect() const"

    Destructor for TextureBase
    Get the Rect object
        
    :material-keyboard-return: **Return**
    :    std::optional<Rect>
    

### getWidth<a name="getWidth"></a>
!!! function "[[nodiscard]] uint32_t getWidth() const"

    Get the Width object
        
    :material-keyboard-return: **Return**
    :    uint32_t Width
    

### setHeight<a name="setHeight"></a>
!!! function "void setHeight(uint32_t newHeight)"

    Set the Height object
        
    :material-location-enter: `height`
    :    uint32_t Height
    

### setRect<a name="setRect"></a>
!!! function "void setRect(const std::optional&lt;Rect&gt; &amp;newRect)"

    Set the Rect object
        
    :material-location-enter: `rect`
    :    const std::optional<Rect> Rect properties
    

### setWidth<a name="setWidth"></a>
!!! function "void setWidth(uint32_t newWidth)"

    Set the Width object
        
    :material-location-enter: `newWidth`
    :    uint32_t Width
    

