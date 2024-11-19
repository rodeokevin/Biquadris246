#include "block.h"
#include "board.h"
#include "observer.h"
#include "textObserver.h"
#include "tile.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    Board *board = new Board(0,0);
    std::vector<Observer*> observers; // Keep a vector of Observer pointers to be deleted at the end

}