#ifndef LEVEL_H
#define LEVEL_H

class Level {
    protected:
        int level;

    public:
        Level(int l);
        virtual ~Level();
        virtual char produceBlock() = 0;
        int getLevel();
        virtual void outputProbs();
};

#endif
