#include "textObserver.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(Board *board1, Board *board2):board1{board1},board2{board2}{}

void TextObserver::notify() {
    // Header
    out << "Level:    " << board1->level << "     "
        << "Level:    " << board2->level << endl;
    out << "Score:    " << board1->score << "     "
        << "Score:    " << board2->score << endl;
    out << "-----------     -----------" << endl;
    // Body (the board) [TODO: optimize how we output? if it is Player1's turn, don't loop Player 2's board]
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << board1->getState(i,j);
        }
        cout << "     ";
        for (int j = 0; j < 11; ++j) {
            cout << board2->getState(i,j);
        }
        out << endl;
    }
    // Footer
    out << "-----------     -----------" << endl;
    out << "Next:      " << "     "
        << "Next:      " << endl;
    // [TODO: print the next Block (we should write a << function for each Block type)]
}
