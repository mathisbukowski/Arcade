/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 03
*/

#ifndef SDLSOUNDMANAGER_HPP
#define SDLSOUNDMANAGER_HPP

#include <map>

#include "Arcade.hpp"
#include "ISound.hpp"

namespace arcade {
    class SDLSound : public ISound {
    public:
        SDLSound();
        [[nodiscard]] const SoundInfos& getInformations() const override { return _soundInformations; }
    private:
        SoundInfos _soundInformations;
    };
    class SDLSoundManager : public ISoundManager {
    public:
        int load(const std::string& name, const SoundInfos& sound) override;
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
    private:
        std::map<std::string, std::shared_ptr<SDLSound>> _sounds;
    };
};



#endif //SDLSOUNDMANAGER_HPP
