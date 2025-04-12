---
generator: doxide
---


# SFMLTexture

**class SFMLTexture : public ITexture**


This class is used to create a texture using the SFML library
It inherits from the ITexture interface


## Variables

| Name | Description |
| ---- | ----------- |
| [_info](#_info) | Texture information  |
| [_drawable](#_drawable) | SFML drawable object (sprite or text)  |
| [_texture](#_texture) | SFML texture object  |
| [_font](#_font) | SFML font object  |

## Functions

| Name | Description |
| ---- | ----------- |
| [SFMLTexture](#SFMLTexture) | Construct a new SFMLTexture object :material-location-enter: `textureInfo` :    const MyTexture& Texture information  |
| [getInformations](#getInformations) | Destroy the SFMLTexture object get the texture information :material-keyboard-return: **Return** :    const MyTexture&  |
| [set](#set) | set the texture information :material-location-enter: `newTexture` :    MyTexture& New texture information  |
| [getSprite](#getSprite) | get the SFML sprite :material-keyboard-return: **Return** :    sf::Sprite&  |
| [getText](#getText) | get the SFML text :material-keyboard-return: **Return** :    sf::Text&  |
| [isText](#isText) | check if the texture is a text :material-keyboard-return: **Return** :    bool  |
| [loadFromImage](#loadFromImage) | Load texture from image :material-location-enter: `textureImg` :    const TextureImg& Texture image information  |
| [loadFromText](#loadFromText) | Load texture from text :material-location-enter: `textureText` :    const TextureText& Texture text information  |
| [createErrorTexture](#createErrorTexture) | Create an error texture  |

## Variable Details

### _drawable<a name="_drawable"></a>

!!! variable "std::variant&lt;sf::Sprite, sf::Text&gt; _drawable"

    SFML drawable object (sprite or text)
    

### _font<a name="_font"></a>

!!! variable "std::shared_ptr&lt;sf::Font&gt; _font"

    SFML font object
    

### _info<a name="_info"></a>

!!! variable "MyTexture _info"

    Texture information
    

### _texture<a name="_texture"></a>

!!! variable "sf::Texture _texture"

    SFML texture object
    

## Function Details

### SFMLTexture<a name="SFMLTexture"></a>
!!! function "explicit SFMLTexture(const MyTexture&amp; textureInfo)"

    Construct a new SFMLTexture object
    
    :material-location-enter: `textureInfo`
    :    const MyTexture& Texture information
    

### createErrorTexture<a name="createErrorTexture"></a>
!!! function "void createErrorTexture()"

    Create an error texture
    

### getInformations<a name="getInformations"></a>
!!! function "const MyTexture&amp; getInformations() const override"

    Destroy the SFMLTexture object
    get the texture information
        
    :material-keyboard-return: **Return**
    :    const MyTexture&
    

### getSprite<a name="getSprite"></a>
!!! function "sf::Sprite&amp; getSprite()"

    get the SFML sprite
        
    :material-keyboard-return: **Return**
    :    sf::Sprite&
    

### getText<a name="getText"></a>
!!! function "sf::Text&amp; getText()"

    get the SFML text
        
    :material-keyboard-return: **Return**
    :    sf::Text&
    

### isText<a name="isText"></a>
!!! function "bool isText() const"

    check if the texture is a text
        
    :material-keyboard-return: **Return**
    :    bool
    

### loadFromImage<a name="loadFromImage"></a>
!!! function "void loadFromImage(const TextureImg&amp; textureImg)"

    Load texture from image
        
    :material-location-enter: `textureImg`
    :    const TextureImg& Texture image information
    

### loadFromText<a name="loadFromText"></a>
!!! function "void loadFromText(const TextureText&amp; textureText)"

    Load texture from text
        
    :material-location-enter: `textureText`
    :    const TextureText& Texture text information
    

### set<a name="set"></a>
!!! function "void set(MyTexture&amp; newTexture) override"

    set the texture information
        
    :material-location-enter: `newTexture`
    :    MyTexture& New texture information
    

