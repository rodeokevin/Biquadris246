#include "board.h"
#include "tile.h"
#include "block.h"

// Constructor
Board::Board(){
    grid.resize(15, std::vector<Tile>(11));
    // Set all to blank initially
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (j % 2 == 0) {
                Tile blankTile{' ', false, nullptr};
                grid[i][j] = blankTile;
            }
            else {
                Tile blankTile{' ', false, nullptr};
                grid[i][j] = blankTile;
            }
        }
    }
}

char Board::charAt(int row, int col) const {
    return grid[row][col].getSymbol();
}

// Function to check whether a Block can be placed at (x,y)
bool Board::isBlockPlaceable(Block *block, int startX, int startY) {
    for (const auto& tile : block->getCoords()) {
        size_t x = tile.first;
        size_t y = tile.second;
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
            return false; // Invalid position on the board
        }
        if (grid[y][x].getIsOccupied()) {
            return false; // Tile already occupied
        }
    }
    return true; // All Tiles not occupied
}

// Function to place the Block on the Board
void Board::placeBlock(Block *block) {
    for (const auto& tile : block->getCoords()) {
        grid[tile.second][tile.first] = block->getBlockTile(); // Place the new Tile
    }
}

