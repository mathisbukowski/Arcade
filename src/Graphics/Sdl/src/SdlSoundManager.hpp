/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLSOUNDMANAGER_HPP
#define SDLSOUNDMANAGER_HPP

#include <map>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_mixer.h>

#include "Arcade.hpp"
#include "ISound.hpp"

namespace arcade {
    /**
     * @class SDLSound
     * This class is used to create a sound using the SDL2 library
     * It inherits from the ISound interface
     */
    class SDLSound : public ISound {
    public:
        /**
         * Construct a new SDLSound object
         */
        SDLSound();
        /**
         * Destroy the SDLSound object
         */
        ~SDLSound();
        /**
         * Get the sound information
         * @return const SoundInfos &
         */
        [[nodiscard]] const SoundInfos& getInformations() const override { return _soundInformations; }
        /**
         * Play the sound
         * @param volume float Volume of the sound
         */
        void play(float volume) override;
        /**
         * Stop the sound
         */
        void stop() override;
        /**
         * Get the sound information
         * @param infos SoundInfos & Sound information
         */
        void setSoundInfos(const SoundInfos& infos) { _soundInformations = infos; }

    private:
        /**
         * Sound information
         */
        SoundInfos _soundInformations;
        /**
         * SDL chunk
         */
        std::shared_ptr<Mix_Chunk> _chunk;
        /**
         * SDL channel
         */
        int _channel;
    };

    /**
     * @class SDLSoundManager
     * This class is used to manage the sounds using the SDL2 library
     * It inherits from the ISoundManager interface
     */
    class SDLSoundManager : public ISoundManager {
    public:
        /**
         * Construct a new SDLSoundManager object
         */
        SDLSoundManager();

        /**
         * Load a sound
         * @param name const std::string & Name of the sound
         * @param sound const SoundInfos & Sound information
         * @return int
         */
        int load(const std::string& name, const SoundInfos& sound) override;
        /**
         * Get a sound
         * @param name const std::string & Name of the sound
         * @return std::shared_ptr<ISound>
         */
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
        /**
         * Play a sound
         * @param name const std::string & Name of the sound
         * @param volume float Volume of the sound
         */
        void playSound(const std::string& name, float volume) override;
        /**
         * Stop a sound
         * @param name const std::string & Name of the sound
         */
        void stopSound(const std::string& name) override;

    private:
        /**
         * Map of sounds
         */
        std::map<std::string, std::shared_ptr<SDLSound>> _sounds;
    };
};

#endif //SDLSOUNDMANAGER_HPP
