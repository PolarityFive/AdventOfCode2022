#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream theFile;
    std::string line;
    int currentSum = 0, max = 0;

    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\calories.txt)");

    while(std::getline(theFile, line))
    {

        if (line.empty())
        {
            currentSum = 0;
        }
        else
        {
            currentSum = currentSum + std::stoi(line);
        }

        if (currentSum > max)
        {
            max = currentSum;
        }

    }

    std::cout << max;
    return 0;
}