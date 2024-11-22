#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "block.h"

class Board {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    Block *currentBlock;
    Block *nextBlock;
    public:
        Board(); // Constructor
        char charAt(int row, int col) const; // Get the char at a specific index
        
        void setNewCurrentBlock(Block *block); // Set the new currentBlock
        void setNewNextBlock(Block *block); // Set the new nextBlock

        bool tryPlaceBlock(); // Check if a Block can be placed at starting position
        void placeBlock();
        void removeBlock(); // Remove the Block from the Board

        bool tryRotateBlock(string dir); // Check if a Block can rotate (dir is either "CW" or "CCW")
        void rotateBlock(string dir); // Rotate the block

        bool tryMoveBlock(string dir); //check if a Block can move (dir is "l", "r" or "d")
        void moveBlock(string dir);

        void dropBlock();
};

#endif
