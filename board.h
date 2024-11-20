#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "tile.h"
#include "observer.h"

class Observer; // forward declaration

// Our Board class will also be a Subject
class Subject {
  std::vector<Observer*> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual char getState( int row, int col ) const = 0;
  virtual ~Subject() = default;
};

class Board: public Subject {
    std::vector<std::vector<Tile>> grid; // 2D vector representing the Board
    
    public:
        int level; // Current level

        int score = 0; // Current score
        char getState(int row, int col) const override;
        char charAt(int row, int col) const; // Get the char at a specific index
        Board(int level); // Constructor
};

#endif
