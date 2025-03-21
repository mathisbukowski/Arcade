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
            _path(std::move(path)), _volume(50) {}
        ~SoundInfos() = default;

        /**
         * @brief Get the Path object
         * @return std::string
         */
        [[nodiscard]] std::string getPath();
        /**
         * @brief Get the Volume object
         * @return float
         */
        [[nodiscard]] float getVolume();
        /**
         * @brief sound is playing
         * @return bool
         */
        [[nodiscard]] bool isPlaying();

        /**
         * @brief Set the Volume object
         * @param newVolume New volume
         */
        void setVolume(float newVolume);
        /**
         * @brief Play the sound
         */
        virtual void play() = 0;

    private:
        std::string _path;
        float _volume;
        bool _playing = false;
    };

    
    /**
     * @brief Music properties
     */
    class MusicInfos: public SoundInfos
    {
    public:
      /**
        * @brief Construct a new Music Infos object
        * @param path Path to the music file
        */
        MusicInfos(std::string path):
            SoundInfos(std::move(path)) {}
        ~MusicInfos() = default;

        /**
         * @brief Get the Loop object
         * @return bool
         */
        [[nodiscard]] bool isLooped();
        /**
         * @brief Set the Loop object
         * @param loop Loop the music
         */
        void setLoop(bool loop);

    private:
        bool _loop = false;
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
