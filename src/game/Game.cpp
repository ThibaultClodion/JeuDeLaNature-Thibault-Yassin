#include <ctime>

#include "Game.h"
#include "Param.h"
#include "UIManager.h"

Game::Game() 
{
  // Create the main window
  window = sf::RenderWindow{sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                            "Jeu De La Nature"};
  window.setFramerateLimit(30);

  // Initialize in game UI
  uiManager = UIManager(window);

  // Initialize the powers
  powerManager = std::make_unique<PowerManager>();
  map = std::make_unique<Map>();
  seed = -1;

  // Initialize Main menu
  context = C_MainMenu;
  mainMenu = std::make_unique<MainMenu>(window);

  // Initialize ImGui-SFML
  if (!ImGui::SFML::Init(window)) {
    throw std::runtime_error("Failed to initialize ImGui-SFML");
  }
}

void Game::Run() 
{
  while (window.isOpen()) 
  {
    while (const std::optional event = window.pollEvent()) 
    {
      // Process ImGui events
      ImGui::SFML::ProcessEvent(window, *event);

      // Handle the close event
      if (event->is<sf::Event::Closed>()) window.close();

      // Catch the resize events
      if (const auto* resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }

      if (event->is<sf::Event::MouseButtonPressed>() && context == C_Game) 
      {
          sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // en pixels
          sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

          // Convert world position to cell coordinates
          int cellX = static_cast<int>(worldPos.x) / CELL_SIZE;
          int cellY = static_cast<int>(worldPos.y) / CELL_SIZE;

          // Click inside the map
          if (cellX >= 0 && cellX < NB_CELL_ROW && cellY >= 0 &&
              cellY < NB_CELL_COLUMN) 
          {
            powerManager->UseCurrentPower(map.get(), cellX, cellY);
          }
      }
    }

    window.clear();

    // Draw the map and in game UI
    if (context == C_Game)
    {
      uiManager.Update(window, map.get(), powerManager.get(), this);
      map->Draw(window);
    } 
    // Draw the main menu
    else if (context == C_MainMenu) 
    {
      mainMenu.get()->Update(window, this);
    }
    ImGui::SFML::Render(window);

    window.display();
  }

  ImGui::SFML::Shutdown();
}

void Game::Play()
{
  context = C_Game;
  seed = time(nullptr);
  map->Initialize(true, seed);
  powerManager->Reset();
}

void Game::Play(const char* filename)
{
  context = C_Game;
  map->Initialize(filename);
  powerManager->Reset();
}

void Game::End(int nbNatureCell) 
{
  context = C_MainMenu;
  mainMenu->nbNatureCell = nbNatureCell;
}