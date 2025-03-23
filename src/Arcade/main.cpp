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
        arcade::DynamicLibraryManager manager("./lib", true);

        auto usedLib = manager.loadLibrary(av[1]);

        std::cout << "Library name: " << usedLib->getName() << std::endl;
        std::cout << "Library type: " << usedLib->getType() << std::endl;
        manager.setNextGraphicLib(usedLib->getType());
        auto nextLib = manager.getCurrentGraphicLib();
        if (nextLib) {
            std::cout << "Next library: " << nextLib->getName() << std::endl;
        }
        else
            std::cout << "No next library" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
