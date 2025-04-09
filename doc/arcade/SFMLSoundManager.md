---
generator: doxide
---


# SFMLSoundManager

**class SFMLSoundManager : public ISoundManager**


    This class is used to manage sounds using the SFML library
    It inherits from the ISoundManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_sounds](#_sounds) | Map of sounds  |

## Functions

| Name | Description |
| ---- | ----------- |
| [playSound](#playSound) | Construct a new SFMLSoundManager object Destroy the SFMLSoundManager object Play sound :material-location-enter: `name` :    const std::string& Name of the sound :material-location-enter: `volume` :    float Volume of the sound  |
| [stopSound](#stopSound) | Stop sound :material-location-enter: `name` :    const std::string& Name of the sound  |
| [load](#load) | Load sound :material-location-enter: `name` :    const std::string& Name of the sound :material-location-enter: `sound` :    const SoundInfos& Sound information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get sound :material-location-enter: `name` :    const std::string& Name of the sound :material-keyboard-return: **Return** :    std::shared_ptr<ISound>  |

## Variable Details

### _sounds<a name="_sounds"></a>

!!! variable "mutable std::map&lt;std::string, std::shared_ptr&lt;SFMLSound&gt;&gt; _sounds"

    Map of sounds
    

## Function Details

### get<a name="get"></a>
!!! function "std::shared_ptr&lt;ISound&gt; get(const std::string&amp; name) const override"

    Get sound
        
    :material-location-enter: `name`
    :    const std::string& Name of the sound
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ISound>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const SoundInfos&amp; sound) override"

    Load sound
        
    :material-location-enter: `name`
    :    const std::string& Name of the sound
        
    :material-location-enter: `sound`
    :    const SoundInfos& Sound information
        
    :material-keyboard-return: **Return**
    :    int
    

### playSound<a name="playSound"></a>
!!! function "void playSound(const std::string&amp; name, const float volume) override"

    Construct a new SFMLSoundManager object
    Destroy the SFMLSoundManager object
    Play sound
        
    :material-location-enter: `name`
    :    const std::string& Name of the sound
        
    :material-location-enter: `volume`
    :    float Volume of the sound
    

### stopSound<a name="stopSound"></a>
!!! function "void stopSound(const std::string&amp; name) override"

    Stop sound
        
    :material-location-enter: `name`
    :    const std::string& Name of the sound
    

