#ifndef LEVEL_H
#define LEVEL_H
#include <string>

class Level {
    protected:
        int level;

    public:
        Level(int l);
        virtual ~Level();
        virtual char produceBlock() = 0;
        int getLevel();
        virtual void setNoRand(std::string s = "");
        virtual void setRand();
};

#endif
