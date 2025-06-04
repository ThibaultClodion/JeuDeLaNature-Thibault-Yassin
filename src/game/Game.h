#pragma once

#include <SFML/Graphics.hpp>

#include "map/Map.h"
#include "UIManager.h"
#include "MainMenu.h"
#include "power/PowerManager.h"

enum Context { C_MainMenu, C_Game };


class Game
{

public:
  Game();
  void Run();
  void Play() { context = C_Game; };

private:
  Context context;
  Map map;
  PowerManager powerManager;
  UIManager uiManager;
  MainMenu mainMenu;
  sf::RenderWindow window;
};