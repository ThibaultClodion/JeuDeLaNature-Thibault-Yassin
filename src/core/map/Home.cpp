#include "Home.h"
#include "Nature.h"
#include "Map.h"

sf::Texture Home::GetTexture() 
{
  if (texture.getSize().x == 0) {
    if (!texture.loadFromFile("resources/house.png")) {
      throw std::runtime_error("Failed to load texture for Home cell");
    }
  }

  return texture;
}

std::unique_ptr<Cell> Home::nextGeneration(Map& map) {
  if (isFrozen) return std::make_unique<Home>(x, y);

  int nbNature = map.CountNeighbors(x, y, CT_Nature);

  // House return to nature if isolated
  if (nbNature == 8) return std::make_unique<Nature>(x, y);

  return std::make_unique<Home>(*this);
}