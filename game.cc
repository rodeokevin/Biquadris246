#include <iostream>
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
    // initializing the command interpreter
    ci = std::make_unique<CommandInterpreter>();
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

void Game::updateScoreDestroyedBlock(int origLvl) {
    currPlayerPointer->scoreBlock(origLvl);

    updateHiScore();
}

int Game::getPlayerTurn() const {
    return currPlayerIdx;
}

void Game::switchPlayerTurn() {
    // updating the Player pointer
    if (currPlayerIdx = 0) currPlayerPointer = p2.get();
    else currPlayerPointer = p1.get();

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

// Tries to drop a 1-by-1 block in the middle column of the current player's board.
// Returns True if successful, and False otherwise (the player loses, since the
// middle column is full and cannot take an extra block)
bool Game::addPenalty() {
    if (currPlayerIdx == 0) return board1->addPenaltyBlock();
    else return board2->addPenaltyBlock();
}

// prompts the current player if they cleared more than 1 row this turn to pick
// one or more special actions, depending on the number of rows cleared
void Game::promptForSpecAct(int rowsCleared) {
    const int numOfSpecAct = rowsCleared - SPECIAL_ACTION_THRES;
    std::vector<std::string> validInputSpecAct;

    if (numOfSpecAct > 0) {
        cout << "Multiple rows cleard!" << " You are allowed to pick " << numOfSpecAct;

        // different output depending on the number of special actions the player
        // can pick
        if (numOfSpecAct > 1) cout << " special actions.\n";
        else cout << " special action.\n";

        // listing out the available actions
        cout << "The available actions are:\t"
             << "\tblind\n" << "\theavy\n" << "\tforce BLOCK"
             << ", replace BLOCK by one of I, J, L, O, S, Z, or T\n";
        
        while (validInputSpecAct.size() != numOfSpecAct) {
            promptValSpecAct(validInputSpecAct);
            checkDupSpecAct(validInputSpecAct);
        }
    }
}

void Game::promptValSpecAct(std::vector<std::string>& specActs) {
    while (!ci->parseSpecAct(specActs)) {
        cout << "Invalid special action. Try again.\n";
    }
}

void Game::checkDupSpecAct(std::vector<std::string>& specActs) {
    bool removedDup = false;

    // looking for duplicates by brute force, luckily there cannot be many special
    // actions at a time, technically at most 3 since as the tallest block, the
    // I-block, allows at most 4 rows to be cleared, which is at most 3 special
    // actions
    for (auto it1 = specActs.begin(); it != specActs.end(); ++it) {
        for (auto it2 = std::next(it, 1); it2 != specActs.end();) {
            if (*it1 == *it2){
                specActs.erase(it2);
                removedDup = true;
            } else if ((*it1).size() == 1 && (*it2).size() == 1) {
                specActs.erase(it2);
            }
        }
    }

    if (removedDup) cout << "Removed duplicate special actions.\n";
}

// overall method to play the game, uses helper functions for different parts of
// the game, such as a turn, end of a turn, and so on
void Game::play() {
    int currTurnRowsCleared = 0;
    bool currPlayLose = false;

    while (playTurn(currTurnRowsCleared, currPlayLose)) {
        promptForSpecAct(currTurnRowsCleared);

        // there are two ways the current player could have lost: their starting
        // block could not be initiated, or during Level 4, the 1 by 1 block
        // cannot be dropped upon the player incurring the Level 4 penalty ('turnEnd()'
        // returns True when the current player incurs the Level 4 penalty and
        // 'addPenalty()' returns False when the 1 by 1 block was not dropped
        // successfully, meaning that column was full prior to the block's addition,
        // and adding another one caused the current player to lose)
        if (currPlayLose || currPlayerPointer->turnEnd(currTurnRowsCleared) && !addPenalty()) {
            // the only course of action is to verify whether the player(s) still
            // wish to continue playing, meaning they must enter the 'restart'
            // command, and all other commands pertaining to board and block
            // movements themselves do nothing, such as 'left', 'I', etc., though
            // setting
            std::string s;
            bool gameRestart = false;

            while (std::getline(std::cin, s)) {
                if (ci->checkForRestart(s)) {
                    gameRestart = true;
                    break;
                }
            }

            if (gameRestart) {
                restart();
                continue;
            } else break;
        }

        switchPlayerTurn();
        // reset the number of rows cleared for the next player's turn
        currTurnRowsCleared = 0;
    }
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
