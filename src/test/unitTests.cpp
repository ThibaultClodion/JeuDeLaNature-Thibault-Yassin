#include <gtest/gtest.h>

#include "Param.h"
#include "map/Map.h"
#include "map/Nature.h"
#include "map/Field.h"
#include "map/Home.h"

TEST(TestNotRandomGeneration, TestInitialization) 
{ 
  Map map{};
  map.Initialize(false, 0);

  for (int i = 0; i < NB_CELL_ROW; ++i) {
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      Cell* cell = map.GetCell(i, j);
      EXPECT_EQ(cell->GetType(), CellType::CT_Nature);
    }
  }
}

TEST(TestSetCells, TestInitialization) 
{
  Map map{};
  map.Initialize(false, 0);

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

TEST(TestNbNonNatureCells, TestInitialization) {
  Map map;
  map.Initialize(true, time(nullptr));

  int nonNatureCount = 0;
  for (int i = 0; i < NB_CELL_ROW; ++i) {
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      Cell* cell = map.GetCell(i, j);
      if (cell->GetType() != CellType::CT_Nature) {
        ++nonNatureCount;
      }
    }
  }

  EXPECT_TRUE(nonNatureCount >= MIN_NON_NATURE);
}

TEST(TestOnlyNature, TestNextGeneration)
{
  Map map{};
  map.Initialize(false, 0);

  map.NextGeneration();

  for (int i = 0; i < NB_CELL_ROW; ++i) {
    for (int j = 0; j < NB_CELL_COLUMN; ++j) {
      Cell* cell = map.GetCell(i, j);
      EXPECT_EQ(cell->GetType(), CellType::CT_Nature);
    }
  }
}

TEST(TestStayNature, TestNextGeneration) 
{
  Map map{};
  map.Initialize(false, 0);

  map.SetCell(0, 1, std::make_unique<Field>(0, 1));
  map.SetCell(1, 0, std::make_unique<Home>(1, 0));
  map.NextGeneration();

  EXPECT_EQ(map.GetCell(0, 0)->GetType(), CellType::CT_Nature);
}

TEST(TestChangeToFieldOrHome, TestNextGeneration) {
  Map map{};
  map.Initialize(false, 0);

  map.SetCell(0, 1, std::make_unique<Field>(0, 1));
  map.SetCell(1, 0, std::make_unique<Home>(1, 0));
  map.SetCell(1, 1, std::make_unique<Field>(1, 1));
  map.NextGeneration();

  // Cell at (0, 0) should change to Field or Home
  EXPECT_TRUE(map.GetCell(0, 0)->GetType() == CellType::CT_Field ||
              map.GetCell(0, 0)->GetType() == CellType::CT_Home);
}

TEST(TestHomeAlone, TestNextGeneration) 
{
  Map map{};
  map.Initialize(false, 0);

  map.SetCell(1, 1, std::make_unique<Home>(1, 1));
  map.NextGeneration();

  EXPECT_EQ(map.GetCell(1, 1)->GetType(), CellType::CT_Nature);
}

TEST(TestFieldAlone, TestNextGeneration) {
  Map map{};
  map.Initialize(false, 0);

  map.SetCell(1, 1, std::make_unique<Field>(1, 1));
  map.NextGeneration();

  EXPECT_EQ(map.GetCell(1, 1)->GetType(), CellType::CT_Nature);
}