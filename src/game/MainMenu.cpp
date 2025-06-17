#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(sf::RenderWindow& window) 
{
  // Define background
  if (!backgroundTexture.loadFromFile("resources/menu/main_menu.png")) 
  {
    throw std::runtime_error("Failed to initialize main menu background");
  }
}

void MainMenu::Update(sf::RenderWindow& window, Game* game)
{
  // Draw background
  sf::Sprite background(backgroundTexture);
  window.draw(background);

  // Update UI
  ImGui::SFML::Update(window, deltaClock.restart());
  ButtonStyle();

  if (situation == S_Main)
  {
    DisplayMainButtons(game);
    DisplayLastGameInformation(game);
  } 
  else if (situation == S_Options)
  {
    DisplayOptions();
  }
  else if (situation == S_Challenge)
  {
    DisplayChallenge(game);
  }
  else if (situation == S_Seed) {
    DisplaySeed(game);
  }

  ResetButtonStyle();
}

void MainMenu::DisplayMainButtons(Game* game) 
{
  const int nbButtons = 4;

  ImGui::SetNextWindowSize(GetWindowSize(nbButtons));
  ImGui::SetNextWindowPos(GetWindowPos(ImGui::GetWindowSize()));

  ImGui::Begin("Main Menu", nullptr,
               ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoScrollbar |
                   ImGuiWindowFlags_NoBackground);

  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("Play", ImVec2(ButtonWidth, ButtonHeight))) {
    situation = S_Seed;
  }

  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Challenge", ImVec2(ButtonWidth, ButtonHeight))) {
    situation = S_Challenge;
  }

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Options", ImVec2(ButtonWidth, ButtonHeight))) {
    situation = S_Options;
  }

  ImGui::SetCursorPos(GetButtonPos(3));
  if (ImGui::Button("Quit", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Quit();
  }

  ImGui::End();
}

void MainMenu::DisplayLastGameInformation(Game* game) {
  if (nbNatureCell >= 0) {
    // Define the green background color
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.3f, 0.2f, 0.8f));

    // Measure text and define window size
    const char* label = "Nature cells saved : %d          Seed used : %d";
    char buffer[126];
    snprintf(buffer, sizeof(buffer), label, nbNatureCell, game->GetSeed());

    ImVec2 textSize = ImGui::CalcTextSize(buffer);
    ImVec2 windowSize = ImVec2(textSize.x + 100, textSize.y + 40);

    // Center the window on screen
    ImGui::SetNextWindowSize(windowSize);
    ImGui::SetNextWindowPos(
        ImVec2(WINDOW_WIDTH / 2.f - windowSize.x / 2.f, WINDOW_HEIGHT / 1.2f));

    ImGui::Begin("Last Game Information", nullptr,
                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                     ImGuiWindowFlags_NoScrollbar);

    // Center horizontally and vertically
    ImVec2 contentSize = ImGui::GetContentRegionAvail();
    ImGui::SetCursorPosX((contentSize.x - textSize.x) * 0.5f);
    ImGui::SetCursorPosY((contentSize.y - textSize.y) * 0.5f + 7);

    ImGui::Text("%s", buffer);

    ImGui::End();

    // Pop the window background color
    ImGui::PopStyleColor();
  }
}

void MainMenu::DisplayOptions()
{
  static float volume = 50.0f;

  ImVec2 optionSize(400, 200);
  ImVec2 optionPos(WINDOW_WIDTH / 2.f - optionSize.x / 2.f,
                   WINDOW_HEIGHT / 2.f - optionSize.y / 2.f);

  ImGui::SetNextWindowSize(optionSize);
  ImGui::SetNextWindowPos(optionPos);

  ImGui::Begin("Options", nullptr,
               ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

  ImGui::Text("Sound volume:");
  ImGui::SliderFloat("##VolumeSlider", &volume, 0.0f, 100.0f, "%.1f");

  ImGui::Spacing();
  ImGui::SetCursorPosX((optionSize.x - 100) * 0.5f);

  if (ImGui::Button("Retour", ImVec2(100, 35))) 
  {
    situation = S_Main;
  }

  ImGui::End();
}

void MainMenu::DisplayChallenge(Game* game)
{
  const int nbButtons = 5;


  ImGui::SetNextWindowSize(GetWindowSize(nbButtons));
  ImGui::SetNextWindowPos(GetWindowPos(ImGui::GetWindowSize()));

  ImGui::Begin("Main Menu", nullptr,
               ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoScrollbar |
                   ImGuiWindowFlags_NoBackground);

  ImGui::SetCursorPos(GetButtonPos(0));
  if (ImGui::Button("The field line", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play("resources/levels/map_field_line.txt");
    situation = S_Main;
  }

  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Town", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play("resources/levels/map_town.txt");
    situation = S_Main;
  }

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Surrounded", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play("resources/levels/map_surround.txt");
    situation = S_Main;
  }

  ImGui::SetCursorPos(GetButtonPos(3));
  if (ImGui::Button("Corner", ImVec2(ButtonWidth, ButtonHeight))) {
    game->Play("resources/levels/map_corner.txt");
    situation = S_Main;
  }

  ImGui::SetCursorPos(GetButtonPos(4));
  if (ImGui::Button("Return", ImVec2(ButtonWidth, ButtonHeight))) {
    situation = S_Main;
  }

  ImGui::End();
}

void MainMenu::DisplaySeed(Game* game) {
  const int nbButtons = 3;

  static char seedInput[32] = "";

  ImGui::SetNextWindowSize(GetWindowSize(nbButtons));
  ImGui::SetNextWindowPos(GetWindowPos(ImGui::GetWindowSize()));

  ImGui::Begin("Seed", nullptr,
               ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoScrollbar |
                   ImGuiWindowFlags_NoBackground);

  ImGui::SetCursorPos(GetButtonPos(0));
  ImGui::Text("Enter custom seed:");
  ImGui::SetCursorPosX(ButtonWidth / 2.f);
  ImGui::InputText("##SeedInputMap", seedInput, IM_ARRAYSIZE(seedInput));

  ImGui::SetCursorPos(GetButtonPos(1));
  if (ImGui::Button("Start Game", ImVec2(120, 35))) {
    situation = S_Main;
    if (seedInput[0] != '\0') {
      game->SetSeed(std::stoi(seedInput));
    } else {
      game->SetSeed(time(nullptr));
    }
    game->Play();
  }

  ImGui::SetCursorPos(GetButtonPos(2));
  if (ImGui::Button("Return", ImVec2(ButtonWidth, ButtonHeight))) {
    situation = S_Main;
  }

  ImGui::End();
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

ImVec2 MainMenu::GetWindowSize(int nbButtons) const 
{
  float height = nbButtons * ButtonHeight + (nbButtons - 1) * ButtonSpacing + 20;
  return ImVec2(ButtonWidth * 2, height);
}

ImVec2 MainMenu::GetWindowPos(ImVec2 windowSize) const 
{
  return ImVec2((WINDOW_WIDTH - windowSize.x) / 2.f,
                (WINDOW_HEIGHT - windowSize.y) / 2.f);
}

ImVec2 MainMenu::GetButtonPos(int buttonIndex) const 
{
  float x = ButtonWidth / 2.f;
  float y = 10 + buttonIndex * (ButtonHeight + ButtonSpacing);
  return ImVec2(x, y);
}