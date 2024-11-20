#include "board.h"
#include "tile.h"

// Constructor
Board::Board(int level):level{level}{
    grid.resize(15, std::vector<Tile>(11));
    // Set all to blank initially
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (level == 0) {
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

char Board::getState(int row, int col) const {
    return charAt(row, col);
}

void Subject::attach( Observer* o ) {
    // Add the observer pointer to the back of the vector
    observers.push_back(o);
}

void Subject::detach( Observer* o ) {
    // Find the observer and erase it (it does nothing if not found)
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers() {
    // Notify each observer in the vector
    for (auto it : observers) {
        it->notify();
    }
}
