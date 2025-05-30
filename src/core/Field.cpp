#include "Field.h"
#include "Nature.h"
#include "Map.h"

std::unique_ptr<Cell> Field::nextGeneration(Map& map) 
{
  int nbNature = map.CountNeighbors(x, y, CT_Nature);

  // Field returns to nature if isolated
  if (nbNature == 8) return std::make_unique<Nature>(x, y);

  return std::make_unique<Field>(x, y);
}