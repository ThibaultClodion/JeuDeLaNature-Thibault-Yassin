#include "Nature.h"
#include "Field.h"
#include "Home.h"
#include "Map.h"

std::unique_ptr<Cell> Nature::nextGeneration(Map& map) {

  if (isFrozen) return std::make_unique<Nature>(x, y);

  int nbHome = map.CountNeighbors(x, y, CT_Home);
  int nbField = map.CountNeighbors(x, y, CT_Field);

  if (nbField + nbHome >= 3) 
  {
    // Randomly choose the less frequent neighbor type
    int randomGeneration = rand() % (nbHome + nbField);

    if (randomGeneration < nbHome) 
    {
      return std::make_unique<Field>(x, y);
    } 
    else 
    {
      return std::make_unique<Home>(x, y);
    }
  }

  return std::make_unique<Nature>(x, y);
}