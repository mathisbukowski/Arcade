---
generator: doxide
---


# LevelManager

**class LevelManager**



## Functions

| Name | Description |
| ---- | ----------- |
| [LevelManager](#LevelManager) | @brief Constructor :material-location-enter: `levelFilePath` :    Path to the level file  |
| [getLevel](#getLevel) | @brief Get a level layout by index :material-location-enter: `level` :    Level index (1-based) :material-keyboard-return: **Return** :    Level layout as a vector of strings  |
| [getLevelCount](#getLevelCount) | @brief Get the total number of levels :material-keyboard-return: **Return** :    Number of levels  |
| [loadLevelsFromFile](#loadLevelsFromFile) | @brief Load levels from a file :material-location-enter: `filePath` :    Path to the level file  |
| [createDefaultLevel](#createDefaultLevel) | @brief Create a default level as fallback :material-keyboard-return: **Return** :    Default level layout  |

## Function Details

### LevelManager<a name="LevelManager"></a>
!!! function "explicit LevelManager(const std::string&amp; levelFilePath = &quot;assets/nibbler/levels.txt&quot;)"

    @brief Constructor
    
    :material-location-enter: `levelFilePath`
    :    Path to the level file
    

### createDefaultLevel<a name="createDefaultLevel"></a>
!!! function "std::vector&lt;std::string&gt; createDefaultLevel() const"

    @brief Create a default level as fallback
        
    :material-keyboard-return: **Return**
    :    Default level layout
    

### getLevel<a name="getLevel"></a>
!!! function "std::vector&lt;std::string&gt; getLevel(int level) const"

    @brief Get a level layout by index
        
    :material-location-enter: `level`
    :    Level index (1-based)
        
    :material-keyboard-return: **Return**
    :    Level layout as a vector of strings
    

### getLevelCount<a name="getLevelCount"></a>
!!! function "int getLevelCount() const"

    @brief Get the total number of levels
        
    :material-keyboard-return: **Return**
    :    Number of levels
    

### loadLevelsFromFile<a name="loadLevelsFromFile"></a>
!!! function "void loadLevelsFromFile(const std::string&amp; filePath)"

    @brief Load levels from a file
        
    :material-location-enter: `filePath`
    :    Path to the level file
    

