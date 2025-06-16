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

  // Getters and setters
  Cell* GetCell(int x, int y) const;
  void SetCell(int x, int y, std::unique_ptr<Cell> cell);
  int GetRound() const { return round; }
  int GetNbNatureCell() const { return nbNatureCell; };

  template<typename T>
  int CountCellType() const {
    int count = 0;
    for (const auto& row : grid) {
      for (const auto& cell : row) {
        if (dynamic_cast<T*>(cell.get())) {
          count++;
        }
      }
    }
    return count;
  }


private:
  void RandomizeGridCenter(int randomSize);
  void ComputeNbNatureCell();

  std::vector<std::vector<std::unique_ptr<Cell>>> grid;
  int round = 0;
  int nbNatureCell = 0;
};
