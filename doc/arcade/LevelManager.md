---
generator: doxide
---


# LevelManager

**class LevelManager**


This class is used to manage levels for the Nibbler game.
It loads levels from a file and provides methods to access them.


## Variables

| Name | Description |
| ---- | ----------- |
| [_levels](#_levels) | Path to the level file  |

## Functions

| Name | Description |
| ---- | ----------- |
| [LevelManager](#LevelManager) | Constructor :material-location-enter: `levelFilePath` :    const std::string & Path to the level file  |
| [getLevel](#getLevel) |  Get a level layout by index :material-location-enter: `level` :    int Level index (1-based) :material-keyboard-return: **Return** :    std::vector<std::string> Level layout as a vector of strings  |
| [getLevelCount](#getLevelCount) | Get the total number of levels :material-keyboard-return: **Return** :    int Number of levels  |
| [loadLevelsFromFile](#loadLevelsFromFile) | Load levels from a file :material-location-enter: `filePath` :    const std::string & Path to the level file  |
| [createDefaultLevel](#createDefaultLevel) | Create a default level as fallback :material-keyboard-return: **Return** :    std::vector<std::string> Default level layout  |

## Variable Details

### _levels<a name="_levels"></a>

!!! variable "std::vector&lt;std::vector&lt;std::string&gt;&gt; _levels"

    Path to the level file
    

## Function Details

### LevelManager<a name="LevelManager"></a>
!!! function "explicit LevelManager(const std::string&amp; levelFilePath = &quot;assets/nibbler/levels.txt&quot;)"

    Constructor
    
    :material-location-enter: `levelFilePath`
    :    const std::string & Path to the level file
    

### createDefaultLevel<a name="createDefaultLevel"></a>
!!! function "std::vector&lt;std::string&gt; createDefaultLevel() const"

    Create a default level as fallback
        
    :material-keyboard-return: **Return**
    :    std::vector<std::string> Default level layout
    

### getLevel<a name="getLevel"></a>
!!! function "std::vector&lt;std::string&gt; getLevel(int level) const"

     Get a level layout by index
        
    :material-location-enter: `level`
    :    int Level index (1-based)
        
    :material-keyboard-return: **Return**
    :    std::vector<std::string> Level layout as a vector of strings
    

### getLevelCount<a name="getLevelCount"></a>
!!! function "int getLevelCount() const"

    Get the total number of levels
        
    :material-keyboard-return: **Return**
    :    int Number of levels
    

### loadLevelsFromFile<a name="loadLevelsFromFile"></a>
!!! function "void loadLevelsFromFile(const std::string&amp; filePath)"

    Load levels from a file
        
    :material-location-enter: `filePath`
    :    const std::string & Path to the level file
    

