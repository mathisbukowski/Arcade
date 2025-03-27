/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Sfml.hpp
*/

#ifndef ARCADE_SFML_HPP
    #define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>
#include <map>
#include <variant>
#include "IDisplayLibrary.hpp"
#include "IDisplayModule.hpp"
#include "ITexture.hpp"
#include "IFont.hpp"
#include "ISound.hpp"
#include "Misc.hpp"
#include "Vector.hpp"
#include "Arcade.hpp"

namespace arcade {

class SFMLDisplay;
class SFMLTextureManager;
class SFMLFontManager;
class SFMLSoundManager;
class SFMLTexture;
class SFMLFont;
class SFMLSound;

/**
 * Implementation of ITexture for SFML
 */
class SFMLTexture : public ITexture {
public:
    explicit SFMLTexture(const MyTexture& textureInfo);
    ~SFMLTexture() override = default;

    const MyTexture& getInformations() const override;

    sf::Sprite& getSprite();
    sf::Text& getText();
    bool isText() const;

private:
    void loadFromImage(const TextureImg& textureImg);
    void loadFromText(const TextureText& textureText);
    bool loadFontForText(sf::Font& font);
    void createDefaultSprite();
    MyTexture _info;
    std::variant<sf::Sprite, sf::Text> _drawable;
    sf::Texture _texture;
};

/**
 * Implementation of IFont for SFML
 */
class SFMLFont : public IFont {
public:
    explicit SFMLFont(const Font& fontInfo);
    ~SFMLFont() override = default;

    const Font& getInformations() const override;
    sf::Font& getFont();

private:
    Font _info;
    sf::Font _font;
};

/**
 * Implementation of ISound for SFML
 */
class SFMLSound : public ISound {
public:
    explicit SFMLSound(const MySound& soundInfo);
    ~SFMLSound() override = default;

    const MySound& getInformations() const override;
    void play(float volume);
    void stop();

private:
    MySound _info;
    std::variant<sf::Sound, sf::Music> _sound;
    sf::SoundBuffer _buffer;
};

/**
 * Implementation of ITextureManager for SFML
 */
class SFMLTextureManager : public ITextureManager {
public:
    SFMLTextureManager();
    ~SFMLTextureManager() override = default;

    int load(const std::string& name, const MyTexture& newTexture) override;
    std::shared_ptr<ITexture> get(const std::string& name) const override;

private:
    mutable std::map<std::string, std::shared_ptr<SFMLTexture>> _textures;
    mutable sf::Font _defaultFont;
};

/**
 * Implementation of IFontManager for SFML
 */
class SFMLFontManager : public IFontManager {
public:
    SFMLFontManager();
    ~SFMLFontManager() override = default;

    int load(const std::string& name, const Font font) const override;
    std::shared_ptr<IFont> get(const std::string& name) const override;

private:
    mutable std::map<std::string, std::shared_ptr<SFMLFont>> _fonts;
};

/**
 * Implementation of ISoundManager for SFML
 */
class SFMLSoundManager : public ISoundManager {
public:
    SFMLSoundManager();
    ~SFMLSoundManager() override = default;

    void playSound(const std::string& name, const float volume) override;
    void stopSound(const std::string& name) override;
    int load(const std::string& name, const MySound sound) const override;
    std::shared_ptr<ISound> get(const std::string& name) const override;

private:
    mutable std::map<std::string, std::shared_ptr<SFMLSound>> _sounds;
};

/**
 * Implementation of IDisplayModule for SFML
 */
class SFMLDisplay : public IDisplayModule {
public:
    SFMLDisplay();
    ~SFMLDisplay() override;

    void init() override;
    void stop() override;
    const std::string& getName() const override;
    void setupWindowProperties(WindowProperties& properties) override;
    void openWindow() override;
    void closeWindow() override;
    void clearWindow(Color color) override;
    void updateWindow(float delta) override;
    bool isWindowOpen() override;
    void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
    Keyboard& getKeyboard() override;
    Mouse& getMouse() override;

    void processEvents();

private:
    std::string _name;
    sf::RenderWindow* _window;
    Keyboard _keyboard;
    Mouse _mouse;
    WindowProperties _properties;
};

/**
 * Implementation of IDisplayLibrary for SFML
 */
class SFMLLibrary : public IDisplayLibrary {
public:
    SFMLLibrary();
    ~SFMLLibrary() override;

    IDisplayModule& getDisplay() override;
    ITextureManager& getTextures() override;
    IFontManager& getFonts() override;
    ISoundManager& getSounds() override;

private:
    std::unique_ptr<SFMLDisplay> _display;
    std::unique_ptr<SFMLTextureManager> _textureManager;
    std::unique_ptr<SFMLFontManager> _fontManager;
    std::unique_ptr<SFMLSoundManager> _soundManager;
};

}
#endif //ARCADE_SFML_HPP
