#include <SFML/Graphics.hpp>

#include "Circle.h"

int main() 
{
  // Test the Circle class
  Circle* circle = new Circle();
  circle->Test();

  sf::RenderWindow window{sf::VideoMode({800, 800}), "Jeu De La Nature"};
  window.setFramerateLimit(30);

  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (const std::optional event = window.pollEvent()) {
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

    window.display();
  }

  return 0;
}