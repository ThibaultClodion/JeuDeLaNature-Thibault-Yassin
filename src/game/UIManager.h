#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

class UIManager 
{
 public:
  UIManager() = default;
  UIManager(sf::RenderWindow& window);

  void ProcessEvent(sf::RenderWindow& window, const sf::Event& event);
  void Update(sf::RenderWindow& window);
  void Render(sf::RenderWindow& window);
  void Shutdown();

private:
  sf::Clock deltaClock;
  sf::RectangleShape background;
};