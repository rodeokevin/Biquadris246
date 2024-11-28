#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <functional>
#include <string>
#include <unordered_map>


using namespace std;

class CommandInterpreter {
    // Game* game;
    unordered_map<string, string> commands;

    void renameCommand(string& commandName, string& newName);

   public:
    // CommandInterpreter(Game* game);
    CommandInterpreter();
    ~CommandInterpreter() = default;

    string parseCommand(std::istream& in, int& multiplier, string& filename);
    std::string parseSpecAct(std::istream& in) const;
};

#endif
