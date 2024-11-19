#include "textObserver.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(Board *board):board{board}{}

void TextObserver::notify() {
    // Header
    out << "Level:     " << board->playerOneLevel << "     "
        << "Level:     " << board->playerTwoLevel << endl;
    out << "Score:     " << board->playerOneScore << "     "
        << "Score:     " << board->playerTwoScore << endl;
    out << "----------     ----------" << endl;
    // Body (the board) [TODO: optimize?]
    for (int i = 0; i <= 15; ++i) {
        for (int j = 0; j <= 11; ++j) {
            cout << board->charAt(i,j);
        }
    }
    // Footer
    out << "----------     ----------" << endl;
    out << "Next:      " << "     "
        << "Next:      " << endl;
    // [TODO: print the next Block (we should write a << function for each Block type)]
}