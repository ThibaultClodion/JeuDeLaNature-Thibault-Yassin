#include "Field.h"
#include "Nature.h"
#include "Map.h"

sf::Texture Field::GetTexture() 
{
  if (texture.getSize().x == 0) {
    int randomInt = rand() % 4 + 1;  // Randomly choose between 1 and 2
    if (!texture.loadFromFile("resources/map/grass_" + std::to_string(randomInt) +
                              ".png")) {
      throw std::runtime_error("Failed to load texture for Field cell");
    }
  }

  return texture;
}

std::unique_ptr<Cell> Field::NextGeneration(Map& map) {
  if (isFrozen) return std::make_unique<Field>(x, y);

  int nbNature = map.CountNeighbors(x, y, CT_Nature);

  // Field returns to nature if isolated
  if (nbNature == 8) return std::make_unique<Nature>(x, y);

  return std::make_unique<Field>(*this);
}