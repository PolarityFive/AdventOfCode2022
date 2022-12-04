#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <variant>

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

void processInput(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<std::variant<Rock, Paper, Scissors>> &selfStrategy);
int calculateScore(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<std::variant<Rock, Paper, Scissors>> &selfStrategy);
bool isRock(std::variant<Rock, Paper, Scissors> variant);
bool isPaper(std::variant<Rock, Paper, Scissors> variant);
bool isScissors(std::variant<Rock, Paper, Scissors> variant);
std::pair<int,std::variant<Rock, Paper, Scissors>> getScoreIfIdentical(std::variant<Rock, Paper, Scissors> enemyVariant, std::variant<Rock, Paper, Scissors> selfVariant);

int main()
{
    std::vector<std::variant<Rock, Paper, Scissors>> enemyStrategy, selfStrategy;
    processInput(enemyStrategy, selfStrategy);

    std::cout << "Final score: " << calculateScore(enemyStrategy, selfStrategy) << std::endl;

    return 0;
}

void processInput(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<std::variant<Rock, Paper, Scissors>> &selfStrategy)
{
    std::ifstream theFile;
    theFile.open(R"(C:\Users\arist\CLionProjects\untitled\strategy.txt)");

    std::string enemyPlay, selfPlay;

    while (!theFile.eof())
    {
        theFile >> enemyPlay >> selfPlay;

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

        if (selfPlay == "X")
        {
            Rock rock;
            selfStrategy.emplace_back(rock);
        }
        else if (selfPlay == "Y")
        {
            Paper paper;
            selfStrategy.emplace_back(paper);
        }
        else
        {
            Scissors scissors;
            selfStrategy.emplace_back(scissors);
        }
    }
}

int calculateScore(std::vector<std::variant<Rock, Paper, Scissors>> &enemyStrategy, std::vector<std::variant<Rock, Paper, Scissors>> &selfStrategy)
{
    int totalScore = 0;
    for (int i = 0; i < enemyStrategy.size(); i++)
    {
        std::pair drawScore = getScoreIfIdentical(enemyStrategy[i], selfStrategy[i]);
        if (drawScore.first != -1) {
            totalScore += 3 + drawScore.first;
            continue;
        }

        if (isRock(enemyStrategy[i]) && isPaper(selfStrategy[i]))
            totalScore += 6 + Paper::score;
        else if (isScissors(enemyStrategy[i]) && isRock(selfStrategy[i]))
            totalScore += 6 + Rock::score;
        else if (isPaper(enemyStrategy[i]) && isScissors(selfStrategy[i]))
            totalScore += 6 + Scissors::score;

        if (isRock(enemyStrategy[i]) && isScissors(selfStrategy[i]))
            totalScore += Scissors::score;
        else if (isScissors(enemyStrategy[i]) && isPaper(selfStrategy[i]))
            totalScore += Paper::score;
        else if (isPaper(enemyStrategy[i]) && isRock(selfStrategy[i]))
            totalScore += Rock::score;

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

std::pair<int, std::variant<Rock, Paper, Scissors>> getScoreIfIdentical(std::variant<Rock, Paper, Scissors> enemyVariant, std::variant<Rock, Paper, Scissors> selfVariant)
{
    std::pair<int, std::variant<Rock, Paper, Scissors>> pair;
    pair.first = -1;

    if (isRock(enemyVariant) && isRock(selfVariant))
    {
        pair.first = Rock::score;
        pair.second = selfVariant;
        return pair;
    }

    if (isPaper(enemyVariant) && isPaper(selfVariant))
    {
        pair.first = Paper::score;
        pair.second = selfVariant;
        return pair;
    }

    if (isScissors(enemyVariant) && isScissors(selfVariant))
    {
        pair.first = Scissors::score;
        pair.second = selfVariant;
        return pair;
    }

    return pair;
}


