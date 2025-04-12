# Arcade Project Documentation

## Overview
The Arcade Project is a modular gaming platform that allows dynamic loading of both graphical display libraries and games. This architecture enables users to switch between different graphic libraries or games at runtime without recompilation.

## Table of Contents
- [Core Architecture](#core-architecture)
  - [Library Types](#library-types)
  - [Dynamic Library Manager](#dynamic-library-manager)
  - [Dynamic Library Object](#dynamic-library-object)
- [Creating Graphic Libraries](#creating-graphic-libraries)
  - [Display Module Interface](#display-module-interface)
  - [Required Managers](#required-managers)
    - [Sound Manager](#sound-manager)
    - [Font Manager](#font-manager)
    - [Texture Manager](#texture-manager)
  - [Library Implementation](#library-implementation)
  - [Library Export](#library-export)
- [Creating Game Libraries](#creating-game-libraries)
  - [Game Module Interface](#game-module-interface)

## Core Architecture

### Library Types
The Arcade main header defines the namespace and tools required for development. A fundamental enum defines the library types:

```cpp
enum LibraryType {
    GRAPHIC_LIB, // Graphical dynamic libraries (e.g., SDL, SFML, Ncurses)
    GAME,        // Game dynamic libraries (e.g., Snake, Pacman)
    UNKNOWN      // Unknown library type
};
```

### Dynamic Library Manager
The Dynamic Library Manager builds a list of libraries in the `./lib` folder, creates Dynamic Library Objects, and provides information like library type or finding the next library of a given type.

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
```

### Dynamic Library Object
The Dynamic Library Object represents entities in the `./lib` folder and encapsulates the `dlfcn.h` library functionality:

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
```

## Creating Graphic Libraries

To create a graphic library, you need to implement all required managers. The interfaces are available in the include folder at the project root.

### Display Module Interface

Using Ncurses as an example:

```cpp
namespace arcade {
    /**
     * @class NcursesDisplayModule
     * This class is used to create a window using the ncurses library
     * It inherits from the IDisplayModule interface
     */
    class NcursesDisplayModule : public IDisplayModule {
    public:
        NcursesDisplayModule(const std::string &name = "NCURSES");
        ~NcursesDisplayModule() override;

        void init(const std::string& title, size_t width, size_t height) override;
        void stop() override;
        [[nodiscard]] const std::string &getName() const override { return _name; }
        void setupWindowProperties(WindowProperties &properties) override { _windowProperties = properties; }
        void openWindow() override;
        void closeWindow() override;
        void clearWindow(Color color) override;
        void updateWindow(float delta) override;
        bool isWindowOpen() override { return _isOpen; }
        void drawTexture(std::shared_ptr<ITexture> texture, Vector<float> position) override;
        [[nodiscard]] Keyboard &getKeyboard() override { return _keyboard; }
        [[nodiscard]] Mouse &getMouse() override { return _mouse; }
        [[nodiscard]] WindowProperties& getWindowProperties() override { return _windowProperties; }

        void processEvents();
        void handleEvent(int ch);

    private:
        WindowProperties _windowProperties;
        std::string _name;
        bool _isOpen;
        Keyboard _keyboard;
        Mouse _mouse;
    };
};
```

### Required Managers

#### Sound Manager

```cpp
namespace arcade {
    /**
     * @class NcursesSound
     * This class is used to create a sound using the ncurses library
     */
    class NcursesSound : public ISound {
    public:
        NcursesSound(const SoundInfos& sound) : _soundInformations(sound) {}
        [[nodiscard]] const SoundInfos& getInformations() const override { return _soundInformations; }
    private:
        SoundInfos _soundInformations;
    };

    /**
     * @class NcursesSoundManager
     * This class is used to manage sounds using the ncurses library
     */
    class NcursesSoundManager : public ISoundManager {
    public:
        int load(const std::string& name, const SoundInfos& sound) override;
        [[nodiscard]] std::shared_ptr<ISound> get(const std::string& name) const override;
        void playSound(const std::string& name, float volume) override;
        void stopSound(const std::string& name) override;
    private:
        std::map<std::string, std::shared_ptr<NcursesSound>> _sounds;
    };
}
```

#### Font Manager

```cpp
namespace arcade {
    /**
     * @class NcursesFont
     * This class is used to create a font using the ncurses library
     */
    class NcursesFont : public IFont {
    public:
        NcursesFont(const Font& font) : _fontInformations(font) {}
        [[nodiscard]] const Font& getInformations() const override { return _fontInformations; }
    private:
        Font _fontInformations;
    };

    /**
     * @class NcursesFontManager
     * This class is used to manage fonts using the ncurses library
     */
    class NcursesFontManager : public IFontManager {
    public:
        int load(const std::string& name, Font& font) override;
        std::shared_ptr<IFont> get(const std::string& name) const override;
    private:
        std::map<std::string, std::shared_ptr<NcursesFont>> _fonts;
    };
};
```

#### Texture Manager

```cpp
namespace arcade {
    /**
     * @class NcursesTexture
     * This class is used to create a texture using the ncurses library
     */
    class NcursesTexture : public ITexture {
    public:
        NcursesTexture(const MyTexture &texture);
        [[nodiscard]] const MyTexture& getInformations() const override { return _textureInformations; }
        void set(MyTexture& texture) override {_textureInformations = texture;}
    private:
        MyTexture _textureInformations;
    };

    /**
     * @class NcursesTextureManager
     * This class is used to manage textures using the ncurses library
     */
    class NcursesTextureManager : public ITextureManager {
    public:
        int load(const std::string& name, const MyTexture& newTexture) override;
        [[nodiscard]] std::shared_ptr<ITexture> get(const std::string& name) const override;
    private:
        std::map<std::string, std::shared_ptr<NcursesTexture>> _textures;
    };
};
```

### Library Implementation

```cpp
namespace arcade {
    /**
     * @class NcursesLibrary
     * This class is used to create a library using the ncurses library
     */
    class NcursesLibrary : public IDisplayLibrary {
    public:
        NcursesLibrary();
        virtual ~NcursesLibrary();
        
        IDisplayModule &getDisplay() override { return this->_display; }
        ITextureManager &getTextures() override { return this->_textures; }
        IFontManager &getFonts() override { return this->_fonts; }
        ISoundManager &getSounds() override { return this->_sounds; }

    private:
        NcursesTextureManager _textures;
        NcursesDisplayModule _display;
        NcursesFontManager _fonts;
        NcursesSoundManager _sounds;
    };
}
```

### Library Export

```cpp
extern "C" {
    arcade::IDisplayLibrary* entryPoint() {
        return new arcade::NcursesLibrary;
    }

    arcade::LibType entryPointType() {
        return arcade::LibType::DISPLAY;
    }

    std::string entryPointName() {
        return "NCURSES";
    }
}
```

## Creating Game Libraries

### Game Module Interface

To create a game, you need to implement the `IGameModule` interface:

```cpp
namespace arcade {
    /**
     * Interface for the game module
     */
    class IGameModule {
    public:
        virtual ~IGameModule () = default;
        
        /**
         * Initialize the game module
         * @param displayLib std::shared_ptr<IDisplayLibrary> Display library
         */
        virtual void init(std::shared_ptr<IDisplayLibrary> displayLib) = 0;
        
        /**
         * Stop the game module
         */
        virtual void stop() = 0;
        
        /**
         * update the game module
         * @param delta float Time since the last update
         */
        virtual void update(float delta) = 0;
        
        /**
         * Display the game module
         */
        virtual void display() = 0;
    };
}
```

These functions allow you to create and manage your game holistically, enabling games to adapt to different graphical libraries. Now you have all the tools needed to create your own arcade library and games!
