---
generator: doxide
---


# SDLTextureManager

**class SDLTextureManager : public ITextureManager**


    Manager for SDL textures in Arcade


## Variables

| Name | Description |
| ---- | ----------- |
| [_renderer](#_renderer) | SDL renderer manager reference  |
| [_textures](#_textures) | Map of loaded textures  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SDLTextureManager](#SDLTextureManager) | Construct a new SDLTextureManager :material-location-enter: `renderer_manager` :    SDLRendererManager & Reference to SDL renderer manager  |
| [load](#load) | Destroy the SDLTextureManager Load a texture with given name and data :material-location-enter: `name` :    const std::string & Name to identify the texture :material-location-enter: `newTexture` :    const MyTexture & Texture information to load :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |
| [get](#get) | Get a texture by name :material-location-enter: `name` :    const std::string & Name of the texture to retrieve :material-keyboard-return: **Return** :    std::shared_ptr<ITexture> Shared pointer to the texture, or nullptr if not found  |
| [createTexture](#createTexture) | Create a new texture :material-location-enter: `name` :    const std::string & Name to identify the texture :material-location-enter: `newTexture` :    MyTexture & Texture information to load :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |
| [updateTexture](#updateTexture) | Update an existing texture :material-location-enter: `existingTexture` :    std::shared_ptr<SDLTexture  Existing texture to update :material-location-enter: `newTexture` :    const MyTexture & New texture information :material-keyboard-return: **Return** :    int 0 on success, -1 on failure  |

## Variable Details

### _renderer<a name="_renderer"></a>

!!! variable "SDLRendererManager&amp; _renderer"

    SDL renderer manager reference
    

### _textures<a name="_textures"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;SDLTexture&gt;&gt; _textures"

    Map of loaded textures
    

## Function Details

### SDLTextureManager<a name="SDLTextureManager"></a>
!!! function "explicit SDLTextureManager(SDLRendererManager&amp; renderer_manager)"

    Construct a new SDLTextureManager
        
    :material-location-enter: `renderer_manager`
    :    SDLRendererManager & Reference to SDL renderer manager
    

### createTexture<a name="createTexture"></a>
!!! function "int createTexture(const std::string&amp; name, const MyTexture&amp; newTexture)"

    Create a new texture
        
    :material-location-enter: `name`
    :    const std::string & Name to identify the texture
        
    :material-location-enter: `newTexture`
    :    MyTexture & Texture information to load
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

### get<a name="get"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;ITexture&gt; get(const std::string&amp; name) const override"

    Get a texture by name
        
    :material-location-enter: `name`
    :    const std::string & Name of the texture to retrieve
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<ITexture> Shared pointer to the texture, or nullptr if not found
    

### load<a name="load"></a>
!!! function "int load(const std::string&amp; name, const MyTexture&amp; newTexture) override"

    Destroy the SDLTextureManager
     Load a texture with given name and data
        
    :material-location-enter: `name`
    :    const std::string & Name to identify the texture
        
    :material-location-enter: `newTexture`
    :    const MyTexture & Texture information to load
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

### updateTexture<a name="updateTexture"></a>
!!! function "int updateTexture(std::shared_ptr&lt;SDLTexture&gt; existingTexture, const MyTexture&amp; newTexture)"

    Update an existing texture
        
    :material-location-enter: `existingTexture`
    :    std::shared_ptr<SDLTexture  Existing texture to update
        
    :material-location-enter: `newTexture`
    :    const MyTexture & New texture information
        
    :material-keyboard-return: **Return**
    :    int 0 on success, -1 on failure
    

