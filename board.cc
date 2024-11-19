#include "board.h"

char Board::charAt(int row, int col) {
    return grid[row][col].symbol;
}