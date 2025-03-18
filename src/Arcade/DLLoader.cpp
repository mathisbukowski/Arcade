/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

DLLoader::DLLoader(const std::string &dll_path, int mode)
    : _dllPath(dll_path), _mode(mode), _libHandle(nullptr, &dlclose) {}

DLLoader::~DLLoader()
{
    this->closeLibrary();
}

void DLLoader::closeLibrary()
{
    _libHandle.reset();
}

void DLLoader::openLibrary()
{
    _libHandle.reset(dlopen(_dllPath.c_str(), _mode));
    if (!_libHandle)
        throw std::runtime_error("Failed to open library: " + this->getError());
}

std::string DLLoader::getError()
{
    const char *error = dlerror();
    const std::string errorStr = error ? error : "No Error";

    return errorStr;
}

template <typename FromLib>
FromLib DLLoader::getFunction(const std::string& function_name)
{
    void *function = dlsym(_libHandle.get(), function_name.c_str());
    if (!function)
        throw std::runtime_error("Failed to load function: " + this->getError());
    return reinterpret_cast<FromLib>(function);
}

