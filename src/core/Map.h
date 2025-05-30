#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Map 
{

public:
  Map(bool isRandom);
  void Draw(sf::RenderWindow& window) const;

  // Functions for UnitTests
  Cell* GetCell(int x, int y) const;
  void SetCell(int x, int y, std::unique_ptr<Cell> cell);

  void NextGeneration();
  int CountNeighbors(int x, int y, CellType Type);

private:
  void RandomizeGridCenter(int randomSize);

  std::vector<std::vector<std::unique_ptr<Cell>>> grid;
};
