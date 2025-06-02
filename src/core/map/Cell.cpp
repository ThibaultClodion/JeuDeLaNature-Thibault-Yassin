#include "Cell.h"
#include "Param.h"

Cell::Cell(int x, int y) : x(x), y(y) {}

void Cell::Draw(sf::RenderWindow& window) 
{
  sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
  rectangle.setPosition({(float)x * CELL_SIZE, (float)y * CELL_SIZE});
  rectangle.setFillColor(GetColor());

  // make the rectangle border black
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(1.f);

  window.draw(rectangle);

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
