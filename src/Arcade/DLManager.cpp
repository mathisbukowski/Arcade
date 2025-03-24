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

arcade::DynamicLibraryManager::DynamicLibraryManager(const std::string& libToLoad)
{
    _currentGameLib = nullptr;
    _currentGraphicLib = nullptr;
    if (!libToLoad.empty())
        this->scanDirectory(libToLoad);
}

arcade::DynamicLibraryManager::~DynamicLibraryManager()
{
    _libraries.clear();
}

void arcade::DynamicLibraryManager::scanDirectory(const std::string& libToLoad)
{
    std::filesystem::path lib(libToLoad);
    std::filesystem::path dirToLoad = lib.parent_path();

    if (!std::filesystem::exists(dirToLoad) || !std::filesystem::is_directory(dirToLoad)) {
        std::cerr << "Error: Directory " << dirToLoad << " does not exist or is not accessible." << std::endl;
        return;
    }
    for (const auto& entry : std::filesystem::directory_iterator(dirToLoad)) {
        if (entry.path().extension() == ".so") {
            auto newLib = std::make_shared<DynamicLibraryObject>(entry.path().string());
            if (!newLib) {
                std::cerr << "Error: Failed to load library " << entry.path().string() << std::endl;
                continue;
            }
            _libraries.emplace(entry.path().string(), newLib);
            auto newType = newLib->getType();
            if (entry.path().string() == libToLoad) {
                if (newType == GAME)
                    this->setCurrentGameLib(newLib);
                else if (newType == DISPLAY)
                    this->setCurrentGraphicLib(newLib);
                else
                    std::cerr << "Warning: Unknown library type for " << entry.path().string() << std::endl;
            }
        }
    }
}

void arcade::DynamicLibraryManager::loadLibrary(const std::string& name)
{
    (void)name;
}

std::map<std::string, std::shared_ptr<arcade::DynamicLibraryObject>> arcade::DynamicLibraryManager::getAllLibrariesByType(LibType type) const
{
    std::map<std::string, std::shared_ptr<DynamicLibraryObject>> filteredLibraries;

    std::copy_if(_libraries.begin(), _libraries.end(), std::inserter(filteredLibraries, filteredLibraries.end()),
        [type](const auto& library) { return library.second->getType() == type; });

    return filteredLibraries;
}


void arcade::DynamicLibraryManager::setCurrentGameLib(const std::shared_ptr<DynamicLibraryObject>& current_game_lib) {
    _currentGameLib = current_game_lib;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::getCurrentGameLib() const {
    return _currentGameLib;
}

void arcade::DynamicLibraryManager::setCurrentGraphicLib(const std::shared_ptr<DynamicLibraryObject>& current_graphic_lib) {
    _currentGraphicLib = current_graphic_lib;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::getCurrentGraphicLib() const {
    return _currentGraphicLib;
}