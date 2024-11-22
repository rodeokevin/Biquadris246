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
            cout << game->getState(1, i, j); // State of p1
        }
        cout << "     ";
        for (int j = 0; j < 11; ++j) {
            cout << game->getState(2, i, j); // State of p2
        }
        out << endl;
    }
    // Footer
    out << "-----------     -----------" << endl;
    out << "Next:      " << "     "
        << "Next:      " << endl;
    // [TODO: print the next Block (we should write a << function for each Block type)]
}
