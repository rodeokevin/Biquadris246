#include "block.h"

// Abstract Block class
Tile Block::getBlockTile() const { return blockTile; }


/*************************************************************/
// OBlock class

OBlock::OBlock() {
    blockTile = Tile('O', true, this);
    coords = {{0, 3}, {1, 3}, {0, 4}, {1, 4}}; // Default position on the board when dropped
}
std::vector<std::pair<int, int>> OBlock::getCoords() const { return coords; }
// New coords for a OBlock rotation
std::vector<std::pair<int, int>> OBlock::computeRotatedCoords(string dir) const {
    return coords;
}
// Rotating an OBlock does nothing
void OBlock::rotate(string dir) {}

// New coords for a Oblock movement
std::vector<std::pair<int, int>> OBlock::computeMovedCoords(string dir) const {
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
void OBlock::move(string dir) {
    coords = computeMovedCoords(dir);
}

/*************************************************************/
// IBlock class

IBlock::IBlock() {
    blockTile = Tile('I', true, this);
    coords = {{0, 3}, {1, 3}, {2, 3}, {3, 3}};
}
std::vector<std::pair<int, int>> IBlock::getCoords() const { return coords; }
// Get rotated coords
std::vector<std::pair<int, int>> IBlock::computeRotatedCoords(string dir) const {
    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < 4; ++i) {
        if (state == 0) { // Horizontal to Vertical
            res.emplace_back(coords[i].second - 3, coords[i].first);
        } else { // Vertical to Horizontal
            res.emplace_back(coords[i].second, coords[i].first + 3);
        }
    }
    return res;
}
// Rotating an IBlock
void IBlock::rotate(string dir) {
    coords = computeRotatedCoords(dir);
    state = 1 - state; // Toggle the state
}

// New coords for a Iblock movement
std::vector<std::pair<int, int>> IBlock::computeMovedCoords(string dir) const {
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
void IBlock::move(string dir) {
    coords = computeMovedCoords(dir);
}

/*************************************************************/
// SBlock class

// Constructor TODO
SBlock::SBlock() {
    blockTile = Tile('S', true, this);
    coords = {{0, 3}, {1, 3}, {1, 2}, {2, 2}};
}
std::vector<std::pair<int, int>> SBlock::getCoords() const { return coords; }
// Get rotated coords [TODO]
std::vector<std::pair<int, int>> SBlock::computeRotatedCoords(string dir) const {
        std::vector<std::pair<int, int>> res = 
            {{coords[0].first, coords[0].second + (state ? 2 : -2)}, // If state == 1, +2, else -2 
            {coords[1].first + (state ? 1 : -1), coords[1].second + (state ? 1 : -1)},
            {coords[2].first, coords[2].second},
            {coords[3].first + (state ? 1 : -1), coords[3].second + (state ? -1 : 1)},};
        return res;
}
// Rotating an SBlock
void SBlock::rotate(string dir) {
    coords = computeRotatedCoords(dir);
    state = 1 - state; // Toggle the state
}

// New coords for a SBlock movement
std::vector<std::pair<int, int>> SBlock::computeMovedCoords(string dir) const {
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
void SBlock::move(string dir) {
    coords = computeMovedCoords(dir);
}
