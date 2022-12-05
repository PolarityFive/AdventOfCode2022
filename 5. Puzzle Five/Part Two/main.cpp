#include <string>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <regex>
#include "parser.h"

struct Instructions
{
    int moveAmount = 0;
    int moveFrom = 0;
    int moveTo = 0;
};

void processInstructions(std::vector<Instructions> &instructions);
void move(std::vector<std::stack<char>> &stacks, std::vector<Instructions> &instructions);
std::string replaceWithWhitespace(std::string line);

int main()
{
    std::vector<std::stack<char>> stacks(9);
    std::vector<Instructions> instructions;

    parseStacks(stacks);
    processInstructions(instructions);
    move(stacks, instructions);

    for (auto & stack : stacks)
        std::cout << stack.top();

    return 0;
}

void processInstructions(std::vector<Instructions> &instructions)
{
    std::ifstream theFile;
    std::string line;
    const int ignoredLines = 9;
    int i = 0;
    theFile.open(R"(S:\CLION\CLionProjects\untitled\cargo.txt)");
    while (std::getline(theFile, line))
    {
        if (i > ignoredLines)
        {
            line = replaceWithWhitespace(line);

            Instructions instruction;
            std::stringstream ss(line);

            ss >> instruction.moveAmount >> instruction.moveFrom >> instruction.moveTo;
            instruction.moveFrom -= 1;
            instruction.moveTo -= 1;
            instructions.emplace_back(instruction);
        }
        else
            i++;
    }
    theFile.close();
}

void move(std::vector<std::stack<char>> &stacks, std::vector<Instructions> &instructions)
{
    for (auto & instruction : instructions)
    {
        std::vector<char> chars;

        for (int j = 0; j < instruction.moveAmount; j++)
        {
            chars.emplace_back(stacks[instruction.moveFrom].top());
            stacks[instruction.moveFrom].pop();
        }

        for (int j = chars.size() - 1; j >= 0; j--)
            stacks[instruction.moveTo].push(chars[j]);

    }
}

std::string replaceWithWhitespace(std::string line)
{
    line = std::regex_replace(line, std::regex("move"), " ");
    line = std::regex_replace(line, std::regex("from"), " ");
    line = std::regex_replace(line, std::regex("to"), " ");

    return line;
}
