/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** DLLoader
*/

#include "DLManager.hpp"
#include <filesystem>
#include <algorithm>
#include <iostream>

arcade::DynamicLibraryManager::DynamicLibraryManager(const std::string& directory, bool loadImmediately)
{
    if (!directory.empty()) {
        scanDirectory(directory, loadImmediately);
    }
}

int arcade::DynamicLibraryManager::scanDirectory(const std::string& directory, bool loadDiscovered)
{
    int count = 0;

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            if (loadDiscovered) {
                try {
                    loadLibrary(entry.path().string(), determineLibraryType(entry.path().string()));
                } catch (const std::exception& e) {
                    std::cerr << "Failed to load library: " << entry.path().string() << " (" << e.what() << ")" << std::endl;
                }
            }
            count++;
        }
    }

    return count;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::loadLibrary(const std::string& path, LibraryType type)
{
    auto library = std::make_shared<DynamicLibraryObject>(path, type);
    _libraries.push_back(library);
    return library;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::findLibrary(const std::string& name) const
{
    auto it = std::find_if(_libraries.begin(), _libraries.end(),
        [&name](const std::shared_ptr<DynamicLibraryObject>& lib) {
            return lib->getName() == name;
        });

    return (it != _libraries.end()) ? *it : nullptr;
}

std::vector<std::shared_ptr<arcade::DynamicLibraryObject>> arcade::DynamicLibraryManager::getLibrariesByType(LibraryType type) const
{
    std::vector<std::shared_ptr<DynamicLibraryObject>> result;

    for (const auto& lib : _libraries) {
        if (lib->getType() == type) {
            result.push_back(lib);
        }
    }

    return result;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::getNextLibrary(LibraryType type)
{
    auto& index = _typeIndices[type];
    auto libraries = getLibrariesByType(type);

    if (libraries.empty())
        return nullptr;

    auto library = libraries[index];
    index = (index + 1) % libraries.size();
    return library;
}

arcade::LibraryType arcade::DynamicLibraryManager::determineLibraryType(const std::string& path)
{
    if (path.find("game") != std::string::npos)
        return LibraryType::GAME;
    if (path.find("lib") != std::string::npos)
        return LibraryType::GRAPHIC_LIB;
    return LibraryType::UNKNOWN;
}

std::string arcade::DynamicLibraryManager::extractNameFromPath(const std::string& path) const
{
    size_t lastSlash = path.find_last_of('/');
    size_t lastDot = path.find_last_of('.');
    if (lastDot == std::string::npos || lastDot <= lastSlash)
        return path.substr(lastSlash + 1);
    return path.substr(lastSlash + 1, lastDot - lastSlash - 1);
}
    
