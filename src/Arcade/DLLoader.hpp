/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
    #define DLLOADER_HPP_

/**
 * @brief Class to load dynamic libraries & encapsulate them
 */

#include <dlfcn.h> -> dlclose, dlopen, dlsym, dlerror
#include <string>
#include <memory>
#include <stdexcept>


/**
 * @class DLLoader
 * @brief Class for loading dynamic libraries in C++.
 */
class DLLoader {
    public:
        /**
         * @brief Constructor for DLLoader.
         * @param dll_path Path to the dynamic library.
         * @param mode Mode for opening the library (RTLD_LAZY, etc.).
         */
        DLLoader(const std::string &dll_path, int mode);

        /**
         * @brief Destructor for DLLoader.
         */
        ~DLLoader();

        /**
         * @brief Opens the dynamic library.
         * @throws std::runtime_error if the library cannot be opened.
         */
        void openLibrary();

        /**
         * @brief Closes the dynamic library.
         */
        void closeLibrary();

        /**
         * @brief Retrieves a function from the library.
         * @tparam FromLib The function type (e.g., `int(*)(float)`).
         * @param function_name Name of the function.
         * @return A function pointer of type FromLib.
         * @throws std::runtime_error if the function is not found.
        */
        template <typename FromLib>
        FromLib getFunction(const std::string &function_name);

        /**
        * @brief Gets the last error message.
        * @return The error message as a string.
        */
        std::string getError();

    protected:
    private:
        /**
         * @brief Path to the dynamic library.
         */
        std::string _dllPath;
        /**
         * @brief Mode for opening the library.
         */
        int _mode;
        /**
         * @brief Handle to the dynamic library.
         */
        std::unique_ptr<void, decltype(&dlclose)> _libHandle;
};

#endif /* !DLLOADER_HPP_ */
