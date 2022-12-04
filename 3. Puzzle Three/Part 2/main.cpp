#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct Group
{
    std::string rucksackOne;
    std::string rucksackTwo;
    std::string rucksackThree;

    char findMatch()
    {
        for (int i = 0; i < this->rucksackOne.size(); i++)
        {
            for (int j = 0; j < this->rucksackTwo.size(); j++)
            {
                if (rucksackOne[i] == rucksackTwo[j])
                {
                    for (int k = 0; k < this->rucksackThree.size(); k++)
                    {
                        if (rucksackOne[i] == rucksackThree[k])
                        {
                            std::cout << "Found match: " << rucksackOne[i] << std::endl;
                            return rucksackOne[i];
                        }
                    }
                }
            }
        }
        return 0;
    }
};

void processInput(std::vector<Group> &groups);
std::vector<char> findMatches(std::vector<Group> groups);
int findPriority(const std::vector<char>& matchedItems);

int main()
{
    std::vector<Group> groups;

    processInput(groups);
    std::vector<char> matches = findMatches(groups);

    std::cout << "Priority of all items: " << findPriority(matches) << std::endl;

    return 0;
}

void processInput(std::vector<Group> &groups)
{
    std::ifstream theFile;
    std::string line;
    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\contents.txt)");
    int i = 0;
    Group group;
    while (getline(theFile, line))
    {
        if (i == 0)
        {
            group.rucksackOne = line;
            i++;
        }
        else if (i == 1)
        {
            group.rucksackTwo = line;
            i++;
        }
        else if (i == 2)
        {
            group.rucksackThree = line;
            groups.emplace_back(group);
            i++;
        }

        if (i > 2)
            i = 0;
    }
}

std::vector<char> findMatches(std::vector<Group> groups)
{
    std::vector<char> matches;

    for (auto & group : groups)
        matches.push_back(group.findMatch());

    return matches;
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
