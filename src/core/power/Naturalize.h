#pragma once

#include "power/Power.h"
#include "map/Nature.h"

class Naturalize : public Power {
 public:
  Naturalize() {
    cooldown = 1;
    maxCooldown = 2;
    buffer.loadFromFile("resources/Naturalize.mp3");
    sound.setBuffer(buffer);
  };

  void Activate(Map* map, int x, int y) override 
  {
    __super::Activate(map, x, y);  // Call the base class method to set cooldown
    map->SetCell(x, y, std::make_unique<Nature>(x, y));
    sound.play();
  }
};