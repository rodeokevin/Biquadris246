#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>

using namespace std;

class CommandInterpreter {
    // Game* game;
    unordered_map<string, string> commands;
    vector<string> builtinCommands;

    void renameCommand(string& commandName, string& newName);
    bool createMacro();
    bool isBuiltinCommand(string& command) const;

   public:
    // CommandInterpreter(Game* game);
    CommandInterpreter();
    ~CommandInterpreter() = default;

    string parseCommand(std::istream& in, string& filename, bool bonus);
    std::string parseSpecAct(std::istream& in) const;
};

#endif
