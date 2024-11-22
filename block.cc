#include "block.h"

// Abstract Block class
Block::~Block(){} // Destructor does nothing
Tile Block::getBlockTile() const { return blockTile; }
std::vector<std::pair<int, int>> Block::getCoords() const { return coords; }

// New coords for rotation
// Get rotated coords
std::vector<std::pair<int, int>> Block::computeRotatedCoords(string dir) const {
    std::vector<std::pair<int, int>> res;
    std::pair<int, int> prevBottomLeft = bottomLeft;
    int adjustX;
    int adjustY;
    // CW rotation
    if (dir == "CW") {
        std::pair<int, int> rotatedBottomRight = {-(bottomRight.second), bottomRight.first};
        adjustX = prevBottomLeft.first - rotatedBottomRight.first;
        adjustY = prevBottomLeft.second - rotatedBottomRight.second;
        for (int i = 0; i < 4; ++i) {
            res.emplace_back(-(coords[i].second) + adjustX, coords[i].first + adjustY);
        }
    }
    // CCW rotation
    else {
        std::pair<int, int> rotatedTopLeft = {topLeft.second, -(topLeft.first)};
        adjustX = prevBottomLeft.first - rotatedTopLeft.first;
        adjustY = prevBottomLeft.second - rotatedTopLeft.second;
        for (int i = 0; i < 4; ++i) {
            res.emplace_back(coords[i].second + adjustX, -(coords[i].first) + adjustY);
        }
    }
    return res;
}
// Actually rotate the Block
void Block::rotate(string dir) {
    coords = computeRotatedCoords(dir);
    // Update the corners
    std::pair<int, int> prevBottomLeft = bottomLeft;
    int adjustX;
    int adjustY;
    if (dir == "CW") {
        std::pair<int, int> rotatedBottomRight = {-(bottomRight.second), bottomRight.first};
        std::pair<int, int> rotatedTopRight = {-(topRight.second), topRight.first};
        std::pair<int, int> rotatedBottomLeft = {-(bottomLeft.second), bottomLeft.first};
        std::pair<int, int> rotatedTopLeft = {-(topLeft.second), topLeft.first};
        adjustX = prevBottomLeft.first - rotatedBottomRight.first;
        adjustY = prevBottomLeft.second - rotatedBottomRight.second;
        // Mutates here
        bottomLeft = {rotatedBottomRight.first + adjustX, rotatedBottomRight.second + adjustY};
        bottomRight = {rotatedTopRight.first + adjustX, rotatedTopRight.second + adjustY};
        topLeft = {rotatedBottomLeft.first + adjustX, rotatedBottomLeft.second + adjustY};
        topRight = {rotatedTopLeft.first + adjustX, rotatedTopLeft.second + adjustY};
    }
    else {
        std::pair<int, int> rotatedBottomRight = {bottomRight.second, -(bottomRight.first)};
        std::pair<int, int> rotatedTopRight = {topRight.second, -(topRight.first)};
        std::pair<int, int> rotatedBottomLeft = {bottomLeft.second, -(bottomLeft.first)};
        std::pair<int, int> rotatedTopLeft = {topLeft.second, -(topLeft.first)};
        adjustX = prevBottomLeft.first - rotatedTopLeft.first;
        adjustY = prevBottomLeft.second - rotatedTopLeft.second;
        // Mutates here
        bottomLeft = {rotatedTopLeft.first + adjustX, rotatedTopLeft.second + adjustY};
        bottomRight = {rotatedBottomLeft.first + adjustX, rotatedBottomLeft.second + adjustY};
        topLeft = {rotatedTopRight.first + adjustX, rotatedTopRight.second + adjustY};
        topRight = {rotatedBottomRight.first + adjustX, rotatedBottomRight.second + adjustY};
    }
    state = 1 - state; // Toggle the state
}

// New coords for movement
std::vector<std::pair<int, int>> Block::computeMovedCoords(string dir) const {
    std::vector<std::pair<int, int>> res;
    // Move left
    if (dir == "l") {
        for (int i = 0; i < 4; ++i) {
            res.emplace_back(coords[i].first - 1, coords[i].second);
        }
    }
    // Move right
    else if (dir == "r") {
        for (int i = 0; i < 4; ++i) {
            res.emplace_back(coords[i].first + 1, coords[i].second);
        }
    }
    // Move down
    else {
        for (int i = 0; i < 4; ++i) {
            res.emplace_back(coords[i].first, coords[i].second + 1);
        }
    }
    return res;
}
// Actually move the block
void Block::move(string dir) {
    coords = computeMovedCoords(dir);
    // Update the corners
    // Move left
    if (dir == "l") {
        bottomLeft.first -= 1;
        bottomRight.first -= 1;
        topLeft.first -= 1;
        topRight.first -= 1;
    }
    // Move right
    else if (dir == "r") {
        bottomLeft.first += 1;
        bottomRight.first += 1;
        topLeft.first += 1;
        topRight.first += 1;
    }
    // Move down
    else {
        bottomLeft.second += 1;
        bottomRight.second += 1;
        topLeft.second += 1;
        topRight.second += 1;
    }
}




// Derived classes

// OBlock class

OBlock::OBlock() {
    blockTile = Tile('O', true, this);
    coords = {{0, 2}, {1, 2}, {0, 3}, {1, 3}}; // Default position on the board when dropped
    bottomLeft = {0,3};
    bottomRight = {1,3};
    topLeft = {0,2};
    topRight = {1,2};
}
// New coords for a OBlock rotation
std::vector<std::pair<int, int>> OBlock::computeRotatedCoords(string dir) const {
    return coords;
}

// IBlock class

IBlock::IBlock() {
    blockTile = Tile('I', true, this);
    coords = {{0, 3}, {1, 3}, {2, 3}, {3, 3}};
    bottomLeft = {0,3};
    bottomRight = {3,3};
    topLeft = {0,3};
    topRight = {3,3};
}

// SBlock class

// Constructor
SBlock::SBlock() {
    blockTile = Tile('S', true, this);
    coords = {{0, 3}, {1, 3}, {1, 2}, {2, 2}};
    bottomLeft = {0,3};
    bottomRight = {2,3};
    topLeft = {0,2};
    topRight = {2,2};
}

// ZBlock class

// Constructor
ZBlock::ZBlock() {
    blockTile = Tile('Z', true, this);
    coords = {{0, 2}, {1, 2}, {1, 3}, {2, 3}};
    bottomLeft = {0,3};
    bottomRight = {2,3};
    topLeft = {0,2};
    topRight = {2,2};
}

// JBlock class

// Constructor
JBlock::JBlock() {
    blockTile = Tile('J', true, this);
    coords = {{0, 2}, {0, 3}, {1, 3}, {2, 3}};
    bottomLeft = {0,3};
    bottomRight = {2,3};
    topLeft = {0,2};
    topRight = {2,2};
}

// LBlock class

// Constructor
LBlock::LBlock() {
    blockTile = Tile('L', true, this);
    coords = {{2, 2}, {0, 3}, {1, 3}, {2, 3}};
    bottomLeft = {0,3};
    bottomRight = {2,3};
    topLeft = {0,2};
    topRight = {2,2};
}

// TBlock class

// Constructor
TBlock::TBlock() {
    blockTile = Tile('T', true, this);
    coords = {{0, 2}, {1, 2}, {2, 2}, {1, 3}};
    bottomLeft = {0,3};
    bottomRight = {2,3};
    topLeft = {0,2};
    topRight = {2,2};
}

