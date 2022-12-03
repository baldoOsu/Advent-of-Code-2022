#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <chrono>

std::vector<char> getCommonItems(const char*);
int prioritiesSum(std::vector<char>);
int itemToPriority(char);


int main()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    std::vector<char> commonItems = getCommonItems("input");
    int sum = prioritiesSum(commonItems);

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);

    std::cout << "Priorities sum: " << sum << std::endl;
    std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

    system("pause");

}

std::vector<char> getCommonItems(const char* filename)
{
    // common items will be contained in this vector
    std::vector<char> commonItems;

    std::ifstream file(filename);
    std::string line;

    std::string firstCompartment;
    std::string secondCompartment;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line.size() % 2 == 1) throw "Line size is an odd number"; // this shouldnt happen

            // populate the compartments
            firstCompartment = line.substr(0, line.size()/2);
            secondCompartment = line.substr(line.size()/2, line.size());


            // find if they have a character in common
            // if they do, add to common items
            for (char item : firstCompartment)
            {
                if (secondCompartment.find(item) != std::string::npos)
                {
                    commonItems.push_back(item);
                    break;
                }
            }
        }
    }

    return commonItems;
}

int prioritiesSum(std::vector<char> items)
{
    int sum = 0;
    for (char item : items)
    {
        sum += itemToPriority(item);
    }

    return sum;
}

int itemToPriority(char item)
{
    // A-Z char ASCII ranges from 65-90
    // a-z char ASCII ranges from 97-122
    if ((int)item - 38 >= 27 && (int)item - 38 <= 52)
        return item - 38;
    else
        return item - 96;
}
