#include "commandInterpreter.h"

CommandInterpreter::CommandInterpreter(Game* game) : game(game) {
    commands["left"] = [this]() { this->game->getBoard()->moveBlock("l"); };
    commands["right"] = [this]() { this->game->getBoard()->moveBlock("r"); };
    commands["down"] = [this]() { this->game->getBoard()->moveBlock("d"); };
    commands["clockwise"] = [this]() { this->game->getBoard()->rotateBlock("CW"); };
    commands["counterclockwise"] = [this]() { this->game->getBoard()->moveBlock("CCW"); };
    commands["drop"] = [this]() { this->game->getBoard()->dropBlock(); };

    commands["levelup"] = [this]() { this->game->() };
    commands["leveldown"] = [this]() { this->game->() };
    commands["norandom"] = [this]() {
        std::string fileName;
        std::cin >> fileName;
        // ... set block sequence
    };

    for (std::string blockType : {"I", "J", "L", "O", "S", "Z", "T"}) {
        commands[blockType] = [this, blockType]() {};
    }

    commands["restart"] = [this]() { game->restart(); };
}