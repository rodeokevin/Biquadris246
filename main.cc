#include "block.h"
#include "board.h"
#include "observer.h"
#include "textObserver.h"
#include "tile.h"
#include "game.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    Board *board1 = new Board();
    Board *board2 = new Board();
    Game *game = new Game(0, 1, board1, board2);
    std::vector<Observer*> observers; // Keep a vector of Observer pointers to be deleted at the end
    TextObserver *textObserver = new TextObserver(game);
    game->attach(textObserver);
    // OBlock *testOBlock = new OBlock();
    // board1->placeBlock(testOBlock);
    SBlock *testSBlock = new SBlock();
    board1->placeBlock(testSBlock);
    board1->rotateBlock(testSBlock, "CW");
    game->notifyObservers();
    //board1->moveBlock(testSBlock, "d");
    //board1->moveBlock(testSBlock, "r");
    //board1->moveBlock(testSBlock, "d");
    //board1->moveBlock(testSBlock, "r");
    board1->rotateBlock(testSBlock, "CW");
    game->notifyObservers();
}
