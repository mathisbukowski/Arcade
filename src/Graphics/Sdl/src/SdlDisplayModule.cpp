/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** SdlDisplayModule implementation
*/

#include "SdlDisplayModule.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <stdexcept>

namespace arcade {

SDLDisplayModule::SDLDisplayModule(SDLRendererManager& renderer_manager)
    : _windowProperties("", 0, 0), _isOpen(false), _rendererManager(renderer_manager)
{
    this->initializeSDL();
}

SDLDisplayModule::~SDLDisplayModule() = default;

void SDLDisplayModule::initializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("SDL could not initialize! SDL Error: " + std::string(SDL_GetError()));

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

    if (!(IMG_Init(imgFlags) & imgFlags))
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
}

void SDLDisplayModule::init(const std::string& title, std::size_t width, std::size_t height)
{
    WindowProperties newWindowProperties = {title, width, height};

    this->setupWindowProperties(newWindowProperties);
    _rendererManager.initializeRenderer(title, width, height);
    _renderer = _rendererManager.getRenderer();
    _window = _rendererManager.getWindow();
    this->validateRendererAndWindow();
    this->openWindow();
}

void SDLDisplayModule::validateRendererAndWindow()
{
    if (!_renderer)
        throw std::runtime_error("Failed to create renderer");
    if (!_window)
        throw std::runtime_error("Failed to create window");
}

void SDLDisplayModule::stop()
{
    if (!isWindowOpen())
        return;
    this->cleanupResources();
}

void SDLDisplayModule::cleanupResources()
{
    if (_renderer)
        _renderer.reset();
    if (_window)
        _window.reset();
    if (TTF_WasInit())
        TTF_Quit();
    SDL_Quit();
}

void SDLDisplayModule::openWindow()
{
    this->_isOpen = true;
}

void SDLDisplayModule::closeWindow()
{
    this->_isOpen = false;
}

void SDLDisplayModule::clearWindow(Color color)
{
    SDL_SetRenderDrawColor(_renderer.get(), color.getR(), color.getG(), color.getB(), color.getOpacity());
    SDL_RenderClear(_renderer.get());
}

void SDLDisplayModule::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    auto sdlTexture = std::dynamic_pointer_cast<SDLTexture>(texture);

    if (!sdlTexture || !sdlTexture->getTexture())
        return;

    if (std::holds_alternative<TextureText>(sdlTexture->getInformations())) {
        this->drawTextTexture(sdlTexture, position);
    } else {
        this->drawSpriteTexture(sdlTexture, position);
    }
}

void SDLDisplayModule::drawTextTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position)
{
    SDL_Rect srcRect = {0, 0, 0, 0};
    SDL_Rect dstRect = {
        static_cast<int>(position.getX()),
        static_cast<int>(position.getY()),
        0, 0
    };

    SDL_QueryTexture(texture->getTexture().get(), nullptr, nullptr, &srcRect.w, &srcRect.h);

    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;

    SDL_RenderCopy(_renderer.get(), texture->getTexture().get(), &srcRect, &dstRect);
}

void SDLDisplayModule::drawSpriteTexture(std::shared_ptr<SDLTexture> texture, Vector<float> position)
{
    SDL_Rect srcRect = {0, 0, 0, 0};
    SDL_Rect dstRect;

    SDL_QueryTexture(texture->getTexture().get(), nullptr, nullptr, &srcRect.w, &srcRect.h);

    auto [scaleX, scaleY] = this->calculateSpriteScale(texture->getTexture().get());
    dstRect.w = static_cast<int>(srcRect.w * scaleX);
    dstRect.h = static_cast<int>(srcRect.h * scaleY);

    auto [x, y] = this->calculateAdjustedPosition(position);
    dstRect.x = static_cast<int>(x);
    dstRect.y = static_cast<int>(y);

    SDL_RenderCopy(_renderer.get(), texture->getTexture().get(), &srcRect, &dstRect);
}

std::pair<float, float> SDLDisplayModule::calculateSpriteScale(SDL_Texture* texture)
{
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);

    float cellWidth = _windowProperties.getWidth() / GRID_SIZE;
    float cellHeight = _windowProperties.getHeight() / GRID_SIZE;

    if (textureWidth > 0 && textureHeight > 0) {
        float scaleX = (cellWidth * CELL_SCALE_FACTOR) / textureWidth;
        float scaleY = (cellHeight * CELL_SCALE_FACTOR) / textureHeight;
        return {scaleX, scaleY};
    }
    return {1.0f, 1.0f};
}

