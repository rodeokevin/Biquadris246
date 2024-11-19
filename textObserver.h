#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include <iostream>
#include "observer.h"
#include "board.h"

// Observer used for the text-based display
class TextObserver: public Observer {
    // Output stream of the Observer
    std::ostream &out = std::cout;
    // Pointer to the Board subject
    Board *board;

    public:
        TextObserver(Board *board);
        void notify() override;
        ~TextObserver() = default;
};
#endif