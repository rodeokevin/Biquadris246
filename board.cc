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
                Tile blankTile{'#', false, nullptr};
                grid[i][j] = blankTile;
            }
            else {
                Tile blankTile{'@', false, nullptr};
                grid[i][j] = blankTile;
            }
        }
    }
}

char Board::charAt(int row, int col) const {
    return grid[row][col].getSymbol();
}

// Check whether a Block can be placed at the starting position
bool Board::tryPlaceBlock(Block *block) {
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
// Place the Block on the Board
void Board::placeBlock(Block *block) {
    for (const auto& tile : block->getCoords()) {
        grid[tile.second][tile.first] = block->getBlockTile(); // Place the new Tile
    }
}

// Remove the Bloack on the Board (does not modify the Block's coordinates)
void Board::removeBlock(Block *block) {
    for (const auto& tile : block->getCoords()) {
        grid[tile.second][tile.first] = Tile(' '); // Replace with Blank Tile
    }
}

// Check whether a Block can be rotated
bool Board::tryRotateBlock(Block *block, string dir) {
    std::vector<std::pair<int, int>> newCoords = block->computeRotatedCoords(dir); // Obtain the new coords
    for (const auto& tile : newCoords) {
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
// Rotate the Block
void Board::rotateBlock(Block *block, string dir) {
    removeBlock(block);
    block->rotate(dir);
    placeBlock(block);
}

// Check whether the Block can be moved in specified direction
bool Board::tryMoveBlock(Block *block, string dir) {
    std::vector<std::pair<int, int>> newCoords = block->computeMovedCoords(dir); // Obtain the new coords
        for (const auto& tile : newCoords) {
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
// Move the Block
void Board::moveBlock(Block *block, string dir) {
    removeBlock(block);
    block->move(dir);
    placeBlock(block);
}
