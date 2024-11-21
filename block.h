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
    // Vector of pairs to store the relative coords of the Tiles forming the Block
    std::vector<std::pair<int, int>> coords;
  public:
    virtual std::vector<std::pair<int, int>> getCoords() const = 0;
    virtual ~Block() = default;
    virtual Tile getBlockTile() const;

    // Get the new coords when rotating (give "CW" or "CCW")
    virtual std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const = 0;
    // Actually rotate the block
    virtual void rotate(string dir) = 0;

    // Get the new coords when moving (give "l", "r", or "d")
    virtual std::vector<std::pair<int, int>> computeMovedCoords(string dir) const = 0;
    // Actually move the block
    virtual void move(string dir) = 0;
   
};

// OBlock
class OBlock : public Block {
public:
    OBlock();
    std::vector<std::pair<int, int>> getCoords() const override;
    std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const override;
    void rotate(string dir) override;
    std::vector<std::pair<int, int>> computeMovedCoords(string dir) const override;
    void move(string dir) override;
};

// IBlock
class IBlock : public Block {
  int state = 0; // Todo: define what the 0 state is (it will be the flat state, and 1 is the stood up state)
public:
  IBlock();
  std::vector<std::pair<int, int>> getCoords() const override;
  std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const override;
  void rotate(string dir) override;
  std::vector<std::pair<int, int>> computeMovedCoords(string dir) const override;
  void move(string dir) override;
};

// SBlock
class SBlock : public Block {
  int state = 0; // Todo: define what the 0 state is (it will be the flat state, and 1 is the stood up state)
public:
  SBlock();
  std::vector<std::pair<int, int>> getCoords() const override;
  std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const override;
  void rotate(string dir) override;
  std::vector<std::pair<int, int>> computeMovedCoords(string dir) const override;
  void move(string dir) override;
};

// ZBlock
// class ZBlock : public Block {
//  int state = 0; // Todo: define what the 0 state is (it will be the flat state, and 1 is the stood up state)
//public:
//  ZBlock();
//  std::vector<std::pair<int, int>> getCoords() const override;
//  std::vector<std::pair<int, int>> computeRotatedCoords(string dir) const override;
//  void rotate(string dir) override;
//  std::vector<std::pair<int, int>> computeMovedCoords(string dir) const override;
//  void move(string dir) override;
//};

#endif
