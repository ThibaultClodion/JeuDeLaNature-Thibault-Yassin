#ifndef FIRESTORM_H
#define FIRESTORM_H

#include <iostream>

#include "Param.h"
#include "RandomEvent.h"
#include "map/Nature.h"

class Firestorm : public RandomEvent {
public:
  Firestorm() = default;

  void Trigger(Map* map) override {
    Activate(map);
  }

  void Activate(Map* map) override {
    std::cout << "Firestorm triggered\n";

    for (int y = 0; y < NB_CELL_COLUMN; ++y) {
      for (int x = 0; x < NB_CELL_ROW; ++x) {
        Cell* cell = map->GetCell(x, y);
        if (cell && cell->GetType() != CellType::CT_Nature) {
          if (rand() % 10 < 2) { // 20% de chance de brûler chaque cellule Nature
            map->SetCell(x, y, std::make_unique<Nature>(x, y));
          }
        }
      }
    }
  }

  float ComputeModifier(const Map* map) const override {
    int round = map->GetRound();

    // Augmente la chance de survenue avec le temps, max 0.7
    float modifier = std::min(0.1f + round * 0.01f, 0.7f);
    return modifier;
  }

  const char* GetName() const override {
    return "Firestorm";
  }
};

#endif //FIRESTORM_H