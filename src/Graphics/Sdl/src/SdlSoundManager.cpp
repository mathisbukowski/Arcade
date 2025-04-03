/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlSoundManager.hpp"

/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#include "SdlSoundManager.hpp"
#include <SDL2/SDL_mixer.h>
#include <iostream>

arcade::SDLSound::SDLSound() : _soundInformations("", 50)
{
    // Initialisation avec valeurs par défaut
}

int arcade::SDLSoundManager::load(const std::string& name, const SoundInfos& sound)
{
    auto newSound = std::make_shared<SDLSound>();
    newSound->_soundInformations = sound;

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
    (void)name;
    (void)volume;
}

void arcade::SDLSoundManager::stopSound(const std::string& name)
{
    (void)name;
}
