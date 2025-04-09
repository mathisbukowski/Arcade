---
generator: doxide
---


# SDLFontManager

**class SDLFontManager : public IFontManager**


    This class is used to create a font manager using the SDL2 library
    It inherits from the IFontManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_fonts](#_fonts) | Map of fonts  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLFontManager](#SDLFontManager) | Construct a new SDLFontManager object  |
| [load](#load) | Destroy the SDLFontManager object Load a font :material-location-enter: `name` :    const std::string & Name of the font :material-location-enter: `newFont` :    Font & Font information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get a font :material-location-enter: `name` :    const std::string & Name of the font :material-keyboard-return: **Return** :    std::shared_ptr<IFont>  |

## Variable Details

### _fonts<a name="_fonts"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;IFont&gt;&gt; _fonts"

    Map of fonts
    

## Function Details

### SDLFontManager<a name="SDLFontManager"></a>
!!! function "SDLFontManager()"

    Construct a new SDLFontManager object
    

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;IFont&gt; get(const std::string&amp; name) const override"

    Get a font
        
    :material-location-enter: `name`
    :    const std::string & Name of the font
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<IFont>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const Font&amp; newFont) override"

    Destroy the SDLFontManager object
    Load a font
        
    :material-location-enter: `name`
    :    const std::string & Name of the font
        
    :material-location-enter: `newFont`
    :    Font & Font information
        
    :material-keyboard-return: **Return**
    :    int
    

