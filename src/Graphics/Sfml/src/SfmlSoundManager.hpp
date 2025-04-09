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
     * @class Implementation of ISound for SFML
     * This class is used to create a sound using the SFML library
     * It inherits from the ISound interface
     */
    class SFMLSound : public ISound {
    public:
        /**
         * Construct a new SFMLSound object
         * @param soundInfo const SoundInfos& Sound information
         */
        SFMLSound(const SoundInfos& soundInfo);
        /**
         * Destroy the SFMLSound object
         */
        ~SFMLSound() override = default;

        /**
         * Load sound from file
         * @param soundInfos const SoundInfos& Sound information
         */
        const SoundInfos& getInformations() const override;
        /**
         * play sound
         * @return sf::SoundBuffer&
         */
        void play(float volume);
        /**
         * stop sound
         */
        void stop();

    private:
        /**
         * Load sound from file
         * @param soundInfos const SoundInfos& Sound information
         */
        void loadSound(const SoundInfos& soundInfos);
        /**
         * Load music from file
         * @param musicInfos const SoundInfos& Music information
         */
        void loadMusic(const SoundInfos& musicInfos);
        /**
         * Sound information
         */
        SoundInfos _info;
        /**
         * Sound or music object
         */
        std::variant<sf::Sound, std::unique_ptr<sf::Music>> _sound;
        /**
         * Sound buffer
         */
        sf::SoundBuffer _buffer;
    };

    /**
     * @class SFMLSoundManager
     * This class is used to manage sounds using the SFML library
     * It inherits from the ISoundManager interface
     */
    class SFMLSoundManager : public ISoundManager {
    public:
        /**
         * Construct a new SFMLSoundManager object
         */
        SFMLSoundManager() noexcept = default;
        /**
         * Destroy the SFMLSoundManager object
         */
        ~SFMLSoundManager() override = default;

        /**
         * Play sound
         * @param name const std::string& Name of the sound
         * @param volume float Volume of the sound
         */
        void playSound(const std::string& name, const float volume) override;
        /**
         * Stop sound
         * @param name const std::string& Name of the sound
         */
        void stopSound(const std::string& name) override;
        /**
         * Load sound
         * @param name const std::string& Name of the sound
         * @param sound const SoundInfos& Sound information
         * @return int
         */
        int load(const std::string& name, const SoundInfos& sound) override;
        /**
         * Get sound
         * @param name const std::string& Name of the sound
         * @return std::shared_ptr<ISound>
         */
        std::shared_ptr<ISound> get(const std::string& name) const override;

    private:
        /**
         * Map of sounds
         */
        mutable std::map<std::string, std::shared_ptr<SFMLSound>> _sounds;
    };
}



#endif //SFMLSOUNDMANAGER_HPP
