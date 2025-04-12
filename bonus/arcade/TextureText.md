---
generator: doxide
---


# TextureText

**class TextureText : public TextureBase**

Class for textured text


## Variables

| Name | Description |
| ---- | ----------- |
| [_text](#_text) | Text to be displayed  |
| [_color](#_color) | Color of the text  |

## Functions

| Name | Description |
| ---- | ----------- |
| [TextureText](#TextureText) | Constructor for TextureText :material-location-enter: `text` :    std::string Text :material-location-enter: `color` :    Color Text color :material-location-enter: `rect` :    const std::optional<Rect> & Rect properties  |
| [getText](#getText) | Get the Text object :material-keyboard-return: **Return** :    std::string Text  |
| [setText](#setText) | Set the Text object :material-location-enter: `newText` :    const std::string & Text  |
| [getColor](#getColor) | Get the Color object :material-keyboard-return: **Return** :    const Color Color  |
| [setColor](#setColor) | Set the Color object :material-location-enter: `newColor` :    const Color & Color  |

## Variable Details

### _color<a name="_color"></a>

!!! variable "Color _color"

    Color of the text
    

### _text<a name="_text"></a>

!!! variable "std::string _text"

    Text to be displayed
    

## Function Details

### TextureText<a name="TextureText"></a>
!!! function "explicit TextureText(std::string text = &quot;&quot;, Color color = Color(0, 0, 0), const std::optional&lt;Rect&gt; &amp;rect = std::nullopt)"

    Constructor for TextureText
        
    :material-location-enter: `text`
    :    std::string Text
        
    :material-location-enter: `color`
    :    Color Text color
        
    :material-location-enter: `rect`
    :    const std::optional<Rect> & Rect properties
    

### getColor<a name="getColor"></a>
!!! function "[[nodiscard]] const Color getColor() const"

    Get the Color object
        
    :material-keyboard-return: **Return**
    :    const Color Color
    

### getText<a name="getText"></a>
!!! function "[[nodiscard]] std::string getText() const"

    Get the Text object
        
    :material-keyboard-return: **Return**
    :    std::string Text
    

### setColor<a name="setColor"></a>
!!! function "void setColor(const Color &amp;newColor)"

    Set the Color object
        
    :material-location-enter: `newColor`
    :    const Color & Color
    

### setText<a name="setText"></a>
!!! function "void setText(const std::string &amp;newText)"

    Set the Text object
        
    :material-location-enter: `newText`
    :    const std::string & Text
    

