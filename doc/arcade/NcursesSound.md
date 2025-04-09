---
generator: doxide
---


# NcursesSound

**class NcursesSound : public ISound**


This class is used to create a sound using the ncurses library
It inherits from the ISound interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_soundInformations](#_soundInformations) | Sound informations  |

## Functions

| Name | Description |
| ---- | ----------- |
| [NcursesSound](#NcursesSound) | Constructor :material-location-enter: `sound` :    SoundInfos & Sound to create  |
| [getInformations](#getInformations) | Get the sound informations :material-keyboard-return: **Return** :    const SoundInfos & Sound informations  |

## Variable Details

### _soundInformations<a name="_soundInformations"></a>

!!! variable "SoundInfos _soundInformations"

    Sound informations
    

## Function Details

### NcursesSound<a name="NcursesSound"></a>
!!! function "NcursesSound(const SoundInfos&amp; sound)"

    Constructor
    
    :material-location-enter: `sound`
    :    SoundInfos & Sound to create
    

### getInformations<a name="getInformations"></a>
!!! function "[[nodiscard]] const SoundInfos&amp; getInformations() const override"

    Get the sound informations
        
    :material-keyboard-return: **Return**
    :    const SoundInfos & Sound informations
    

