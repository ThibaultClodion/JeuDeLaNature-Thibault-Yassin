#pragma once

#include "map/Nature.h"
#include "map/Cell.h"
#include "Param.h"
#include "power/Power.h"

class Sunlight : public Power {
 public:
  Sunlight() : Power("resources/Sunlight.mp3") {
    cooldown = 7;
    maxCooldown = 5;
  };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);  // Call the base class method to set cooldown

    for (int i = 0; i < NB_CELL_COLUMN; i++)
    {
      if (map->GetCell(i, y)->GetType() == CT_Field) 
      {
        map->SetCell(i, x, std::make_unique<Nature>(i, x));
      }

      if (map->GetCell(x, i)->GetType() == CT_Field)
      {
        map->SetCell(x, i, std::make_unique<Nature>(x, i));
      }
    }
  }
};