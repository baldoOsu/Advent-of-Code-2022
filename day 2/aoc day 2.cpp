// aoc day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <chrono>

int main()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    std::cout << "Hello World!\n";

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);

    std::cout << "Duration: " << duration.count() << std::endl;

    std::system("pause");
}

std::vector<char[2]> getStrategies(const char* filename)
{
    std::ifstream file(filename);
    std::string line;
    
    std::vector<char[2]> strategies;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // line format is "X Y", with X being opponent move and Y being recommended move
            char opponent_move = line[0];
            char own_move = line[2];
            
            strategies.push_back({ opponent_move, own_move });
        }
    }
}

int getTotalPoints(std::vector<char[2]> strategies)
{
    int totalPoints;
    for (auto strategy : strategies)
    {
        char opponent_move = strategy[0];
        char own_move = strategy[1];

        switch (opponent_move)
        {
        case 0:
            switch (own_move)
            {

            }
        }
    }

    return totalPoints;
}


enum gameState
{
    lose = 0,
    win = 6,
    draw = 3
};

int charToPoints(char character)
{
    switch (character)
    {
        case 'A':
            return 

    }
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
