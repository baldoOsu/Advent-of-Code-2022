#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <chrono>

std::vector<char> getBadges(const char*);
char findBadgeForGroup(std::string[3]);
int prioritiesSum(std::vector<char>);
int itemToPriority(char);


int main()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    std::vector<char> commonItems = getBadges("input");
    int sum = prioritiesSum(commonItems);

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);

    std::cout << "Priorities sum: " << sum << std::endl;
    std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

    system("pause");
}

std::vector<char> getBadges(const char* filename)
{
    // common items will be contained in this vector
    std::vector<char> badges;

    std::ifstream file(filename);
    std::string line;

    std::string group[3];

    if (file.is_open())
    {
        // index the groups
        int x = 0;
        while (std::getline(file, line))
        {
            if (x != 2)
                group[x] = line;
            else
            {
                group[x] = line;
                badges.push_back(findBadgeForGroup(group));

                x = 0;
                continue;
            }

            x++;
        }
    }

    return badges;
}

char findBadgeForGroup(std::string group[3])
{
    for (char item : group[0])
    {
        // std::string::find() returns std::string::npos if value isn't found
        if (group[1].find(item) != std::string::npos)
            if (group[2].find(item) != std::string::npos)
                return item;
    }
    throw "Badge not found!"; // this shouldnt happen
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
