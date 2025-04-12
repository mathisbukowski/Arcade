---
generator: doxide
---


# SFMLTextureManager

**class SFMLTextureManager : public ITextureManager**


    This class is used to manage textures using the SFML library
    It inherits from the ITextureManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_textures](#_textures) | Map of textures  |

## Functions

| Name | Description |
| ---- | ----------- |
| [load](#load) | Construct a new SFMLTextureManager object Destroy the SFMLTextureManager object Load a texture :material-location-enter: `name` :    const std::string& Name of the texture :material-location-enter: `newTexture` :    const MyTexture& Texture information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get a texture :material-location-enter: `name` :    const std::string& Name of the texture :material-keyboard-return: **Return** :    std::shared_ptr<ITexture>  |

## Variable Details

### _textures<a name="_textures"></a>

!!! variable "mutable std::map&lt;std::string, std::shared_ptr&lt;SFMLTexture&gt;&gt; _textures"

    Map of textures
    

## Function Details

### get<a name="get"></a>
!!! function "std::shared_ptr&lt;ITexture&gt; get(const std::string&amp; name) const override"

    Get a texture
        
    :material-location-enter: `name`
    :    const std::string& Name of the texture
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ITexture>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const MyTexture&amp; newTexture) override"

    Construct a new SFMLTextureManager object
    Destroy the SFMLTextureManager object
    Load a texture
        
    :material-location-enter: `name`
    :    const std::string& Name of the texture
        
    :material-location-enter: `newTexture`
    :    const MyTexture& Texture information
        
    :material-keyboard-return: **Return**
    :    int
    

