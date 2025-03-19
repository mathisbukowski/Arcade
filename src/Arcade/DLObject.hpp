/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** 03
*/

#ifndef DLOBJECT_HPP
#define DLOBJECT_HPP

#include <string>
#include "Arcade.hpp"
#include <dlfcn.h>


/**
 * @brief Class to load dynamic libraries & encapsulate them
 */

namespace arcade {
    class DynamicLibraryObject {
    public:
        /**
         * @brief Constructor
         * @param path Path to the library
         * @param type Type of the library
         */
        DynamicLibraryObject(const std::string& path, LibraryType type);

        /**
         * @brief Destructor
         */
        ~DynamicLibraryObject();

        /**
         * @brief Get a function from the library
         * @tparam FuncType Type of the function
         * @param symbolName Name of the symbol
         * @return Function pointer
         */
        template <typename FuncType>
        FuncType getFunction(const std::string& symbolName) {
            void* symbol = dlsym(_handle.get(), symbolName.c_str());
            if (!symbol) {
                throw std::runtime_error("Failed to load symbol: " + symbolName);
            }
            return reinterpret_cast<FuncType>(symbol);
        }

        /**
         * @brief Get the name of the library
         * @return Name of the library
         */
        std::string getName() const;

        /**
         * @brief Get the type of the library
         * @return Type of the library
         */
        LibraryType getType() const;

        /**
         * @brief Get the library type from entryPointType function
         * @return Library type from entryPointType or the default type if the function doesn't exist
         */
        LibraryType getEntryPointType() const;

        /**
         * @brief Get the library name from entryPointName function
         * @return Library name from entryPointName or the default name if the function doesn't exist
         */
        std::string getEntryPointName();

    private:

        /**
         * @brief Handle to the library
         * @note The handle is automatically closed when the object is destroyed
         */
        std::unique_ptr<void, int(*)(void*)> _handle;

        /**
         * @brief Name of the library
         */
        std::string _name;

        /**
         * @brief Type of the library
         */
        LibraryType _type;
    };
}

#endif //DLOBJECT_HPP
