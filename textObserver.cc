#include "textObserver.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(Game *game):game{game}{}

void TextObserver::notify() {
    // Header
    out << "         BIQUADRIS" << endl;
    out << "HISCORE: " << game->getHiScore() << "   TURN: PLAYER " << (game->getPlayerTurn())+1 << endl;
    out << endl;
    out << "LEVEL:    " << game->getLevel(P0_IDX) << "     "
        << "LEVEL:    " << game->getLevel(P1_IDX) << endl;
    out << "SCORE:    " << game->getScore(P0_IDX) << "     "
        << "SCORE:    " << game->getScore(P1_IDX) << endl;
    out << "-----------     -----------" << endl;
    
    print();

    // Footer
    out << "-----------     -----------" << endl;
    out << "NEXT:      " << "     "
        << "NEXT:      " << endl;
    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bool found = false;
            // If the following does not find, print " "
            for (int k = 0; k < 4; ++k) {
                if (((game->getNextBlock(P0_IDX))->getCoords())[k].first == j && ((game->getNextBlock(P0_IDX))->getCoords())[k].second == i) {
                    out << (game->getNextBlock(P0_IDX))->getBlockSymbol();
                    found = true;
                }
            }
            if (!found) out << " ";
        }
        out << "            ";
        for (int j = 0; j < 4; ++j) {
            bool found = false;
            // If the following does not find, print " "
            for (int k = 0; k < 4; ++k) {
                if (((game->getNextBlock(P1_IDX))->getCoords())[k].first == j && ((game->getNextBlock(P1_IDX))->getCoords())[k].second == i) {
                    out << (game->getNextBlock(P1_IDX))->getBlockSymbol();
                    found = true;
                }
            }
            if (!found) out << " ";
        }
        out << "       " << endl;
    }
}

void TextObserver::notifyWin() {
    out << "Player " << game->getPlayerTurn() + 1 << " has won!\n";
    out << "Enter 'restart' to restart the game.\n";
}

void TextObserver::print() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            out << game->getState(P0_IDX, i, j); // State of p1
        }
        out << "     ";
        for (int j = 0; j < COLS; ++j) {
            if (j >= BLINDL && j <= BLINDR && i >= BLINDT && i <= BLINDB && game->isBoardBlind(P1_IDX)) {
                out << '?';
            }
            else {
                out << game->getState(P1_IDX, i, j); // State of p2
            }
        }
        out << endl;
    }
}
