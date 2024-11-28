#include "level0.h"

Level0::Level0(const int l, std::string s): Level{l}, seq{s}, f{seq} {}

char Level0::produceBlock() {
    char c;
    
    // as long as the input file stream finds a character, we read it
    while (f.get(c)) {
        // if it's the newline character, skip over it
        if (c == '\n') continue;
        else return c;
    }

    // upon reaching EOF, we would have to go back to the beginning of the file
    // and start reading from there again
    f.clear();
    f.seekg(0);

    // finding the first non-newline character, and returning it
    while (f.get(c)) {
        if (c == '\n') continue;
        else return c;
    }

    // technically should never get here, unless we get an erroneous empty text file
    // as input
    return 0;
}

Level0::~Level0() {
    f.close();
}
