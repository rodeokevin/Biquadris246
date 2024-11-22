#include "game.h"

#include "board.h"

// Get the state of one of the Boards
char Game::getState(int board, int row, int col) const {
    if (board == 1) {
        return board1->charAt(row, col);
    } else {
        return board2->charAt(row, col);
    }
}

int Game::getLevel(int p) {
    return (p == 1) ? p1Level : p2Level;
}

int Game::getScore(int p) {
    return (p == 1) ? p1Score : p2Score;
}

int Game::getPlayerTurn() {
    return currentPlayer;
}

void Game::switchPlayerTurn() {
    currentPlayer = currentPlayer == 0 ? 1 : 0;
}

Game::Game(int p1Level, int p2Level, int currentPlayer, Board* board1, Board* board2)
    : p1Level{p1Level}, p2Level{p2Level}, currentPlayer{currentPlayer} {
    boards[0] = board1;
    boards[1] = board2;
}

void Subject::attach(Observer* o) {
    // Add the observer pointer to the back of the vector
    observers.push_back(o);
}

void Subject::detach(Observer* o) {
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
