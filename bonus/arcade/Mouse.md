---
generator: doxide
---


# Mouse

**class Mouse**

Mouse input


## Variables

| Name | Description |
| ---- | ----------- |
| [_position](#_position) | Position of the mouse  |
| [_pressed](#_pressed) | Pressed state of the mouse button  |

## Functions

| Name | Description |
| ---- | ----------- |
| [getPos](#getPos) | Mouse button codes Destroy the Mouse object Retrieves the current position of the mouse. |
| [isPressed](#isPressed) | Checks if the mouse button is currently pressed. |
| [setPos](#setPos) | Sets the position of the mouse. |
| [setPressed](#setPressed) | Sets the pressed state of the mouse button. |

## Variable Details

### _position<a name="_position"></a>

!!! variable "Vector&lt;float&gt; _position"

    Position of the mouse
    

### _pressed<a name="_pressed"></a>

!!! variable "bool _pressed"

    Pressed state of the mouse button
    

## Function Details

### getPos<a name="getPos"></a>
!!! function "[[nodiscard]] Vector&lt;float&gt; getPos() const"

    Mouse button codes
    Destroy the Mouse object
    Retrieves the current position of the mouse.
        
    :material-keyboard-return: **Return**
    :    Vector<float> position of the mouse
    

### isPressed<a name="isPressed"></a>
!!! function "[[nodiscard]] bool isPressed() const"

    Checks if the mouse button is currently pressed.
        
    :material-keyboard-return: **Return**
    :    bool true if the mouse button is pressed, false otherwise
    

### setPos<a name="setPos"></a>
!!! function "void setPos(Vector&lt;float&gt; newPos)"

    Sets the position of the mouse.
        
    :material-location-enter: `newPos`
    :    Vector<float> representing the new position of the mouse.
    

### setPressed<a name="setPressed"></a>
!!! function "void setPressed(bool pressed)"

    Sets the pressed state of the mouse button.
        
    :material-location-enter: `pressed`
    :    A boolean value indicating whether the mouse button is pressed.
    

