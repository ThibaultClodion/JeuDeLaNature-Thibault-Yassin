#pragma once

#include "map/Map.h"

class Power
{
 public:
  Power() = default;

  virtual void Activate(Map& map, int x, int y) { cooldown = maxCooldown; };

  void UpdateCooldown() {
    if (cooldown > 0) {
      --cooldown;}
  }

  int GetCooldown() const { return cooldown; }

protected:
  int cooldown = 0;
  int maxCooldown = 1;
};