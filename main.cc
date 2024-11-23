#include <iostream>
#include <string>

#include "block.h"
#include "board.h"
#include "game.h"
#include "observer.h"
#include "textObserver.h"
#include "tile.h"
using namespace std;

int main(int argc, char *argv[]) {
    Board *board1 = new Board();
    Board *board2 = new Board();
    Game *game = new Game(0, 1, 0, board1, board2);
    std::vector<Observer *> observers;  // Keep a vector of Observer pointers to be deleted at the end
    TextObserver *textObserver = new TextObserver(game);
    game->attach(textObserver);
    IBlock *testIBlock = new IBlock();
    IBlock *testIBlock2 = new IBlock();
    OBlock *testOBlock = new OBlock();
    ZBlock *testZBlock = new ZBlock();
    board1->setNewCurrentBlock(testZBlock);
    board2->setNewNextBlock(testOBlock);
    board1->setNewNextBlock(testIBlock2);
    board1->placeBlock();
    game->notifyObservers();
    board1->rotateBlock("CW");
    board1->dropBlock();
    board1->setNewCurrentBlock(testIBlock);
    board1->rotateBlock("CW");
    board1->dropBlock();
    game->notifyObservers();
    // board1->moveBlock(testIBlock, "d");
    // game->notifyObservers();
    // board1->rotateBlock(testIBlock, "CW");
    // game->notifyObservers();
    // board1->moveBlock(testIBlock, "d");
}
