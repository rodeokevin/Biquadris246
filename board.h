#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "block.h"

class Board {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    public:
        char charAt(int row, int col) const; // Get the char at a specific index
        Board(); // Constructor

        bool tryPlaceBlock(Block *block); // Check's if a Block can be placed at starting position
        void placeBlock(Block *block);
        void removeBlock(Block *block); // Remove the Block from the Board

        bool tryRotateBlock(Block *block, string dir); // Check if a Block can rotate (dir is either "CW" or "CCW")
        void rotateBlock(Block *block, string dir); // Rotate the block

        bool tryMoveBlock(Block *block, string dir); //check if a Block can move (dir is "l", "r" or "d")
        void moveBlock(Block *block, string dir);
};

#endif
