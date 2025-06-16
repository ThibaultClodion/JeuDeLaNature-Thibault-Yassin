//
// Created by Yassin Malik on 16/06/2025.
//

#include "SeedSelection.h"

#include "SeedSelection.h"
#include "Game.h"

SeedSelection::SeedSelection(int nbNatureCell) {
  seedInput[0] = '\0';
  nbCell = nbNatureCell;
}

void SeedSelection::Update(sf::RenderWindow& window, Game* game) {
  ImGui::SetNextWindowSize(ImVec2(400, 250));
  ImGui::SetNextWindowPos(ImVec2((WINDOW_WIDTH - 400) / 2.f, (WINDOW_HEIGHT - 250) / 2.f));

  ImGui::Begin("Seed Selection", nullptr,
               ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
               ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

  ImGui::Text("Enter a seed (leave blank for random):");
  ImGui::InputText("##SeedInput", seedInput, IM_ARRAYSIZE(seedInput));

  if (ImGui::Button("Start Game", ImVec2(120, 35))) {
    if (seedInput[0] != '\0') {
      game->SetSeed(std::stoi(seedInput));
    } else {
      game->SetSeed(time(nullptr));
    }
    game->Play(); // Start game using current seed
  }

  ImGui::Spacing();

  if (ImGui::Button("Back", ImVec2(120, 35))) {
    game->End(nbCell);
  }

  ImGui::End();
}

int SeedSelection::GetSeed() const {
  return (seedInput[0] != '\0') ? std::stoi(seedInput) : -1;
}
