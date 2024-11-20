#include "level1.h"

Level1::Level1(const float sProb, const float zProb) {
    level = 1;
    noRand = false;
    // we have 'NUM_BLOCKS - 2' other blocks for which we must equally divide
    // the probability amongst
    const int OTHER_BLOCKS = NUM_BLOCKS - 2;
    float otherProbs = (total - sProb - zProb) / OTHER_BLOCKS;

    probs.push_back(sProb);
    probs.push_back(zProb);
    
    for (int _ = 0; _ < OTHER_BLOCKS; ++_) probs.push_back(otherProbs);
}
