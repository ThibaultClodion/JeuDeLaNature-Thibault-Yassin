#pragma once

#include "power/Power.h"

class PowerManager
{
public:
  PowerManager();

  void UseCurrentPower(Map& map, int x, int y);
  void UpdateCooldown();

  void SetPower(int i) { currentPower = i; };
  int GetPowerCooldown(int i) { return powers[i]->GetCooldown();}

private:
 int currentPower = -1;
 std::vector<std::unique_ptr<Power>> powers;
};