#pragma once

#include "Cell.h"

class Home : public Cell 
{
public:
  Home(int x, int y) : Cell(x, y) {};
  sf::Color GetColor() const override { return sf::Color(150, 150, 150); };
  CellType GetType() const override { return CellType::CT_Home; };
};