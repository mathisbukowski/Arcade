---
generator: doxide
---


# ResolutionScaler

**class ResolutionScaler**


Class to scale the resolution of the display.


## Variables

| Name | Description |
| ---- | ----------- |
| [_scaleX](#_scaleX) | Scale factors for X axis  |
| [_scaleY](#_scaleY) | Scale factors for Y axis  |
| [_isTextBased](#_isTextBased) | Boolean to check if the display is text based  |
| [_scaleFontSize](#_scaleFontSize) | Scale factor for font size  |
| [REF_WIDTH](#REF_WIDTH) | Reference width for the display  |
| [REF_HEIGHT](#REF_HEIGHT) | Reference height for the display  |
| [NCURSES_REF_WIDTH](#NCURSES_REF_WIDTH) | Reference width for the ncurses based display  |
| [NCURSES_REF_HEIGHT](#NCURSES_REF_HEIGHT) | Reference height for the ncurses based display  |

## Functions

| Name | Description |
| ---- | ----------- |
| [ResolutionScaler](#ResolutionScaler) | Constructor :material-location-enter: `display` :    IDisplayModule& Reference to the display module  |
| [toScreenPosition](#toScreenPosition) | Function to scale the position to the scaled resolution :material-location-enter: `pos` :    const Vector<float>& Position to scale :material-keyboard-return: **Return** :    Vector<float> Scaled position  |
| [toScreenSize](#toScreenSize) | Function to scale the size to the scaled resolution :material-location-enter: `size` :    const Vector<float>& Size to scale :material-keyboard-return: **Return** :    Vector<float> Scaled size  |
| [buildScreenRect](#buildScreenRect) | Function to call toScreenPosition and toScreenSize to build a Rect at the scaled resolution :material-location-enter: `logicalPos` :    const Vector<float>& Logical position :material-location-enter: `logicalSize` :    const Vector<float>& Logical size :material-keyboard-return: **Return** :    Rect Scaled Rect  |

## Variable Details

### NCURSES_REF_HEIGHT<a name="NCURSES_REF_HEIGHT"></a>

!!! variable "static constexpr float NCURSES_REF_HEIGHT"

    Reference height for the ncurses based display
    

### NCURSES_REF_WIDTH<a name="NCURSES_REF_WIDTH"></a>

!!! variable "static constexpr float NCURSES_REF_WIDTH"

    Reference width for the ncurses based display
    

### REF_HEIGHT<a name="REF_HEIGHT"></a>

!!! variable "static constexpr float REF_HEIGHT"

    Reference height for the display
    

### REF_WIDTH<a name="REF_WIDTH"></a>

!!! variable "static constexpr float REF_WIDTH"

    Reference width for the display
    

### _isTextBased<a name="_isTextBased"></a>

!!! variable "bool _isTextBased"

    Boolean to check if the display is text based
    

### _scaleFontSize<a name="_scaleFontSize"></a>

!!! variable "float _scaleFontSize"

    Scale factor for font size
    

### _scaleX<a name="_scaleX"></a>

!!! variable "float _scaleX"

    Scale factors for X axis
    

### _scaleY<a name="_scaleY"></a>

!!! variable "float _scaleY"

    Scale factors for Y axis
    

## Function Details

### ResolutionScaler<a name="ResolutionScaler"></a>
!!! function "explicit ResolutionScaler(IDisplayModule&amp; display)"

    Constructor
    
    :material-location-enter: `display`
    :    IDisplayModule& Reference to the display module
    

### buildScreenRect<a name="buildScreenRect"></a>
!!! function "[[nodiscard]] Rect buildScreenRect(const Vector&lt;float&gt;&amp; logicalPos, const Vector&lt;float&gt;&amp; logicalSize) const"

    Function to call toScreenPosition and toScreenSize to build a Rect at the scaled resolution
        
    :material-location-enter: `logicalPos`
    :    const Vector<float>& Logical position
        
    :material-location-enter: `logicalSize`
    :    const Vector<float>& Logical size
        
    :material-keyboard-return: **Return**
    :    Rect Scaled Rect
    

### toScreenPosition<a name="toScreenPosition"></a>
!!! function "[[nodiscard]] Vector&lt;float&gt; toScreenPosition(const Vector&lt;float&gt;&amp; pos) const"

    Function to scale the position to the scaled resolution
        
    :material-location-enter: `pos`
    :    const Vector<float>& Position to scale
        
    :material-keyboard-return: **Return**
    :    Vector<float> Scaled position
    

### toScreenSize<a name="toScreenSize"></a>
!!! function "[[nodiscard]] Vector&lt;float&gt; toScreenSize(const Vector&lt;float&gt;&amp; size) const"

    Function to scale the size to the scaled resolution
        
    :material-location-enter: `size`
    :    const Vector<float>& Size to scale
        
    :material-keyboard-return: **Return**
    :    Vector<float> Scaled size
    

