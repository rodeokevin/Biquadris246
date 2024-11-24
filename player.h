#ifndef PLAYER_H
#define PLAYER_H
#include "level0.h"
#include "probsLevel.h"
#include "probsOfLevels.h"
#include <string>
#include <memory>

class Player {
    const int LOWEST_LVL = 0, HIGHEST_LVL = 4;
    int score;
    std::string seq;
    std::unique_ptr<Level> l;
    std::unique_ptr<ProbsOfLevels> pol;

    public:
        Player(std::string s, int startLevel);
        void setLevel(int levelToSet);
        int getScore();
        int getLevel();
        void setNoRand(std::string s = "");
        void setRand();
        void updateScore(int inc);
        char getBlock();
};

#endif
