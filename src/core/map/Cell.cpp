#include "Cell.h"
#include "Param.h"

Cell::Cell(int x, int y) : x(x), y(y) {}

void Cell::Draw(sf::RenderWindow& window) 
{
  sf::Texture spriteTexture = GetTexture();
  sf::Sprite sprite(spriteTexture);
  sprite.setPosition({(float)x * CELL_SIZE, (float)y * CELL_SIZE});
  sprite.setScale({CELL_SIZE / (float)spriteTexture.getSize().x,
                   CELL_SIZE / (float)spriteTexture.getSize().y});

  window.draw(sprite);

  // Add blue overlay if the cell is frozen
  // TODO : modify the overlay with a snowflake texture
  if (isFrozen) 
  {
    sf::RectangleShape overlay(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    overlay.setPosition({(float)x * CELL_SIZE, (float)y * CELL_SIZE});
    overlay.setFillColor(
        sf::Color(100, 100, 255, 100));
    window.draw(overlay);
  }
}
