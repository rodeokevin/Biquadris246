#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>

#include "board.h"
#include "observer.h"
#include "tile.h"

class Observer;  // forward declaration

// Game will be the Subject for the Observers
class Subject {
    std::vector<Observer *> observers;

   public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual char getState(int player, int row, int col) const = 0;
    virtual ~Subject() = default;
};

class Game : public Subject {
    int p1Level, p2Level, p1Score, p2Score;
    int currentPlayer;
    Board *board1, *board2;

   public:
    Game(int p1Level, int p2Level, int currentPlayer, Board *board1, Board *board2);  // Ctor

    // Accessors (and settors?)
    int getLevel(int p);
    int getScore(int p);

    int getPlayerTurn();
    Board *getBoard();

    char getState(int board, int row, int col) const override;

    void switchPlayerTurn();
    Block *getNextBlock(int p);
};

#endif
