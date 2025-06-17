#pragma once

#include "power/Power.h"

class Freeze : public Power 
{

public:
  Freeze() : Power("resources/powers/Freeze.mp3") 
  { maxCooldown = 1; };

  void Activate(Map* map, int x, int y) override 
  {
    Power::Activate(map, x, y);
    map->GetCell(x, y)->Freeze();
  }
};