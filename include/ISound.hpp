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
         * @param path Path to the sound file
         */
        SoundInfos(std::string path):
            _path(std::move(path)), _volume(50) {}
        virtual ~SoundInfos() = default;

        /**
         * Get the path of the sound file
         * @return std::string
         */
        [[nodiscard]] std::string getPath() { return _path; }

        /**
         * Get the volume level
         * @return float
         */
        [[nodiscard]] float getVolume() const { return _volume; }

        /**
         * Check if the sound is currently playing
         * @return bool
         */
        [[nodiscard]] bool isPlaying() const { return _playing; }

        /**
         * Set the volume level
         * @param newVolume New volume value
         */
        virtual void setVolume(float newVolume) { _volume = newVolume; }

        /**
         * Play the sound
         */
        virtual void play() { _playing = true; }

    private:
        std::string _path;
        float _volume;
        bool _playing = false;
    };

    /**
     * Music properties
     */
    class MusicInfos final : public SoundInfos
    {
    public:
        /**
         * Construct a new MusicInfos object
         * @param path Path to the music file
         */
        MusicInfos(std::string path):
            SoundInfos(std::move(path)) {}
        ~MusicInfos() = default;

        /**
         * Check if the music is looped
         * @return bool
         */
        [[nodiscard]] bool isLooped() const { return _loop; }

        /**
         * Enable or disable looping
         * @param loop Whether the music should loop
         */
        void setLoop(bool loop) { _loop = loop; }

    private:
        bool _loop = false;
    };

    /**
     * MySound type
     * Contains SoundInfos or MusicInfos
     */
    using MySound = std::variant<SoundInfos, MusicInfos>;

    /**
     * Interface for the sound
     */
    class ISound {
    public:
        virtual ~ISound() = default;

        /**
         * Get the sound information
         * @return const MySound&
         */
        [[nodiscard]] virtual const MySound& getInformations() const = 0;
    };

    /**
     * Interface for the sound manager
     */
    class ISoundManager {
    public:
        virtual ~ISoundManager() = default;

        /**
         * Play a sound
         * @param name Name of the sound
         * @param volume Volume level
         */
        virtual void playSound(const std::string& name, float volume) = 0;

        /**
         * Stop a sound
         * @param name Name of the sound
         */
        virtual void stopSound(const std::string& name) = 0;

        /**
         * Load a sound
         * @param name Name of the sound
         * @param sound Sound properties
         * @return int
         */
        [[nodiscard]] virtual int load(const std::string& name, const MySound& sound) = 0;

        /**
         * Get a sound
         * @param name Name of the sound
         * @return std::shared_ptr<ISound>
         */
        [[nodiscard]] virtual std::shared_ptr<ISound> get(const std::string& name) const = 0;
    };
}

#endif /* !ISOUND_HPP_ */
