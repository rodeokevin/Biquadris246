#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "observer.h"
#include "subject.h"

class Board: public Subject {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    
    public:
        int playerOneLevel; // Each player's current level
        int playerTwoLevel;

        int playerOneScore = 0; // Each player's current score
        int playerTwoScore = 0;

        char charAt(int row, int col); // Get the char at a specific index
        Board(int p1Level, int p2Level);
};

#endif