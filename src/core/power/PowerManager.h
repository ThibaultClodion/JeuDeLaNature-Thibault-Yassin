#pragma once

#include "power/Power.h"

class PowerManager
{
public:
  PowerManager();

  void UseCurrentPower(Map& map, int x, int y);
  void UpdateCooldown();

  void SetFreezePower() { currentPower = 0; }

private:
 int currentPower = -1;
 std::vector<std::unique_ptr<Power>> powers;
};