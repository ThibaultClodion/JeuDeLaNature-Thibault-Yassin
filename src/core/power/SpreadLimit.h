#pragma once

#include "power/Power.h"

class SpreadLimit : public Power {
 public:
  SpreadLimit() : Power("resources/powers/SpreadLimit.mp3") {
    cooldown = 3;
    maxCooldown = 10;
  };

  void Activate(Map* map, int x, int y) override 
  {
    Power::Activate(map, x, y);

    for (int i = 0; i < NB_CELL_ROW; ++i) {
      for (int j = 0; j < NB_CELL_COLUMN; ++j) {
        if (map->GetCell(i, j)->GetType() == CT_Nature) {
          map->GetCell(i, j)->Limit();
        }
      }
    }
  }
};