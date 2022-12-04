#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

#include <chrono>

std::vector<std::array<std::string, 2>> getRanges(const char*);
int getOverlapping(std::vector<std::array<std::string, 2>>);
bool isOverlapping(std::string range1, std::string);


int main()
{
	auto startTimer = std::chrono::high_resolution_clock::now();

	auto ranges = getRanges("input");
	int overlapping = getOverlapping(ranges);

	auto endTimer = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimer - startTimer);

	std::cout << "Is overlapping: " << overlapping << std::endl;
	std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

	system("pause");
}

std::vector<std::array<std::string, 2>> getRanges(const char* filename)
{
	std::ifstream file(filename);
	std::string line;

	std::vector<std::array<std::string, 2>> ranges;

	if (file.is_open())
		while (std::getline(file, line))
		{
			size_t pos = line.find(",");
			ranges.push_back(std::array<std::string, 2>({
				line.substr(0, pos),
				line.substr(pos + 1, line.size()) // pos +1 to ignore the comma
			}));
		}

	return ranges;
}

int getOverlapping(std::vector<std::array<std::string, 2>> rangesVector)
{
	int fullyOverlapping = 0;

	for (auto ranges : rangesVector)
		if (isOverlapping(ranges[0], ranges[1]))
			fullyOverlapping++;

	return fullyOverlapping;
}


bool isOverlapping(std::string range1, std::string range2)
{
	size_t delimiterPos1 = range1.find("-");
	size_t delimiterPos2 = range2.find("-");


	int firstRangeStart = std::stoi(range1.substr(0, delimiterPos1));
	int secondRangeStart = std::stoi(range2.substr(0, delimiterPos2));

	int firstRangeEnd = std::stoi(range1.substr(delimiterPos1 + 1, range1.size()));
	int secondRangeEnd = std::stoi(range2.substr(delimiterPos2 + 1, range2.size()));

	if (firstRangeStart <= secondRangeEnd && secondRangeStart <= firstRangeEnd)
		return true;

	return false;
}