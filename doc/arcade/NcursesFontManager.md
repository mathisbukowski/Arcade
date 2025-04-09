---
generator: doxide
---


# NcursesFontManager

**class NcursesFontManager : public IFontManager**


    This class is used to manage fonts using the ncurses library
    It inherits from the IFontManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_fonts](#_fonts) | Map of fonts  |

## Functions

| Name | Description |
| ---- | ----------- |
| [load](#load) | Function to load a font :material-location-enter: `name` :    const std::string & Name of the font :material-location-enter: `font` :    Font & Font to load :material-keyboard-return: **Return** :    int 0 if success, -1 if error  |
| [get](#get) | Function to get a font :material-location-enter: `name` :    const std::string & Name of the font :material-keyboard-return: **Return** :    std::shared_ptr<IFont> Font  |

## Variable Details

### _fonts<a name="_fonts"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;NcursesFont&gt;&gt; _fonts"

    Map of fonts
    

## Function Details

### get<a name="get"></a>
!!! function "std::shared_ptr&lt;IFont&gt; get(const std::string&amp; name) const override"

    Function to get a font
        
    :material-location-enter: `name`
    :    const std::string & Name of the font
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<IFont> Font
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const Font&amp; font) override"

    Function to load a font
        
    :material-location-enter: `name`
    :    const std::string & Name of the font
        
    :material-location-enter: `font`
    :    Font & Font to load
        
    :material-keyboard-return: **Return**
    :    int 0 if success, -1 if error
    

