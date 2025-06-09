#pragma once

#include "power/Power.h"
#include "map/Nature.h"

class Naturalize : public Power {
 public:
  Naturalize() : Power("resources/powers/Naturalize.mp3") {
    cooldown = 1;
    maxCooldown = 2;
  };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);
    map->SetCell(x, y, std::make_unique<Nature>(x, y));
  }
};