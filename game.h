#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>
#include <vector>

#include "board.h"
#include "observer.h"
#include "player.h"
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
    bool textOnly;
    int hiScore;
    // update 'currPlayerIdx' using: currPlayerIdx = 1 - currPlayerIdx, like
    // taking the NOT of a bit
    int currPlayerIdx;
    std::unique_ptr<Player> p1, p2;
    // raw pointer pointing to the current player, makes it easier to access the
    // actual Player object instead, and relies on 'currPlayerIdx' integer to
    // switch between the two players easily
    Player *currPlayerPointer;
    std::unique_ptr<Board> board1, board2;

    // private methods, mechanics to allow our game to run
    void updateHiScore();
    // returns TRUE when the turn ended successfully, meaning it is now the next
    // player's turn, and FALSE when EOF is reached
    bool playTurn();
    // methods relating to the special actions, adding them to a Board and
    // clearing the special actions upon a turn end, as all special actions
    // currently only last one turn for a player
    void addSpecAct(std::string specAct);
    void clearSpecAct();
    // method to add the penalty 1-by-1 block for the current player if they
    // were unable to clear a block within 5 turns when in Level 4
    void addPenalty();

   public:
    Game(bool textOnly, int seed, string seq1, string seq2, int startLevel);  // Ctor

    // Accessors (and settors?)
    int getLevel(int player) const;
    int getScore(int player) const;
    void updateScoreDestroyedBlock(int increase);

    int getPlayerTurn() const;
    Player *getCurrentPlayer() const;
    Board *getBoard() const;

    char getState(int board, int row, int col) const override;

    void switchPlayerTurn();
    Block *getNextBlock(int p);  // For textObserver to fetch the next Block
    void play();
    void restart();
};

#endif