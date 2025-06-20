#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Map 
{

public:
  Map();
  void Initialize(bool isRandom, int seed);
  void Initialize(const char* filename);
  void Draw(sf::RenderWindow& window) const;
  
  void NextGeneration();
  int CountNeighbors(int x, int y, CellType Type);

  int GetRound() const { return round; }
  int GetNbNatureCell() const { return nbNatureCell; };

  
  // For unit test
  Cell* GetCell(int x, int y) const;
  void SetCell(int x, int y, std::unique_ptr<Cell> cell);

  int CountCellType(CellType type) const {
    int count = 0;
    for (const auto& row : grid) {
      for (const auto& cell : row) 
      {
        if (cell.get()->GetType() == type) 
        {
          count++;
        }
      }
    }
    return count;
  }


private:
  void RandomizeGridCenter(int randomSize);
  void ComputeNbNatureCell() { nbNatureCell = CountCellType(CT_Nature); }

  std::vector<std::vector<std::unique_ptr<Cell>>> grid;
  int round = 0;
  int nbNatureCell = 0;
};
