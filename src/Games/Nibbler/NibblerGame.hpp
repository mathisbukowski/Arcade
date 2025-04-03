/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Nibbler game implementation
*/

#ifndef NIBBLER_GAME_HPP_
#define NIBBLER_GAME_HPP_

#include "BaseSnakeGame.hpp"
#include "LevelManager.hpp"
#include <vector>

namespace arcade {
    class NibblerGame : public BaseSnakeGame {
        public:
        NibblerGame();
        ~NibblerGame() override = default;
        void update(float delta) override;

        private:
        void initGrid() override;
        CollisionType checkCollisions() override;
        Direction handleAutomaticTurns(const Vector<float>& currentPosition);
        std::vector<Direction> getAvailableDirections(const Vector<float>& position) const;
        bool isTjunction(const Vector<float>& position) const;
        void loadLevel(int level);
        void onLevelComplete() override;
        void onGameOver() override;
        std::string getWindowTitle() const;
        static constexpr float DEFAULT_SPEED = 0.15f;
        static constexpr float LEVEL_SPEED_INCREASE = 0.02f;
        static constexpr int MAX_LEVEL = 5;
        static constexpr float BASE_TIME_LIMIT = 60.0f;
        static constexpr float TIME_BONUS_PER_FOOD = 5.0f;

        LevelManager _levelManager;
    };
}

#endif // NIBBLER_GAME_HPP_
