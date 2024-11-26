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

    void renameCommand(const string& commandName, const string& newName);

   public:
    CommandInterpreter(Game* game);
    ~CommandInterpreter();

    string parseCommand() const;
};

#endif