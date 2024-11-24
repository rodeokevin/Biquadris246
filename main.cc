#include <iostream>
#include <string>
#include <memory>

#include "block.h"
#include "board.h"
#include "game.h"
#include "observer.h"
#include "textObserver.h"
#include "tile.h"

int main(int argc, char* argv[]) {
  
    // constants indicating the number/range of available levels
    const int LOWEST_LEVEL = 0, HIGHEST_LEVEL = 4;
    // setting up the default options, if none are supplied
    bool textOnly = false;
    int seed = 1;
    std::string seq1 = "sequence1.txt", seq2 = "sequence2.txt";
    int startLevel = 0;

    // iterating through the command line arguments, if any
    int i = 0;

    // very basic command checking, assuming that any command that comes in pairs
    // have their appropriate command name + argument
    while (i < argc) {
        std::string s = argv[i];

        if (s == "-text") textOnly = true;
        else if (s == "-seed") {
            ++i;
            seed = std::stoi(argv[i]);
        } else if (s == "-scriptfile1") {
            ++i;
            seq1 = argv[i];
        } else if (s == "-scriptfile2") {
            ++i;
            seq2 = argv[i];
        } else if (s == "-startlevel") {
            ++i;
            startLevel = std::stoi(argv[i]);

            if (startLevel < LOWEST_LEVEL || startLevel > HIGHEST_LEVEL) {
                std::cerr << "Invalid level range. Available levels range from "
                     << LOWEST_LEVEL << " to " << HIGHEST_LEVEL << ", inclusive."
                     << std::endl;
                
                return 1;
            }
        } else {
            std::cerr << "Invalid command. Valid commands are:\n"
                      << "\t'-text'\n"
                      << "\t'-seed SEEDVAL', replace SEEDVAL with a seed value\n"
                      << "\t'-scriptfile1 FILENAME', replace FILENAME with an existing file name\n"
                      << "\t'-scriptfile2 FILENAME', replace FILENAME with an existing file name\n"
                      << "\t'-startlevel LEVEL', replace LEVEL with an appropriate level\n";
            
            return 1;
        }

        ++i;
    }

    // REMEMBER TO UPDATE 'GAME' AND ITS CTOR
    std::unique_ptr<Game> game(new Game{textOnly, seed, seq1, seq2, startLevel});

    // playing the game, until end of input/file
    game->play();
}
