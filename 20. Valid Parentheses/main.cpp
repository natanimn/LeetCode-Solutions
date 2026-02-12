#include <iostream>
#include <stack>
#include <map>

class Solution {
    std::map<char, char> parenthesis = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
public:
    bool isValid(std::string string) {
        if (string.empty()) return false;

        std::stack<char> p;

        bool valid = false;

        for (char s: string) {
            if (p.empty()) {
                if (!parenthesis.contains(s))
                    return false;
                p.push(s);
                valid = false;
            } else if (parenthesis.find(p.top())->second == s) {
                valid = true;
                p.pop();
            } else {
                valid = false;
                p.push(s);
            }
        }
        if (!p.empty()) return false;
        return valid;
    }
};

int main() {
    Solution solution;
    std::cout << solution.isValid("()");
    return 0;
}