/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** 04
*/

#ifndef NCURSESTEXTUREMANAGER_HPP
#define NCURSESTEXTUREMANAGER_HPP


#include "ITexture.hpp"
#include <map>

namespace arcade {

    class NcursesTexture : public ITexture {
    public:
        NcursesTexture(const MyTexture &texture) : _textureInformations(texture) {}
        [[nodiscard]] const MyTexture& getInformations() const override { return _textureInformations; }
        void set(MyTexture& texture) override;
    private:
        MyTexture _textureInformations;
    };

    class NcursesTextureManager : public ITextureManager {
    public:
        int load(const std::string& name, const MyTexture& newTexture) override;
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        std::map<std::string, std::shared_ptr<NcursesTexture>> _textures;
    };
};


#endif //NCURSESTEXTUREMANAGER_HPP
