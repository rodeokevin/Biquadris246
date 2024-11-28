#ifndef TILE_H
#define TILE_H

#include <memory>

class Block; // Forward declaration

// Tile class that represents 1 tile on the board
class Tile {
        char symbol;
        bool isOccupied;
        std::shared_ptr<Block> parent = nullptr; // pointer to the parent
    public:
        char getSymbol() const;
        bool getIsOccupied() const;
        Tile(char symbol = ' ', bool isOccupied = false, std::shared_ptr<Block> parent = nullptr);
};

#endif
