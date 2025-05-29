#include <gtest/gtest.h>

#include "Param.h"
#include "Map.h"
#include "Nature.h"
#include "Field.h"
#include "Home.h"

TEST(TestNotRandomGeneration, TestGeneration) 
{ 
  Map map{false};

  for (int i = 0; i < NB_CELL_ROW; ++i) {
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      Cell* cell = map.GetCell(i, j);
      EXPECT_EQ(cell->GetType(), CellType::CT_Nature);
    }
  }
}

TEST(TestSetCells, TestSet)
{
  Map map{false};

  // Set a cell to Field
  map.SetCell(0, 0, std::make_unique<Field>(0, 0));
  Cell* cell = map.GetCell(0, 0);
  EXPECT_EQ(cell->GetType(), CellType::CT_Field);

  // Set a cell to Home
  map.SetCell(0, 0, std::make_unique<Home>(0, 0));
  cell = map.GetCell(0, 0);
  EXPECT_EQ(cell->GetType(), CellType::CT_Home);

  // Set a cell to Nature
  map.SetCell(0, 0, std::make_unique<Nature>(0, 0));
  cell = map.GetCell(0, 0);
  EXPECT_EQ(cell->GetType(), CellType::CT_Nature);
}