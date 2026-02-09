#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& vector) {
        if (vector.empty()) return "";

        std::string first = vector[0];
        std::string common;

        bool add_str = true;
        bool break_loop = false;
        for (int i=0; i < first.length(); i++) {
            for (auto& vec: vector) {
                if (i > vec.size()) {
                    break_loop = true;
                    break;
                };
                if (vec[i] != first[i]) {
                    add_str = false;
                    break;
                }
            }
            if (add_str)
                common += first[i];
            if (break_loop) break;
        }
        return common;
    }
};

int main() {
    std::vector<std::string> vector = {std::string("abdh", 1000), std::string("cbd", 10)};
    Solution solution;
    std::cout << solution.longestCommonPrefix(vector)<< std::endl;
    return 0;
}