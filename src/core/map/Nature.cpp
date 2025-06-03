#include "Nature.h"
#include "Field.h"
#include "Home.h"
#include "Map.h"

sf::Texture Nature::GetTexture() 
{
  if (texture.getSize().x == 0) {
    int randomInt = rand() % 2 + 1;  // Randomly choose between 1 and 2
    if (!texture.loadFromFile("resources/tree_" + std::to_string(randomInt) +
                              ".png")) {
      throw std::runtime_error("Failed to load texture for Nature cell");
    }
  }

  return texture;
}

std::unique_ptr<Cell> Nature::nextGeneration(Map& map) {

  if (isFrozen) return std::make_unique<Nature>(x, y);

  int nbHome = map.CountNeighbors(x, y, CT_Home);
  int nbField = map.CountNeighbors(x, y, CT_Field);

  if (nbField + nbHome >= 3) 
  {
    // Randomly choose the less frequent neighbor type
    // If is limited, nature cell appears twice as often
    int randomGeneration = rand() % ((nbHome + nbField + 1) * (isLimited + 1));

    if (randomGeneration < nbHome) 
    {
      return std::make_unique<Field>(x, y);
    } 
    else if (randomGeneration < nbHome + nbField)
    {
      return std::make_unique<Home>(x, y);
    }
    else
    {
      return std::make_unique<Nature>(x, y);
    }
  }

  return std::make_unique<Nature>(*this);
}