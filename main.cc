#include "block.h"
#include "board.h"
#include "observer.h"
#include "textObserver.h"
#include "tile.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    Board *board1 = new Board(0);
    Board *board2 = new Board(1);
    std::vector<Observer*> observers; // Keep a vector of Observer pointers to be deleted at the end
    TextObserver *textObserver1 = new TextObserver(board1, board2);
    board1->attach(textObserver1);
    board1->notifyObservers();
}
