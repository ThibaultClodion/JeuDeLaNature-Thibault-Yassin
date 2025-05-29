#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Map 
{

public:
  Map(bool isRandom);
  void Draw(sf::RenderWindow& window) const;

private:
  void RandomizeGridCenter(int randomSize);

  std::vector<std::vector<std::unique_ptr<Cell>>> grid;
};
