---
generator: doxide
---


# DynamicLibraryManager

**class DynamicLibraryManager**



## Variables

| Name | Description |
| ---- | ----------- |
| [_libraries](#_libraries) | Loaded libraries  |

## Functions

| Name | Description |
| ---- | ----------- |
| [DynamicLibraryManager](#DynamicLibraryManager) | Constructor :material-location-enter: `directory` :    Directory to search for libraries :material-location-enter: `loadImmediately` :    Whether to load libraries immediately  |
| [~DynamicLibraryManager](#_u007eDynamicLibraryManager) | Destructor  |
| [scanDirectory](#scanDirectory) | Scan a directory for libraries :material-location-enter: `directory` :    Directory path :material-location-enter: `loadDiscovered` :    Whether to load discovered librariesx  |
| [getAllLibraries](#getAllLibraries) | Get all loaded libraries :material-keyboard-return: **Return** :    _libraries  |
| [getAllLibrariesByType](#getAllLibrariesByType) | Get all libraries of a specific type :material-keyboard-return: **Return** :    std::map<std::string, std::shared_ptr<DynamicLibraryObject>>  |
| [getCurrentGraphicLib](#getCurrentGraphicLib) | Get current graphic library :material-keyboard-return: **Return** :    std::shared_ptr<DynamicLibraryObject>  |
| [setCurrentGraphicLib](#setCurrentGraphicLib) | Set current graphic library :material-location-enter: `current_graphic_lib` :    New graphic library  |
| [getCurrentGameLib](#getCurrentGameLib) | Get current game library :material-keyboard-return: **Return** :    std::shared_ptr<DynamicLibraryObject>  |
| [setCurrentGameLib](#setCurrentGameLib) | Set current game library :material-location-enter: `current_game_lib` :    New game library  |
| [initGameLib](#initGameLib) | Initialize the game library  |
| [setNextGame](#setNextGame) | Set next game library  |
| [setNextGraphicLib](#setNextGraphicLib) | Set next graphic library  |

## Variable Details

### _libraries<a name="_libraries"></a>

!!! variable "std::map&lt;std::string, std::shared_ptr&lt;DynamicLibraryObject&gt;&gt; _libraries"

    Loaded libraries
    

## Function Details

### DynamicLibraryManager<a name="DynamicLibraryManager"></a>
!!! function "DynamicLibraryManager(const std::string&amp; libToLoad)"

    Constructor
    
    :material-location-enter: `directory`
    :    Directory to search for libraries
        
    :material-location-enter: `loadImmediately`
    :    Whether to load libraries immediately
    

### getAllLibraries<a name="getAllLibraries"></a>
!!! function "[[nodiscard]] std::map&lt;std::string, std::shared_ptr&lt;DynamicLibraryObject&gt;&gt; getAllLibraries() const"

    Get all loaded libraries
        
    :material-keyboard-return: **Return**
    :    _libraries
    

### getAllLibrariesByType<a name="getAllLibrariesByType"></a>
!!! function "[[nodiscard]] std::map&lt;std::string, std::shared_ptr&lt;DynamicLibraryObject&gt;&gt; getAllLibrariesByType(LibType type) const"

    Get all libraries of a specific type
        
    :material-keyboard-return: **Return**
    :    std::map<std::string, std::shared_ptr<DynamicLibraryObject>>
    

### getCurrentGameLib<a name="getCurrentGameLib"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;DynamicLibraryObject&gt; getCurrentGameLib() const"

    Get current game library
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<DynamicLibraryObject>
    

### getCurrentGraphicLib<a name="getCurrentGraphicLib"></a>
!!! function "[[nodiscard]] std::shared_ptr&lt;DynamicLibraryObject&gt; getCurrentGraphicLib() const"

    Get current graphic library
        
    :material-keyboard-return: **Return**
    :    std::shared_ptr<DynamicLibraryObject>
    

### initGameLib<a name="initGameLib"></a>
!!! function "void initGameLib()"

    Initialize the game library
    

### scanDirectory<a name="scanDirectory"></a>
!!! function "void scanDirectory(const std::string&amp; libToLoad)"

    Scan a directory for libraries
        
    :material-location-enter: `directory`
    :    Directory path
        
    :material-location-enter: `loadDiscovered`
    :    Whether to load discovered librariesx
    

### setCurrentGameLib<a name="setCurrentGameLib"></a>
!!! function "void setCurrentGameLib(const std::shared_ptr&lt;DynamicLibraryObject&gt;&amp; current_game_lib)"

    Set current game library
        
    :material-location-enter: `current_game_lib`
    :    New game library
    

### setCurrentGraphicLib<a name="setCurrentGraphicLib"></a>
!!! function "void setCurrentGraphicLib(const std::shared_ptr&lt;DynamicLibraryObject&gt;&amp; current_graphic_lib)"

    Set current graphic library
        
    :material-location-enter: `current_graphic_lib`
    :    New graphic library
    

### setNextGame<a name="setNextGame"></a>
!!! function "void setNextGame()"

    Set next game library
    

### setNextGraphicLib<a name="setNextGraphicLib"></a>
!!! function "void setNextGraphicLib()"

    Set next graphic library
    

### ~DynamicLibraryManager<a name="_u007eDynamicLibraryManager"></a>
!!! function "~DynamicLibraryManager()"

    Destructor
    

