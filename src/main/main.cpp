#include <SFML/Graphics.hpp>

#include "Param.h"
#include "Map.h"

int main() 
{
  //Create the map
  Map map{true};

  // Create the main window
  sf::RenderWindow window{sf::VideoMode({WINDOW_HEIGHT, WINDOW_WIDTH}),"Jeu De La Nature"};
  window.setFramerateLimit(30);

  // run the program as long as the window is open
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) 
    {
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }
    }

    window.clear();

    sf::RectangleShape background(sf::Vector2f(1600.f, 1600.f));
    background.setFillColor(sf::Color::White);
    window.draw(background);

    // Draw the map
    map.Draw(window);

    window.display();
  }

  return 0;
}