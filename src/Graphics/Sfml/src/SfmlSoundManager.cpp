/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#include "SfmlSoundManager.hpp"
#include <filesystem>
#include <iostream>

namespace arcade {
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
}
