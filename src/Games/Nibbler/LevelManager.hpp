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

class LevelManager {
public:
    /**
     * @brief Constructor
     * @param levelFilePath Path to the level file
     */
    explicit LevelManager(const std::string& levelFilePath = "assets/nibbler/levels.txt");

    /**
     * @brief Get a level layout by index
     * @param level Level index (1-based)
     * @return Level layout as a vector of strings
     */
    std::vector<std::string> getLevel(int level) const;

    /**
     * @brief Get the total number of levels
     * @return Number of levels
     */
    int getLevelCount() const;

private:
    /**
     * @brief Load levels from a file
     * @param filePath Path to the level file
     */
    void loadLevelsFromFile(const std::string& filePath);

    /**
     * @brief Create a default level as fallback
     * @return Default level layout
     */
    std::vector<std::string> createDefaultLevel() const;

    std::vector<std::vector<std::string>> _levels;
};

}

#endif /* !LEVEL_MANAGER_HPP_ */
