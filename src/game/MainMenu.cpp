#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(sf::RenderWindow& window) 
{
  // Define background
  backgroundTexture.loadFromFile("resources/main_menu.png");
}

void MainMenu::Update(sf::RenderWindow& window, Game* game)
{
  // Draw background
  sf::Sprite background(backgroundTexture);
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  UpdateButtons(game);
}

void MainMenu::UpdateButtons(Game* game) 
{
  const int nbButtons = 3;

  ImGui::SetNextWindowPos(GetWindowSize(nbButtons));
  ImGui::SetNextWindowSize(GetWindowPos(GetWindowSize(nbButtons)));

  ButtonStyle();

  ImGui::Begin("Main Menu", nullptr,
               ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoScrollbar |
                   ImGuiWindowFlags_NoBackground);

  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("Play", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play();
  }

  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Options", ImVec2(ButtonWidth, ButtonHeight))) {
    // Option logic
  }

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Quit", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Quit();
  }

  ImGui::End();


  ResetButtonStyle();
}

void MainMenu::ButtonStyle() 
{
  ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(20, 10));
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.5f, 0.2f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.7f, 0.2f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.4f, 0.0f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
}

void MainMenu::ResetButtonStyle() {
  ImGui::PopStyleColor(4);
  ImGui::PopStyleVar();
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