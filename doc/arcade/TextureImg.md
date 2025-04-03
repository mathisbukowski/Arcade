---
generator: doxide
---


# TextureImg

**class TextureImg**

TextureImg properties


## Functions

| Name | Description |
| ---- | ----------- |
| [TextureImg](#TextureImg) | Construct a new Texture Img object :material-location-enter: `path` :    Path to the image file :material-location-enter: `rect` :    Rect properties :material-keyboard-return: **Return** :    TextureImg  |
| [getPath](#getPath) | Get the Path object :material-keyboard-return: **Return** :    std::string  |
| [getRect](#getRect) | Get the Rect object :material-keyboard-return: **Return** :    std::optional<Rect>  |
| [setRect](#setRect) | Set the Rect object :material-location-enter: `rect` :    Rect properties  |

## Function Details

### TextureImg<a name="TextureImg"></a>
!!! function "TextureImg(std::string path, const std::optional&lt;Rect&gt; &amp;rect = std::nullopt)"

    Construct a new Texture Img object
        
    :material-location-enter: `path`
    :    Path to the image file
        
    :material-location-enter: `rect`
    :    Rect properties
        
    :material-keyboard-return: **Return**
    :    TextureImg
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] std::string getPath() const"

    Get the Path object
        
    :material-keyboard-return: **Return**
    :    std::string
    

### getRect<a name="getRect"></a>
!!! function "[[nodiscard]] std::optional&lt;Rect&gt; getRect() const"

    Get the Rect object
        
    :material-keyboard-return: **Return**
    :    std::optional<Rect>
    

### setRect<a name="setRect"></a>
!!! function "void setRect(const std::optional&lt;Rect&gt; &amp;newRect)"

    Set the Rect object
        
    :material-location-enter: `rect`
    :    Rect properties
    

