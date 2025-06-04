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
};