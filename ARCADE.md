# Arcade Documentation

## Table of Contents
- [Library Type](#library-type)
- [Dynamic Library Manager](#dynamic-library-manager)
- [Dynamic Library Object](#dynamic-library-object)
- [Vector Class](#vector-class)


## Library Type
The Arcade Main header is where we find out the namespace and all tools who are required for the development of Arcade Project.
We find in it the `enum` for the `LibraryType` : 
```cpp
    enum  LibraryType {
        GRAPHIC_LIB, // When it is a graphical dynamic lib like Sdl
        GAME, // When it is a game dynamic lib like Snake
        UNKNOWN // When we don't know
    };
```

## Dynamic Library Manager
The Dynamic Library Manager is the class in which we build our list of libraries present in the `./lib` folder. 
It then allows us to create Dynamic Library Objects.
 Finally, it provides functions to give us information such as the type of library or the next library according to its type. 
```cpp
        /**
         * @brief Constructor
         * @param directory Directory to search for libraries
         * @param loadImmediately Whether to load libraries immediately
         */
        DynamicLibraryManager(const std::string& directory = "./lib", bool loadImmediately = false);

        /**
         * @brief Scan a directory for libraries
         * @param directory Directory path
         * @param loadDiscovered Whether to load discovered libraries
         * @return Number of libraries found
         */
        int scanDirectory(const std::string& directory, bool loadDiscovered = true);

        /**
         * @brief Load a specific library
         * @param path Path to the library
         * @param type Type of the library
         * @return Shared pointer to the loaded library
         */
        std::shared_ptr<DynamicLibraryObject> loadLibrary(const std::string& path, LibraryType type = LibraryType::UNKNOWN);

        /**
         * @brief Find a library by name
         * @param name Name of the library
         * @return Shared pointer to the library if found, nullptr otherwise
         */
        std::shared_ptr<DynamicLibraryObject> findLibrary(const std::string& name) const;

        /**
         * @brief Get all libraries of a specific type
         * @param type Type of libraries to retrieve
         * @return Vector of libraries of the specified type
         */
        std::vector<std::shared_ptr<DynamicLibraryObject>> getLibrariesByType(LibraryType type) const;
        /**
         * @brief Get all loaded libraries
         * @return Vector of all loaded libraries
         */
        const std::vector<std::shared_ptr<DynamicLibraryObject>>& getAllLibraries() const { return _libraries;}
        /**
         * @brief Get the next library of a specific type
         * @param type Type of library to get
         * @return Next library of specified type
         */
        std::shared_ptr<DynamicLibraryObject> getNextLibrary(LibraryType type);
        /**
         * @brief Determine library type from filename or content
         * @param path Path to the library
         * @return Determined library type
         */
        LibraryType determineLibraryType(const std::string& path);
        /**
         * @brief Extract name from path
         * @param path File path
         * @return Filename without path and extension
         */
        std::string extractNameFromPath(const std::string& path) const;
        /**
         * @brief Loaded libraries
         */
        std::vector<std::shared_ptr<DynamicLibraryObject>> _libraries;
        /**
         * @brief Type indices
         */
        std::map<LibraryType, size_t> _typeIndices;
```

## Dynamic Library Object
The Dynamic Library Object is the "subclass" of DLManager. That represents all entities in `./lib` folder. And this is here, we encapsulate the `dlfcn.h` library.

```cpp
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
```

## Vector Class

The `Vector` class is a template class designed to represent 2D vectors. It provides a set of operations and methods to manipulate vectors, making it a versatile tool for various calculations in the Arcade project, such as movement, collision detection, or graphical transformations.

### Features
- **Template Support**: The class supports any numeric type (e.g., `int`, `float`, `double`) through templates.
- **Basic Operations**: Includes addition, subtraction, multiplication, and division of vectors.
- **Comparison Operators**: Allows comparison of vectors using equality, inequality, and relational operators.
- **Getter and Setter Methods**: Provides access to and modification of the `x` and `y` components.

### Example Usage
```cpp
#include "Vector.hpp"
#include <iostream>

int main() {
    Vector<int> v1(3, 4);
    Vector<int> v2(1, 2);

    // Vector addition
    Vector<int> result = v1 + v2;

    // Accessing components
    std::cout << "Result: (" << result.getX() << ", " << result.getY() << ")" << std::endl;

    // Comparison
    if (v1 != v2) {
        std::cout << "Vectors are not equal." << std::endl;
    }

    return 0;
}
```

### Operator Overloads

The `Vector` class supports a variety of operator overloads to simplify vector operations. Below is a table summarizing the available operators and their functionality:

| **Operator**      | **Description**                                      | **Return Type**          |
|--------------------|------------------------------------------------------|--------------------------|
| `+`               | Adds two vectors component-wise                      | `Vector<T>`             |
| `-`               | Subtracts two vectors component-wise                 | `Vector<T>`             |
| `*`               | Multiplies two vectors component-wise                | `Vector<T>`             |
| `/`               | Divides two vectors component-wise                   | `Vector<T>`             |
| `==`              | Checks if two vectors are equal                      | `bool`                  |
| `!=`              | Checks if two vectors are not equal                  | `bool`                  |
| `<`               | Checks if one vector is less than another (both components) | `bool`          |
| `>`               | Checks if one vector is greater than another (both components) | `bool`          |
| `<=`              | Checks if one vector is less than or equal to another (both components) | `bool` |
| `>=`              | Checks if one vector is greater than or equal to another (both components) | `bool` |
| `+=`              | Adds another vector to the current vector            | `Vector<T>&`            |
| `-=`              | Subtracts another vector from the current vector     | `Vector<T>&`            |

### Notes
- All arithmetic operators (`+`, `-`, `*`, `/`) perform operations component-wise.
- Comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`) compare the `x` and `y` components of the vectors.
- Compound assignment operators (`+=`, `-=`) modify the current vector in place.