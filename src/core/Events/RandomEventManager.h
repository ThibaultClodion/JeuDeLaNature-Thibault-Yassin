//
// Created by Yassin Malik on 16/06/2025.
//

#ifndef RANDOMEVENTMANAGER_H
#define RANDOMEVENTMANAGER_H



#pragma once

#include <memory>
#include <vector>
#include "map/Map.h"
#include "RandomEvent.h"

class RandomEventManager {
public:
  RandomEventManager();

  void Update(Map* map, float gameTime, float natureRatio); // To call each frame

private:
  std::vector<std::unique_ptr<RandomEvent>> events;
};



#endif //RANDOMEVENTMANAGER_H
