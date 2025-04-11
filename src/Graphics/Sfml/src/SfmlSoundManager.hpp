/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef SFMLSOUNDMANAGER_HPP
#define SFMLSOUNDMANAGER_HPP

#include "ISound.hpp"
#include <SFML/Audio.hpp>
#include <map>

namespace arcade {
    /**
 * Implementation of ISound for SFML
 */
    class SFMLSound : public ISound {
    public:
        SFMLSound(const SoundInfos& soundInfo);
        ~SFMLSound() override = default;

        const SoundInfos& getInformations() const override;
        void play(float volume) override;
        void stop() override;

    private:
        void loadSound(const SoundInfos& soundInfos);
        void loadMusic(const SoundInfos& musicInfos);
        SoundInfos _info;
        std::variant<sf::Sound, std::unique_ptr<sf::Music>> _sound;
        sf::SoundBuffer _buffer;
    };

    /**
 * Implementation of ISoundManager for SFML
 */
    class SFMLSoundManager : public ISoundManager {
    public:
        SFMLSoundManager() noexcept = default;
        ~SFMLSoundManager() override = default;

        void playSound(const std::string& name, const float volume) override;
        void stopSound(const std::string& name) override;
        int load(const std::string& name, const SoundInfos& sound) override;
        std::shared_ptr<ISound> get(const std::string& name) const override;

    private:
        mutable std::map<std::string, std::shared_ptr<SFMLSound>> _sounds;
    };
}



#endif //SFMLSOUNDMANAGER_HPP
