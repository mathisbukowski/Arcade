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

    std::string libName = av[1];
    try {
        arcade::DynamicLibraryManager manager(libName);

        std::shared_ptr<arcade::DynamicLibraryObject> coucou = manager.getCurrentGraphicLib();

        std::cout << coucou->getName() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
