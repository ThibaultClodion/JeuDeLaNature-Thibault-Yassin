#pragma once

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "UIManager.h"

class Game
{

public:
  Game();
  void Run();

private:
  Map map;
  UIManager uiManager;
  sf::RenderWindow window;
};