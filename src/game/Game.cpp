#include "Game.h"
#include "Param.h"
#include "UIManager.h"

Game::Game() 
{
  // Create the main window
  window = sf::RenderWindow{sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                          "Jeu De La Nature"};
  window.setFramerateLimit(30);

  // Initialize UIManager
  uiManager = UIManager(window);

  // Create the map
  map = Map{1};
}

void Game::Run() 
{
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) {
      uiManager.ProcessEvent(window, *event);

      // Handle the close event
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }
    }



    window.clear();

    // Draw the background and the ui
    uiManager.Update(window, map);
    map.Draw(window);
    uiManager.Render(window);

    window.display();
  }
  
  uiManager.Shutdown();
}
