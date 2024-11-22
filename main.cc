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
    IBlock *testIBlock = new IBlock();
    board1->setNewCurrentBlock(testIBlock);
    board1->placeBlock();
    game->notifyObservers();
    board1->dropBlock();
    game->notifyObservers();
    // board1->moveBlock(testIBlock, "d");
    // game->notifyObservers();
    // board1->rotateBlock(testIBlock, "CW");
    // game->notifyObservers();
    //board1->moveBlock(testIBlock, "d");
}
