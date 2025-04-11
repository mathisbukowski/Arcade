---
generator: doxide
---


# NcursesSoundManager

**class NcursesSoundManager : public ISoundManager**


    This class is used to manage sounds using the ncurses library
    It inherits from the ISoundManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_sounds](#_sounds) | Map of sounds  |

## Functions

| Name | Description |
| ---- | ----------- |
| [load](#load) | Function to load a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-location-enter: `sound` :    SoundInfos & Sound to load :material-keyboard-return: **Return** :    int 0 if success, -1 if error  |
| [get](#get) | Function to get a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-keyboard-return: **Return** :    std::shared_ptr<ISound> Sound  |
| [playSound](#playSound) | Function to play a sound :material-location-enter: `name` :    const std::string & Name of the sound :material-location-enter: `volume` :    float Volume of the sound  |
| [stopSound](#stopSound) | Function to stop a sound :material-location-enter: `name` :    const std::string & Name of the sound  |

## Variable Details

### _sounds<a name="_sounds"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;NcursesSound&gt;&gt; _sounds"

    Map of sounds
    

## Function Details

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;ISound&gt; get(const std::string&amp; name) const override"

    Function to get a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ISound> Sound
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const SoundInfos&amp; sound) override"

    Function to load a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-location-enter: `sound`
    :    SoundInfos & Sound to load
        
    :material-keyboard-return: **Return**
    :    int 0 if success, -1 if error
    

### playSound<a name="playSound"></a>
!!! function "void playSound(const std::string&amp; name, float volume) override"

    Function to play a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
        
    :material-location-enter: `volume`
    :    float Volume of the sound
    

### stopSound<a name="stopSound"></a>
!!! function "void stopSound(const std::string&amp; name) override"

    Function to stop a sound
        
    :material-location-enter: `name`
    :    const std::string & Name of the sound
    

