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
    try {
            LibraryType detectedType = getEntryPointType();
            if (detectedType != LibraryType::UNKNOWN) {
                _type = detectedType;
            }
                        std::string detectedName = getEntryPointName();
            if (!detectedName.empty() && detectedName != path) {
                _name = detectedName;
            }
        } catch (const std::exception&) {
        }
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

arcade::LibraryType arcade::DynamicLibraryObject::getEntryPointType() const
{
    using EntryPointTypeFunc = LibraryType (*)();

    dlerror();

    void* symbol = dlsym(_handle.get(), "entryPointType");
    const char* error = dlerror();

    if (error || !symbol)
        return _type;
    auto entryPointFunc = reinterpret_cast<EntryPointTypeFunc>(symbol);
    return entryPointFunc();
}

std::string arcade::DynamicLibraryObject::getEntryPointName()
{
    using EntryPointNameFunc = std::string (*)();

    dlerror();

    void* symbol = dlsym(_handle.get(), "entryPointName");
    const char* error = dlerror();

    if (error || !symbol)
        return _name;
    auto entryPointFunc = reinterpret_cast<EntryPointNameFunc>(symbol);
    return entryPointFunc();
}
