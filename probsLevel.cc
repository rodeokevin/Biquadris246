#include "probsLevel.h"
#include <cstdlib>

void ProbsLevel::setNoRand(std::string sequence) {
    noRand = true;
    seq = sequence;

    if (f.is_open()) f.close();

    f.open(seq);
}

void ProbsLevel::setRand() {
    noRand = false;
    
    if (f.is_open()) f.close();
}

char ProbsLevel::produceBlock() {
    if (noRand) return produceNoRandBlock();
    else return produceRandBlock();
}

char ProbsLevel::produceRandBlock() {
    float randVal = static_cast<float>(rand()) / RAND_MAX * total;
    float cumulativeProb = 0.0f;

    for (int i = 0; i < NUM_BLOCKS; ++i) {
        if (i == NUM_BLOCKS - 1) return blocks[i];
        
        cumulativeProb += probs[i];

        if (randVal <= cumulativeProb) return blocks[i];
    }

    // technically should never get here, as we ensure that we return one of the
    // available blocks, assuming that the computation of each of the blocks'
    // probabilities is correct
    return 0;
}

char ProbsLevel::produceNoRandBlock() {
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

ProbsLevel::~ProbsLevel() {
    if (f.is_open()) f.close();
}
