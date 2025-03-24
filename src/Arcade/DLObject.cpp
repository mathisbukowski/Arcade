/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** 03
*/

#include "DLObject.hpp"
#include <iostream>


arcade::DynamicLibraryObject::DynamicLibraryObject(const std::string& path)
    : _handle(nullptr, &dlclose)
{
    _handle.reset(dlopen(path.c_str(), RTLD_LAZY));

    if (!_handle) {
        std::cerr << "Error loading library: " << path << " -> " << dlerror() << std::endl;
        throw std::runtime_error("Failed to load library: " + path);
    }
    try {
        LibType detectedType = this->getEntryPointType();
        if (detectedType != UNKNOWN) {
            _type = detectedType;
        }
        std::string detectedName = this->getEntryPointName();
        if (!detectedName.empty() && detectedName != path) {
            _name = detectedName;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in library initialization: " << e.what() << " (" << path << ")" << std::endl;
    }
}

arcade::DynamicLibraryObject::~DynamicLibraryObject()
{
}

std::string arcade::DynamicLibraryObject::getName() const
{
    return _name;
}

arcade::LibType arcade::DynamicLibraryObject::getType() const
{
    return _type;
}

arcade::LibType arcade::DynamicLibraryObject::getEntryPointType() const
{
    using EntryPointTypeFunc = LibType (*)();

    dlerror();
    void* symbol = dlsym(_handle.get(), "entryPointType");
    const char* error = dlerror();

    if (error || !symbol) {
        std::cerr << "Warning: entryPointType not found in library. Using default type." << std::endl;
        return _type;
    }

    auto entryPointFunc = reinterpret_cast<EntryPointTypeFunc>(symbol);
    return entryPointFunc();
}

std::string arcade::DynamicLibraryObject::getEntryPointName()
{
    using EntryPointNameFunc = const char* (*)();

    dlerror();
    void* symbol = dlsym(_handle.get(), "entryPointName");
    const char* error = dlerror();

    if (error || !symbol) {
        std::cerr << "Warning: entryPointName not found in library. Using default name." << std::endl;
        return _name;
    }

    auto entryPointFunc = reinterpret_cast<EntryPointNameFunc>(symbol);
    return std::string(entryPointFunc());
}
