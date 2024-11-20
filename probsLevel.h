#ifndef PROBS_LEVEL_H
#define PROBS_LEVEL_H
#include "level.h"
#include <vector>
#include <string>
#include <fstream>

// for all classes that have to randomly generate blocks following certain
// probabilities
class ProbsLevel: public Level {
    protected:
        // blocks that any of the Levels would return
        std::vector<char> blocks{'S', 'Z', 'I', 'J', 'L', 'O', 'T'};
        int NUM_BLOCKS = 7;
        // storing the probabilities of each block, same order as in the above vector
        std::vector<float> probs;
        const float total = 1.0f;
        bool noRand;
        std::string seq;
        std::ifstream f;

    public:
        void setNoRand(std::string sequence = "");
        void setRand();
        char produceBlock();
        char produceRandBlock();
        char produceNoRandBlock();
        ~ProbsLevel();
};

#endif
