---
generator: doxide
---


# Mouse

**class Mouse**

Mouse input


## Functions

| Name | Description |
| ---- | ----------- |
| [getPos](#getPos) | Retrieves the current position of the mouse. |
| [isPressed](#isPressed) | Checks if the mouse button is currently pressed. |
| [setPos](#setPos) | Sets the position of the mouse. |
| [setPressed](#setPressed) | Sets the pressed state of the mouse button. |

## Function Details

### getPos<a name="getPos"></a>
!!! function "[[nodiscard]] Vector&lt;float&gt; getPos() const"

    Retrieves the current position of the mouse.
    
    
    :material-keyboard-return: **Return**
    :    A Vector<float> representing the current position of the mouse.
    

### isPressed<a name="isPressed"></a>
!!! function "[[nodiscard]] bool isPressed() const"

    Checks if the mouse button is currently pressed.
    
    
    :material-keyboard-return: **Return**
    :    A boolean value indicating whether the mouse button is pressed.
    

### setPos<a name="setPos"></a>
!!! function "void setPos(Vector&lt;float&gt; newPos)"

    Sets the position of the mouse.
    
    
    :material-location-enter: `newPos`
    :    A Vector<float> representing the new position of the mouse.
    

### setPressed<a name="setPressed"></a>
!!! function "void setPressed(bool pressed)"

    Sets the pressed state of the mouse button.
    
    
    :material-location-enter: `pressed`
    :    A boolean value indicating whether the mouse button is pressed.
    

