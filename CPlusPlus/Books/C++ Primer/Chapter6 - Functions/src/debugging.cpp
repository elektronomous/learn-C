#include <iostream>
#include <string>
#include <cassert>

using std::cin,
      std::cout,
      std::endl,
      std::string;

inline bool isLower(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}
inline bool isGreater(const string &s1, const string &s2) {
  return s1.size() > s2.size();
}

auto chooseMode(const string &s) -> bool (*)(const string &, const string &) {
  if (s == "lower")
    return isLower;
  
  return isGreater;
}

int main(void) {
  
}
