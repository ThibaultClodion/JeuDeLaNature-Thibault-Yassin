#pragma once

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>

#include "Param.h"

class Game;

enum Situation { S_Main, S_Options, S_Challenge, S_Seed };

class MainMenu 
{
 public:
  MainMenu() = default;
  MainMenu(sf::RenderWindow& window);

  void Update(sf::RenderWindow& window, Game* game);

  int nbNatureCell = -1;

 private:
  void DisplayMainButtons(Game* game);
  void DisplayLastGameInformation(Game* game);
  void DisplayOptions();
  void DisplayChallenge(Game* game);
  void DisplaySeed(Game* game);
  void ButtonStyle();
  void ResetButtonStyle();

  sf::Texture backgroundTexture;
  sf::Clock deltaClock;

  // UI Layout helpers
  ImVec2 GetWindowSize(int nbButtons) const;
  ImVec2 GetWindowPos(ImVec2 windowSize) const;
  ImVec2 GetButtonPos(int buttonIndex) const;

  const int ButtonWidth = 200;
  const int ButtonHeight = 50;
  const int ButtonSpacing = 40;
  
  Situation situation = S_Main;
};