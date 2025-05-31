#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include "Param.h"

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
  void UpdateRoundWindow();
  
  sf::Clock deltaClock;
  sf::RectangleShape background;

  // Size and Position Calculation

  ImVec2 GetWindowPos() const {
    return ImVec2(NB_CELL_COLUMN * CELL_SIZE, 0); 
  }
  ImVec2 GetWindowSize(int nbButton) const {
    return ImVec2(WINDOW_WIDTH_PADING,
                  (ButtonHeight + ButtonYOffset) * nbButton + 60);
  }
  ImVec2 GetButtonPos(int buttonPos) const {
    return ImVec2(ButtonXOffset, ButtonYOffset * (buttonPos + 2) + ButtonHeight * buttonPos);
  }

  int ButtonXOffset = 25;
  int ButtonYOffset = 25;
  int ButtonWidth = WINDOW_WIDTH_PADING - ButtonXOffset * 2;
  int ButtonHeight = 30;
};