#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct SectorPair
{
    std::pair<int, int> pairOne;
    std::pair<int, int> pairTwo;

    bool hasOverlap() const
    {
        if (this->pairOne.first <= pairTwo.first)
            if (this->pairOne.second >= pairTwo.second)
                return true;

        if (this->pairTwo.first <= pairOne.first)
            if (this->pairTwo.second >= pairOne.second)
                return true;

        return false;
    }
};

void processInput(std::vector<SectorPair> &sectorPairs);
int countOverlaps(std::vector<SectorPair> &sectorPairs);

int main()
{
    std::vector<SectorPair> sectorPairs;
    processInput(sectorPairs);
    std::cout << "Overlaps: " << countOverlaps(sectorPairs) << std::endl;

    return 0;
}

void processInput(std::vector<SectorPair> &sectorPairs)
{
    std::ifstream theFile;
    std::string line;
    SectorPair sectorPair;

    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\sectors.txt)");
    while (std::getline(theFile, line))
    {
        std::replace(line.begin(), line.end(), '-', ' ');
        std::replace(line.begin(), line.end(), ',', ' ');

        std::stringstream ss(line);
        ss >>sectorPair.pairOne.first >> sectorPair.pairOne.second >>
        sectorPair.pairTwo.first >> sectorPair.pairTwo.second;

        sectorPairs.emplace_back(sectorPair);
    }
}

int countOverlaps(std::vector<SectorPair> &sectorPairs)
{
    int count = 0;

    for (auto & sectorPair : sectorPairs)
    {
        if (sectorPair.hasOverlap())
            count++;
    }

    return count;
}