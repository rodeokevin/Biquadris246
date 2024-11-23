#include "game.h"
#include "board.h"

// Get the state of one of the Boards
char Game::getState(int board, int row, int col) const {
    if (board == 1) {
        return board1->charAt(row, col);
    }
    else {
        return board2->charAt(row, col);
    }
}

Block* Game::getNextBlock(int p) {
    return (p == 1) ? board1->nextBlock : board2->nextBlock;
}

int Game::getLevel(int p) {
    return (p == 1) ? p1Level : p2Level;
}

int Game::getScore(int p) {
    return (p == 1) ? p1Score : p2Score;
}

Game::Game(int p1Level, int p2Level, Board *board1, Board *board2)
    :p1Level{p1Level},p2Level{p2Level},board1{board1},board2{board2}{}

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
