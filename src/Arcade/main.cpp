/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** main
*/


#include "DLManager.hpp"
#include "DLObject.hpp"
#include <filesystem>
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << "./lib/lib.so" << std::endl;
        return 1;
    }

    std::filesystem::path libPath = std::filesystem::current_path() / av[1];
    if (!std::filesystem::exists(libPath)) {
        std::cerr << "Library not found: " << libPath << std::endl;
        return 1;
    }
    try {
        arcade::DynamicLibraryManager manager("../lib", true);


        const auto& libraries = manager.getAllLibraries();
        std::cout << "Loaded libraries:" << std::endl;
        for (const auto& lib : libraries) {
            std::cout << "- " << lib->getName() << " (Type: " << static_cast<int>(lib->getType()) << ")" << std::endl;
            auto foundLibrary = manager.findLibrary(lib->getName());
            if (foundLibrary) {
                std::cout << "Found library: " << foundLibrary->getName() << std::endl;
                auto func = foundLibrary->getFunction<void(*)()>("entryPoint");
                auto type = foundLibrary->getFunction<arcade::LibraryType(*)()>("entryPointType");
                std::cout << "Type: " << static_cast<int>(type()) << std::endl;
                auto name = foundLibrary->getFunction<std::string(*)()>("entryPointName");
                std::cout << "Name: " << name() << std::endl;
                func();
            } else {
                std::cout << "Library not found: " << lib->getName() << std::endl;
            }
        }
    
        auto nextGameLibrary = manager.getNextLibrary(arcade::LibType::GAME);
        if (nextGameLibrary) {
            std::cout << "Next game library: " << nextGameLibrary->getName() << std::endl;
        } else {
            std::cout << "No game libraries available." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
