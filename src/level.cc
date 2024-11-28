#include "level.h"

Level::Level(const int l): level{l} {}

Level::~Level() {}

int Level::getLevel() { return level; }

void Level::setNoRand(std::string s) {}

void Level::setRand() {}
