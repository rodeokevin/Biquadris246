#include "tile.h"

// Constructor for Tile
Tile::Tile(char symbol, bool isOccupied, std::shared_ptr<Block> parent)
    :symbol{symbol},isOccupied{isOccupied},parent{parent}{}
char Tile::getSymbol() const { return symbol; }
bool Tile::getIsOccupied() const { return isOccupied; }
