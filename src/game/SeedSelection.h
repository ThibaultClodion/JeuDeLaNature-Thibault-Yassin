//
// Created by Yassin Malik on 16/06/2025.
//

#ifndef SEEDSELECTION_H
#define SEEDSELECTION_H



#pragma once

#include "MainMenu.h"
#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"
#include "imgui.h"

//class Game; // Forward declaration

class SeedSelection {
public:
  SeedSelection(int nbNatureCell);

  void Update(sf::RenderWindow& window, Game* game);
  int GetSeed() const;

private:
  char seedInput[32];
  int nbCell;
};



#endif //SEEDSELECTION_H
