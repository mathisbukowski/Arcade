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
            DynamicLibraryManager(const std::string& directory = "./lib", bool loadImmediately = false);
    
            /**
             * Scan a directory for libraries
             * @param directory Directory path
             * @param loadDiscovered Whether to load discovered libraries
             * @return Number of libraries found
             */
            int scanDirectory(const std::string& directory, bool loadDiscovered = true);
    
            /**
             * Load a specific library
             * @param path Path to the library
             * @param type Type of the library
             * @return Shared pointer to the loaded library
             */
            std::shared_ptr<DynamicLibraryObject> loadLibrary(const std::string& path, LibraryType type = LibraryType::UNKNOWN);
    
            /**
             * Find a library by name
             * @param name Name of the library
             * @return Shared pointer to the library if found, nullptr otherwise
             */
            std::shared_ptr<DynamicLibraryObject> findLibrary(const std::string& name) const;
    
            /**
             * Get all libraries of a specific type
             * @param type Type of libraries to retrieve
             * @return Vector of libraries of the specified type
             */
            std::vector<std::shared_ptr<DynamicLibraryObject>> getLibrariesByType(LibraryType type) const;
    
            /**
             * Get all loaded libraries
             * @return Vector of all loaded libraries
             */
            const std::vector<std::shared_ptr<DynamicLibraryObject>>& getAllLibraries() const {
                return _libraries;
            }
    
            /**
             * Get the next library of a specific type
             * @param type Type of library to get
             * @return Next library of specified type
             */
            std::shared_ptr<DynamicLibraryObject> getNextLibrary(LibraryType type);
    
        private:
            /**
             * Determine library type from filename or content
             * @param path Path to the library
             * @return Determined library type
             */
            LibraryType determineLibraryType(const std::string& path);
    
            /**
             * Extract name from path
             * @param path File path
             * @return Filename without path and extension
             */
            std::string extractNameFromPath(const std::string& path) const;
    
        private:

            /**
             * Loaded libraries
             */
            std::vector<std::shared_ptr<DynamicLibraryObject>> _libraries;
            
            /**
             * Type indices
             */
            std::map<LibraryType, size_t> _typeIndices;
    };
}

#endif /* !DLLOADER_HPP_ */
