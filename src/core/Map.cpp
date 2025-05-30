#include <random>
#include <ctime>

#include "Param.h"
#include "Map.h"
#include "Nature.h"
#include "Field.h"
#include "Home.h"

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
    // Randomize seed
    // TODO : add posibility to choose seed to replay the same randomization
    srand(time(nullptr));
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

Cell* Map::GetCell(int x, int y) const 
{
  if (x < 0 || x >= NB_CELL_ROW || y < 0 || y >= NB_CELL_COLUMN) return nullptr;

  return grid[x][y].get();
}

void Map::SetCell(int x, int y, std::unique_ptr<Cell> cell) 
{
  if (x < 0 || x >= NB_CELL_ROW || y < 0 || y >= NB_CELL_COLUMN) return;

  grid[x][y] = std::move(cell);
}

void Map::NextGeneration() 
{
  std::vector<std::vector<std::unique_ptr<Cell>>> newGrid(NB_CELL_ROW);

  for (int i = 0; i < NB_CELL_ROW; ++i) {
    newGrid[i].resize(NB_CELL_COLUMN);
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      newGrid[i][j] = grid[i][j]->nextGeneration(*this);
    }
  }
  grid = std::move(newGrid);
}

int Map::CountNeighbors(int x, int y, CellType Type) 
{
  static const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  static const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

  int count = 0;
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < NB_CELL_ROW && ny >= 0 && ny < NB_CELL_COLUMN) {
      if (grid[nx][ny]->GetType() == Type) {
        ++count;
      }
    }
  }

  return count;
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
        // TODO : Use a better randomization method (to balance the game)

        int randomValue = rand() % 3;

        if (randomValue == 0)
          grid[i][j] = std::make_unique<Nature>(i, j);

        else if (randomValue == 1)
        grid[i][j] = std::make_unique<Field>(i, j);

        else if (randomValue == 2)
          grid[i][j] = std::make_unique<Home>(i, j);
      }
    }
  }
}
