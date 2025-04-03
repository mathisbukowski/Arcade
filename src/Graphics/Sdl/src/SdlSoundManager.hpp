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
    class SDLSound : public ISound {
    public:
        SDLSound();
        ~SDLSound();
        [[nodiscard]] const SoundInfos& getInformations() const override { return _soundInformations; }
        void play(float volume);
        void stop();
        void setSoundInfos(const SoundInfos& infos) { _soundInformations = infos; }

    private:
        SoundInfos _soundInformations;
        std::shared_ptr<Mix_Chunk> _chunk;
        int _channel;
    };

    class SDLSoundManager : public ISoundManager {
    public:
        SDLSoundManager();

        int load(const std::string& name, const SoundInfos& sound) override;
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
        void playSound(const std::string& name, float volume) override;
        void stopSound(const std::string& name) override;

    private:
        std::map<std::string, std::shared_ptr<SDLSound>> _sounds;
    };
};

#endif //SDLSOUNDMANAGER_HPP
