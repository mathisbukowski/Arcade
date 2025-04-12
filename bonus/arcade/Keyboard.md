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

## Variables

| Name | Description |
| ---- | ----------- |
| [_keys](#_keys) | Map of key codes and their pressed state  |

## Functions

| Name | Description |
| ---- | ----------- |
| [isKeyPressed](#isKeyPressed) | Check if a key is pressed :material-location-enter: `code` :    KeyCode Key code :material-keyboard-return: **Return** :    true if the key is pressed, false otherwise (bool)  |
| [setKey](#setKey) | Set a key state :material-location-enter: `code` :    KeyCode Key code :material-location-enter: `isPressed` :    bool Key state  |
| [clearPressedKeys](#clearPressedKeys) | Clear all pressed keys  |

## Variable Details

### _keys<a name="_keys"></a>

!!! variable "std::unordered_map&lt;KeyCode, bool&gt; _keys"

    Map of key codes and their pressed state
    

## Function Details

### clearPressedKeys<a name="clearPressedKeys"></a>
!!! function "void clearPressedKeys()"

    Clear all pressed keys
    

### isKeyPressed<a name="isKeyPressed"></a>
!!! function "bool isKeyPressed(KeyCode code) const"

    Check if a key is pressed
    
    :material-location-enter: `code`
    :    KeyCode Key code
        
    :material-keyboard-return: **Return**
    :    true if the key is pressed, false otherwise (bool)
    

### setKey<a name="setKey"></a>
!!! function "void setKey(KeyCode code, bool isPressed)"

    Set a key state
        
    :material-location-enter: `code`
    :    KeyCode Key code
        
    :material-location-enter: `isPressed`
    :    bool Key state
    

