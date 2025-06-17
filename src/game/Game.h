#pragma once

#include <SFML/Graphics.hpp>

#include "Events/RandomEventManager.h"
#include "MainMenu.h"
#include "SeedSelection.h"
#include "UIManager.h"
#include "map/Map.h"
#include "power/PowerManager.h"

enum Context { C_MainMenu, C_Game, C_SeedSelection };


class Game
{

public:
  Game();
  void Run();
  void Play();
  void Play(const char* filename);
  void End(int nbNatureCell);
  void Quit() { window.close(); }

  int GetSeed() { return seed; };
  void SetSeed(int seed) { this->seed = seed; };

  RandomEventManager* GetRandomEventManager() const { return randomEventManager.get(); }

private:
  Context context;
  std::unique_ptr<Map> map;
  std::unique_ptr<PowerManager> powerManager;
  std::unique_ptr<RandomEventManager> randomEventManager;
  int seed;
  UIManager uiManager;
  std::unique_ptr<MainMenu> mainMenu;
  sf::RenderWindow window;
};