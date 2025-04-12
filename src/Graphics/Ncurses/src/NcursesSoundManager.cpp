/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "NcursesSoundManager.hpp"

#include <iostream>

std::shared_ptr<arcade::ISound> arcade::NcursesSoundManager::get(const std::string& name) const
{
    auto it = _sounds.find(name);
    if (it != _sounds.end())
        return it->second;
    std::cerr << "Sound not found: " << name << std::endl;
    return nullptr;
}


int arcade::NcursesSoundManager::load(const std::string& name, const SoundInfos& sound)
{
    try {
        _sounds[name] = std::make_shared<NcursesSound>(sound);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Failed to load sound: " << e.what() << std::endl;
        return -1;
    }
}

void arcade::NcursesSound::play(float volume)
{
    std::cout << "NCURSE doesn't provide sounds." << volume << std::endl;
}

void arcade::NcursesSound::stop()
{
    std::cout << "NCURSE doesn't provide sounds." << std::endl;
}


void arcade::NcursesSoundManager::playSound(const std::string& name, float volume)
{
    auto sound = this->get(name);
    if (sound) {
        auto soundInfos = sound->getInformations();
        soundInfos.setVolume(volume);
        sound->play(volume);
        std::cout << "Playing sound: " << name << " at volume: " << volume << std::endl;
    }
}

void arcade::NcursesSoundManager::stopSound(const std::string& name)
{
    auto sound = this->get(name);
    if (sound) {
        auto soundInfos = sound->getInformations();
        sound->stop();
        std::cout << "Stopped sound: " << name << std::endl;
    }
}
