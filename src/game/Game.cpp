#include "Game.h"
#include "Param.h"
#include "UIManager.h"

#include <iostream> // Temporary for std::cout

Game::Game() 
{
  // Create the main window
  window = sf::RenderWindow{sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                          "Jeu De La Nature"};
  window.setFramerateLimit(30);

  // Initialize UIManager
  uiManager = UIManager(window);

  // Initialize the map and the powers
  map = Map{1};
  powerManager = PowerManager();
}

void Game::Run() 
{
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) 
    {
      uiManager.ProcessEvent(window, *event);

      // Handle the close event
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }

      if (event->is<sf::Event::MouseButtonPressed>()) 
      {
          sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // en pixels
          sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

          // Convert world position to cell coordinates
          int cellX = static_cast<int>(worldPos.y) / CELL_SIZE;
          int cellY = static_cast<int>(worldPos.x) / CELL_SIZE;

          // Click inside the map
          if (cellX >= 0 && cellX < NB_CELL_ROW && cellY >= 0 &&
              cellY < NB_CELL_COLUMN) 
          {
            powerManager.UseCurrentPower(map, cellX, cellY);
          }
      }
    }

    window.clear();

    // Draw the background and the ui
    uiManager.Update(window, map, powerManager);
    map.Draw(window);
    uiManager.Render(window);

    window.display();
  }
  
  uiManager.Shutdown();
}
