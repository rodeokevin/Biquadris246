#include "level0.h"

Level0::Level0(const int l, std::string s1, std::string s2): Level{l}, seq1{s1}, seq2{s2}, f1{seq1}, f2{seq2} { level = 0; }

char Level0::readLine(std::ifstream& f) {
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

char Level0::produceBlock(int player) {
    if (player == 0) return readLine(f1);
    else return readLine(f2);
}

Level0::~Level0() {
    f1.close();
    f2.close();
}
