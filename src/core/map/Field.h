#pragma once

#include "Cell.h"

class Field : public Cell 
{

public:
  Field(int x, int y) : Cell(x, y) {};
  sf::Color GetColor() const override { return sf::Color::Yellow; };
  sf::Texture GetTexture() override;
  CellType GetType() const override { return CellType::CT_Field; };

  std::unique_ptr<Cell> NextGeneration(Map& map) override;
};