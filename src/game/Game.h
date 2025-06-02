#pragma once

#include <SFML/Graphics.hpp>

#include "map/Map.h"
#include "UIManager.h"
#include "power/PowerManager.h"

class Game
{

public:
  Game();
  void Run();

private:
  Map map;
  PowerManager powerManager;
  UIManager uiManager;
  sf::RenderWindow window;
};