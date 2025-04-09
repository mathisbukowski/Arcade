---
generator: doxide
---


# SFMLFontManager

**class SFMLFontManager : public IFontManager**


    This class is used to manage fonts using the SFML library
    It inherits from the IFontManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_fonts](#_fonts) | Map of fonts  |

## Functions

| Name | Description |
| ---- | ----------- |
| [load](#load) | Construct a new SFMLFontManager object Destroy the SFMLFontManager object Load a font :material-location-enter: `name` :    const std::string& Name of the font :material-location-enter: `font` :    const Font& Font information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get a font :material-location-enter: `name` :    const std::string& Name of the font :material-keyboard-return: **Return** :    std::shared_ptr<IFont>  |

## Variable Details

### _fonts<a name="_fonts"></a>

!!! variable "mutable std::map&lt;std::string, std::shared_ptr&lt;SFMLFont&gt;&gt; _fonts"

    Map of fonts
    

## Function Details

### get<a name="get"></a>
!!! function "std::shared_ptr&lt;IFont&gt; get(const std::string&amp; name) const override"

    Get a font
        
    :material-location-enter: `name`
    :    const std::string& Name of the font
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<IFont>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const Font&amp; font) override"

    Construct a new SFMLFontManager object
    Destroy the SFMLFontManager object
    Load a font
        
    :material-location-enter: `name`
    :    const std::string& Name of the font
        
    :material-location-enter: `font`
    :    const Font& Font information
        
    :material-keyboard-return: **Return**
    :    int
    

