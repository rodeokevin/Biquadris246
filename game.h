#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <memory>

#include "board.h"
#include "observer.h"
#include "tile.h"
#include "player.h"
#include "commandInterpreter.h"

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
    // clearing more than 'SPECIAL_ACTION_THRES' rows allows the current player
    // to pick at least one special action
    const int SPECIAL_ACTION_THRES = 1;
    bool textOnly;
    int hiScore;
    // update 'currPlayerIdx' using: currPlayerIdx = 1 - currPlayerIdx, like
    // taking the NOT of a bit
    int currPlayerIdx;
    std::unique_ptr<Player> p1, p2;
    // raw pointer pointing to the current player, makes it easier to access the
    // actual Player object instead, and relies on 'currPlayerIdx' integer to
    // switch between the two players easily
    Player* currPlayerPointer;
    std::unique_ptr<Board> board1, board2;
    std::unique_ptr<CommandInterpreter> ci;

    // private methods, mechanics to allow our game to run
    void updateHiScore();
    // Returns TRUE when the turn ended successfully, meaning it is now the next
    // player's turn, and FALSE when EOF is reached. Directly mutates the argument
    // to indicate how many rows the player has cleared on their turn. Also
    // indicates whether the current player has lost.
    bool playTurn(int& currTurnRowsCleared, bool& currPlayLost);
    // prompting the player to choose special action(s) depending on 'rowsCleared'
    void promptForSpecAct(int rowsCleared);
    // obtaining valid input from the player when prompting them for special
    // action(s)
    void promptValSpecAct(std::vector<std::string>& validSpecAct);
    // checking for duplicates for the chosen special actions
    void checkDupSpecAct(std::vector<std::string>& specActs);
    // methods relating to the special actions, adding them to a Board and
    // clearing the special actions upon a turn end, as all special actions
    // currently only last one turn for a player
    void addSpecAct(std::string specAct);
    void clearSpecAct();
    // method to add the penalty 1-by-1 block for the current player if they
    // were unable to clear a block within 5 turns when in Level 4
    bool addPenalty();

   public:
    Game(bool textOnly, int seed, string seq1, string seq2, int startLevel);  // Ctor

    // Accessors (and settors?)
    int getLevel(int player) const;
    int getScore(int player) const;
    void updateScoreDestroyedBlock(int increase);

    int getPlayerTurn() const;
    Board *getBoard() const;

    char getState(int board, int row, int col) const override;
    
    void switchPlayerTurn();
    Block *getNextBlock(int p); // For textObserver to fetch the next Block
    void play();
    void restart();
};

#endif
