#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "block.h"

class Board {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    public:
        char charAt(int row, int col) const; // Get the char at a specific index
        Board(); // Constructor
        bool isBlockPlaceable(Block *block, int startX, int startY); // Check's if a Block can be placed at (x,y)
        void placeBlock(Block *block);
};

#endif
