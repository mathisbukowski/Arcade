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
#include <stdexcept>
#include <map>
#include <vector>
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
             * @param directory Directory to search for libraries
             * @param loadImmediately Whether to load libraries immediately
             */
            DynamicLibraryManager(const std::string& libToLoad);

            /**
             * Destructor
             */
            ~DynamicLibraryManager();
            /**
             * Scan a directory for libraries
             * @param directory Directory path
             * @param loadDiscovered Whether to load discovered librariesx
             */
            void scanDirectory(const std::string& libToLoad);

            /**
             * Load a specific library
             * @param path Path to the library
             * @param type Type of the library
             * @return Shared pointer to the loaded library
             */
            void loadLibrary(const std::string& name);

            [[nodiscard]] std::map<std::string, std::shared_ptr<DynamicLibraryObject>> getAllLibraries() const { return _libraries; }

            [[nodiscard]] std::map<std::string, std::shared_ptr<DynamicLibraryObject>> getAllLibrariesByType(LibType type) const;

            [[nodiscard]] std::shared_ptr<DynamicLibraryObject> getCurrentGraphicLib() const;

            void setCurrentGraphicLib(const std::shared_ptr<DynamicLibraryObject>& current_graphic_lib);

            [[nodiscard]] std::shared_ptr<DynamicLibraryObject> getCurrentGameLib() const;

            void setCurrentGameLib(const std::shared_ptr<DynamicLibraryObject>& current_game_lib);
        private:

            /**
             * Loaded libraries
             */
            std::map<std::string, std::shared_ptr<DynamicLibraryObject>> _libraries;

            std::shared_ptr<DynamicLibraryObject> _currentGraphicLib;

            std::shared_ptr<DynamicLibraryObject> _currentGameLib;
    };
}

#endif /* !DLLOADER_HPP_ */
