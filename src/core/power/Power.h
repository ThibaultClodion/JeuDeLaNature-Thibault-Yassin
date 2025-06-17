#pragma once

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "map/Map.h"

class Power
{
 public:
  Power(const char* filename) : sound(buffer)
  { 
    if (!buffer.loadFromFile(filename))
    {
      throw std::runtime_error("Failed to load sound filename");
    }
    sound.setBuffer(buffer);
  };

  virtual void Activate(Map* map, int x, int y) 
  { 
    cooldown = maxCooldown;

    sound.play();
  };

  void UpdateCooldown() {
    if (cooldown > 0) {
      --cooldown;}
  }

  int GetCooldown() const { return cooldown; }

protected:
  int cooldown = 0;
  int maxCooldown = 1;
  sf::SoundBuffer buffer;
  sf::Sound sound;
};