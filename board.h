#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "tile.h"

class Board {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    
    public:
        char charAt(int row, int col) const; // Get the char at a specific index
        Board(); // Constructor
};

#endif
