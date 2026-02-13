#include <iostream>
#include <map>

class Solution {
    std::map<int, std::string> integers = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {400, "CD"},
        {100, "C"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
public:
    std::string intToRoman(int num) {
        if (num == 0) return "";
        if (integers.contains(num)) return integers.find(num) -> second;
        if (num > 1000) return std::string(num / 1000, 'M') + intToRoman(num % 1000);
        if (num > 900)  return "CM" + intToRoman(num % 900);
        if (num > 500)  return std::string(num / 500, 'D') + intToRoman(num % 500);
        if (num > 400)  return "CD" + intToRoman(num % 400);
        if (num > 100)  return std::string(num/100, 'C') + intToRoman(num % 100);
        if (num > 90)   return "XC" + intToRoman(num % 90);
        if (num > 50)   return "L" + intToRoman(num % 50);
        if (num > 40)   return "XL" + intToRoman(num % 40);
        if (num > 10)   return std::string(num/10, 'X') + intToRoman(num % 10);
        if (num > 5)    return "V" + intToRoman(num % 5);
        return "I" + intToRoman(num - 1);
    }
};

int main() {
    Solution solution;
    std::cout << solution.intToRoman(45);
    // std::cout << std::string(3, 'M');
}