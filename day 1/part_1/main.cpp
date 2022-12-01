// AoC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <chrono>

struct elf 
{
    uint16_t number{ 0 };
    uint32_t calories{ 0 };
};

std::vector<int> getElves(const char* filename)
{
    std::vector<int> calories;
    std::string line;
    std::ifstream file(filename);

    calories.push_back(0);

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line != "")
            {
                calories.back() += std::stoi(line);

            }
            else
            {
                calories.push_back(0);
            }
        }
        file.close();
    }

    return calories;
}

int findMaxCalories(std::vector<int> elvesCalories)
{
    int maxCalories = 0;

    for (auto calories : elvesCalories)
        if (calories > maxCalories) maxCalories = calories;

    return maxCalories;
}

int main()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    std::vector<int> elvesCalories = getElves("input");
    int highestCalories = findMaxCalories(elvesCalories);

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);


    std::cout << "Amount of elves: " << elvesCalories.size() << std::endl;
    std::cout << "Highest calories: " << highestCalories << std::endl;
    std::cout << "Time to complete: " << duration.count() << " microseconds" << std::endl;

    std::system("pause");
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
