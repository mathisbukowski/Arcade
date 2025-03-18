/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** 03
*/

#include "DLObject.hpp"


arcade::DynamicLibraryObject::DynamicLibraryObject(const std::string& path, LibraryType type)
    : _handle(nullptr, &dlclose), _name(path), _type(type)
{
    _handle.reset(dlopen(path.c_str(), RTLD_LAZY));
    if (!_handle)
        throw std::runtime_error("Failed to load library: " + path);
}

arcade::DynamicLibraryObject::~DynamicLibraryObject()
{
    if (_handle)
        dlclose(_handle.get());
}

std::string arcade::DynamicLibraryObject::getName() const
{
    return _name;
}

arcade::LibraryType arcade::DynamicLibraryObject::getType() const
{
    return _type;
}