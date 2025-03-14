#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include <iostream>
#include "observer.h"
#include "game.h"
#include "board.h"

// Observer used for the text-based display
class TextObserver: public Observer {
    const int ROWS = 18, COLS = 11;
    const int BLINDL = 2, BLINDR = 8, BLINDT = 2, BLINDB = 11;
    const int P0_IDX = 0, P1_IDX = 1;
    // Output stream of the Observer
    std::ostream &out = std::cout;
    // Pointer to the Game subject
    Game *game;
    void print();

    public:
        TextObserver(Game *game);
        void notify() override;
        void notifyWin() override;
        ~TextObserver() = default;
};
#endif
