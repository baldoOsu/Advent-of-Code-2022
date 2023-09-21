#include <iostream>
#include <fstream>

int getMarker(const char* fname);
bool isMarker(char buffer[4]);
int _shiftBuffer(char buffer[4], char newChar);

int main() {
  const char* fname = "input";

  std::cout << getMarker(fname) << std::endl;

  return 0;
}

int getMarker(const char* fname) {
std::ifstream file(fname);

  if (file.is_open()) {
    std::string line;
    char buffer[4];

    while(std::getline(file, line)) {
      for (int i = 0; i < 4; i++) {
        buffer[i] = line[i];
      }

      if (isMarker(buffer))
        return 4;

      for (int i = 4; i < line.size(); i++) {
        _shiftBuffer(buffer, line[i]);

        if (isMarker(buffer)) {
          return i+1;
        }
      }
    }

    file.close();
  }

  return -1;
}
bool isMarker(char buffer[4]) {
  for (int i = 0; i < 3; i++) {
    for (int j = i+1; j < 4; j++) {
      if (buffer[i] == buffer[j])
        return false;
    }
  }

  return true;
}

int _shiftBuffer(char buffer[4], char newChar) {
  for (int i = 0; i < 3; i++)
    buffer[i] = buffer[i+1];

  buffer[3] = newChar;

  return 0;
}
