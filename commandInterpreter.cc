#include "commandInterpreter.h"

#include <iostream>
#include <memory>
#include <regex>
#include <sstream>

#include "block.h"

using namespace std;

const int MAX_LEVEL = 4;

void CommandInterpreter::renameCommand(string& commandName, string& newName) {
    auto it = commands.find(commandName);
    if (it == commands.end()) {
        throw std::runtime_error("Error: Command \"" + commandName + "\" not found.");
    }
    if (commands.find(newName) != commands.end()) {
        throw std::runtime_error("Error: Command \"" + newName + "\" already exists.");
    }

    commands[newName] = it->second;
    commands.erase(it);
}

bool CommandInterpreter::createMacro() {
    string name;
    string macroCommands;
    cout << "Defining a Macro. Enter macro name: ";
    if (!(cin >> name)) {
        return false;
    }
    cout << "Macro will be named \"" << name
         << "\". Enter commands, using their full names. Commands multipliers are accepted (e.g. 3left 2clockwise): "
         << endl;
    std::cin.ignore(1, '\n');
    if (!(getline(cin, macroCommands))) {
        return false;
    }
    commands[name] = macroCommands;
    cout << "Macro created: " << name << "->" << macroCommands << endl;
    return true;
}

bool CommandInterpreter::isBuiltinCommand(string& command) const {
    for (string s : builtinCommands) {
        if (command == s) {
            return true;
        }
    }
    return false;
}

CommandInterpreter::CommandInterpreter() {
    builtinCommands = {
        "left",
        "right",
        "down",
        "clockwise",
        "counterclockwise",
        "drop",
        "levelup",
        "leveldown",
        "sequence",
        "I",
        "J",
        "L",
        "O",
        "S",
        "Z",
        "T",
        "restart",
        "norandom",
        "random",
        "help",
        "rename",
        "macro"};

    for (string s : builtinCommands) {
        commands[s] = s;
    }
}

string CommandInterpreter::parseCommand(std::istream& in, string& filename) {
    string input;

    if (!(getline(in, input))) {
        return "EOF";
    }

    istringstream iss{input};
    string first, second, third;
    iss >> first >> second >> third;

    regex commandRegex(R"((\d*)([a-zA-Z]+))");
    smatch matches;
    if (regex_match(first, matches, commandRegex)) {
        int multiplier = 1;
        string commandName;

        // check if a multiplier is provided
        if (matches[1].matched && !matches[1].str().empty()) {
            multiplier = stoi(matches[1].str());
        }

        commandName = matches[2].str();
        // try to match the command name to a registered command
        string match;
        for (const auto& [key, value] : commands) {
            if (key.find(commandName) == 0) {  // check if first is a prefix of a command
                if (!match.empty()) {
                    // more than one command matches
                    cout << "Ambiguous command: \"" << commandName << "\". Type 'help' for a list of commands." << endl;
                    return "";
                }
                match = value;  // Set the match to the value
            }
        }
        // If we didn't find a command, reprompt
        if (match.empty()) {
            std::cout << "No command found: " << commandName << std::endl;
        }
        // check for commands with multiple arguments or special commands
        if (match == "sequence" || match == "norandom") {
            filename = second;
        } else if (match == "rename") {
            try {
                renameCommand(second, third);
                std::cout << "Command renamed from \"" << second << "\" to \"" << third << "\"\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (match == "macro") {
            if (!createMacro()) {
                return "EOF";
            }
            return "";
        } else if (match == "help") {
            cout << "Available commands:\n";
            for (const auto& [key, _] : commands) {
                cout << "- " << key << "\n";
            }
            cout << "You can also prefix commands with a number (e.g., '3left' to move left three times).\n";
        }
        if (isBuiltinCommand(match)) {
            return to_string(multiplier) + match;
        } else {
            return match;
        }
    } else {
        std::cout << "Invalid input format: \"" << first << "\". Type 'help' for a list of commands." << std::endl;
        return "";
    }
}

std::string CommandInterpreter::parseSpecAct(std::istream& in) const {
    cout << "Choose a special action (blind, heavy, force <blockType>): ";
    string input;

    if (!getline(in, input)) {
        return "EOF";
    }

    // match the three special actions
    std::regex blindPattern("^b(l(i(n(d)?)?)?)?$", std::regex::icase);
    std::regex heavyPattern("^h(e(a(v(y)?)?)?)?$", std::regex::icase);
    std::regex forcePattern("^(f(o(r(c(e)?)?)?)?)\\s+(I|J|L|O|S|Z|T)$", std::regex::icase);

    if (regex_match(input, blindPattern)) {
        return "blind";
    } else if (regex_match(input, heavyPattern)) {
        return "heavy";
    } else if (regex_match(input, forcePattern)) {
        // extract block type for force
        std::smatch match;
        if (regex_search(input, match, forcePattern)) {
            //
            if (match[6].matched) {
                return match[6];
            }
        }
        cout << "Invalid block type for 'force'.\n";
        return "";
    } else {
        // invalid input
        cout << "Invalid special action. No action will be applied.\n";
        return "";
    }
}
