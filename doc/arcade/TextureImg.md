---
generator: doxide
---


# TextureImg

**class TextureImg : public TextureBase**

Class for textured images


## Variables

| Name | Description |
| ---- | ----------- |
| [_path](#_path) | Path to the image file  |

## Functions

| Name | Description |
| ---- | ----------- |
| [TextureImg](#TextureImg) | Constructor for TextureImg :material-location-enter: `path` :    std::string Path to the image file :material-location-enter: `rect` :    const std::optional <Rect> & Rect properties  |
| [getPath](#getPath) | Get the Path object :material-keyboard-return: **Return** :    std::string  |

## Variable Details

### _path<a name="_path"></a>

!!! variable "std::string _path"

    Path to the image file
    

## Function Details

### TextureImg<a name="TextureImg"></a>
!!! function "explicit TextureImg(std::string path, const std::optional&lt;Rect&gt; &amp;rect = std::nullopt)"

    Constructor for TextureImg
        
    :material-location-enter: `path`
    :    std::string Path to the image file
        
    :material-location-enter: `rect`
    :    const std::optional <Rect> & Rect properties
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] std::string getPath() const"

    Get the Path object
        
    :material-keyboard-return: **Return**
    :    std::string
    

