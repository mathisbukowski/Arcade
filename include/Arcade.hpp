/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

/**
 * @namespace arcade
 * Namespace containing classes and types related to the Arcade project.
 */
namespace arcade {
    /**
     * @enum LibraryType
     * Represents the types of dynamic libraries.
     */
    enum class LibraryType {
        GAME, /**< Game library */
        DISPLAY, /**< Graphic library */
        UNKNOWN /**< Unknown type */
    };
    class DynamicLibraryObject;
    class DynamicLibraryManager;
}

#endif /* !ARCADE_HPP_ */