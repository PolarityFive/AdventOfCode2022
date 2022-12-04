#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <variant>
#define LOSE 0
#define DRAW 1
#define WIN 2

struct Rock
{
    static const int score = 1;
};

struct Paper
{
    static const int score = 2;
};

struct Scissors
{
    static const int score = 3;
};

void processInput(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<int> &expectedOutcome);
int calculateScore(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<int> &expectedOutcome);
bool isRock(std::variant<Rock, Paper, Scissors> variant);
bool isPaper(std::variant<Rock, Paper, Scissors> variant);
bool isScissors(std::variant<Rock, Paper, Scissors> variant);

int main()
{
    std::vector<std::variant<Rock, Paper, Scissors>> enemyStrategy;
    std::vector<int> expectedOutcome;
    processInput(enemyStrategy, expectedOutcome);

    std::cout << "Final score: " << calculateScore(enemyStrategy, expectedOutcome) << std::endl;

    return 0;
}

void processInput(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<int> &expectedOutcome)
{
    std::ifstream theFile;
    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\strategy.txt)");

    std::string enemyPlay, expectedOutcomeString;

    while (!theFile.eof())
    {
        theFile >> enemyPlay >> expectedOutcomeString;

        if (enemyPlay == "A")
        {
            Rock rock;
            enemyStrategy.emplace_back(rock);
        }
        else if (enemyPlay == "B")
        {
            Paper paper;
            enemyStrategy.emplace_back(paper);
        }
        else
        {
            Scissors scissors;
            enemyStrategy.emplace_back(scissors);
        }

        //EOF Enemy

        if (expectedOutcomeString == "X")
            expectedOutcome.emplace_back(LOSE);
        else if (expectedOutcomeString == "Y")
            expectedOutcome.emplace_back(DRAW);
        else
            expectedOutcome.emplace_back(WIN);
    }
}

int calculateScore(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<int> &expectedOutcome)
{
    int totalScore = 0;
    for (int i = 0; i < enemyStrategy.size(); i++)
    {
        if (expectedOutcome[i] == LOSE)
        {
            if (isRock(enemyStrategy[i]))
                totalScore += Scissors::score;
            else if (isScissors(enemyStrategy[i]))
                totalScore += Paper::score;
            else if (isPaper(enemyStrategy[i]))
                totalScore += Rock::score;
        }
        else if (expectedOutcome[i] == DRAW)
        {
            if (isRock(enemyStrategy[i]))
                totalScore += 3 + Rock::score;
            else if (isScissors(enemyStrategy[i]))
                totalScore += 3 + Scissors::score;
            else if (isPaper(enemyStrategy[i]))
                totalScore += 3 + Paper::score;
        }
        else
        {
            if (isRock(enemyStrategy[i]))
                totalScore += 6 + Paper::score;
            else if (isScissors(enemyStrategy[i]))
                totalScore += 6 + Rock::score;
            else if (isPaper(enemyStrategy[i]))
                totalScore += 6 + Scissors::score;
        }

    }

    return totalScore;
}

bool isRock(std::variant<Rock, Paper, Scissors> variant)
{
    return (std::holds_alternative<Rock>(variant));
}
bool isPaper(std::variant<Rock, Paper, Scissors> variant)
{
    return (std::holds_alternative<Paper>(variant));
}
bool isScissors(std::variant<Rock, Paper, Scissors> variant)
{
    return (std::holds_alternative<Scissors>(variant));
}

