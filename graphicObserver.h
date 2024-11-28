#ifndef _GRAPHICOBSERVER__H_
#define _GRAPHICOBSERVER__H_
#include "observer.h"
#include "game.h"
#include "board.h"
#include "window.h"
#include <iostream>
#include <vector>
#include <memory>

// Graphic observer
class GraphicObserver: public Observer {
    const int ROWS = 18, COLS = 11;
    const int NEXTROWS = 4, NEXTCOLS = 4;

    const int BLINDL = 2, BLINDR = 8, BLINDT = 2, BLINDB = 11;
    const int WINDOW_WIDTH = 28;
    const int WINDOW_HEIGHT = 31;

    const int GRID1LEFT = 1; // How many tiles Grid1 is shifted left
    const int GRID2LEFT = 16; // How many tiles Grid2 is shifted
    const int GRIDTOP = 6;

    const int NEXT1LEFT = 1;
    const int NEXT2LEFT = 16;
    const int NEXTGRIDTOP = 25;
    const int P0_IDX = 0, P1_IDX = 1;

    int prevPlayerIdx = 0;
    int prevHighScore = 0;
    int p0PrevLevel = 0;
    int p1PrevLevel = 0;
    int p0PrevScore = 0;
    int p1PrevScore = 0;


    // Window for this Observer
    std::unique_ptr<Xwindow> window = nullptr;
    // Pointer to the Game subject
    Game *game;
    // Char version of the grids to check what needs to be redrawn
    std::vector<std::vector<char>> charGrid1;
    std::vector<std::vector<char>> charGrid2;

    // Char version of the grid for next block (4x4 grid), but we will only loop the bottom half
    std::vector<std::vector<char>> nextGrid1;
    std::vector<std::vector<char>> nextGrid2;

    int getColourForBlock(char c);
    void print();

    public:
        GraphicObserver(Game *game); // Ctor
        void notify() override;
        ~GraphicObserver() = default;
};

#endif
