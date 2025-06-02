#include "PowerManager.h"
#include "Freeze.h"

PowerManager::PowerManager() 
{ 
  powers.push_back(std::make_unique<Freeze>()); 
}

void PowerManager::UseCurrentPower(Map& map, int x, int y) 
{
  if (currentPower >= 0 && currentPower < powers.size() && powers[currentPower]->GetCooldown() == 0) 
  {
    powers[currentPower]->Activate(map, x, y);
    currentPower = -1;  // Reset power after use
  } 
}

void PowerManager::UpdateCooldown() 
{
  for (auto& power : powers) {
    power->UpdateCooldown();
  }
}