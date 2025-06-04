#pragma once

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>

#include "Param.h"

class Game;

class MainMenu 
{
 public:
  MainMenu() = default;
  MainMenu(sf::RenderWindow& window);

  void Update(sf::RenderWindow& window, Game* game);

 private:
  void UpdateButtons(Game* game);

  sf::Clock deltaClock;
  sf::RectangleShape background;

  // UI Layout helpers
  ImVec2 GetWindowSize(int nbButtons) const;
  ImVec2 GetWindowPos(ImVec2 windowSize) const;
  ImVec2 GetButtonPos(int buttonIndex) const;

  const int ButtonWidth = 200;
  const int ButtonHeight = 60;
  const int ButtonSpacing = 20;
};