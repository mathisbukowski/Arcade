/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlSoundManager.hpp"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>

arcade::SDLSound::SDLSound() : _soundInformations(""), _chunk(nullptr), _channel(-1) { }

arcade::SDLSound::~SDLSound()
{
    stop();
    _chunk.reset();
}

void arcade::SDLSound::play(float volume)
{
    if (!_chunk) {
        _chunk = std::shared_ptr<Mix_Chunk>(
            Mix_LoadWAV(_soundInformations.getPath().c_str()),
            Mix_FreeChunk
        );
        if (!_chunk) {
            std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
            return;
        }
    }
    Mix_VolumeChunk(_chunk.get(), static_cast<int>(volume * 128.0f));
    _channel = Mix_PlayChannel(-1, _chunk.get(), _soundInformations.isLooped() ? -1 : 0);
    if (_channel == -1)
        std::cerr << "Failed to play sound: " << Mix_GetError() << std::endl;
}

void arcade::SDLSound::stop()
{
    if (_channel != -1) {
        Mix_HaltChannel(_channel);
        _channel = -1;
    }
}

arcade::SDLSoundManager::SDLSoundManager()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize audio! SDL Error: " << SDL_GetError() << std::endl;
        return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

int arcade::SDLSoundManager::load(const std::string& name, const SoundInfos& sound)
{
    auto newSound = std::make_shared<SDLSound>();
    newSound->setSoundInfos(sound);

    if (_sounds.find(name) != _sounds.end())
        return -1;

    _sounds[name] = newSound;
    return 0;
}

std::shared_ptr<arcade::ISound> arcade::SDLSoundManager::get(const std::string& name) const
{
    auto it = _sounds.find(name);
    if (it == _sounds.end())
        return nullptr;
    return it->second;
}

void arcade::SDLSoundManager::playSound(const std::string& name, float volume)
{
    auto it = _sounds.find(name);
    if (it != _sounds.end()) {
        auto sound = std::dynamic_pointer_cast<SDLSound>(it->second);
        if (sound) {
            sound->play(volume);
        }
    }
}

void arcade::SDLSoundManager::stopSound(const std::string& name)
{
    auto it = _sounds.find(name);
    if (it != _sounds.end()) {
        auto sound = std::dynamic_pointer_cast<SDLSound>(it->second);
        if (sound) {
            sound->stop();
        }
    }
}
