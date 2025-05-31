#include <iostream> // For temporary std::cout

#include "Game.h"
#include "Param.h"


Game::Game() 
{
  // Create the main window
  window = sf::RenderWindow{sf::VideoMode({WINDOW_HEIGHT, WINDOW_WIDTH}),
                          "Jeu De La Nature"};
  window.setFramerateLimit(30);

  // Initialize ImGui-SFML
  if (!ImGui::SFML::Init(window)) 
  {
    throw std::runtime_error("Failed to initialize ImGui-SFML");
  }

  // Create the map
  map = Map{1};

  // Define background
  background = sf::RectangleShape(sf::Vector2f(WINDOW_HEIGHT, WINDOW_WIDTH));
  background.setFillColor(sf::Color::White);
}

void Game::Run() 
{
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) 
    {
      // Process the event with ImGui-SFML
      ImGui::SFML::ProcessEvent(window, *event);

      // Handle the close event
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) 
      {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }
    }

    // ImGui-SFML - Test
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::Begin("Hello, world!");
    if (ImGui::Button("Next Generation")) 
    {
      map.NextGeneration();
    }
    ImGui::End();

    window.clear();

    // Draw the background and the map
    window.draw(background);
    map.Draw(window);
    ImGui::SFML::Render(window);

    window.display();
  }

  ImGui::SFML::Shutdown();
}
