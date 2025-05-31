#pragma once

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "Map.h"

class Game
{

public:
  Game();
  void Run();

private:
  sf::RenderWindow window;
  sf::Clock deltaClock;
  Map map;
  sf::RectangleShape background;
};