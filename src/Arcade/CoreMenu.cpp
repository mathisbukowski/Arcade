/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Core menu rendering
*/

#include "Core.hpp"
#include <iostream>

namespace arcade {

void Core::displayMenu() {
    prepareMenuDisplay();
    renderMenuSections();
    renderMenuInstructions();
    _currentGraphicLib->getDisplay().updateWindow(_deltaTime);
}

void Core::prepareMenuDisplay() {
    _currentGraphicLib->getDisplay().clearWindow(Color(20, 20, 30));
    drawMenuSectionBackgrounds();
    drawMenuTitle();
}

void Core::drawMenuSectionBackgrounds() {
    drawMenuSection(100, 150, 300, 180, "games_bg", Color(40, 40, 60));
    drawMenuSection(500, 150, 300, 180, "graphics_bg", Color(40, 40, 60));
    drawMenuSection(100, 350, 300, 180, "scores_bg", Color(40, 40, 60));
    drawMenuSection(500, 400, 300, 80, "name_bg", Color(40, 40, 60));
}

void Core::drawMenuTitle() {
    auto& textures = _currentGraphicLib->getTextures();
    auto titleText = MyTexture(TextureText("ARCADE", Color(100, 100, 255)));
    int result = textures.load("menu_title", titleText);

    if (result != 0)
        std::cerr << "Failed to load menu_title texture" << std::endl;
    _currentGraphicLib->getDisplay().drawTexture(
        textures.get("menu_title"),
        _resolutionScaler->toScreenPosition(Vector<float>(350, 50))
    );
}

void Core::renderMenuSections() {
    auto positionGameList = _resolutionScaler->toScreenPosition(Vector<float>(100, 150));
    auto positionGraphicsList = _resolutionScaler->toScreenPosition(Vector<float>(500, 150));
    auto positionScores = _resolutionScaler->toScreenPosition(Vector<float>(100, 350));
    auto positionPlayerName = _resolutionScaler->toScreenPosition(Vector<float>(500, 400));

    this->renderGameList(positionGameList.getX(), positionGameList.getY());
    this->renderGraphicsList(positionGraphicsList.getX(), positionGraphicsList.getY());
    this->renderScores(positionScores.getX(), positionScores.getY());
    this->renderPlayerNameInput(positionPlayerName.getX(), positionPlayerName.getY());
}

void Core::renderMenuInstructions() {
    auto& textures = _currentGraphicLib->getTextures();

    auto instructionsText = MyTexture(TextureText(
        "Controls: Arrow Keys-Navigate, ENTER-Select, ESC-Exit", Color(200, 200, 200)));
    int result = textures.load("menu_instructions", instructionsText);

    if (result != 0)
        std::cerr << "Failed to load menu_instructions texture" << std::endl;
    _currentGraphicLib->getDisplay().drawTexture(textures.get("menu_instructions"), _resolutionScaler->toScreenPosition(Vector<float>(250, 550))
    );
}

void Core::displayGame() {
    auto& display = _currentGraphicLib->getDisplay();

    display.clearWindow(Color(0, 0, 0));
    if (_currentGame)
        _currentGame->display();
    display.updateWindow(_deltaTime);
}

void Core::drawMenuSection(float x, float y, float width, float height, const std::string& name, Color color) {
    auto& textures = _currentGraphicLib->getTextures();
    auto& display = _currentGraphicLib->getDisplay();
    auto rect = Rect(Vector<float>(x, y), width, height);
    auto bgTexture = MyTexture(TextureText("", color));
    int result = textures.load(name, bgTexture);

    if (result != 0)
        std::cerr << "Failed to load " << name << " texture" << std::endl;
    display.drawTexture(textures.get(name), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));
}

void Core::renderGameList(float x, float y) {
    renderMenuListTitle(x, y, "Games:", MenuSection::GAMES, "games_title");
    renderGameItems(x, y + 30);
}

void Core::renderGraphicsList(float x, float y) {
    renderMenuListTitle(x, y, "Graphics Libraries:", MenuSection::GRAPHICS, "graphics_title");
    renderGraphicsItems(x, y + 30);
}

void Core::renderMenuListTitle(float x, float y, const std::string& title, MenuSection section, const std::string& textureName) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& textures = _currentGraphicLib->getTextures();
    Color titleColor = (_currentMenuSection == section) ? Color(255, 255, 0) : Color(255, 255, 255);
    auto titleTexture = MyTexture(TextureText(title, titleColor));
    int result = textures.load(textureName, titleTexture);

    if (result != 0)
        std::cerr << "Failed to load " << textureName << " texture" << std::endl;
    display.drawTexture(textures.get(textureName), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));
}

