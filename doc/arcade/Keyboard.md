---
generator: doxide
---


# Keyboard

**class Keyboard**

Keyboard input


## Types

| Name | Description |
| ---- | ----------- |
| [KeyCode](Keyboard/KeyCode.md) | Key codes  |

## Functions

| Name | Description |
| ---- | ----------- |
| [isKeyPressed](#isKeyPressed) | Check if a key is pressed :material-location-enter: `keyCode` :    Key code :material-keyboard-return: **Return** :    true if the key is pressed, false otherwise  |
| [setKey](#setKey) | Set a key state :material-location-enter: `keyCode` :    Key code :material-location-enter: `isPressed` :    Key state  |
| [clearPressedKeys](#clearPressedKeys) | Clear all pressed keys  |

## Function Details

### clearPressedKeys<a name="clearPressedKeys"></a>
!!! function "void clearPressedKeys()"

    Clear all pressed keys
    

### isKeyPressed<a name="isKeyPressed"></a>
!!! function "bool isKeyPressed(KeyCode code) const"

    Check if a key is pressed
    
    :material-location-enter: `keyCode`
    :    Key code
        
    :material-keyboard-return: **Return**
    :    true if the key is pressed, false otherwise
    

### setKey<a name="setKey"></a>
!!! function "void setKey(KeyCode code, bool isPressed)"

    Set a key state
        
    :material-location-enter: `keyCode`
    :    Key code
        
    :material-location-enter: `isPressed`
    :    Key state
    

