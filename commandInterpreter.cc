#include "commandInterpreter.h"

#include <iostream>
#include <memory>
#include <regex>
#include <sstream>

#include "block.h"

using namespace std;

const int MAX_LEVEL = 4;

void CommandInterpreter::renameCommand(const string& commandName, const string& newName) {
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

CommandInterpreter::CommandInterpreter(Game* game) : game(game) {
    commands["left"] = [this]() { this->game->getBoard()->moveBlock("l"); };
    commands["right"] = [this]() { this->game->getBoard()->moveBlock("r"); };
    commands["down"] = [this]() { this->game->getBoard()->moveBlock("d"); };
    commands["clockwise"] = [this]() { this->game->getBoard()->rotateBlock("CW"); };
    commands["counterclockwise"] = [this]() { this->game->getBoard()->moveBlock("CCW"); };
    commands["drop"] = [this]() { this->game->getBoard()->dropBlock(); };

    commands["levelup"] = [this]() {
        Player* p = this->game->getCurrentPlayer();
        p->setLevel(p->getLevel() + 1);
    };
    commands["leveldown"] = [this]() {
        Player* p = this->game->getCurrentPlayer();
        p->setLevel(p->getLevel() - 1);
    };
    commands["norandom"] = [this]() {
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        // ... set block sequence
        this->game->getCurrentPlayer()->setNoRand(fileName);
    };

    commands["I"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["J"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["L"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["O"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["S"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["Z"] = [this]() { this->game->getBoard()->removeBlock(); };
    commands["T"] = [this]() { this->game->getBoard()->removeBlock(); };

    commands["restart"] = [this]() { this->game->restart(); };
    commands["quit"] = []() {
        cout << "Game Over. Exiting..." << endl;
        exit(0);
    };
    commands["help"] = [this]() {
        std::cout << "Available commands:\n";
        for (const auto& [key, _] : commands) {
            std::cout << "- " << key << "\n";
        }
        std::cout << "You can also prefix commands with a number (e.g., '3left' to move left three times).\n";
    };
    commands["rename"] = [this] {
        std::string commandName, newName;
        std::cout << "Enter command to rename: ";
        std::cin >> commandName;
        std::cout << "Enter new name: ";
        std::cin >> newName;

        try {
            renameCommand(commandName, newName);
            std::cout << "Command renamed from \"" << commandName << "\" to \"" << newName << "\"\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    };
}

string CommandInterpreter::parseCommand() const {
    string input;
    cout << "Enter command: ";
    if (!(cin >> input)) {
        std::cout << "End of input detected. Exiting..." << std::endl;
        exit(0);
    }

    regex commandRegex(R"((\d*)([a-zA-Z]+))");
    smatch matches;
    if (regex_match(input, matches, commandRegex)) {
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
            if (key.find(commandName) == 0) {  // check if input is a prefix of a command
                if (!match.empty()) {
                    // more than one command matches
                    cout << "Ambiguous command : \"" << commandName << "\". Type 'help' for a list of commands." << endl;
                    return "";
                }
                match = key;
            }
        }

        // execute the matched command
        if (!match.empty() && commands.find(match) != commands.end()) {
            for (int i = 0; i < multiplier; ++i) {
                commands.at(match)();
            }
            return match;
        } else {
            cout << "Invalid command: \"" << input << "\". Type 'help' for a list of commands." << endl;
            return "";
        }
    } else {
        std::cout << "Invalid input format: \"" << input << "\". Type 'help' for a list of commands." << std::endl;
        return "";
    }
}
