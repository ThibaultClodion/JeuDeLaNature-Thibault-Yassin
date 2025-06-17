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

  void Update(Map* map); // To call each frame

  bool GetHappened() {return happened;}
  void SetHappened() {happened = false;}

private:
  std::vector<std::unique_ptr<RandomEvent>> events;
  bool happened = false;
};



#endif //RANDOMEVENTMANAGER_H
