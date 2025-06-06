#pragma once

#include "map/Nature.h"
#include "map/Cell.h"
#include "power/Power.h"
#include "Param.h"

#include <iostream>

class Earthquake : public Power {
 public:
  Earthquake() 
  { 
    cooldown = 10;
    maxCooldown = 7; 
  };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);  // Call the base class method to set cooldown

    for (int dy = -radius; dy <= radius; ++dy) {
      for (int dx = -radius; dx <= radius; ++dx) {
        int maskX = dx + radius;
        int maskY = dy + radius;

        if (diskMask[maskY][maskX]) {
          int nx = x + dx;
          int ny = y + dy;

          if (nx >= 0 && nx < NB_CELL_ROW && ny >= 0 && ny < NB_CELL_COLUMN) 
          {
            if (rand() % 4 != 0) 
            {
              map->SetCell(nx, ny, std::make_unique<Nature>(nx, ny));
            }
          }
        }
      }
    }
  }

private:
  const int radius = 4; 

  const bool diskMask[4*2 + 1][4*2 + 1] = {
      {0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0}};
};