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
  const int nbButtons = 2;

  ImGui::SetNextWindowPos(GetWindowSize(nbButtons));
  ImGui::SetNextWindowSize(GetWindowPos(GetWindowSize(nbButtons)));

  ImGui::Begin("Main Menu", nullptr,
               ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoScrollbar);

  // Play button
  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("Play", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play();
  }

  // Quit button
  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Quit", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Quit();
  }

  ImGui::End();
}

ImVec2 MainMenu::GetWindowSize(int nbButtons) const {
  float height =
      nbButtons * ButtonHeight + (nbButtons - 1) * ButtonSpacing + 20;
  return ImVec2(400, height);
}

ImVec2 MainMenu::GetWindowPos(ImVec2 windowSize) const {
  return ImVec2((WINDOW_WIDTH - windowSize.x) / 2.f,
                (WINDOW_HEIGHT - windowSize.y) / 2.f);
}

ImVec2 MainMenu::GetButtonPos(int buttonIndex) const {
  float x = (400 - ButtonWidth) / 2.f;  // Centrage horizontal
  float y = 10 + buttonIndex * (ButtonHeight + ButtonSpacing);
  return ImVec2(x, y);
}