#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) 
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

void MainMenu::ProcessEvent(sf::RenderWindow& window, const sf::Event& event)
{
  ImGui::SFML::ProcessEvent(window, event);
}

void MainMenu::Update(sf::RenderWindow& window)
{
  // Draw background
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  UpdateButtons();
}

void MainMenu::Render(sf::RenderWindow& window) 
{ 
  ImGui::SFML::Render(window); 
}

void MainMenu::Shutdown() 
{ 
  ImGui::SFML::Shutdown(); 
}

void MainMenu::UpdateButtons() 
{
  ImGui::SetNextWindowPos(ImVec2(0,0));
  ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
  ImGui::Begin("Main Menu");
  ImGui::End();

  /* 
  ImGui::SetCursorPos(GetButtonPos(0));
  ImGui::Text("Round: %d", map.GetRound());
  ImGui::SetCursorPos(GetButtonPos(1));
  ImGui::Text("Nature Cells: %d", map.GetNbNatureCell());

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Next Generation", ImVec2(ButtonWidth, ButtonHeight))) {
    map.NextGeneration();
    powerManager.UpdateCooldown();
  }*/
}
