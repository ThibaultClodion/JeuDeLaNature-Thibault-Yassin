#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Map 
{

public:
  Map();
  void Initialize(bool isRandom, int seed);
  void Draw(sf::RenderWindow& window) const;
  
  void NextGeneration();
  int CountNeighbors(int x, int y, CellType Type);

  // Getters and setters
  Cell* GetCell(int x, int y) const;
  void SetCell(int x, int y, std::unique_ptr<Cell> cell);
  int GetRound() const { return round; }
  int GetNbNatureCell() const { return nbNatureCell; };


private:
  void RandomizeGridCenter(int randomSize);
  void ComputeNbNatureCell();

  std::vector<std::vector<std::unique_ptr<Cell>>> grid;
  int round = 0;
  int nbNatureCell = 0;
};
