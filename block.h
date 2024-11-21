#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
#include <utility>
#include "tile.h"

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
    virtual void rotateBlock() = 0;
   
};

// OBlock
class OBlock : public Block {
public:
    OBlock(char symbol);
    std::vector<std::pair<int, int>> getCoords() const override;
    void rotateBlock() override;
};

// IBlock
class IBlock : public Block {
  int state = 0; // Todo: define what the 0 state is (it will be the flat state, and 1 is the stood up state)
public:
  IBlock(char symbol);
  std::vector<std::pair<int, int>> getCoords() const override;
  void rotateBlock() override;
};

#endif
