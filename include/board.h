#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "block.h"

class Board {
    friend class Game;
    const int ROWS = 18, COLS = 11;
    const int BLINDL = 2, BLINDR = 11, BLINDT = 2, BLINDB = 8;
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;
    bool isBlindBoard;

    bool tryMoveBlock(string dir); // Check if a Block can move (dir is "l", "r" or "d")
    bool tryRotateBlock(string dir); // Check if a Block can rotate (dir is either "CW" or "CCW")
    void shiftDown(int i); //Shifts all blocks in rows above and including i downards by 1
    public:
        Board(); // Constructor
        char charAt(int row, int col) const; // Get the char at a specific index
        Block *getNextBlock();
        
        void setNewCurrentBlock(std::shared_ptr<Block> block); // Set the new currentBlock
        void setNewNextBlock(std::shared_ptr<Block> block); // Set the new nextBlock
        std::shared_ptr<Block> getBoardNextBlock();

        bool tryPlaceBlock(); // Check if a Block can be placed at starting position
        void placeBlock();
        // 'pointOffset' indicates whether, upon removing a Block, whether we
        // actually wish to increment the Player's point. Cases where we would
        // give false as an argument is when the opposing Player applies 'force'
        // to the current Player, or when, for testing purposes, we manually set
        // the current Block to a specific one. The way we implemented the Block's
        // dtors is that they automatically increment the approrpriate Player's
        // score, but if the Blocks were destroyed in the aforementionned methods,
        // then we do not actually want to increment their score, so we offset it.
        void removeBlock(bool pointOffset); // Remove the Block from the Board

        void rotateBlock(string dir); // Rotate the block
        
        void moveBlock(string dir);

        void dropBlock();

        int clearFullRows(); // Clears full rows from the board and returns the number of cleared rows
        void clearBoard(); // Set all Tiles to blank Tiles

        bool dropStarBlock(Player* player); // Drops a StarBlock down the middle. Returns false if can't be placed
        void setBlind(const bool blind);
        bool isBlind();
};

#endif
