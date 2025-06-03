#pragma once

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>

#include "Param.h"

class MainMenu 
{
 public:
  MainMenu() = default;
  MainMenu(sf::RenderWindow& window);

  void ProcessEvent(sf::RenderWindow& window, const sf::Event& event);
  void Update(sf::RenderWindow& window);
  void Render(sf::RenderWindow& window);
  void Shutdown();

 private:
  void UpdateButtons();

  sf::Clock deltaClock;
  sf::RectangleShape background;
};