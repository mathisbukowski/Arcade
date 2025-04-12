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

    /**
     * @class NcursesTexture
     * This class is used to create a texture using the ncurses library
     * It inherits from the ITexture interface
     */
    class NcursesTexture : public ITexture {
    public:
        /**
         * Constructor
         * @param texture MyTexture & Texture to create
         */
        NcursesTexture(const MyTexture &texture);
        /**
         * Get the texture informations
         * @return const MyTexture & Texture informations
         */
        [[nodiscard]] const MyTexture& getInformations() const override { return _textureInformations; }
        /**
         * Set the texture informations
         * @param texture MyTexture & Texture to set
         */
        void set(MyTexture& texture) override {_textureInformations = texture;}


    private:
        /**
         * Texture informations
         */
        MyTexture _textureInformations;
        TextureText convertImageToText(const TextureImg& img);
    };

    /**
     * @class NcursesTextureManager
     * This class is used to manage textures using the ncurses library
     * It inherits from the ITextureManager interface
     */
    class NcursesTextureManager : public ITextureManager {
    public:
        /**
         * Function to load a texture
         * @param name const std::string & Name of the texture
         * @param newTexture MyTexture & Texture to load
         * @return int 0 if success, -1 if error
         */
        int load(const std::string& name, const MyTexture& newTexture) override;
        /**
         * Function to get a texture
         * @param name const std::string & Name of the texture
         * @return std::shared_ptr<ITexture> Texture
         */
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        /**
         * Map of textures
         */
        std::map<std::string, std::shared_ptr<NcursesTexture>> _textures;
    };
};


#endif //NCURSESTEXTUREMANAGER_HPP
