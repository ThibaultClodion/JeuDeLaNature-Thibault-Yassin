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
    sf::Sprite sprite(frozenTexture);
    sprite.setPosition({(float)x * CELL_SIZE, (float)y * CELL_SIZE});
    sprite.setScale({CELL_SIZE / (float)frozenTexture.getSize().x,
                     CELL_SIZE / (float)frozenTexture.getSize().y});

    window.draw(sprite);
  }
}

void Cell::Freeze() 
{ 
  isFrozen = true; 

  // Load the frozen texture if it hasn't been loaded yet
  if (frozenTexture.getSize().x == 0) {
    if (!frozenTexture.loadFromFile("resources/powers/snowflake.png")) {
      throw std::runtime_error("Failed to load frozen texture");
    }
  }
}
