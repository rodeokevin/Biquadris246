#include "textObserver.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(Game *game):game{game}{}

void TextObserver::notify() {
    // Header
    out << "Level:    " << game->getLevel(1) << "     "
        << "Level:    " << game->getLevel(2) << endl;
    out << "Score:    " << game->getScore(1) << "     "
        << "Score:    " << game->getScore(2) << endl;
    out << "-----------     -----------" << endl;
    // Body (the board) [TODO: optimize how we output? if it is Player1's turn, don't loop Player 2's board]
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            out << game->getState(1, i, j); // State of p1
        }
        cout << "     ";
        for (int j = 0; j < 11; ++j) {
            out << game->getState(2, i, j); // State of p2
        }
        out << endl;
    }
    // Footer
    out << "-----------     -----------" << endl;
    out << "Next:      " << "     "
        << "Next:      " << endl;
    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bool found = false;
            // If the following does not find, print " "
            for (int k = 0; k < 4; ++k) {
                if (((game->getNextBlock(1))->getCoords())[k].first == j && ((game->getNextBlock(1))->getCoords())[k].second == i) {
                    out << (game->getNextBlock(1))->getBlockSymbol();
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
                if (((game->getNextBlock(2))->getCoords())[k].first == j && ((game->getNextBlock(2))->getCoords())[k].second == i) {
                    out << (game->getNextBlock(2))->getBlockSymbol();
                    found = true;
                }
            }
            if (!found) out << " ";
        }
        out << "       " << endl;
    }
}
