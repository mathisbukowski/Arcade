/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** ISound
*/

#ifndef ISOUND_HPP_
#define ISOUND_HPP_

#include <string>
#include <memory>
#include <optional>
#include <variant>

namespace arcade {
    /**
     * Sound properties
     */
    class SoundInfos
    {
    public:
        /**
         * Construct a new SoundInfos object
         * @param path std::string Path to the sound file
         */
        SoundInfos(std::string path):
            _path(std::move(path)), _volume(50) {}
        /**
         * Destroy the SoundInfos object
         */
        virtual ~SoundInfos() = default;

        /**
         * Get the path of the sound file
         * @return std::string Path of the sound file
         */
        [[nodiscard]] std::string getPath() const { return _path; }

        /**
         * Get the volume level
         * @return float Volume level
         */
        [[nodiscard]] float getVolume() const { return _volume; }

        /**
         * Set the volume level
         * @param newVolume float New volume value
         */
        virtual void setVolume(float newVolume) { _volume = newVolume; }

        /**
         * Check if the music is looped
         * @return bool True if the music is looped, false otherwise
         */
        [[nodiscard]] bool isLooped() const { return _loop; }

        /**
         * Enable or disable looping
         * @param loop bool Whether the music should loop
         */
        void setLoop(bool loop) { _loop = loop; }

    private:
        /**
         * Path to the sound file
         */
        std::string _path;
        /**
         * Volume level
         */
        float _volume;
        /**
         * Looping state
         */
        bool _loop = false;
    };

    /**
     * Interface for the sound
     */
    class ISound {
    public:
        /**
         * Destroy the ISound object
         */
        virtual ~ISound() = default;

        /**
         * Get the sound information
         * @return const MySound& Sound information
         */
        [[nodiscard]] virtual const SoundInfos& getInformations() const = 0;

        /**
        * Play the sound
        */
        virtual void play(float volume) = 0;

        /**
         * Stop the sound
         */
        virtual void stop() = 0;
    };

    /**
     * Interface for the sound manager
     */
    class ISoundManager {
    public:
        /**
         * Destroy the ISoundManager object
         */
        virtual ~ISoundManager() = default;

        /**
         * Play a sound
         * @param name const std::string & Name of the sound
         * @param volume float Volume level
         */
        virtual void playSound(const std::string& name, float volume) = 0;

        /**
         * Stop a sound
         * @param name const std::string & Name of the sound
         */
        virtual void stopSound(const std::string& name) = 0;

        /**
         * Load a sound
         * @param name const std::string & Name of the sound
         * @param sound const SoundInfos & Sound properties
         * @return int 0 if success, -1 if error
         */
        [[nodiscard]] virtual int load(const std::string& name, const SoundInfos& sound) = 0;

        /**
         * Get a sound
         * @param name const std::string & Name of the sound
         * @return std::shared_ptr<ISound> Sound object
         */
        [[nodiscard]] virtual std::shared_ptr<ISound> get(const std::string& name) const = 0;
    };
}

#endif /* !ISOUND_HPP_ */
