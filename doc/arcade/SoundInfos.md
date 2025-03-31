---
generator: doxide
---


# SoundInfos

**class SoundInfos**

Sound properties


## Functions

| Name | Description |
| ---- | ----------- |
| [SoundInfos](#SoundInfos) | Construct a new SoundInfos object :material-location-enter: `path` :    Path to the sound file  |
| [getPath](#getPath) | Get the path of the sound file :material-keyboard-return: **Return** :    std::string  |
| [getVolume](#getVolume) | Get the volume level :material-keyboard-return: **Return** :    float  |
| [isPlaying](#isPlaying) | Check if the sound is currently playing :material-keyboard-return: **Return** :    bool  |
| [setVolume](#setVolume) | Set the volume level :material-location-enter: `newVolume` :    New volume value  |
| [play](#play) | Play the sound  |

## Function Details

### SoundInfos<a name="SoundInfos"></a>
!!! function "SoundInfos(std::string path)"

    Construct a new SoundInfos object
    
    :material-location-enter: `path`
    :    Path to the sound file
    

### getPath<a name="getPath"></a>
!!! function "[[nodiscard]] std::string getPath()"

    Get the path of the sound file
        
    :material-keyboard-return: **Return**
    :    std::string
    

### getVolume<a name="getVolume"></a>
!!! function "[[nodiscard]] float getVolume() const"

    Get the volume level
        
    :material-keyboard-return: **Return**
    :    float
    

### isPlaying<a name="isPlaying"></a>
!!! function "[[nodiscard]] bool isPlaying() const"

    Check if the sound is currently playing
        
    :material-keyboard-return: **Return**
    :    bool
    

### play<a name="play"></a>
!!! function "virtual void play()"

    Play the sound
    

### setVolume<a name="setVolume"></a>
!!! function "virtual void setVolume(float newVolume)"

    Set the volume level
        
    :material-location-enter: `newVolume`
    :    New volume value
    

