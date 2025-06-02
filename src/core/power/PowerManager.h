#pragma once

#include <memory>
#include "power/Power.h"

#include "power/Freeze.h"

class PowerManager
{
public:
  PowerManager() = default;

  void SetFreezePower() { currentPower = std::make_unique<Freeze>(); }

  void UseCurrentPower(Map& map, int x, int y) {
    if (currentPower) {
      currentPower->Activate(map, x, y);
    }
    currentPower = nullptr;  // Reset current power after use
  }

private:
 std::unique_ptr<Power> currentPower;
};