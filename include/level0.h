#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <fstream>
#include <string>

class Level0: public Level {
    std::string seq;
    std::ifstream f;

    char readLine(std::ifstream& f);

    public:
        Level0(const int l, std::string s);
        char produceBlock() override;
        ~Level0() override;
};

#endif
