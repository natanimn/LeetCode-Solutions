#include <iostream>
#include <map>

class Solution {
    std::map<char, int> numbers = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
    };
public:
    int myAtoi(const std::string& string) {
        long long val = 0;
        bool negative = false;
        bool skipped_zero = false;
        for (const auto& s: string) {
            if (s == ' ' && val == 0 && !skipped_zero)
                continue;
            if (val == 0 && s == '0') skipped_zero = true;
            else if (s == '+' && val == 0 && !skipped_zero) skipped_zero = true;
            else if (s == '-' && val == 0 && !skipped_zero) {
                negative = true;
                skipped_zero = true;
            }
            else if (!numbers.contains(s)) break;
            else {
                val += numbers.find(s) -> second;
                if (val > INT_MAX) {
                    if (negative)
                        return INT_MIN;
                    return INT_MAX;
                }
                val*=10;
            }

            if (!skipped_zero) skipped_zero = true;
        }

        val /= 10;
        if (negative) val = -val;
        return val;
    }
};

int main() {

    Solution solution;
    std::cout << solution.myAtoi("2147483646");
    return 0;
}