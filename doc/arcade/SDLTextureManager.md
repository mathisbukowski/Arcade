---
generator: doxide
---


# SDLTextureManager

**class SDLTextureManager : public ITextureManager**


    This class is used to create a texture manager using the SDL2 library
    It inherits from the ITextureManager interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_renderer](#_renderer) | SDL Renderer Manager  |
| [_textures](#_textures) | Map of textures  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLTextureManager](#SDLTextureManager) | Construct a new SDLTextureManager object :material-location-enter: `renderer_manager` :    SDLRendererManager&  |
| [load](#load) | Destroy the SDLTextureManager object Load a new texture :material-location-enter: `name` :    const std::string & Name of the texture :material-location-enter: `newTexture` :    MyTexture & Texture information :material-keyboard-return: **Return** :    int  |
| [get](#get) | Get a texture :material-location-enter: `name` :    const std::string & Name of the texture :material-keyboard-return: **Return** :    std::shared_ptr<ITexture>  |

## Variable Details

### _renderer<a name="_renderer"></a>

!!! variable "SDLRendererManager&amp; _renderer"

    SDL Renderer Manager
    

### _textures<a name="_textures"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;SDLTexture&gt;&gt; _textures"

    Map of textures
    

## Function Details

### SDLTextureManager<a name="SDLTextureManager"></a>
!!! function "SDLTextureManager(SDLRendererManager&amp; renderer_manager)"

    Construct a new SDLTextureManager object
        
    :material-location-enter: `renderer_manager`
    :    SDLRendererManager&
    

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;ITexture&gt; get(const std::string&amp; name) const override"

    Get a texture
        
    :material-location-enter: `name`
    :    const std::string & Name of the texture
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ITexture>
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const MyTexture&amp; newTexture) override"

    Destroy the SDLTextureManager object
    Load a new texture
        
    :material-location-enter: `name`
    :    const std::string & Name of the texture
        
    :material-location-enter: `newTexture`
    :    MyTexture & Texture information
        
    :material-keyboard-return: **Return**
    :    int
    

