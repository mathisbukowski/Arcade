/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include "DLManager.hpp"
#include "IGameModule.hpp"
#include "IDisplayLibrary.hpp"

namespace arcade {

enum class GameState {
    MENU,
    GAME,
    EXIT
};

struct Score {
    std::string playerName;
    std::string gameName;
    int score;

    Score(const std::string& name, const std::string& game, int value)
        : playerName(name), gameName(game), score(value) {}
};

class Core {
public:
    Core(const std::string& initialLibPath);
    ~Core();

    void run();

private:
    GameState _state;
    std::string _playerName;
    std::vector<Score> _scores;

    std::unique_ptr<DynamicLibraryManager> _libManager;

    std::shared_ptr<IDisplayLibrary> _currentGraphicLib;
    std::shared_ptr<IGameModule> _currentGame;

    std::chrono::high_resolution_clock::time_point _lastFrameTime;
    float _deltaTime;

    void initializeGraphicsLib(const std::string& path);
    void initializeGameLib();

    void updateMenu();
    void updateGame();
    void displayMenu();
    void displayGame();

    void loadScores();
    void saveScores();
    void switchGraphicsLib(const std::string& libName);
    void switchGame(const std::string& gameName);
    void restartGame();
    void goToMenu();
    void handleMenuInput();
    void handleGameInput();
    void updateDeltaTime();
    void renderGameList(int x, int y);
    void renderGraphicsList(int x, int y);
    void renderScores(int x, int y);
    void renderPlayerNameInput(int x, int y);

    void checkGameListClicks(float mouseX, float mouseY);
    int _selectedGameIndex;
};

}

#endif // CORE_HPP_
