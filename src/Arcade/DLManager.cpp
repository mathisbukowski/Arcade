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
    if (!directory.empty())
        scanDirectory(directory, loadImmediately);
}

arcade::DynamicLibraryManager::~DynamicLibraryManager()
{
    _libraries.clear();
}

void arcade::DynamicLibraryManager::scanDirectory(const std::string& directory, bool loadDiscovered)
{
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            if (loadDiscovered) {
                try {
                    auto newLibrary = std::make_shared<DynamicLibraryObject>(entry.path().string());
                    auto newLibName = newLibrary->getName();
                    std::cout << newLibrary->getType() << std::endl;
                    if (!_libraries.contains(newLibName))
                        _libraries.emplace(entry.path().string(), newLibrary);
                } catch (const std::exception& e) {
                    std::cerr << "Failed to load library: " << entry.path().string() << " (" << e.what() << ")" << std::endl;
                }
            }
        }
    }
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::loadLibrary(const std::string& name) const
{
    auto libraryToLoad = _libraries.find(name);
    if (libraryToLoad == _libraries.end())
        return nullptr;
    return libraryToLoad->second;
}

std::map<std::string, std::shared_ptr<arcade::DynamicLibraryObject>> arcade::DynamicLibraryManager::getAllLibrariesByType(LibType type) const
{
    std::map<std::string, std::shared_ptr<DynamicLibraryObject>> filteredLibraries;

    for (const auto& library : _libraries) {
        if (library.second->getType() == type)
            filteredLibraries.emplace(library.first, library.second);
    }
    return filteredLibraries;
}

void arcade::DynamicLibraryManager::setNextGameLib(LibType type)
{
    auto currentLib = std::find_if(_libraries.begin(), _libraries.end(), [this](const auto& lib) {
        return lib.second == getCurrentGameLib();
    });
    if (currentLib == _libraries.end())
        return;
    auto nextLib = std::find_if(currentLib, _libraries.end(), [type](const auto& lib) {
        return lib.second->getType() == type;
    });
    if (nextLib == _libraries.end())
        return;
    this->setCurrentGameLib(nextLib->second);
}

void arcade::DynamicLibraryManager::setNextGraphicLib(LibType type)
{
    auto currentLib = std::find_if(_libraries.begin(), _libraries.end(), [this](const auto& lib) {
        return lib.second == getCurrentGraphicLib();
    });
    if (currentLib == _libraries.end())
        return;
    auto nextLib = std::find_if(currentLib, _libraries.end(), [type](const auto& lib) {
        return lib.second->getType() == type;
    });
    if (nextLib == _libraries.end())
        return;
    this->setCurrentGraphicLib(nextLib->second);
}
