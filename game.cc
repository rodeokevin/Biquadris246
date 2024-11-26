#include "game.h"

#include "board.h"

Game::Game(bool textOnly, int seed, string seq1, string seq2, int startLevel)
    : textOnly{textOnly}, hiScore{0}, currPlayerIdx{0} {
    // setting up the players
    p1 = std::make_unique<Player>(seq1, startLevel);
    p2 = std::make_unique<Player>(seq2, startLevel);
    currPlayerPointer = p1.get();
    // setting up the board for each player, though they do not actually have
    // access to their associated player
    board1 = std::make_unique<Board>(this);
    board2 = std::make_unique<Board>(this);
}

// Get the state of one of the Boards
char Game::getState(int board, int row, int col) const {
    if (board == 1) {
        return board1->charAt(row, col);
    } else {
        return board2->charAt(row, col);
    }
}

Block* Game::getNextBlock(int player) {
    return (player == 1) ? board1->nextBlock.get() : board2->nextBlock.get();
}

int Game::getLevel(int player) const {
    return (player == 1) ? p1->getLevel() : p2->getLevel();
}

int Game::getScore(int player) const {
    return (player == 1) ? p1->getScore() : p2->getScore();
}

void Game::updateHiScore() { hiScore = max(hiScore, max(p1->getScore(), p2->getScore())); }

void Game::updateScoreDestroyedBlock(int increase) {
    currPlayerPointer->updateScore(increase);

    updateHiScore();
}

int Game::getPlayerTurn() const {
    return currPlayerIdx;
}

Player* Game::getCurrentPlayer() const {
    return currPlayerPointer;
}

void Game::switchPlayerTurn() {
    // updating the Player pointer
    if (currPlayerIdx = 0)
        currPlayerPointer = p2.get();
    else
        currPlayerPointer = p1.get();

    // updating the player 'index'
    currPlayerIdx = 1 - currPlayerIdx;
}

Board* Game::getBoard() const {
    return currPlayerIdx == 0 ? board1.get() : board2.get();
}

void Game::restart() {
    currPlayerIdx = 0;
    p1->restart();
    p2->restart();
    currPlayerPointer = p1.get();
    board1 = std::make_unique<Board>(this);
    board2 = std::make_unique<Board>(this);
}

void Game::addPenalty() {}

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
