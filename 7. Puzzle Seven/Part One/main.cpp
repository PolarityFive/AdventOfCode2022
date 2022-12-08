#include <iostream>
#include <fstream>
#include <vector>
#include "RegexUtil/RegexUtil.h"
#include "System/System.h"
#include "StringUtil/StringUtil.h"

void processInput(std::vector<std::string> &commands);
void constructTree(std::vector<std::string> &commands, System &system);

int main() {

    System system = System();
    std::vector<std::string> commands;
    processInput(commands);
    constructTree(commands, system);

    std::cout << system.solve() << std::endl;
    return 0;
}

void processInput(std::vector<std::string> &commands)
{
    std::ifstream theFile;
    std::string line;
    theFile.open(R"(S:\CLION\CLionProjects\untitled\system.txt)");

    while (std::getline(theFile, line))
    {
        commands.emplace_back(line);
    }
}

void constructTree(std::vector<std::string> &commands, System &system)
{
    system.rootDir->name = "/";
    system.currentDir = system.rootDir;

    for (int i = 1; i < commands.size(); i++)
    {
        if (RegexUtil::isCd(commands[i]))
            system.cd(StringUtil::getDirNameForCd(commands[i]));
        else if (RegexUtil::isCdBack(commands[i]))
            system.cdBack();
        else if(RegexUtil::isDir(commands[i]))
        {
            Node *newDir = new Node();
            newDir->name = StringUtil::getDirName(commands[i]);
            system.addDir(newDir);
        }
        else if (RegexUtil::isFile(commands[i]))
        {
            uintptr_t size = StringUtil::getFileSize(commands[i]);
            system.addSize(size);
            system.calcParentalSize(size);
        }
    }
}