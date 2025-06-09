#pragma once

#include "Param.h"
#include "map/Cell.h"
#include "map/Nature.h"
#include "map/Field.h"
#include "map/Home.h"
#include "power/Power.h"

class Wind : public Power {
 public:
  Wind() : Power("resources/SpreadLimit.mp3"){
    cooldown = 5;
    maxCooldown = 3;
  };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);  // Call the base class method to set cooldown

    static const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    static const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    int count = 0;
    for (int i = 0; i < 8; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < NB_CELL_ROW && ny >= 0 && ny < NB_CELL_COLUMN)
      {
        int randInt = rand() % 3;
        if (randInt == 0)
        {
          map->SetCell(nx, ny, std::make_unique<Nature>(nx, ny));
        } else if (randInt == 1) {
          map->SetCell(nx, ny, std::make_unique<Field>(nx, ny));
        } else {
          map->SetCell(nx, ny, std::make_unique<Home>(nx, ny));
        }
      }
    }
  }
};