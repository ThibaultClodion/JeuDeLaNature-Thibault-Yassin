//
// Created by Yassin Malik on 16/06/2025.
//

#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#endif //RANDOMEVENT_H

#pragma once

#include "map/Map.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

class RandomEvent {
public:
  RandomEvent(const char* filename) {
    if (!buffer.loadFromFile(filename)) {
      //throw std::runtime_error("Failed to load event sound");
    }
  }

  RandomEvent() = default;

  virtual ~RandomEvent() = default;

  virtual void Activate(Map* map) = 0;

  virtual float ComputeModifier(const Map* map) const = 0;

  virtual const char* GetName() const = 0;

  float GetProbability() const { return probability; }

protected:
  sf::SoundBuffer buffer;
  float probability = 0.1f;
};
