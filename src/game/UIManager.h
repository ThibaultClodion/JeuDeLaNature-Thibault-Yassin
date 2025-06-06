#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include "Param.h"
#include "map/Map.h"
#include "power/PowerManager.h"

class Game;

class UIManager 
{
 public:
  UIManager() = default;
  UIManager(sf::RenderWindow& window);

  void Update(sf::RenderWindow& window, Map* map, PowerManager* powerManager, Game* game);

private:
  void UpdateRoundWindow(Map* map, PowerManager* powerManager, Game* game);
  void UpdatePowerWindow(Map* map, PowerManager* powerManager);
  void UpdateIndicationWindow();
  void ButtonStyle();
  void ResetButtonStyle();
  
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