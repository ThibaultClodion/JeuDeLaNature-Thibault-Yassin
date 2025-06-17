//
// Created by Yassin Malik on 16/06/2025.
//

#ifndef FAMINE_H
#define FAMINE_H
#include <iostream>

#include "Param.h"
#include "RandomEvent.h"
#include "map/Field.h"
#include "map/Home.h"
#include "map/Nature.h"

class Famine : public RandomEvent {
public:
  Famine() = default;

  void Trigger(Map* map) override { Activate(map); }

  void Activate(Map* map) override {

    std::cout << "Famine triggered\n";

    for (int y = 0; y < NB_CELL_COLUMN; ++y) {
      for (int x = 0; x < NB_CELL_ROW; ++x) {
        Cell* cell = map->GetCell(x, y);
        if (cell && cell->GetType() == CellType::CT_Home) {
          if (rand() % 10 < 2) { // 20% de chance de détruire chaque cellule Home
            map->SetCell(x, y, std::make_unique<Nature>(x, y));
          }
        }
      }
    }
  }

  float ComputeModifier(const Map* map) const override {
    int nbTowns = map->CountCellType(CT_Home);
    int nbFarms = map->CountCellType(CT_Field);
    if (nbTowns == 0) return 0.0f;
    float ratio = static_cast<float>(nbFarms) / nbTowns;
    return (ratio < 0.5f) ? 0.8f : 0.1f; // Plus de chance si pas assez de farms
  }

  const char* GetName() const override {
    return "Famine";
  }
};

#endif //FAMINE_H
