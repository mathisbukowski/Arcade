/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlDisplayModule.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "SdlTextureManager.hpp"

arcade::SDLDisplayModule::SDLDisplayModule(const std::string& name): _windowProperties("", 0, 0), _name(name), _isOpen(false) {}

arcade::SDLDisplayModule::~SDLDisplayModule()
{
    this->stop();
}

void arcade::SDLDisplayModule::init(const std::string& title, std::size_t width, std::size_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("Failed to initialize SDL");
    WindowProperties newWindownProperties = {title, width, height};
    this->setupWindowProperties(newWindownProperties);
    auto window = SDL_CreateWindow(_windowProperties.getTitle().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    static_cast<int>(_windowProperties.getWidth()), static_cast<int>(_windowProperties.getHeight()), 0);
    if (!window)
        throw std::runtime_error("Failed to create window");
    this->_window.reset(window, SDL_DestroyWindow);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    this->_renderer.reset(renderer, SDL_DestroyRenderer);
}

void arcade::SDLDisplayModule::stop()
{
    _renderer.reset();
    _window.reset();
    SDL_Quit();
}

void arcade::SDLDisplayModule::openWindow()
{
    this->_isOpen = true;
}

void arcade::SDLDisplayModule::closeWindow()
{
    this->_isOpen = false;
}

void arcade::SDLDisplayModule::clearWindow(Color color)
{
    SDL_SetRenderDrawColor(_renderer.get(), color.getR(), color.getG(), color.getB(), color.getOpacity());
    SDL_RenderClear(_renderer.get());
}

void arcade::SDLDisplayModule::drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position)
{
    auto sdlTexture = std::dynamic_pointer_cast<SDLTexture>(texture);
    if (!sdlTexture) {
        std::cerr << "Invalid texture type" << std::endl;
        return;
    }
    SDL_Rect srcRect = sdlTexture->getRect();
    SDL_Rect dstRect = {
        static_cast<int>(position.getX()),
        static_cast<int>(position.getY()),
        srcRect.w,
        srcRect.h
    };
    SDL_RenderCopy(_renderer.get(), sdlTexture->getTexture().get(), NULL, &dstRect);
}

arcade::Keyboard &arcade::SDLDisplayModule::getKeyboard()
{
    return _keyboard;
}

arcade::Mouse &arcade::SDLDisplayModule::getMouse()
{
    return _mouse;
}

void arcade::SDLDisplayModule::updateWindow(float delta)
{
    SDL_Event event;
    (void)delta;

    _keyboard.clearPressedKeys();

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            this->closeWindow();
            break;
        case SDL_KEYDOWN:
            {
                Keyboard::KeyCode key = mapSDLKeyToArcade(event.key.keysym.sym);
                if (key != Keyboard::UNKNOWN)
                    _keyboard.setKey(key, true);
            }
            break;
        case SDL_KEYUP:
            {
                Keyboard::KeyCode key = mapSDLKeyToArcade(event.key.keysym.sym);
                if (key != Keyboard::UNKNOWN)
                    _keyboard.setKey(key, false);
            }
            break;
        case SDL_MOUSEMOTION:
            _mouse.setPos(Vector<float>(static_cast<float>(event.motion.x),
                                       static_cast<float>(event.motion.y)));
            break;
        case SDL_MOUSEBUTTONDOWN:
            _mouse.setPressed(true);
            break;
        case SDL_MOUSEBUTTONUP:
            _mouse.setPressed(false);
            break;
        }
    }
    SDL_RenderPresent(_renderer.get());
}

arcade::Keyboard::KeyCode arcade::SDLDisplayModule::mapSDLKeyToArcade(SDL_Keycode key)
{
    switch (key) {
        case SDLK_a: return Keyboard::A;
        case SDLK_b: return Keyboard::B;
        case SDLK_c: return Keyboard::C;
        case SDLK_d: return Keyboard::D;
        case SDLK_e: return Keyboard::E;
        case SDLK_f: return Keyboard::F;
        case SDLK_g: return Keyboard::G;
        case SDLK_h: return Keyboard::H;
        case SDLK_i: return Keyboard::I;
        case SDLK_j: return Keyboard::J;
        case SDLK_k: return Keyboard::K;
        case SDLK_l: return Keyboard::L;
        case SDLK_m: return Keyboard::M;
        case SDLK_n: return Keyboard::N;
        case SDLK_o: return Keyboard::O;
        case SDLK_p: return Keyboard::P;
        case SDLK_q: return Keyboard::Q;
        case SDLK_r: return Keyboard::R;
        case SDLK_s: return Keyboard::S;
        case SDLK_t: return Keyboard::T;
        case SDLK_u: return Keyboard::U;
        case SDLK_v: return Keyboard::V;
        case SDLK_w: return Keyboard::W;
        case SDLK_x: return Keyboard::X;
        case SDLK_y: return Keyboard::Y;
        case SDLK_z: return Keyboard::Z;
        case SDLK_RETURN: return Keyboard::ENTER;
        case SDLK_1: return Keyboard::KEY_1;
        case SDLK_2: return Keyboard::KEY_2;
        case SDLK_3: return Keyboard::KEY_3;
        case SDLK_4: return Keyboard::KEY_4;
        case SDLK_5: return Keyboard::KEY_5;
        case SDLK_6: return Keyboard::KEY_6;
        case SDLK_7: return Keyboard::KEY_7;
        case SDLK_8: return Keyboard::KEY_8;
        case SDLK_9: return Keyboard::KEY_9;
        case SDLK_UP: return Keyboard::UP;
        case SDLK_DOWN: return Keyboard::DOWN;
        case SDLK_LEFT: return Keyboard::LEFT;
        case SDLK_RIGHT: return Keyboard::RIGHT;
        case SDLK_ESCAPE: return Keyboard::ESCAPE;
        default: return Keyboard::UNKNOWN;
    }
}
