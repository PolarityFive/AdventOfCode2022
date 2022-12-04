#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream theFile;
    std::string line;
    int currentSum = 0, max = 0, secondMax = 0, thirdMax = 0;

    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\calories.txt)");

    while(std::getline(theFile, line))
    {

        if (line.empty() || theFile.eof())
        {
            if (theFile.eof())
                currentSum = currentSum + std::stoi(line);

            if (currentSum > max)
            {
                thirdMax = secondMax;
                secondMax = max;
                max = currentSum;
            }

            if (currentSum > secondMax && currentSum < max)
            {
                thirdMax = secondMax;
                secondMax = currentSum;
            }

            if (currentSum > thirdMax && currentSum < max && currentSum < secondMax)
            {
                thirdMax = currentSum;
            }

            currentSum = 0;

        }
        else
        {
            currentSum = currentSum + std::stoi(line);
        }

    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Second Max: " << secondMax << std::endl;
    std::cout << "Third Max: " << thirdMax << std::endl;

    std::cout << "Total: " << max + secondMax + thirdMax << std::endl;

    return 0;
}