---
generator: doxide
---


# SFMLSound

**class SFMLSound : public ISound**

 of ISound for SFML
This class is used to create a sound using the SFML library
It inherits from the ISound interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_info](#_info) | Sound information  |
| [_sound](#_sound) | Sound or music object  |
| [_buffer](#_buffer) | Sound buffer  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLSound](#SFMLSound) | Construct a new SFMLSound object :material-location-enter: `soundInfo` :    const SoundInfos& Sound information  |
| [getInformations](#getInformations) | Destroy the SFMLSound object Load sound from file :material-location-enter: `soundInfos` :    const SoundInfos& Sound information  |
| [play](#play) | play sound :material-keyboard-return: **Return** :    sf::SoundBuffer&  |
| [stop](#stop) | stop sound  |
| [loadSound](#loadSound) | Load sound from file :material-location-enter: `soundInfos` :    const SoundInfos& Sound information  |
| [loadMusic](#loadMusic) | Load music from file :material-location-enter: `musicInfos` :    const SoundInfos& Music information  |

## Variable Details

### _buffer<a name="_buffer"></a>

!!! variable "sf::SoundBuffer _buffer"

    Sound buffer
    

### _info<a name="_info"></a>

!!! variable "SoundInfos _info"

    Sound information
    

### _sound<a name="_sound"></a>

!!! variable "std::variant&lt;sf::Sound, std::unique_ptr&lt;sf::Music&gt;&gt; _sound"

    Sound or music object
    

## Function Details

### SFMLSound<a name="SFMLSound"></a>
!!! function "SFMLSound(const SoundInfos&amp; soundInfo)"

    Construct a new SFMLSound object
    
    :material-location-enter: `soundInfo`
    :    const SoundInfos& Sound information
    

### getInformations<a name="getInformations"></a>
!!! function "const SoundInfos&amp; getInformations() const override"

    Destroy the SFMLSound object
    Load sound from file
        
    :material-location-enter: `soundInfos`
    :    const SoundInfos& Sound information
    

### loadMusic<a name="loadMusic"></a>
!!! function "void loadMusic(const SoundInfos&amp; musicInfos)"

    Load music from file
        
    :material-location-enter: `musicInfos`
    :    const SoundInfos& Music information
    

### loadSound<a name="loadSound"></a>
!!! function "void loadSound(const SoundInfos&amp; soundInfos)"

    Load sound from file
        
    :material-location-enter: `soundInfos`
    :    const SoundInfos& Sound information
    

### play<a name="play"></a>
!!! function "void play(float volume)"

    play sound
        
    :material-keyboard-return: **Return**
    :    sf::SoundBuffer&
    

### stop<a name="stop"></a>
!!! function "void stop()"

    stop sound
    

