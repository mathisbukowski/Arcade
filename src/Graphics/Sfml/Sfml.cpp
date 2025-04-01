/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SFML implementation for arcade
*/

#include "Sfml.hpp"
#include "ISound.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>
#include <filesystem>

namespace arcade {

SFMLTexture::SFMLTexture(MyTexture& textureInfo) : _info(textureInfo),
                                                         _font(std::make_shared<sf::Font>()),
    ITexture(textureInfo)
{
    try {
        if (std::holds_alternative<TextureImg>(textureInfo)) {
            loadFromImage(std::get<TextureImg>(textureInfo));
        } else {
            loadFromText(std::get<TextureText>(textureInfo));
        }
    } catch (const std::exception& e) {
        std::cerr << "Error creating texture: " << e.what() << std::endl;
        createErrorTexture();
    }
}

void SFMLTexture::loadFromImage(const TextureImg& textureImg)
{
    if (!std::filesystem::exists(textureImg.getPath())) {
        throw std::runtime_error("Texture file not found");
    }
    if (!_texture.loadFromFile(textureImg.getPath())) {
        throw std::runtime_error("Failed to load texture");
    }
    sf::Sprite sprite;
    sprite.setTexture(_texture);
    _drawable = sprite;
    auto& mutableImg = const_cast<TextureImg&>(std::get<TextureImg>(_info));
    mutableImg.setWidth(_texture.getSize().x);
    mutableImg.setHeight(_texture.getSize().y);
}

void SFMLTexture::loadFromText(const TextureText& textureText)
{
    if (!std::filesystem::exists("assets/fonts/PixelFont.ttf")) {
        throw std::runtime_error("Font file not found");
    }

    if (!_font->loadFromFile("assets/fonts/PixelFont.ttf")) {
        throw std::runtime_error("Failed to load required font");
    }

    sf::Text text;
    text.setFont(*_font);
    text.setString(textureText.getText());
    text.setFillColor(sf::Color(
        textureText.getColor().getR(),
        textureText.getColor().getG(),
        textureText.getColor().getB(),
        textureText.getColor().getOpacity()
    ));

    if (textureText.getRect().has_value()) {
        auto rect = textureText.getRect().value();
        text.setPosition(rect.getPosition().getX(), rect.getPosition().getY());
    }

    _drawable = text;
    auto& mutableText = const_cast<TextureText&>(std::get<TextureText>(_info));
    mutableText.setWidth(text.getLocalBounds().width);
    mutableText.setHeight(text.getLocalBounds().height);
}

void SFMLTexture::createErrorTexture()
{
    sf::Sprite sprite;
    _texture.create(32, 32);

    std::vector<sf::Uint8> pixels(32 * 32 * 4, 0);

    for (int y = 0; y < 32; y++) {
        for (int x = 0; x < 32; x++) {
            int index = (y * 32 + x) * 4;
            pixels[index] = 0;
            pixels[index+1] = 0;
            pixels[index+2] = 0;
            pixels[index+3] = 0;
            if (x == y || x == (31 - y)) {
                pixels[index] = 255;
                pixels[index+1] = 0;
                pixels[index+2] = 0;
                pixels[index+3] = 255;
            }
        }
    }

    _texture.update(pixels.data());
    sprite.setTexture(_texture);
    _drawable = sprite;

    if (std::holds_alternative<TextureImg>(_info)) {
        auto& mutableImg = const_cast<TextureImg&>(std::get<TextureImg>(_info));
        mutableImg.setWidth(32);
        mutableImg.setHeight(32);
    } else {
        auto& mutableText = const_cast<TextureText&>(std::get<TextureText>(_info));
        mutableText.setWidth(32);
        mutableText.setHeight(32);
    }
}

const MyTexture& SFMLTexture::getInformations() const
{
    return _info;
}

sf::Sprite& SFMLTexture::getSprite()
{
    if (!std::holds_alternative<sf::Sprite>(_drawable))
        throw std::runtime_error("Texture is not a sprite");
    return std::get<sf::Sprite>(_drawable);
}

sf::Text& SFMLTexture::getText()
{
    if (!std::holds_alternative<sf::Text>(_drawable))
        throw std::runtime_error("Texture is not a text");
    return std::get<sf::Text>(_drawable);
}

bool SFMLTexture::isText() const
{
    return std::holds_alternative<sf::Text>(_drawable);
}

SFMLFont::SFMLFont(const Font& fontInfo) : _info(fontInfo)
{
    try {
        if (!std::filesystem::exists(fontInfo.getPath())) {
            throw std::runtime_error("Font file not found");
        }

        if (!_font.loadFromFile(fontInfo.getPath())) {
            throw std::runtime_error("Failed to load font");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error creating font: " << e.what() << std::endl;
    }
}

const Font& SFMLFont::getInformations() const
{
    return _info;
}

sf::Font& SFMLFont::getFont()
{
    return _font;
}

SFMLSound::SFMLSound(const SoundInfos &soundInfo) : _info(soundInfo)
{
    loadSound(soundInfo);
}

void SFMLSound::loadSound(const SoundInfos& soundInfos)
{
    if (!std::filesystem::exists(soundInfos.getPath())) {
        throw std::runtime_error("Sound file not found");
    }

    if (!_buffer.loadFromFile(soundInfos.getPath())) {
        throw std::runtime_error("Failed to load sound");
    }

    sf::Sound sound;
    sound.setBuffer(_buffer);
    sound.setVolume(soundInfos.getVolume());
    _sound = sound;
}

void SFMLSound::loadMusic(const SoundInfos& musicInfos)
{
    if (!std::filesystem::exists(musicInfos.getPath())) {
        throw std::runtime_error("Music file not found");
    }

    auto music = std::make_unique<sf::Music>();
    if (!music->openFromFile(musicInfos.getPath())) {
        throw std::runtime_error("Failed to load music");
    }

    music->setVolume(musicInfos.getVolume());
    music->setLoop(musicInfos.isLooped());
    _sound = std::move(music);
}

const SoundInfos& SFMLSound::getInformations() const
{
    return _info;
}

void SFMLSound::play(float volume)
{
    try {
        if (std::holds_alternative<sf::Sound>(_sound)) {
            auto& sound = std::get<sf::Sound>(_sound);
            sound.setVolume(volume);
            sound.play();
        } else if (std::holds_alternative<std::unique_ptr<sf::Music>>(_sound)) {
            auto& music = std::get<std::unique_ptr<sf::Music>>(_sound);
            if (music) {
                music->setVolume(volume);
                music->play();
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error playing sound: " << e.what() << std::endl;
    }
}

void SFMLSound::stop()
{
    try {
        if (std::holds_alternative<sf::Sound>(_sound)) {
            std::get<sf::Sound>(_sound).stop();
        } else if (std::holds_alternative<std::unique_ptr<sf::Music>>(_sound)) {
            auto& music = std::get<std::unique_ptr<sf::Music>>(_sound);
            if (music) {
                music->stop();
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error stopping sound: " << e.what() << std::endl;
    }
}

int SFMLTextureManager::load(const std::string& name, MyTexture& newTexture)
{
    try {
        _textures[name] = std::make_shared<SFMLTexture>(newTexture);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load texture: " << e.what() << std::endl;
        return -1;
    }
}

std::shared_ptr<ITexture> SFMLTextureManager::get(const std::string& name) const
{
    auto it = _textures.find(name);

    if (it != _textures.end())
        return it->second;
    throw std::runtime_error("Texture not found: " + name);
}

int SFMLFontManager::load(const std::string& name, const Font& font)
{
    try {
        _fonts[name] = std::make_shared<SFMLFont>(font);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load font: " << e.what() << std::endl;
        return -1;
    }
}

std::shared_ptr<IFont> SFMLFontManager::get(const std::string& name) const
{
    auto it = _fonts.find(name);

    if (it != _fonts.end())
        return it->second;
    throw std::runtime_error("Font not found: " + name);
}

void SFMLSoundManager::playSound(const std::string& name, const float volume)
{
    try {
        auto sound = std::dynamic_pointer_cast<SFMLSound>(get(name));
        if (sound) {
            sound->play(volume);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error playing sound '" << name << "': " << e.what() << std::endl;
    }
}

void SFMLSoundManager::stopSound(const std::string& name)
{
    try {
        auto sound = std::dynamic_pointer_cast<SFMLSound>(get(name));
        if (sound)
            sound->stop();
    } catch (const std::exception& e) {
        std::cerr << "Error stopping sound '" << name << "': " << e.what() << std::endl;
    }
}

int SFMLSoundManager::load(const std::string& name, const SoundInfos& sound)
{
    try {
        _sounds[name] = std::make_shared<SFMLSound>(sound);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load sound: " << e.what() << std::endl;
        return -1;
    }
}

std::shared_ptr<ISound> SFMLSoundManager::get(const std::string& name) const
{
    auto it = _sounds.find(name);

    if (it != _sounds.end())
        return it->second;
    throw std::runtime_error("Sound not found: " + name);
}

SFMLDisplay::SFMLDisplay() : _name("SFML"), _window(nullptr), _properties(WindowProperties("", 0, 0))
{}

SFMLDisplay::~SFMLDisplay()
{
    try {
        if (_window != nullptr) {
            _window->close();
            delete _window;
            _window = nullptr;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in SFMLDisplay destructor: " << e.what() << std::endl;
    }
}

void SFMLDisplay::init(const std::string& title, size_t width, size_t height)
{
    try {
        if (_window != nullptr) {
            _window->close();
            delete _window;
            _window = nullptr;
        }
        _window = new sf::RenderWindow(
            sf::VideoMode(width, width),
            title,
            sf::Style::Titlebar | sf::Style::Close
        );
        if (!_window)
            throw std::runtime_error("Failed to create SFML window");
        _window->setFramerateLimit(60);
    } catch (const std::exception& e) {
        std::cerr << "Error in SFMLDisplay::init(): " << e.what() << std::endl;
        throw;
    }
}

void SFMLDisplay::stop()
{
    try {
        if (_window != nullptr) {
            _window->close();
            delete _window;
            _window = nullptr;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in SFMLDisplay::stop(): " << e.what() << std::endl;
    }
}

const std::string& SFMLDisplay::getName() const
{
    return _name;
}

void SFMLDisplay::setupWindowProperties(WindowProperties& properties)
{
    _properties = properties;
    if (_window != nullptr) {
        _window->setSize(sf::Vector2u(_properties.getWidth(), _properties.getHeight()));
        _window->setTitle(_properties.getTitle());
    }
}

void SFMLDisplay::openWindow()
{
    try {
        if (_window == nullptr) {
            init(_properties.getTitle(), _properties.getWidth(), _properties.getHeight());
        } else if (!_window->isOpen()) {
            _window->create(
                sf::VideoMode(_properties.getWidth(), _properties.getHeight()),
                _properties.getTitle(),
                sf::Style::Titlebar | sf::Style::Close
            );
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in openWindow: " << e.what() << std::endl;
        throw;
    }
}

void SFMLDisplay::closeWindow()
{
    if (_window != nullptr)
        _window->close();
}

void SFMLDisplay::clearWindow(Color color)
{
    if (_window != nullptr && _window->isOpen())
        _window->clear(sf::Color(color.getR(), color.getG(), color.getB(), color.getOpacity()));
}

void SFMLDisplay::updateWindow(float delta)
{
    (void)delta;

    try {
        if (_window != nullptr && _window->isOpen()) {
            processEvents();
            _window->display();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in updateWindow: " << e.what() << std::endl;
    }
}

bool SFMLDisplay::isWindowOpen()
{
    return _window != nullptr && _window->isOpen();
}

void SFMLDisplay::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    if (_window == nullptr || !_window->isOpen()) return;

    try {
        auto sfmlTexture = std::dynamic_pointer_cast<SFMLTexture>(texture);
        if (!sfmlTexture) {
            std::cerr << "Invalid texture type" << std::endl;
            return;
        }
        if (sfmlTexture->isText()) {
            sf::Text& text = sfmlTexture->getText();
            text.setPosition(position.getX(), position.getY());
            _window->draw(text);
        } else {
            sf::Sprite& sprite = sfmlTexture->getSprite();
            sprite.setPosition(position.getX(), position.getY());
            _window->draw(sprite);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in drawTexture: " << e.what() << std::endl;
    }
}

Keyboard& SFMLDisplay::getKeyboard()
{
    return _keyboard;
}

Mouse& SFMLDisplay::getMouse()
{
    return _mouse;
}

void SFMLDisplay::processEvents()
{
    if (_window == nullptr || !_window->isOpen()) return;

    try {
        sf::Event event;
        while (_window->pollEvent(event))
            handleEvent(event);
    } catch (const std::exception& e) {
        std::cerr << "Error in processEvents: " << e.what() << std::endl;
    }
}

void SFMLDisplay::handleEvent(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::Closed:
            _window->close();
            break;
        case sf::Event::KeyPressed:
            handleKeyEvent(event.key, true);
            break;
        case sf::Event::KeyReleased:
            handleKeyEvent(event.key, false);
            break;
        case sf::Event::MouseButtonPressed:
            _mouse.setPressed(true);
            _mouse.setPos(Vector<float>(event.mouseButton.x, event.mouseButton.y));
            break;
        case sf::Event::MouseButtonReleased:
            _mouse.setPressed(false);
            _mouse.setPos(Vector<float>(event.mouseButton.x, event.mouseButton.y));
            break;
        case sf::Event::MouseMoved:
            _mouse.setPos(Vector<float>(event.mouseMove.x, event.mouseMove.y));
            break;
        default:
            break;
    }
}

void SFMLDisplay::handleKeyEvent(const sf::Event::KeyEvent& keyEvent, bool isPressed)
{
    Keyboard::KeyCode code = mapSfmlKeyToArcade(keyEvent.code);

    _keyboard.setKey(code, isPressed);
}

Keyboard::KeyCode SFMLDisplay::mapSfmlKeyToArcade(sf::Keyboard::Key sfmlKey)
{
    static const std::unordered_map<sf::Keyboard::Key, Keyboard::KeyCode> keyMap = {
        {sf::Keyboard::A, Keyboard::KeyCode::A},
        {sf::Keyboard::B, Keyboard::KeyCode::B},
        {sf::Keyboard::C, Keyboard::KeyCode::C},
        {sf::Keyboard::D, Keyboard::KeyCode::D},
        {sf::Keyboard::E, Keyboard::KeyCode::E},
        {sf::Keyboard::F, Keyboard::KeyCode::F},
        {sf::Keyboard::G, Keyboard::KeyCode::G},
        {sf::Keyboard::H, Keyboard::KeyCode::H},
        {sf::Keyboard::I, Keyboard::KeyCode::I},
        {sf::Keyboard::J, Keyboard::KeyCode::J},
        {sf::Keyboard::K, Keyboard::KeyCode::K},
        {sf::Keyboard::L, Keyboard::KeyCode::L},
        {sf::Keyboard::M, Keyboard::KeyCode::M},
        {sf::Keyboard::N, Keyboard::KeyCode::N},
        {sf::Keyboard::O, Keyboard::KeyCode::O},
        {sf::Keyboard::P, Keyboard::KeyCode::P},
        {sf::Keyboard::Q, Keyboard::KeyCode::Q},
        {sf::Keyboard::R, Keyboard::KeyCode::R},
        {sf::Keyboard::S, Keyboard::KeyCode::S},
        {sf::Keyboard::T, Keyboard::KeyCode::T},
        {sf::Keyboard::U, Keyboard::KeyCode::U},
        {sf::Keyboard::V, Keyboard::KeyCode::V},
        {sf::Keyboard::W, Keyboard::KeyCode::W},
        {sf::Keyboard::X, Keyboard::KeyCode::X},
        {sf::Keyboard::Y, Keyboard::KeyCode::Y},
        {sf::Keyboard::Z, Keyboard::KeyCode::Z},
        {sf::Keyboard::Return, Keyboard::KeyCode::ENTER},
        {sf::Keyboard::Num1, Keyboard::KeyCode::KEY_1},
        {sf::Keyboard::Num2, Keyboard::KeyCode::KEY_2},
        {sf::Keyboard::Num3, Keyboard::KeyCode::KEY_3},
        {sf::Keyboard::Num4, Keyboard::KeyCode::KEY_4},
        {sf::Keyboard::Num5, Keyboard::KeyCode::KEY_5},
        {sf::Keyboard::Num6, Keyboard::KeyCode::KEY_6},
        {sf::Keyboard::Num7, Keyboard::KeyCode::KEY_7},
        {sf::Keyboard::Num8, Keyboard::KeyCode::KEY_8},
        {sf::Keyboard::Num9, Keyboard::KeyCode::KEY_9},
        {sf::Keyboard::Up, Keyboard::KeyCode::UP},
        {sf::Keyboard::Down, Keyboard::KeyCode::DOWN},
        {sf::Keyboard::Left, Keyboard::KeyCode::LEFT},
        {sf::Keyboard::Right, Keyboard::KeyCode::RIGHT},
        {sf::Keyboard::Escape, Keyboard::KeyCode::ESCAPE}
    };

    auto it = keyMap.find(sfmlKey);
    return (it != keyMap.end()) ? it->second : Keyboard::KeyCode::UNKNOWN;
}

SFMLLibrary::SFMLLibrary() :
    _display(std::make_unique<SFMLDisplay>()),
    _textureManager(std::make_unique<SFMLTextureManager>()),
    _fontManager(std::make_unique<SFMLFontManager>()),
    _soundManager(std::make_unique<SFMLSoundManager>())
{
}

SFMLLibrary::~SFMLLibrary() = default;

IDisplayModule& SFMLLibrary::getDisplay()
{
    return *_display;
}

ITextureManager& SFMLLibrary::getTextures()
{
    return *_textureManager;
}

IFontManager& SFMLLibrary::getFonts()
{
    return *_fontManager;
}

ISoundManager& SFMLLibrary::getSounds()
{
    return *_soundManager;
}

}

extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::SFMLLibrary();
    }

    void destroy(arcade::IDisplayLibrary* library) {
        delete library;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::DISPLAY;
    }

    const char* entryPointName() {
        return "SFML";
    }
}
