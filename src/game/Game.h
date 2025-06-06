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
  void Play();
  void End(int nbNatureCell);
  void Quit() { window.close(); };

  int GetSeed() { return seed; };

private:
  Context context;
  std::unique_ptr<Map> map;
  int seed;
  PowerManager powerManager;
  UIManager uiManager;
  std::unique_ptr<MainMenu> mainMenu;
  sf::RenderWindow window;
};