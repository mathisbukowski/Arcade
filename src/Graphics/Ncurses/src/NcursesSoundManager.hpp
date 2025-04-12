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
    /**
     * @class NcursesSound
     * This class is used to create a sound using the ncurses library
     * It inherits from the ISound interface
     */
    class NcursesSound : public ISound {
    public:
        /**
         * Constructor
         * @param sound SoundInfos & Sound to create
         */
        NcursesSound(const SoundInfos& sound) : _soundInformations(sound) {}
        /**
         * Get the sound informations
         * @return const SoundInfos & Sound informations
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
    private:
        /**
         * Sound informations
         */
        SoundInfos _soundInformations;
    };

    /**
     * @class NcursesSoundManager
     * This class is used to manage sounds using the ncurses library
     * It inherits from the ISoundManager interface
     */
    class NcursesSoundManager : public ISoundManager {
    public:
        /**
         * Function to load a sound
         * @param name const std::string & Name of the sound
         * @param sound SoundInfos & Sound to load
         * @return int 0 if success, -1 if error
         */
        int load(const std::string& name, const SoundInfos& sound) override;
        /**
         * Function to get a sound
         * @param name const std::string & Name of the sound
         * @return std::shared_ptr<ISound> Sound
         */
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
        /**
         * Function to play a sound
         * @param name const std::string & Name of the sound
         * @param volume float Volume of the sound
         */
        void playSound(const std::string& name, float volume) override;
        /**
         * Function to stop a sound
         * @param name const std::string & Name of the sound
         */
        void stopSound(const std::string& name) override;
    private:
        /**
         * Map of sounds
         */
        std::map<std::string, std::shared_ptr<NcursesSound>> _sounds;
    };
}


#endif //NCURSESSOUNDMANAGER_HPP
