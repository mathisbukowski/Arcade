/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Level Manager for Nibbler
*/

#ifndef LEVEL_MANAGER_HPP_
#define LEVEL_MANAGER_HPP_

#include <vector>
#include <string>

namespace arcade {

/**
 * @class LevelManager
 * This class is used to manage levels for the Nibbler game.
 * It loads levels from a file and provides methods to access them.
 */
class LevelManager {
public:
    /**
     * Constructor
     * @param levelFilePath const std::string & Path to the level file
     */
    explicit LevelManager(const std::string& levelFilePath = "assets/nibbler/levels.txt");

    /**
     *  Get a level layout by index
     * @param level int Level index (1-based)
     * @return std::vector<std::string> Level layout as a vector of strings
     */
    std::vector<std::string> getLevel(int level) const;

    /**
     * Get the total number of levels
     * @return int Number of levels
     */
    int getLevelCount() const;

private:
    /**
     * Load levels from a file
     * @param filePath const std::string & Path to the level file
     */
    void loadLevelsFromFile(const std::string& filePath);

    /**
     * Create a default level as fallback
     * @return std::vector<std::string> Default level layout
     */
    std::vector<std::string> createDefaultLevel() const;

    /**
     * Path to the level file
     */
    std::vector<std::vector<std::string>> _levels;
};

}

#endif /* !LEVEL_MANAGER_HPP_ */
