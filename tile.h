#ifndef TILE_H
#define TILE_H

class Block; // Forward declaration

// Tile class that represents 1 tile on the board
class Tile {
        char symbol;
        bool isOccupied;
        Block *parent; // pointer to the parent
    public:
        char getSymbol() const;
        bool getIsOccupied() const;
        Tile(char symbol = ' ', bool isOccupied = false, Block *parent = nullptr);
};

#endif
