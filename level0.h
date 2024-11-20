#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <fstream>
#include <string>

class Level0: public Level {
    std::string seq1;
    std::string seq2;
    std::ifstream f1;
    std::ifstream f2;

    char readLine(std::ifstream& f);

    public:
        Level0(std::string s1, std::string s2);
        char produceBlock(int player) override;
        ~Level0() override;
};

#endif
