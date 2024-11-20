#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include <iostream>
#include "observer.h"
#include "board.h"

// Observer used for the text-based display
class TextObserver: public Observer {
    // Output stream of the Observer
    std::ostream &out = std::cout;
    // Pointer to the Board subjects
    Board *board1; // Player 1's Board
    Board *board2; // Player 2's Board

    public:
        TextObserver(Board *board1, Board *board2);
        void notify() override;
        ~TextObserver() = default;
};
#endif