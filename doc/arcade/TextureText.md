---
generator: doxide
---


# TextureText

**class TextureText**

TextureText properties


## Functions

| Name | Description |
| ---- | ----------- |
| [TextureText](#TextureText) | Construct a new Texture Text object :material-location-enter: `text` :    Text :material-location-enter: `color` :    Color of the text :material-location-enter: `rect` :    Rect properties :material-keyboard-return: **Return** :    TextureText  |
| [getText](#getText) | Get the Text object :material-keyboard-return: **Return** :    std::string  |
| [setText](#setText) | Set the Text object :material-location-enter: `text` :    Text  |
| [getColor](#getColor) | Get the Color object :material-keyboard-return: **Return** :    Color  |
| [setColor](#setColor) | Set the Color object :material-location-enter: `color` :    Color  |
| [getRect](#getRect) | Get the Rect object :material-keyboard-return: **Return** :    std::optional<Rect>  |
| [setRect](#setRect) | Set the Rect object :material-location-enter: `rect` :    Rect properties  |

## Function Details

### TextureText<a name="TextureText"></a>
!!! function "TextureText(std::string text = &quot;&quot;, Color color = Color(0, 0, 0), const std::optional&lt;Rect&gt; &amp;rect = std::nullopt)"

    Construct a new Texture Text object
        
    :material-location-enter: `text`
    :    Text
        
    :material-location-enter: `color`
    :    Color of the text
        
    :material-location-enter: `rect`
    :    Rect properties
        
    :material-keyboard-return: **Return**
    :    TextureText
    

### getColor<a name="getColor"></a>
!!! function "[[nodiscard]] Color getColor() const"

    Get the Color object
        
    :material-keyboard-return: **Return**
    :    Color
    

### getRect<a name="getRect"></a>
!!! function "[[nodiscard]] std::optional&lt;Rect&gt; getRect() const"

    Get the Rect object
        
    :material-keyboard-return: **Return**
    :    std::optional<Rect>
    

### getText<a name="getText"></a>
!!! function "[[nodiscard]] std::string getText() const"

    Get the Text object
        
    :material-keyboard-return: **Return**
    :    std::string
    

### setColor<a name="setColor"></a>
!!! function "void setColor(const Color &amp;newColor)"

    Set the Color object
        
    :material-location-enter: `color`
    :    Color
    

### setRect<a name="setRect"></a>
!!! function "void setRect(const std::optional&lt;Rect&gt; &amp;newRect)"

    Set the Rect object
        
    :material-location-enter: `rect`
    :    Rect properties
    

### setText<a name="setText"></a>
!!! function "void setText(const std::string &amp;newText)"

    Set the Text object
        
    :material-location-enter: `text`
    :    Text
    

