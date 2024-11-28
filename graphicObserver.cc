#include "graphicObserver.h"
#include "window.h"
#include <iostream>
#include <string>

using namespace std;

// Colour Code:
/*
IBLock: cyan
JBlock: darkblue
LBlock: orange
OBlock: yellow
ZBlock: green
TBlock: purple
SBlock: red
StarBlock: brown
blindedness: black(?)
*/

// Implementation file for GraphicObserver

GraphicObserver::GraphicObserver(Game *game):game{game} {
    window = std::make_unique<Xwindow>(10*WINDOW_WIDTH, 10*WINDOW_HEIGHT);
    charGrid1.resize(ROWS, std::vector<char>(COLS));
    charGrid2.resize(ROWS, std::vector<char>(COLS));
    nextGrid1.resize(NEXTROWS, std::vector<char>(NEXTCOLS));
    nextGrid2.resize(NEXTROWS, std::vector<char>(NEXTCOLS));
    // Set all to blank initially
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            charGrid1[i][j] = ' ';
            charGrid2[i][j] = ' '; // Set both grids initially to blank
        }
    }
    // Set all to blank initially
    for (int i = 0; i < NEXTROWS; ++i) {
        for (int j = 0; j < NEXTCOLS; ++j) {
            nextGrid1[i][j] = ' ';
            nextGrid2[i][j] = ' '; // Set both grids initially to blank
        }
    }
    // Header
    window->drawString(115, 11, "BIQUADRIS");
    window->drawString(1, 25, "HISCORE: 0");
    window->drawString(195, 25, "TURN: PLAYER 1");
    // Level and score
    window->drawString(9, 43, "LEVEL: 0");
    window->drawString(159, 43, "LEVEL: 0");
    window->drawString(9, 55, "SCORE: 0");
    window->drawString(159, 55, "SCORE: 0");

    // Left grid (l,r,t,b)
    window->fillRectangle(9, 59, 1, 181, Xwindow::Black);
    window->fillRectangle(120, 59, 1, 181, Xwindow::Black);
    window->fillRectangle(9, 59, 112, 1, Xwindow::Black);
    window->fillRectangle(9, 240, 112, 1, Xwindow::Black);

    // Right grid
    window->fillRectangle(159, 59, 1, 181, Xwindow::Black);
    window->fillRectangle(270, 59, 1, 181, Xwindow::Black);
    window->fillRectangle(159, 59, 112, 1, Xwindow::Black);
    window->fillRectangle(159, 240, 112, 1, Xwindow::Black);

    // Next
    window->drawString(10, 260, "NEXT:");
    window->drawString(159, 260, "NEXT:");
}

// Notify
void GraphicObserver::notify() {
    print();
}

void GraphicObserver::notifyWin() {
    /*
    window->fillRectangle(190, 15, 10, 11, Xwindow::Green);
    std::string winningMsg = "Player ";
    winningMsg += std::to_string(game->getPlayerTurn() + 1);
    winningMsg += " has won!";
    window->drawString(190, 25, winningMsg);
    */
}

