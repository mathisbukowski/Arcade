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
#include <random>
#include <ctime>

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

    if (!std::filesystem::exists(dirToLoad) || !std::filesystem::is_directory(dirToLoad))
        throw std::runtime_error("No such directory: " + dirToLoad.string());

    std::shared_ptr<DynamicLibraryObject> requestedLib = nullptr;

    for (const auto& entry : std::filesystem::directory_iterator(dirToLoad)) {
        if (entry.path().extension() == ".so") {
            try {
                auto newLib = std::make_shared<DynamicLibraryObject>(entry.path().string());
                if (!newLib) {
                    std::cout << "Error: Failed to load library " << entry.path().string() << std::endl;
                    continue;
                }

                _libraries.emplace(entry.path().string(), newLib);

                if (entry.path().string() == libToLoad) {
                    requestedLib = newLib;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error loading library " << entry.path().string() << ": " << e.what() << std::endl;
            }
        }
    }
    if (requestedLib) {
        auto type = requestedLib->getType();
        if (type == GAME) {
            throw std::runtime_error("'" + libToLoad + "' not a graphical library");
        } else if (type == DISPLAY) {
            setCurrentGraphicLib(requestedLib);
            std::cout << "Set current graphic library to: " << requestedLib->getName() << std::endl;
        } else {
            throw std::runtime_error("'" + libToLoad + "' has unknown type");
        }
    } else {
        throw std::runtime_error("Failed to load requested library: " + libToLoad);
    }
}

void arcade::DynamicLibraryManager::initGameLib()
{
    auto gameLibs = getAllLibrariesByType(GAME);
    if (gameLibs.empty()) {
        throw std::runtime_error("No game libraries found");
    }
    std::srand(std::time(nullptr));
    int randomIndex = std::rand() % gameLibs.size();
    auto it = std::next(gameLibs.begin(), randomIndex);
    setCurrentGameLib(it->second);
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
    if (!_currentGameLib)
        std::cerr << "Warning: Current game library is null" << std::endl;
    return _currentGameLib;
}

void arcade::DynamicLibraryManager::setCurrentGraphicLib(const std::shared_ptr<DynamicLibraryObject>& current_graphic_lib) {
    _currentGraphicLib = current_graphic_lib;
}

std::shared_ptr<arcade::DynamicLibraryObject> arcade::DynamicLibraryManager::getCurrentGraphicLib() const {
    if (!_currentGraphicLib)
        std::cerr << "Warning: Current graphic library is null" << std::endl;
    return _currentGraphicLib;
}

void arcade::DynamicLibraryManager::setNextGraphicLib()
{
    auto graphicLibs = getAllLibrariesByType(DISPLAY);
    if (graphicLibs.empty())
        throw std::runtime_error("No graphic libraries found");
    auto currentLib = getCurrentGraphicLib();
    auto it = graphicLibs.find(currentLib->getName());
    if (it == graphicLibs.end()) {
        setCurrentGraphicLib(graphicLibs.begin()->second);
    } else {
        it++;
        if (it == graphicLibs.end()) {
            setCurrentGraphicLib(graphicLibs.begin()->second);
        } else {
            setCurrentGraphicLib(it->second);
        }
    }
}

void arcade::DynamicLibraryManager::setNextGame()
{
    auto graphicLibs = getAllLibrariesByType(GAME);
    if (graphicLibs.empty())
        throw std::runtime_error("No graphic libraries found");
    auto currentLib = getCurrentGameLib();
    auto it = graphicLibs.find(currentLib->getName());
    if (it == graphicLibs.end()) {
        setCurrentGameLib(graphicLibs.begin()->second);
    } else {
        it++;
        if (it == graphicLibs.end()) {
            setCurrentGameLib(graphicLibs.begin()->second);
        } else {
            setCurrentGameLib(it->second);
        }
    }
}
