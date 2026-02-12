#include <iostream>
#include <map>
#include <vector>

class Solution {
   const std::map<char, int> romans = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

public:
  int romanToInt(std::string string) {
    if (string.empty()) return 0;

    int result = 0;
    for (int i = 0; i < string.length(); i++) {
      if (i  + 1 < string.length() && romans.find(string[i]) ->second < romans.find(string[i + 1]) ->second)
        result -= romans.find(string[i])->second;
      else
        result += romans.find(string[i])->second;
      }
    return result;
  }
};
int main() {
  Solution solution;
  std::cout << solution.romanToInt("DI") << std::endl; // Expected 1994
  //
  return 0;
}
