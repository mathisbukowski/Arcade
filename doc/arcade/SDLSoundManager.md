---
generator: doxide
---


# SDLSoundManager

**class SDLSoundManager : public ISoundManager**


    This class is used to manage the sounds using the SDL2 library
    It inherits from the ISoundManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_sounds](#_sounds) | Map of sounds  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLSoundManager](#SDLSoundManager) | Construct a new SDLSoundManager object  |
| [load](#load) | Load a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-location-enter: `sound` :    const SoundInfos & Sound information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-keyboard-return: **Return** :    std::shared_ptr<ISound>  |
| [playSound](#playSound) | Play a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-location-enter: `volume` :    float Volume of the sound  |
| [stopSound](#stopSound) | Stop a sound :material-location-enter: `name` :    const std::string & Name of the sound  |

## Variable Details

### _sounds<a name="_sounds"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;SDLSound&gt;&gt; _sounds"

    Map of sounds
    

## Function Details

### SDLSoundManager<a name="SDLSoundManager"></a>
!!! function "SDLSoundManager()"

    Construct a new SDLSoundManager object
    

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;ISound&gt; get(const std::string&amp; name) const override"

    Get a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ISound>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const SoundInfos&amp; sound) override"

    Load a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-location-enter: `sound`
    :    const SoundInfos & Sound information
        
    :material-keyboard-return: **Return**
    :    int
    

### playSound<a name="playSound"></a>
!!! function "void playSound(const std::string&amp; name, float volume) override"

    Play a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-location-enter: `volume`
    :    float Volume of the sound
    

### stopSound<a name="stopSound"></a>
!!! function "void stopSound(const std::string&amp; name) override"

    Stop a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
    

