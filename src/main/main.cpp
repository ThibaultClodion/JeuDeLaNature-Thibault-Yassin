#include <SFML/Graphics.hpp>
#include <iostream> // For temporary std::cout
#include <imgui-SFML.h>
#include <imgui.h>
#include "Param.h"
#include "Map.h"


void DebugTest() { std::cout << "Debug test executed!" << std::endl; }

int main() 
{
  Map map{1};

  // Create the main window
  sf::RenderWindow window{sf::VideoMode({WINDOW_HEIGHT, WINDOW_WIDTH}),"Jeu De La Nature"};
  window.setFramerateLimit(30);

  // Initialize ImGui-SFML
  if (!ImGui::SFML::Init(window)) return -1;

  // Set background color
  sf::RectangleShape background(sf::Vector2f(WINDOW_HEIGHT, WINDOW_WIDTH));
  background.setFillColor(sf::Color::White);

  sf::Clock deltaClock;
  // run the program as long as the window is open
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) 
    {
      ImGui::SFML::ProcessEvent(window, *event);
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }
    }

    // ImGui-SFML - Test
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::Begin("Hello, world!");
    if (ImGui::Button("Debug test")) 
      DebugTest();
    ImGui::End();

    window.clear();

    // Draw the background and the map
    window.draw(background);
    map.Draw(window);
    ImGui::SFML::Render(window);

    window.display();
    
    // Sleep for 5s and log next generation
    //sf::sleep(sf::seconds(5));
    //std::cout << "Next generation..." << std::endl;
    //map.NextGeneration();
  }
  
  ImGui::SFML::Shutdown();

  return 0;
}