// Print with blinded effect
void GraphicObserver::print() {
    // Header
    if (game->getHiScore() != prevHighScore) {
        window->fillRectangle(50, 15, 135, 11, Xwindow::White);
        window->drawString(54, 25, std::to_string(game->getHiScore()));
        prevHighScore = game->getHiScore();
    }
    if (game->getPlayerTurn() != prevPlayerIdx) {
        window->fillRectangle(270, 15, 10, 11, Xwindow::White);
        window->drawString(270, 25, std::to_string(2 - prevPlayerIdx));
        prevPlayerIdx = 1 - prevPlayerIdx;
    }

    // Score + Level
    if (game->getLevel(P0_IDX) != p0PrevLevel) {
        window->fillRectangle(45, 33, 15, 11, Xwindow::White);
        window->drawString(50, 43, std::to_string(game->getLevel(P0_IDX)));
        p0PrevLevel = game->getLevel(P0_IDX); 
    }
    if (game->getScore(P0_IDX) != p0PrevScore) {
        window->fillRectangle(45, 45, 80, 11, Xwindow::White);
        window->drawString(50, 55, std::to_string(game->getScore(P0_IDX)));
        p0PrevScore = game->getScore(P0_IDX);
    }
    if (game->getLevel(P1_IDX) != p1PrevLevel) {
        window->fillRectangle(195, 33, 15, 11, Xwindow::White);
        window->drawString(200, 43, std::to_string(game->getLevel(P1_IDX)));
        p1PrevLevel = game->getLevel(P1_IDX); 
    }
    if (game->getScore(P1_IDX) != p1PrevScore) {
        window->fillRectangle(195, 45, 80, 11, Xwindow::White);
        window->drawString(200, 55, std::to_string(game->getScore(P1_IDX)));
        p1PrevScore = game->getScore(P1_IDX);
    }
    

    for (int i = 0; i < ROWS; ++i) {
        // Grid1
        for (int j = 0; j < COLS; ++j) {
            char c = game->getState(P0_IDX,i,j);
            // If it was the same symbol as before, skip
            if (c == charGrid1[i][j]) {
                continue;
            }
            else {
                int colour = getColourForBlock(c);
                window->fillRectangle((j + GRID1LEFT) * 10, (i + GRIDTOP) * 10, 10, 10, colour);
                charGrid1[i][j] = c; // Update the new char
            }
        }
        // Next Block 1 (Player 0)
        for (int j = 0; j < NEXTCOLS; ++j) {
            if (!((i >= 2) && (i <= 3))) break; // Only from index 2 to 3 (bottom 2 rows of the grid)
            char c;
            bool found = false;
            for (int k = 0; k < 4; ++k) {
                if (((game->getNextBlock(P0_IDX))->getCoords())[k].first == j && ((game->getNextBlock(P0_IDX))->getCoords())[k].second == i) {
                    c = game->getNextBlock(P0_IDX)->getBlockSymbol();
                    found = true;
                }
            }
            if (found) {
                if (nextGrid1[i][j] == c) break; // If same symbol, break
                else {
                    int colour = getColourForBlock(c);
                    window->fillRectangle((j + NEXT1LEFT) * 10, (i + NEXTGRIDTOP) * 10, 10, 10, colour);
                    nextGrid1[i][j] = c;// update the next grid 2
                }
            }
            else {
                if (nextGrid1[i][j] != ' ') { // Not found case. If it was not white, change it to white
                    window->fillRectangle((j + NEXT1LEFT) * 10, (i + NEXTGRIDTOP) * 10, 10, 10, Xwindow::White);
                    nextGrid1[i][j] = ' '; // set to blank
                } // Else leave it white
            }
        }
        // Grid2
        for (int j = 0; j < 11; ++j) {
            char c = game->getState(P1_IDX,i,j);
            // If it was the same symbol as before, skip
            if (c == charGrid2[i][j]) {
                continue;
            }
            else {
                int colour = getColourForBlock(c);
                window->fillRectangle((j + GRID2LEFT) * 10, (i + GRIDTOP) * 10, 10, 10, colour);
                charGrid2[i][j] = c; // Update the new char
            }
        }
        // Next Block 1 (Player 0)
        for (int j = 0; j < NEXTCOLS; ++j) {
            if (!((i >= 2) && (i <= 3))) break; // Only from index 2 to 3 (bottom 2 rows of the grid)
            char c;
            bool found = false;
            for (int k = 0; k < 4; ++k) {
                if (((game->getNextBlock(P1_IDX))->getCoords())[k].first == j && ((game->getNextBlock(P1_IDX))->getCoords())[k].second == i) {
                    c = game->getNextBlock(P1_IDX)->getBlockSymbol();
                    found = true;
                }
            }
            if (found) {
                if (nextGrid2[i][j] == c) break; // If same symbol, break
                else {
                    int colour = getColourForBlock(c);
                    window->fillRectangle((j + NEXT2LEFT) * 10, (i + NEXTGRIDTOP) * 10, 10, 10, colour);
                    nextGrid2[i][j] = c; // update the next grid 2
                }
            }
            else {
                if (nextGrid2[i][j] != ' ') { // Not found case. If it was not white, change it to white
                    window->fillRectangle((j + NEXT2LEFT) * 10, (i + NEXTGRIDTOP) * 10, 10, 10, Xwindow::White);
                    nextGrid2[i][j] = ' '; // set to blank
                } // Else leave it white
            }
        }
    }
}

// Helper to get the Color
int GraphicObserver::getColourForBlock(char c) {
    switch (c) {
        case 'I': return Xwindow::Cyan;
        case 'J': return Xwindow::DarkBlue;
        case 'L': return Xwindow::Orange;
        case 'O': return Xwindow::Yellow;
        case 'Z': return Xwindow::Green;
        case 'T': return Xwindow::Purple;
        case 'S': return Xwindow::Red;
        case '*': return Xwindow::Brown;
        case ' ': return Xwindow::White;
        case '?': return Xwindow::Black;
        default: return Xwindow::White; // Default color for unexpected cases
    }
}
