---
generator: doxide
---


# SDLSound

**class SDLSound : public ISound**


This class is used to create a sound using the SDL2 library
It inherits from the ISound interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_soundInformations](#_soundInformations) | Sound information  |
| [_chunk](#_chunk) | SDL chunk  |
| [_channel](#_channel) | SDL channel  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLSound](#SDLSound) | Construct a new SDLSound object  |
| [~SDLSound](#_u007eSDLSound) | Destroy the SDLSound object  |
| [getInformations](#getInformations) | Get the sound information :material-keyboard-return: **Return** :    const SoundInfos &  |
| [play](#play) | Play the sound :material-location-enter: `volume` :    float Volume of the sound  |
| [stop](#stop) | Stop the sound  |
| [setSoundInfos](#setSoundInfos) | Get the sound information :material-location-enter: `infos` :    SoundInfos & Sound information  |

## Variable Details

### _channel<a name="_channel"></a>

!!! variable "int _channel"

    SDL channel
    

### _chunk<a name="_chunk"></a>

!!! variable "std::shared_ptr&lt;Mix_Chunk&gt; _chunk"

    SDL chunk
    

### _soundInformations<a name="_soundInformations"></a>

!!! variable "SoundInfos _soundInformations"

    Sound information
    

## Function Details

### SDLSound<a name="SDLSound"></a>
!!! function "SDLSound()"

    Construct a new SDLSound object
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const SoundInfos&amp; getInformations() const override"

    Get the sound information
    
    :material-keyboard-return: **Return**
    :    const SoundInfos &
    

### play<a name="play"></a>
!!! function "void play(float volume) override"

    Play the sound
    
    :material-location-enter: `volume`
    :    float Volume of the sound
    

### setSoundInfos<a name="setSoundInfos"></a>
!!! function "void setSoundInfos(const SoundInfos&amp; infos)"

    Get the sound information
        
    :material-location-enter: `infos`
    :    SoundInfos & Sound information
    

### stop<a name="stop"></a>
!!! function "void stop() override"

    Stop the sound
    

### ~SDLSound<a name="_u007eSDLSound"></a>
!!! function "~SDLSound()"

    Destroy the SDLSound object
    

