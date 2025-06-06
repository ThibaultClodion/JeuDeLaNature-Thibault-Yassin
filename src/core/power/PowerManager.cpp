#include "PowerManager.h"
#include "Freeze.h"
#include "Naturalize.h"
#include "Earthquake.h"
#include "SpreadLimit.h"
#include "Sunlight.h"
#include "Wind.h"

PowerManager::PowerManager() 
{ 
  Reset(); 
}

void PowerManager::UseCurrentPower(Map* map, int x, int y) 
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

void PowerManager::Reset()
{
  powers.clear();
  powers.push_back(std::make_unique<Freeze>());
  powers.push_back(std::make_unique<Naturalize>());
  powers.push_back(std::make_unique<SpreadLimit>());
  powers.push_back(std::make_unique<Wind>());
  powers.push_back(std::make_unique<Sunlight>());
  powers.push_back(std::make_unique<Earthquake>());
}
