#pragma once

#include "map/Map.h"

class Power
{
 public:
  Power() = default;
  virtual ~Power() = default;

  // Virtual methods for power actions
  virtual void Activate(Map& map, int x, int y) = 0;
};