std::pair<float, float> SDLDisplayModule::calculateAdjustedPosition(Vector<float> position)
{
    float cellWidth = _windowProperties.getWidth() / GRID_SIZE;
    float cellHeight = _windowProperties.getHeight() / GRID_SIZE;

    float offsetX = (cellWidth * (1.0f - CELL_SCALE_FACTOR)) / 2.0f;
    float offsetY = (cellHeight * (1.0f - CELL_SCALE_FACTOR)) / 2.0f;

    return {position.getX() + offsetX, position.getY() + offsetY};
}

Keyboard &SDLDisplayModule::getKeyboard()
{
    return _keyboard;
}

Mouse &SDLDisplayModule::getMouse()
{
    return _mouse;
}

void SDLDisplayModule::updateWindow(float delta)
{
    (void)delta;

    _keyboard.clearPressedKeys();
    this->processEvents();
    SDL_RenderPresent(_renderer.get());
}

void SDLDisplayModule::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
        this->handleEvent(event);
}

void SDLDisplayModule::handleEvent(const SDL_Event& event)
{
    switch (event.type) {
    case SDL_QUIT:
        this->closeWindow();
        break;
    case SDL_KEYDOWN:
        this->handleKeyboardEvent(event.key, true);
        break;
    case SDL_KEYUP:
        this->handleKeyboardEvent(event.key, false);
        break;
    case SDL_MOUSEMOTION:
        this->handleMouseMotionEvent(event.motion);
        break;
    case SDL_MOUSEBUTTONDOWN:
        this->handleMouseButtonEvent(event.button, true);
        break;
    case SDL_MOUSEBUTTONUP:
        this->handleMouseButtonEvent(event.button, false);
        break;
    default:
        break;
    }
}

void SDLDisplayModule::handleKeyboardEvent(const SDL_KeyboardEvent& keyEvent, bool isPressed)
{
    Keyboard::KeyCode key = this->mapSDLKeyToArcade(keyEvent.keysym.sym);
    if (key != Keyboard::UNKNOWN) {
        _keyboard.setKey(key, isPressed);
    }
}

void SDLDisplayModule::handleMouseButtonEvent(const SDL_MouseButtonEvent& mouseEvent, bool isPressed)
{
    _mouse.setPressed(isPressed);
    _mouse.setPos(Vector<float>(static_cast<float>(mouseEvent.x), static_cast<float>(mouseEvent.y)));
}

void SDLDisplayModule::handleMouseMotionEvent(const SDL_MouseMotionEvent& mouseEvent)
{
    _mouse.setPos(Vector<float>(static_cast<float>(mouseEvent.x), static_cast<float>(mouseEvent.y)));
}

Keyboard::KeyCode SDLDisplayModule::mapSDLKeyToArcade(SDL_Keycode key)
{
    static const std::unordered_map<SDL_Keycode, Keyboard::KeyCode> keyMap = {
        {SDLK_a, Keyboard::A}, {SDLK_b, Keyboard::B}, {SDLK_c, Keyboard::C},
        {SDLK_d, Keyboard::D}, {SDLK_e, Keyboard::E}, {SDLK_f, Keyboard::F},
        {SDLK_g, Keyboard::G}, {SDLK_h, Keyboard::H}, {SDLK_i, Keyboard::I},
        {SDLK_j, Keyboard::J}, {SDLK_k, Keyboard::K}, {SDLK_l, Keyboard::L},
        {SDLK_m, Keyboard::M}, {SDLK_n, Keyboard::N}, {SDLK_o, Keyboard::O},
        {SDLK_p, Keyboard::P}, {SDLK_q, Keyboard::Q}, {SDLK_r, Keyboard::R},
        {SDLK_s, Keyboard::S}, {SDLK_t, Keyboard::T}, {SDLK_u, Keyboard::U},
        {SDLK_v, Keyboard::V}, {SDLK_w, Keyboard::W}, {SDLK_x, Keyboard::X},
        {SDLK_y, Keyboard::Y}, {SDLK_z, Keyboard::Z},
        {SDLK_RETURN, Keyboard::ENTER},
        {SDLK_1, Keyboard::KEY_1}, {SDLK_2, Keyboard::KEY_2}, {SDLK_3, Keyboard::KEY_3},
        {SDLK_4, Keyboard::KEY_4}, {SDLK_5, Keyboard::KEY_5}, {SDLK_6, Keyboard::KEY_6},
        {SDLK_7, Keyboard::KEY_7}, {SDLK_8, Keyboard::KEY_8}, {SDLK_9, Keyboard::KEY_9},
        {SDLK_UP, Keyboard::UP}, {SDLK_DOWN, Keyboard::DOWN},
        {SDLK_LEFT, Keyboard::LEFT}, {SDLK_RIGHT, Keyboard::RIGHT},
        {SDLK_ESCAPE, Keyboard::ESCAPE}
    };

    auto it = keyMap.find(key);
    return (it != keyMap.end()) ? it->second : Keyboard::UNKNOWN;
}

}
