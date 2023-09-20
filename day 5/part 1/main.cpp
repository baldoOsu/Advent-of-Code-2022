#include <vector>
#include <fstream>
#include <iostream>
#include <assert.h>
#include <cmath>

int populateStacks(std::ifstream& file, std::vector<char> stacks[9]);
int populateProcedures(std::ifstream& file, std::vector<int*>& procedures);
int* getProcedure(std::string line);
int applyProcedures(std::vector<char> stacks[9], std::vector<int*> procedures);
char* getResult(std::vector<char> stacks[9]);

int _extractNumFromString(std::string input, size_t idx1, size_t idx2);

int main() {
  std::vector<char> stacks[9];
  std::vector<int*> procedures;

  std::ifstream file("./input");
  std::string line;

  if (file.is_open()) {
    int success = populateStacks(file, stacks);
    if (success) {
      std::cout << "Something went wrong at populating stacks..." << std::endl;
      exit(1);
    }

    std::cout << "Crates: " << std::endl;
    for (int i = 0; i < 9; i++) {
      std::cout << i << ". ";
      for (char j : stacks[i])
        std::cout << "[" << j << "] ";

      std::cout << std::endl;
    }

    std::getline(file, line); // get the empty line out of the way

    populateProcedures(file, procedures);
    applyProcedures(stacks, procedures);
    std::cout << "Crates: " << std::endl;
    for (int i = 0; i < 9; i++) {
      std::cout << i << ". ";
      for (char j : stacks[i])
        std::cout << "[" << j << "] ";

      std::cout << std::endl;
    }
    char* result = getResult(stacks);

    for (int i = 0; i < 9; i++)
      std::cout << result[i];

    std::cout << std::endl;
  } else return 1;

  return 0;
}

int populateStacks(std::ifstream& file, std::vector<char> stacks[9]) {
  std::string line;
  while (std::getline(file, line)) {
    // means crates have all been populated
    if (line[1] == '1')
      return 0;


    for (int i = 1; i < 36; i += 4) {
      if (line[i] != ' ')
        stacks[i/4].push_back(line[i]);
    }
  }

  return 1;
}

int populateProcedures(std::ifstream& file, std::vector<int*>& procedures) {
  std::string line;
  while (std::getline(file, line)) {
    procedures.push_back(getProcedure(line));
  }

  return 0;
}

int* getProcedure(std::string line) {
  int* info = new int[3];

  size_t idx = line.find(' ');
  for (int i = 0; i < 2; i++) {
    size_t idx2 = line.find(' ', idx+1);
    info[i] = _extractNumFromString(line, idx, idx2)-i; // -i will get the index for the "from" stack, but not impact how many crates are moved
    idx = line.find(' ', idx2+1);
  }
  info[2] = _extractNumFromString(line, idx, line.length())-1;

  return info;
}

int applyProcedures(std::vector<char> stacks[9], std::vector<int*> procedures) {
  int k = 0;
  for (int* procedure : procedures) {
    
    for (int i = 0; i < procedure[0]; i++) {
      stacks[procedure[2]].insert(stacks[procedure[2]].begin(), stacks[procedure[1]].at(0));
      stacks[procedure[1]].erase(stacks[procedure[1]].begin());
    }
    k++;
  }

  return 0;
}

char* getResult(std::vector<char> stacks[9]) {
  char* result = new char[9];
  for (int i = 0; i < 9; i++) {
    result[i] = stacks[i].at(0);
  }

  return result;
}

int _extractNumFromString(std::string input, size_t idx1, size_t idx2) {
  int num = 0;
  for (int i = 1; i < idx2 - idx1; i++) {
    num += (input[idx1 + i] - 48) * std::pow(10, idx2-idx1-i-1); // 0 begins at 48 in ascii
  }

  return num;
}