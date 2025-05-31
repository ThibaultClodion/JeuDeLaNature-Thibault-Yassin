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
  background = sf::RectangleShape(sf::Vector2f(WINDOW_HEIGHT, WINDOW_WIDTH));
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
  ImGui::Begin("Hello, world!");
  if (ImGui::Button("Next Generation")) 
  {
    std::cout << "Next Generation button clicked!" << std::endl;
  }
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
