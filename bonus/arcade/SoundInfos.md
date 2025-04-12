---
generator: doxide
---


# SoundInfos

**class SoundInfos**

Sound properties


## Variables

| Name | Description |
| ---- | ----------- |
| [_path](#_path) | Path to the sound file  |
| [_volume](#_volume) | Volume level  |
| [_loop](#_loop) | Looping state  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SoundInfos](#SoundInfos) | Construct a new SoundInfos object :material-location-enter: `path` :    std::string Path to the sound file  |
| [getPath](#getPath) | Destroy the SoundInfos object Get the path of the sound file :material-keyboard-return: **Return** :    std::string Path of the sound file  |
| [getVolume](#getVolume) | Get the volume level :material-keyboard-return: **Return** :    float Volume level  |
| [setVolume](#setVolume) | Set the volume level :material-location-enter: `newVolume` :    float New volume value  |
| [isLooped](#isLooped) | Check if the music is looped :material-keyboard-return: **Return** :    bool True if the music is looped, false otherwise  |
| [setLoop](#setLoop) | Enable or disable looping :material-location-enter: `loop` :    bool Whether the music should loop  |

## Variable Details

### _loop<a name="_loop"></a>

!!! variable "bool _loop"

    Looping state
    

### _path<a name="_path"></a>

!!! variable "std::string _path"

    Path to the sound file
    

### _volume<a name="_volume"></a>

!!! variable "float _volume"

    Volume level
    

## Function Details

### SoundInfos<a name="SoundInfos"></a>
!!! function "SoundInfos(std::string path)"

    Construct a new SoundInfos object
    
    :material-location-enter: `path`
    :    std::string Path to the sound file
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] std::string getPath() const"

    Destroy the SoundInfos object
    Get the path of the sound file
        
    :material-keyboard-return: **Return**
    :    std::string Path of the sound file
    

### getVolume<a name="getVolume"></a>
!!! function "[[nodiscard]] float getVolume() const"

    Get the volume level
        
    :material-keyboard-return: **Return**
    :    float Volume level
    

### isLooped<a name="isLooped"></a>
!!! function "[[nodiscard]] bool isLooped() const"

    Check if the music is looped
        
    :material-keyboard-return: **Return**
    :    bool True if the music is looped, false otherwise
    

### setLoop<a name="setLoop"></a>
!!! function "void setLoop(bool loop)"

    Enable or disable looping
        
    :material-location-enter: `loop`
    :    bool Whether the music should loop
    

### setVolume<a name="setVolume"></a>
!!! function "virtual void setVolume(float newVolume)"

    Set the volume level
        
    :material-location-enter: `newVolume`
    :    float New volume value
    

