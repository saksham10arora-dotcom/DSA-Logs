```cpp
// LeetCode problem 22: Generate Parentheses Optimized
// https://leetcode.com/problems/generate-parentheses/
// Generate all possible combinations of well-formed parentheses.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: generate all possible combinations of parentheses and check if they are well-formed
// Time complexity: O(4^n / n^(3/2)) due to the Catalan number sequence
// Space complexity: O(4^n / n^(3/2)) for storing the result
class Solution_BruteForce {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate(result, "", 0, 0, n);
        return result;
    }

    void generate(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        if (current.size() == max * 2) {
            if (isValid(current)) {
                result.push_back(current);
            }
            return;
        }
        generate(result, current + "(", open + 1, close, max);
        generate(result, current + ")", open, close + 1, max);
    }

    bool isValid(const std::string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else {
                balance--;
                if (balance < 0) {
                    return false;
                }
            }
        }
        return balance == 0;
    }
};

// Optimal solution: use backtracking to generate well-formed parentheses
// Time complexity: O(4^n / n^(3/2)) due to the Catalan number sequence
// Space complexity: O(4^n / n^(3/2)) for storing the result
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::string> result1 = solution.generateParenthesis(3);
    for (const auto& s : result1) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> result2 = solution.generateParenthesis(1);
    for (const auto& s : result2) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> result3 = solution.generateParenthesis(2);
    for (const auto& s : result3) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
```