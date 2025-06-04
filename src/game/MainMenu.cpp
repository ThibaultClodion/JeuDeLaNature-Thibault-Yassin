#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(sf::RenderWindow& window) 
{
  // Define background
  background = sf::RectangleShape(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
  background.setFillColor(sf::Color::White);
}

void MainMenu::Update(sf::RenderWindow& window, Game* game)
{
  // Draw background
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  UpdateButtons(game);
}

void MainMenu::UpdateButtons(Game* game) 
{
  ImGui::SetNextWindowPos(ImVec2(0,0));
  ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
  ImGui::Begin("Main Menu");

  
  ImGui::SetCursorPos(ImVec2(0, 0));
  if (ImGui::Button("Play", ImVec2(200, 200))) 
  {
    game->Play();
  }

  ImGui::SetCursorPos(ImVec2(0, 200));
  if (ImGui::Button("Quit", ImVec2(200, 200))) {
    game->Quit();
  }

  ImGui::End();
}
