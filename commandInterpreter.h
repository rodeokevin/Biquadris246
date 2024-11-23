#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <functional>
#include <string>
#include <unordered_map>

#include "game.h"

using namespace std;

class CommandInterpreter {
    Game* game;
    unordered_map<string, function<void()>> commands;

   public:
    CommandInterpreter(Game* game);
    ~CommandInterpreter();

    void parseCommand(const string& command);
};

#endif