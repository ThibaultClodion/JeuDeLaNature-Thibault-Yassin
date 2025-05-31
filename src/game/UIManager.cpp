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

void UIManager::Update(sf::RenderWindow& window) 
{
  //Draw background
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  UpdateRoundWindow();

  ImGui::End();
}

void UIManager::Render(sf::RenderWindow& window) 
{ 
  ImGui::SFML::Render(window); 
}

void UIManager::Shutdown()
{
  ImGui::SFML::Shutdown();
}

void UIManager::UpdateRoundWindow() 
{
  ImGui::SetNextWindowPos(GetWindowPos());
  ImGui::SetNextWindowSize(GetWindowSize(3));
  ImGui::Begin("Round");

  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("Next Generation", ImVec2(ButtonWidth, ButtonHeight))) {
    std::cout << "Next Generation button clicked!" << std::endl;
  }
  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Next Generation 2", ImVec2(ButtonWidth, ButtonHeight))) {
    std::cout << "Next Generation button clicked!" << std::endl;
  }
  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Next Generation 3", ImVec2(ButtonWidth, ButtonHeight))) {
    std::cout << "Next Generation button clicked!" << std::endl;
  }
}
