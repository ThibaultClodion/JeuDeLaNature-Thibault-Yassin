#include "Home.h"
#include "Nature.h"
#include "Map.h"

std::unique_ptr<Cell> Home::nextGeneration(Map& map) {
  int nbNature = map.CountNeighbors(x, y, CT_Nature);

  // House return to nature if isolated
  if (nbNature == 8) return std::make_unique<Nature>(x, y);

  return std::make_unique<Home>(x, y);
}