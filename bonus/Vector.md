---
generator: doxide
---


# Vector

**template &lt;typename T&gt; class Vector**


Template class representing a generic 2D vector.

:material-code-tags: `T`
:    Type of the vector coordinates.


## Variables

| Name | Description |
| ---- | ----------- |
| [_x](#_x) |     X coordinate. |
| [_y](#_y) |     Y coordinate. |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator+](#operator_u002b) | Operator overloads :material-location-enter: `other` :    Other vector :material-keyboard-return: **Return** :    Vector object  |

## Functions

| Name | Description |
| ---- | ----------- |
| [Vector](#Vector) | Constructor with initial values. |
| [Vector](#Vector) | Default constructor (zero vector). |
| [getX](#getX) | Get the X values :material-keyboard-return: **Return** :    X values  |
| [getY](#getY) | Get the Y values :material-keyboard-return: **Return** :    Y values  |
| [setX](#setX) | Set the X value :material-location-enter: `x` :    X value  |
| [setY](#setY) | Set the Y value :material-location-enter: `y` :    Y value  |

## Variable Details

### _x<a name="_x"></a>

!!! variable "T _x"

        X coordinate.
    

### _y<a name="_y"></a>

!!! variable "T _y"

        Y coordinate.
    

## Operator Details

### operator+<a name="operator_u002b"></a>

!!! function "Vector&lt;T&gt; operator+(const Vector&lt;T&gt;&amp; other) const"

    Operator overloads
        
    :material-location-enter: `other`
    :    Other vector
        
    :material-keyboard-return: **Return**
    :    Vector object
    

## Function Details

### Vector<a name="Vector"></a>
!!! function "Vector(T x, T y)"

    Constructor with initial values.
        
    :material-location-enter: `x`
    :    X coordinate.
        
    :material-location-enter: `y`
    :    Y coordinate.
    

!!! function "Vector()"

    Default constructor (zero vector).
    

### getX<a name="getX"></a>
!!! function "T getX() const"

    Get the X values
        
    :material-keyboard-return: **Return**
    :    X values
    

### getY<a name="getY"></a>
!!! function "T getY() const"

    Get the Y values
        
    :material-keyboard-return: **Return**
    :    Y values
    

### setX<a name="setX"></a>
!!! function "void setX(T x)"

    Set the X value
        
    :material-location-enter: `x`
    :    X value
    

### setY<a name="setY"></a>
!!! function "void setY(T y)"

    Set the Y value
        
    :material-location-enter: `y`
    :    Y value
    