void Core::renderGameItems(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& mouse = display.getMouse();
    auto gameLibs = _libManager->getAllLibrariesByType(LibType::GAME);
    int yOffset = 0;
    int index = 0;

    for (const auto& [name, lib] : gameLibs) {
        bool isHovered = isItemHovered(x, y + yOffset, 200, 25, mouse.getPos());
        bool isSelected = (index == _selectedGameIndex && _currentMenuSection == MenuSection::GAMES);
        Color textColor = getItemTextColor(isSelected, isHovered, false);

        std::string displayName = isSelected ? "> " + name : "  " + name;
        renderMenuItem("game_" + std::to_string(index), displayName, textColor, x, y + yOffset);
        yOffset += 25;
        index++;
    }
}

void Core::renderGraphicsItems(float x, float y) {
    auto& display = _currentGraphicLib->getDisplay();
    auto& mouse = display.getMouse();
    auto graphicLibs = _libManager->getAllLibrariesByType(LibType::DISPLAY);
    int yOffset = 0;
    int index = 0;

    for (const auto& [name, lib] : graphicLibs) {
        bool isHovered = isItemHovered(x, y + yOffset, 200, 25, mouse.getPos());
        bool isSelected = (index == _selectedGraphicLibIndex && _currentMenuSection == MenuSection::GRAPHICS);
        bool isCurrent = (_currentGraphicLib->getDisplay().getName() == name);
        Color textColor = getItemTextColor(isSelected, isHovered, isCurrent);

        std::string displayName = isSelected ? "> " + name : "  " + name;
        if (isCurrent)
            displayName += " (active)";
        renderMenuItem("graphic_" + name, displayName, textColor, x, y + yOffset);
        yOffset += 25;
        index++;
    }
}

void Core::renderMenuItem(const std::string& textureName, const std::string& text, Color color, float x, float y) {
    auto& textures = _currentGraphicLib->getTextures();
    auto& display = _currentGraphicLib->getDisplay();
    auto textTexture = MyTexture(TextureText(text, color));
    int result = textures.load(textureName, textTexture);

    if (result != 0)
        std::cerr << "Failed to load " << textureName << " texture" << std::endl;
    display.drawTexture(textures.get(textureName), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));
}

bool Core::isItemHovered(float x, float y, float width, float height, const Vector<float>& mousePos) const {
    return mousePos.getX() >= x && mousePos.getX() <= x + width &&
           mousePos.getY() >= y && mousePos.getY() <= y + height;
}

Color Core::getItemTextColor(bool isSelected, bool isHovered, bool isCurrent) const {
    if (isSelected) {
        return Color(255, 255, 0);
    } else if (isCurrent) {
        return Color(0, 255, 0);
    } else if (isHovered) {
        return Color(220, 220, 100);
    } else {
        return Color(200, 200, 200);
    }
}

void Core::renderScores(float x, float y) {
    auto& textures = _currentGraphicLib->getTextures();
    auto& display = _currentGraphicLib->getDisplay();
    auto scoresTitle = MyTexture(TextureText("Scores:", Color(255, 255, 255)));
    int result = textures.load("scores_title", scoresTitle);

    if (result != 0)
        std::cerr << "Failed to load scores_title texture" << std::endl;
    display.drawTexture(textures.get("scores_title"), _resolutionScaler->toScreenPosition(Vector<float>(x, y)));
    renderScoreItems(x, y + 30);
}

void Core::renderScoreItems(float x, float y) {
    std::sort(_scores.begin(), _scores.end(),
              [](const Score& a, const Score& b) { return a._score > b._score; });

    int yOffset = 0;
    int count = 0;

    for (const auto& score : _scores) {
        if (count >= 10)
            break;
        std::string scoreText = score._playerName + " - " + score._gameName + ": " + std::to_string(score._score);
        renderMenuItem("score_" + std::to_string(count), scoreText, Color(200, 200, 200), x, y + yOffset);
        yOffset += 25;
        count++;
    }
}

void Core::renderPlayerNameInput(float x, float y) {
    renderMenuListTitle(x, y, "Your Name:", MenuSection::PLAYER_NAME, "name_title");

    auto& textures = _currentGraphicLib->getTextures();
    auto& display = _currentGraphicLib->getDisplay();
    std::string nameWithCursor = _playerName + (_currentMenuSection == MenuSection::PLAYER_NAME ? "_" : "");
    auto nameText = MyTexture(TextureText(nameWithCursor, Color(255, 255, 0)));
    int result = textures.load("player_name", nameText);

    if (result != 0)
        std::cerr << "Failed to load player_name texture" << std::endl;
    display.drawTexture(textures.get("player_name"), _resolutionScaler->toScreenPosition(Vector<float>(x, y + 30)));
}

}
