#pragma once

#include "power/Power.h"

class Freeze : public Power 
{

public:
  Freeze() { maxCooldown = 1; buffer.loadFromFile("resources/Freeze.mp3");
    sound.setBuffer(buffer); };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);  // Call the base class method to set cooldown
    map->GetCell(x, y)->Freeze();
    sound.play();
  }
};