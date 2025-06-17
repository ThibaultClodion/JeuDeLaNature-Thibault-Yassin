//
// Created by Yassin Malik on 16/06/2025.
//

#include "RandomEventManager.h"

#include "Famine.h"
#include "Firestorm.h"
#include "Rotten.h"

RandomEventManager::RandomEventManager() {
  events.push_back(std::make_unique<Firestorm>());
  events.push_back(std::make_unique<Famine>());
  events.push_back(std::make_unique<Rotten>());
}

void RandomEventManager::Update(Map* map) {
  std::vector<std::pair<RandomEvent*, float>> weightedEvents;

  for (auto& event : events) {
    float modifier = event->ComputeModifier(map);
    if (modifier > 0.0f) {
      weightedEvents.emplace_back(event.get(), modifier);
    }
  }

  if (weightedEvents.empty()) return;

  float totalWeight = 0.0f;
  for (auto& [event, mod] : weightedEvents) {
    totalWeight += mod;
  }

  float r = static_cast<float>(rand()) / RAND_MAX * totalWeight;
  for (auto& [event, mod] : weightedEvents) {
    if (r < mod) {
      event->Activate(map);
      break;
    }
    r -= mod;
  }
  happened = true;
}