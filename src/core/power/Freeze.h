#pragma once

#include <iostream>

#include "power/Power.h"

class Freeze : public Power 
{

public:
  Freeze() = default;
  ~Freeze() override = default;

  void Activate(Map& map, int x, int y) override {
    std::cout << "Freeze power activated at cell (" << x << ", " << y << ")"
              << std::endl;
  }
};