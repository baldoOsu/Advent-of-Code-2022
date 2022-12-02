#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <chrono>

#include "enums.h"

std::vector<std::string> getStrategies(const char*);
int getTotalPoints(std::vector<std::string>);


int main()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    std::vector<std::string> strategies = getStrategies("input");
    int totalPoints = getTotalPoints(strategies);

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);

    std::cout << "Total Points: " << totalPoints << std::endl;
    std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

    std::system("pause");
}

std::vector<std::string> getStrategies(const char* filename)
{
    std::ifstream file(filename);
    std::string line;
    
    std::vector<std::string> strategies = {};

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // line format is "X Y", with X being opponent move and Y being recommended move
            strategies.push_back(line);
        }
    }

    return strategies;
}

int getTotalPoints(std::vector<std::string> strategies)
{
    int totalPoints = 0;
    for (auto strategy : strategies)
    {
        opponentMoves_decrypted opponent_move = (opponentMoves_decrypted)strategy[0];
        recommendedMoves_decrypted recommendedGameState = (recommendedMoves_decrypted)strategy[2];

        switch (opponent_move)
        {
        case opponentMoves_rock:
            switch (recommendedGameState)
            {
            case recommendedMoves_rock:
                totalPoints += rockPoints + drawPoints;
                break;
            case recommendedMoves_paper:
                totalPoints += paperPoints + winPoints;
                break;
            case recommendedMoves_scissors:
                totalPoints += scissorsPoints + losePoints;
                break;
            }
            break;

        case opponentMoves_paper:
            switch (recommendedGameState)
            {
            case recommendedMoves_rock:
                totalPoints += rockPoints + losePoints;
                break;
            case recommendedMoves_paper:
                totalPoints += paperPoints + drawPoints;
                break;
            case recommendedMoves_scissors:
                totalPoints += scissorsPoints + winPoints;
                break;
            }
            break;
        case opponentMoves_scissors:
            switch (recommendedGameState)
            {
            case recommendedMoves_rock:
                totalPoints += rockPoints + winPoints;
                break;
            case recommendedMoves_paper:
                totalPoints += paperPoints + losePoints;
                break;
            case recommendedMoves_scissors:
                totalPoints += scissorsPoints + drawPoints;
                break;
            }
            break;
        }
    }

    return totalPoints;
}
