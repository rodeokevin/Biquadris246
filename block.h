#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "tile.h"

using namespace std;

class Block {
  protected:
    // Tile that forms the Blcok
    Tile blockTile;
    // 0 is Horizontal, 1 is Vertical
    int state = 0; // starts Horizontal
    // Vector of pairs to store the relative coords of the Tiles forming the Block
    std::vector<std::pair<int, int>> coords;
    // Keep track of the following corners to adjust the rotations
    std::pair<int, int> bottomLeft;
    std::pair<int, int> bottomRight;
    std::pair<int, int> topLeft;
    std::pair<int, int> topRight;
  public:
    friend class board;
    std::vector<std::pair<int, int>> getCoords() const;
    virtual ~Block() = 0; // To make class abstract
    Tile getBlockTile() const;

    // Get the new coords when rotating (give "CW" or "CCW")
    virtual std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const;
    // Actually rotate the block
    void rotate(string dir);

    // Get the new coords when moving (give "l", "r", or "d")
    std::vector<std::pair<int, int>> computeMovedCoords(string dir) const;
    // Actually move the block
    void move(string dir);
};

// OBlock
class OBlock : public Block {
  public:
    OBlock();
    ~OBlock() override = default;
    // Override because rotation on OBlock does nothing
    std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const override;
};

// IBlock
class IBlock : public Block {
  public:
    IBlock();
    ~IBlock() override = default;
};

// SBlock
class SBlock : public Block {
  public:
    SBlock();
    ~SBlock() override = default;
};

// ZBlock
class ZBlock : public Block {
  public:
    ZBlock();
    ~ZBlock() override = default;
};

// JBlock
class JBlock : public Block {
  public:
    JBlock();
    ~JBlock() override = default;
};

// LBlock
class LBlock : public Block {
  public:
    LBlock();
    ~LBlock() override = default;
};

// TBlock
class TBlock : public Block {
  public:
    TBlock();
    ~TBlock() override = default;
};

#endif
