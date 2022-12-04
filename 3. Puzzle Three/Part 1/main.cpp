#include <string>
#include <fstream>
#include <iostream>
#include <vector>

void processInput(std::vector<std::string> &compartmentOne, std::vector<std::string> &compartmentTwo);
std::vector<char> findMatches(std::vector<std::string> &compartmentOne, std::vector<std::string> &compartmentTwo);
int findPriority(const std::vector<char>& matchedItems);

int main()
{
    std::vector<std::string> compartmentOne;
    std::vector<std::string> compartmentTwo;

    processInput(compartmentOne, compartmentTwo);
    std::vector<char> matchedItems = findMatches(compartmentOne, compartmentTwo);

    std::cout << "Priority of all items: " << findPriority(matchedItems) << std::endl;

    return 0;
}

void processInput(std::vector<std::string> &compartmentOne, std::vector<std::string> &compartmentTwo)
{
    std::ifstream theFile;
    std::string line;
    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\contents.txt)");

    while (getline(theFile, line))
    {
        std::string firstHalf = line.substr(0, line.length()/2);
        std::string secondHalf = line.substr(line.length()/2);

        compartmentOne.emplace_back(firstHalf);
        compartmentTwo.emplace_back(secondHalf);
    }
}

std::vector<char> findMatches(std::vector<std::string> &compartmentOne, std::vector<std::string> &compartmentTwo)
{
    std::vector<char> matchedItems;
    bool matched;

    for (int i = 0; i < compartmentOne.size(); i++)
    {
        for (int j = 0; j < compartmentOne[i].length(); j++)
        {
            matched = false;
            for (int k = 0; k < compartmentOne[i].length(); k++)
            {
                if (compartmentOne[i][j] == compartmentTwo[i][k])
                {
                    matchedItems.emplace_back(compartmentOne[i][j]);
                    matched = true;
                }
                if (matched)
                    break;
            }
            if (matched)
                break;
        }
    }

    return matchedItems;
}

int findPriority(const std::vector<char>& matchedItems)
{
    int prioritySum = 0;

    for (char matchedItem : matchedItems)
    {
        if (islower(matchedItem))
            prioritySum += static_cast<int>(matchedItem) - 96;
        else
            prioritySum += static_cast<int>(matchedItem) - 38;
    }

    return prioritySum;
}
