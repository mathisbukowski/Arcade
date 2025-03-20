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
    
    class SoundInfos
    {
    public:
        SoundInfos(std::string path):
            path(std::move(path)), volume(0) {};
        ~SoundInfos() = default;
        std::string path;
        const float volume;
    };

    class MusicInfos
    {
    public:
        MusicInfos(std::string path):
            path(std::move(path)), isPlaying(false), volume(0) {};
        ~MusicInfos() = default;
        std::string path;
        bool loop;
        bool isPlaying;
        const float volume;
    };

    using MySound = std::variant<SoundInfos, MusicInfos>;

    class ISound {
    public:
        virtual ~ISound() = default;
        [[nodiscard]] virtual const MySound& getInformations() const = 0;
    };


    class ISoundManager {
    public:
        virtual ~ISoundManager() = default;

        virtual void playSound(const std::string& name, const float volume) = 0;
        virtual void stopSound(const std::string& name) = 0;
        [[nodiscard]] virtual int load(const std::string& name, const MySound texture) const = 0;
        [[nodiscard]] virtual std::shared_ptr<ISound> get(const std::string& name) const = 0;
    };
}

#endif /* !ISOUND_HPP_ */
