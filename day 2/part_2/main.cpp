// aoc day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    std::cout << "Duration: " << duration.count() << std::endl;

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
        recommendedGameState_decrypted recommendedGameState = (recommendedGameState_decrypted)strategy[2];

        switch (opponent_move)
        {
        case opponentMoves_rock:
            switch (recommendedGameState)
            {
            case recommendedGameState_lose:
                totalPoints += scissorsPoints + losePoints;
                break;
            case recommendedGameState_draw:
                totalPoints += rockPoints + drawPoints;
                break;
            case recommendedGameState_win:
                totalPoints += paperPoints + winPoints;
                break;
            }
            break;

        case opponentMoves_paper:
            switch (recommendedGameState)
            {
            case recommendedGameState_lose:
                totalPoints += rockPoints + losePoints;
                break;
            case recommendedGameState_draw:
                totalPoints += paperPoints + drawPoints;
                break;
            case recommendedGameState_win:
                totalPoints += scissorsPoints + winPoints;
                break;
            }
            break;

        case opponentMoves_scissors:
            switch (recommendedGameState)
            {
            case recommendedGameState_lose:
                totalPoints += paperPoints + losePoints;
                break;
            case recommendedGameState_draw:
                totalPoints += scissorsPoints + drawPoints;
                break;
            case recommendedGameState_win:
                totalPoints += rockPoints + winPoints;
                break;
            }
            break;
        }
    }

    return totalPoints;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
