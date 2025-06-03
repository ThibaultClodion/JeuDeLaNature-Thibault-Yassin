#include <SFML/Graphics.hpp>
#include <iostream> // For temporary std::cout

#include "UIManager.h"
#include "Param.h"

UIManager::UIManager(sf::RenderWindow& window) 
{
  // Initialize ImGui-SFML
  if (!ImGui::SFML::Init(window)) 
  {
    throw std::runtime_error("Failed to initialize ImGui-SFML");
  }

  // Define background
  background = sf::RectangleShape(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  background.setFillColor(sf::Color::White);
}

void UIManager::ProcessEvent(sf::RenderWindow& window, const sf::Event& event) 
{
  ImGui::SFML::ProcessEvent(window, event);
}

void UIManager::Update(sf::RenderWindow& window, Map& map, PowerManager& powerManager) 
{
  //Draw background
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  UpdateRoundWindow(map, powerManager);
  UpdatePowerWindow(map, powerManager);
  UpdateIndicationWindow();
}

void UIManager::Render(sf::RenderWindow& window) 
{ 
  ImGui::SFML::Render(window); 
}

void UIManager::Shutdown()
{
  ImGui::SFML::Shutdown();
}

void UIManager::UpdateRoundWindow(Map& map, PowerManager& powerManager) 
{
  ImGui::SetNextWindowPos(GetWindowPos());
  ImGui::SetNextWindowSize(GetWindowSize(3));
  ImGui::Begin("Round");

  ImGui::SetCursorPos(GetButtonPos(0));
  ImGui::Text("Round: %d", map.GetRound());
  ImGui::SetCursorPos(GetButtonPos(1));
  ImGui::Text("Nature Cells: %d", map.GetNbNatureCell());

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Next Generation", ImVec2(ButtonWidth, ButtonHeight))) {
    map.NextGeneration();
    powerManager.UpdateCooldown();
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip("Pass the round and make the next generation happen");
  }

  ImGui::End();
}

void UIManager::UpdatePowerWindow(Map& map, PowerManager& powerManager) 
{
  ImGui::SetNextWindowPos(ImVec2(GetWindowPos().x, GetButtonPos(3).y + 10));
  ImGui::SetNextWindowSize(GetWindowSize(6));
  ImGui::Begin("Power");

  // Freeze Power
  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("Freeze", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(0);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip("Freeze one cell so that it will never change again" 
        "\n\nRemaining round to re-use : % d ", 
      powerManager.GetPowerCooldown(0));
  }

  // Naturalize Power
  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Naturalize", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(1);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip("Make the cell nature again"
        "\n\nRemaining round to re-use : %d",
        powerManager.GetPowerCooldown(1));
  }

  // Drought Power
  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Spread Limit", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(2);
    powerManager.UseCurrentPower(map, -1,
                                 -1);  // Use the power without coordinates);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip(
        "Nature cell has 50%% to not be converted for next generation"
        "\n\nRemaining round to re-use : % d",
        powerManager.GetPowerCooldown(2));
  }

    // Wind Power
  ImGui::SetCursorPos(GetButtonPos(3));
  if (ImGui::Button("Wind", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(3);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip(
        "Randomize cells in a 3x3 square"
        "\n\nRemaining round to re-use : % d",
        powerManager.GetPowerCooldown(3));
  }

  // Sunlight Power
  ImGui::SetCursorPos(GetButtonPos(4));
  if (ImGui::Button("Sunlight", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(4);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip(
        "Destroy all fields in a cross shape"
        "\n\nRemaining round to re-use : % d",
        powerManager.GetPowerCooldown(4));
  }

  // Earthquake Power
  ImGui::SetCursorPos(GetButtonPos(5));
  if (ImGui::Button("Earthquake", ImVec2(ButtonWidth, ButtonHeight))) {
    powerManager.SetPower(5);
  }

  if (ImGui::IsItemHovered()) {
    ImGui::SetTooltip("Earthquake destroys homes and fiels with a 75%% chance in a circle shape of radius 5" 
        "\n\nRemaining round to re-use : % d ",
        powerManager.GetPowerCooldown(5));
  }

  ImGui::End();
}

void UIManager::UpdateIndicationWindow()
{
  ImGui::SetNextWindowPos(ImVec2(GetWindowPos().x, GetButtonPos(10).y + 10));
  ImGui::SetNextWindowSize(GetWindowSize(2));

  ImGui::Begin("Indication");

  ImGui::SetCursorPos(GetButtonPos(0));
  ImGui::Text("Rule 1 : A nature cell transforms into a field or\n"
    "home if surrounded by at least three occupied cells, \n"
    "favoring the less common type among its neighbors.\n"
    "There is a small chance it remains nature");

  ImGui::SetCursorPos(GetButtonPos(1));
  ImGui::Text("\nRule 2 : Isolated fields and homes are destroyed");

  ImGui::End();
}