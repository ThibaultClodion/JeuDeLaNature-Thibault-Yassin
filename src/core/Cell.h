#pragma once

#include <SFML/Graphics.hpp>

enum CellType
{ 
  CT_Nature,
  CT_Field, 
  CT_Home
};

class Cell
{

public:
  Cell(int x, int y);
  virtual sf::Color GetColor() const = 0;
  virtual CellType GetType() const = 0;
  void Draw(sf::RenderWindow& window);

private:
  int x;
  int y;

};