/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** main
*/

#include "Core.hpp"
#include <iostream>
#include <filesystem>
#include <exception>

int main(int ac, char **av) {
    if (ac != 2 || av[1] == nullptr) {
        std::cerr << "Usage: " << av[0] << " ./lib/lib.so" << std::endl;
        return 84;
    }

    std::string libName = av[1];
    std::filesystem::path lib = std::filesystem::current_path() / libName;

    if (!std::filesystem::exists(lib)) {
        std::cerr << "Error: " << libName << " does not exist" << std::endl;
        return 84;
    }

    try {
        arcade::Core core(libName);
        core.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }

    return 0;
}
