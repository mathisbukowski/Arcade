/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef NCURSESSOUNDMANAGER_HPP
#define NCURSESSOUNDMANAGER_HPP

#include "ISound.hpp"
#include <map>

namespace arcade {
    class NcursesSound : public ISound {
    public:
        NcursesSound(const SoundInfos& sound) : _soundInformations(sound) {}
        [[nodiscard]] const SoundInfos& getInformations() const override { return _soundInformations; }
    private:
        SoundInfos _soundInformations;
    };

    class NcursesSoundManager : public ISoundManager {
    public:
        int load(const std::string& name, const SoundInfos& sound) override;
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
        void playSound(const std::string& name, float volume) override;
        void stopSound(const std::string& name) override;
    private:
        std::map<std::string, std::shared_ptr<NcursesSound>> _sounds;
    };
}


#endif //NCURSESSOUNDMANAGER_HPP
