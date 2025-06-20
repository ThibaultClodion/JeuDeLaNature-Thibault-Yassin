#pragma once

#include "Cell.h"

class Nature : public Cell 
{

public:
  Nature(int x, int y) : Cell(x, y) {};
  sf::Color GetColor() const override { return sf::Color::Green; };
  sf::Texture GetTexture() override;
  CellType GetType() const override { return CellType::CT_Nature; };

  std::unique_ptr<Cell> NextGeneration(Map& map) override;

};