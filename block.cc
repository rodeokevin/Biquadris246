#include "block.h"

// Abstract Block class
Tile Block::getBlockTile() const { return blockTile; }

// OBlock class
OBlock::OBlock(char symbol) {
    blockTile = Tile(symbol, true);
    coords = {{0, 3}, {1, 3}, {0, 4}, {1, 4}}; // Default position on the board when dropped
}
std::vector<std::pair<int, int>> OBlock::getCoords() const { return coords; }
// Rotating an OBlock does nothing
void OBlock::rotateBlock() {}

// IBlock class
IBlock::IBlock(char symbol) {
    blockTile = Tile(symbol, true);
    coords = {{0, 3}, {1, 3}, {2, 3}, {3, 3}};
}
std::vector<std::pair<int, int>> IBlock::getCoords() const { return coords; }
// Rotating an IBlock
void IBlock::rotateBlock() {
    // If it was horizontal
    if (state == 0) {
        coords = {{coords[0].second - 3, coords[0].first}, 
                    {coords[1].second - 3, coords[1].first}, 
                    {coords[2].second - 3, coords[2].first},
                    {coords[3].second - 3, coords[3].first}};
        state = 1;
    } // If it was vertical
    else {
        coords = {{coords[0].second, coords[0].first + 3}, 
                    {coords[1].second, coords[1].first + 3}, 
                    {coords[2].second, coords[2].first + 3},
                    {coords[3].second, coords[3].first + 3}};
    }
    
}

