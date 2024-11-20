#include "board.h"
#include "tile.h"

// Constructor
Board::Board(){
    grid.resize(15, std::vector<Tile>(11));
    // Set all to blank initially
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (j % 2 == 0) {
                Tile blankTile{'@'};
                grid[i][j] = blankTile;
            }
            else {
                Tile blankTile{'#'};
                grid[i][j] = blankTile;
            }
        }
    }
}

char Board::charAt(int row, int col) const {
    return grid[row][col].symbol;
}

