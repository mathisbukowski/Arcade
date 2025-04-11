/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
    #define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <memory>
#include <map>
#include "Arcade.hpp"
#include "DLObject.hpp"

/**
 * @class DynamicLibraryManager
 * Manages multiple dynamic libraries
 */

namespace arcade {
    class DynamicLibraryManager {
        public:
            /**
             * Constructor
             * @param libToLoad const std::string &  Path to the library to load
             */
            DynamicLibraryManager(const std::string& libToLoad);

            /**
             * Destructor
             */
            ~DynamicLibraryManager();
            /**
             * Scan a directory for libraries
             * @param libToLoad const std::string & Path to the library to load
             */
            void scanDirectory(const std::string& libToLoad);
            /**
             * Get all loaded libraries
             * @return std::map<std::string, std::shared_ptr<DynamicLibraryObject>>
             */
            [[nodiscard]] std::map<std::string, std::shared_ptr<DynamicLibraryObject>> getAllLibraries() const { return _libraries; }

            /**
             * Get all libraries of a specific type
             * @param type LibType Type of library to filter
             * @return std::map<std::string, std::shared_ptr<DynamicLibraryObject>>
             */
            [[nodiscard]] std::map<std::string, std::shared_ptr<DynamicLibraryObject>> getAllLibrariesByType(LibType type) const;

            /**
             * Get current graphic library
             * @return std::shared_ptr<DynamicLibraryObject>
             */
            [[nodiscard]] std::shared_ptr<DynamicLibraryObject> getCurrentGraphicLib() const;

            /**
             * Set current graphic library
             * @param current_graphic_lib const std::shared_ptr<DynamicLibraryObject> & New graphic library
             */
            void setCurrentGraphicLib(const std::shared_ptr<DynamicLibraryObject>& current_graphic_lib);

            /**
             * Get current game library
             * @return std::shared_ptr<DynamicLibraryObject>
             */
            [[nodiscard]] std::shared_ptr<DynamicLibraryObject> getCurrentGameLib() const;

            /**
             * Set current game library
             * @param current_game_lib const std::shared_ptr<DynamicLibraryObject> & New game library
             */
            void setCurrentGameLib(const std::shared_ptr<DynamicLibraryObject>& current_game_lib);

            /**
             * Initialize the game library
             */
            void initGameLib();
            /**
             * Set next game library
             */
            void setNextGame();
            /**
             * Set next graphic library
             */
            void setNextGraphicLib();
        private:

            /**
             * Loaded libraries
             */
            std::map<std::string, std::shared_ptr<DynamicLibraryObject>> _libraries;

            /**
             * Current graphic library
             */
            std::shared_ptr<DynamicLibraryObject> _currentGraphicLib;

            /**
             * Current game library
             */
            std::shared_ptr<DynamicLibraryObject> _currentGameLib;
    };
}

#endif /* !DLLOADER_HPP_ */
