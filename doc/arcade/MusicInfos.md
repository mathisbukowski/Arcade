---
generator: doxide
---


# MusicInfos

**class MusicInfos final : public SoundInfos**

Music properties


## Functions

| Name | Description |
| ---- | ----------- |
| [MusicInfos](#MusicInfos) | Construct a new MusicInfos object :material-location-enter: `path` :    Path to the music file  |
| [isLooped](#isLooped) | Check if the music is looped :material-keyboard-return: **Return** :    bool  |
| [setLoop](#setLoop) | Enable or disable looping :material-location-enter: `loop` :    Whether the music should loop  |

## Function Details

### MusicInfos<a name="MusicInfos"></a>
!!! function "MusicInfos(std::string path)"

    Construct a new MusicInfos object
        
    :material-location-enter: `path`
    :    Path to the music file
    

### isLooped<a name="isLooped"></a>
!!! function "[[nodiscard]] bool isLooped() const"

    Check if the music is looped
        
    :material-keyboard-return: **Return**
    :    bool
    

### setLoop<a name="setLoop"></a>
!!! function "void setLoop(bool loop)"

    Enable or disable looping
        
    :material-location-enter: `loop`
    :    Whether the music should loop
    

