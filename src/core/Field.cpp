#include "Field.h"
#include "Home.h"
#include "Nature.h"
#include "Map.h"

std::unique_ptr<Cell> Field::nextGeneration(Map& map) 
{
  int nbHome = map.CountNeighbors(x, y, CT_Home);

  if (nbHome >= 3) return std::make_unique<Home>(x, y);

  return std::make_unique<Field>(x, y);
}