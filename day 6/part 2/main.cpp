#include <iostream>
#include <fstream>

int getMarker(const char* fname);
bool isMarker(char* buffer, int n);
int _shiftBuffer(char* buffer, char newChar, int n);

int main() {
  const char* fname = "input";

  std::cout << getMarker(fname) << std::endl;

  return 0;
}

int getMarker(const char* fname) {
std::ifstream file(fname);

  if (file.is_open()) {
    std::string line;
    const int n = 14;
    char buffer[n];

    while(std::getline(file, line)) {
      for (int i = 0; i < n; i++) {
        buffer[i] = line[i];
      }

      if (isMarker(buffer, n))
        return n;

      for (int i = n; i < line.size(); i++) {
        _shiftBuffer(buffer, line[i], n);

        if (isMarker(buffer, n)) {
          return i+1;
        }
      }
    }

    file.close();
  }

  return -1;
}
bool isMarker(char* buffer, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (buffer[i] == buffer[j])
        return false;
    }
  }

  return true;
}

int _shiftBuffer(char* buffer, char newChar, int n) {
  for (int i = 0; i < n-1; i++)
    buffer[i] = buffer[i+1];

  buffer[n-1] = newChar;

  return 0;
}
