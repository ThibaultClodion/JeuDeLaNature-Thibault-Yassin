#include "Nature.h"
#include "Field.h"
#include "Home.h"
#include "Map.h"

std::unique_ptr<Cell> Nature::nextGeneration(Map& map) {
  int nbHome = map.CountNeighbors(x, y, CT_Home);
  int nbField = map.CountNeighbors(x, y, CT_Field);

  if (nbField >= 2) return std::make_unique<Field>(x, y);

  if (nbHome >= 2 && nbField >= 1) return std::make_unique<Home>(x, y);

  return std::make_unique<Nature>(x, y);
}