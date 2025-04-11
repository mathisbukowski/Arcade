---
generator: doxide
---


# NcursesTextureManager

**class NcursesTextureManager : public ITextureManager**


    This class is used to manage textures using the ncurses library
    It inherits from the ITextureManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_textures](#_textures) | Map of textures  |

## Functions

| Name | Description |
| ---- | ----------- |
| [load](#load) | Function to load a texture :material-location-enter: `name` :    const std::string & Name of the texture :material-location-enter: `newTexture` :    MyTexture & Texture to load :material-keyboard-return: **Return** :    int 0 if success, -1 if error  |
| [get](#get) | Function to get a texture :material-location-enter: `name` :    const std::string & Name of the texture :material-keyboard-return: **Return** :    std::shared_ptr<ITexture> Texture  |

## Variable Details

### _textures<a name="_textures"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;NcursesTexture&gt;&gt; _textures"

    Map of textures
    

## Function Details

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;ITexture&gt; get(const std::string&amp; name) const override"

    Function to get a texture
        
    :material-location-enter: `name`
    :    const std::string & Name of the texture
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ITexture> Texture
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const MyTexture&amp; newTexture) override"

    Function to load a texture
        
    :material-location-enter: `name`
    :    const std::string & Name of the texture
        
    :material-location-enter: `newTexture`
    :    MyTexture & Texture to load
        
    :material-keyboard-return: **Return**
    :    int 0 if success, -1 if error
    

