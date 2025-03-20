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
     * @brief Sound properties
     */
    class SoundInfos
    {
    public:
        /**
         * @brief Construct a new Sound Infos object
         * @param path Path to the sound file
         */
        SoundInfos(std::string path):
            path(std::move(path)), volume(50), isPlaying(false) {};
        ~SoundInfos() = default;
        std::string path;
        bool isPlaying;
        float volume;
    };
    
    /**
     * @brief Music properties
     */
    class MusicInfos : public SoundInfos
    {
    public:
        /**
         * @brief Construct a new Music Infos object
         * @param path Path to the music file
         */
        MusicInfos(std::string path):
            SoundInfos(std::move(path)), loop(false) {};
        ~MusicInfos() = default;
        bool loop;
    };

    /**
     * @brief MySound type
     * Contains SoundInfos or MusicInfos
     */

    using MySound = std::variant<SoundInfos, MusicInfos>;

    /**
     * @brief Interface for the sound
     */
    class ISound {
    public:
        virtual ~ISound() = default;
        /**
         * @brief Get the sound informations
         * @return const MySound&
         */
        [[nodiscard]] virtual const MySound& getInformations() const = 0;
    };


    /**
     * @brief Interface for the sound manager
     */
    class ISoundManager {
    public:
        virtual ~ISoundManager() = default;
        /**
         * @brief Play a sound
         * @param name Name of the sound
         * @param volume Volume of the sound
         */
        virtual void playSound(const std::string& name, const float volume) = 0;
        /**
         * @brief Stop a sound
         * @param name Name of the sound
         */
        virtual void stopSound(const std::string& name) = 0;
        /**
         * @brief Load a sound
         * @param name Name of the sound
         * @param sound Sound properties
         * @return int
         */
        [[nodiscard]] virtual int load(const std::string& name, const MySound sound) const = 0;
        /**
         * @brief Get a sound
         * @param name Name of the sound
         * @return std::shared_ptr<ISound>
         */
        [[nodiscard]] virtual std::shared_ptr<ISound> get(const std::string& name) const = 0;
    };
}

#endif /* !ISOUND_HPP_ */
