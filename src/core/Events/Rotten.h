//
// Created by Yassin Malik on 16/06/2025.
//

#ifndef ROTTEN_H
#define ROTTEN_H
#include <iostream>

#include "Param.h"
#include "RandomEvent.h"
#include "map/Cell.h"
#include "map/Field.h"
#include "map/Map.h"
#include "map/Nature.h"

#endif //ROTTEN_H

class Rotten : public RandomEvent {
public:
  Rotten() = default;

  void Activate(Map* map) override {
    std::cout << "Rotten event triggered!\n";

    for (int y = 0; y < NB_CELL_COLUMN; ++y) {
      for (int x = 0; x < NB_CELL_ROW; ++x) {
        Cell* cell = map->GetCell(x, y);
        if (dynamic_cast<Field*>(cell)) {
          int neighbors = map->CountNeighbors(x, y, CellType::CT_Field);
          float probability = std::pow(neighbors / 8.0f, 2); // dépend de l'entourage agricole

          if (static_cast<float>(rand()) / RAND_MAX < probability) {
            map->SetCell(x, y, std::make_unique<Nature>(x, y));
          }
        }
      }
    }
  }

  float ComputeModifier(const Map* map) const override {
    int nbHomes = map->CountCellType<CT_Home>();
    int nbFields = map->CountCellType<CT_Field>();

    if (nbFields == 0) return 0.0f; // Pas de ferme = pas de Rotten possible

    float ratio = static_cast<float>(nbFields) / nbHomes; // inversion ici

    if (ratio > 3.0f) return 0.8f;
    if (ratio > 2.0f) return 0.5f;
    if (ratio > 1.5f) return 0.3f;
    if (ratio > 1.0f) return 0.1f;
    return 0.02f;
  }

  const char* GetName() const override {
    return "Rotten";
  }
};