#ifndef PROBS_LEVEL_H
#define PROBS_LEVEL_H
#include "level.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

// for all classes that have to randomly generate blocks following certain
// probabilities
class ProbsLevel: public Level {
    protected:
        // blocks that any of the Levels would return
        const std::vector<char> blocks{'I', 'J', 'L', 'O', 'S', 'Z', 'T'};
        int NUM_BLOCKS = 7;
        // storing the probabilities of each block, same order as in the above vector
        std::vector<float> probs;
        const float total = 1.0f;
        bool noRand;
        std::string seq;
        std::ifstream f;

        // private methods, depending on whether we want randomized blocks
        char produceRandBlock();
        char produceNoRandBlock();

    public:
        ProbsLevel(const int l, const std::vector<float> p);
        void setNoRand(std::string sequence = "") override;
        void setRand() override;
        char produceBlock() override;
        // getters used when switching between levels, to keep the previous level's
        // randomizing settings
        bool isNoRand();
        std::string noRandSeq();
        // dtor
        ~ProbsLevel();
};

#endif
