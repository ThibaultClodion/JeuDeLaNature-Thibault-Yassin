#include "Home.h"
#include "Field.h"
#include "Map.h"
#include "Nature.h"

std::unique_ptr<Cell> Home::nextGeneration(Map& map) {
  int nbHome = map.CountNeighbors(x, y, CT_Home);

  if (nbHome == 0) return std::make_unique<Nature>(x, y);

  return std::make_unique<Home>(x, y);
}