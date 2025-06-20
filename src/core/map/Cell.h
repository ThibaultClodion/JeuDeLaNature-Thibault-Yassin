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
  virtual sf::Texture GetTexture() = 0;
  virtual CellType GetType() const = 0;
  void Draw(sf::RenderWindow& window);
  virtual std::unique_ptr<Cell> NextGeneration(class Map& map) = 0;

  void Freeze();
  void Limit() { isLimited = true; }

protected:
  int x;
  int y;
  sf::Texture texture;
  bool isFrozen = false;
  sf::Texture frozenTexture;
  bool isLimited = false;

};