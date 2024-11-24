#include "player.h"

Player::Player(std::string s, int startLevel): score{0}, seq{s} {
    setLevel(startLevel);
    pol = std::make_unique<ProbsOfLevels>();
}

void Player::setLevel(int level) {
    if (level < LOWEST_LVL || level > HIGHEST_LVL) return;
    else if (level == 0) l = std::make_unique<Level0>(level, seq);
    else l = std::make_unique<ProbsLevel>(level, pol->obtainLvlProb(level));
}

int Player::getScore() const { return score; }

int Player::getLevel() const { return l->getLevel(); }

void Player::setNoRand(std::string s) { l->setNoRand(s); }

void Player::setRand() { l->setRand(); }

void Player::updateScore(int inc) { score += inc; }

char Player::getBlock() const { return l->produceBlock(); }

void Player::addSpecAct(bool lastWholeTurn, std::string specAct) {
    activeSpecAct.push_back({lastWholeTurn, specAct});
}

void Player::clearSpecAct() { activeSpecAct.clear(); }

void Player::restart() {
    updateScore(-score);
    setLevel(getLevel());
    clearSpecAct();
    lvl4LastClearRow = 0;
}

void Player::turnEnd(bool clearedRow) {
    
}
