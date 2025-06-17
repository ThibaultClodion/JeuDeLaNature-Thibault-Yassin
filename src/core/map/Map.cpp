#include <random>
#include <fstream>

#include "Param.h"
#include "Map.h"
#include "Nature.h"
#include "Field.h"
#include "Home.h"

Map::Map() 
{
  grid.resize(NB_CELL_ROW);

  for (int i = 0; i < NB_CELL_ROW; ++i) 
  {
    grid[i].resize(NB_CELL_COLUMN);
  }
}

void Map::Initialize(const char* filename) 
{
  round = 0;

  // Extract file lines
  std::ifstream file(filename);
  std::string line;
  std::vector<std::string> mapLines;

  while (std::getline(file, line)) 
  {
    if (!line.empty()) mapLines.push_back(line);
  }

  // Fill the grid
  int height = mapLines.size();
  int width = (height > 0) ? mapLines[0].size() : 0;

  for (int y = 0; y < height; ++y) 
  {
    for (int x = 0; x < width; ++x)
    {
      char cellChar = mapLines[y][x];
      if (cellChar == 'F')
      {
        grid[x][y] = std::make_unique<Field>(x, y);
      } 
      else if (cellChar == 'H') 
      {
        grid[x][y] = std::make_unique<Home>(x, y);
      }
      else
      {
        grid[x][y] = std::make_unique<Nature>(x, y);
      }
    }
  }

  ComputeNbNatureCell();
}

void Map::Initialize(bool isRandom, int seed)
{
  round = 0;

  for (int i = 0; i < NB_CELL_ROW; ++i)
  {
    for (int j = 0; j < NB_CELL_COLUMN; ++j) 
    {
      grid[i][j] = std::make_unique<Nature>(i, j);
    }
  }

  
  if (isRandom) 
  {
    srand(seed);
    RandomizeGridCenter(RANDOM_EXTENSION_SIZE);
  }

  ComputeNbNatureCell();
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
  ComputeNbNatureCell();
}

void Map::NextGeneration() 
{
  std::vector<std::vector<std::unique_ptr<Cell>>> newGrid(NB_CELL_ROW);

  for (int i = 0; i < NB_CELL_ROW; ++i) {
    newGrid[i].resize(NB_CELL_COLUMN);
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      newGrid[i][j] = grid[i][j]->NextGeneration(*this);
    }
  }

  grid = std::move(newGrid);
  ++round;
  ComputeNbNatureCell();
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

  // Ensure at least MIN_NON_NATURE cells are filled ant not more than the maximum possible cells
  int nbCellsToFill = MIN_NON_NATURE + rand() % ((2 * randomSize + 1) ^ 2 - MIN_NON_NATURE);
  int nbNonNatureCells = 0;

  // Generate random cells
  while (nbNonNatureCells < nbCellsToFill)
  {
    int randomX = centerX + (rand() % (randomSize * 2 + 1)) - randomSize;
    int randomY = centerY + (rand() % (randomSize * 2 + 1)) - randomSize;

    
    if (grid[randomX][randomY]->GetType() == CT_Nature) 
    {
      int randomValue = rand() % 2;

      if (randomValue == 0) 
      {
        grid[randomX][randomY] = std::make_unique<Home>(randomX, randomY);
      } 
      else 
      {
        grid[randomX][randomY] = std::make_unique<Field>(randomX, randomY);
      }

      ++nbNonNatureCells;
    }
  }
}


