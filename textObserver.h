#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include <iostream>
#include "observer.h"
#include "game.h"
#include "board.h"

// Observer used for the text-based display
class TextObserver: public Observer {
    // Output stream of the Observer
    std::ostream &out = std::cout;
    // Pointer to the Game subject
    Game *game;

    public:
        TextObserver(Game *game);
        void notify() override;
        ~TextObserver() = default;
};
#endif