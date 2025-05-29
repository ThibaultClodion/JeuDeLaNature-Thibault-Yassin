#include "Param.h"
#include "Map.h"
#include "Nature.h"
#include "Field.h"

Map::Map(bool isRandom) 
{
  grid.resize(NB_CELL_ROW);

  for (int i = 0; i < NB_CELL_ROW; ++i) 
  {
    grid[i].resize(NB_CELL_COLUMN);

    for (int j = 0; j < NB_CELL_COLUMN; ++j) 
    {
      grid[i][j] = std::make_unique<Nature>(i, j);
    }
  }

  if (isRandom) 
  {
    RandomizeGridCenter(1);
  }
}

void Map::Draw(sf::RenderWindow& window) const 
{
  for (const auto& row : grid) {
    for (const auto& cell : row) {
      cell->Draw(window);
    }
  }
}

void Map::RandomizeGridCenter(int randomSize) 
{
  int centerX = NB_CELL_ROW / 2;
  int centerY = NB_CELL_COLUMN / 2;

  for (int i = centerX - randomSize; i <= centerX + randomSize; ++i) 
  {
    for (int j = centerY - randomSize; j <= centerY + randomSize; ++j) 
    {
      if (i >= 0 && i < NB_CELL_ROW && j >= 0 && j < NB_CELL_COLUMN) 
      {
        // TODO : Randomize the type of cell
        grid[i][j] = std::make_unique<Field>(i, j);
      }
    }
  }
}
