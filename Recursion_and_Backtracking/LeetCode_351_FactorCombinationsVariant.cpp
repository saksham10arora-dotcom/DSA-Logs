```cpp
// LeetCode problem 351: Factor Combinations Variant
// https://leetcode.com/problems/factor-combinations-variants/
// Numbers can be regarded as product of its factors. Write a function to return all factors combinations of a given number.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
class Solution_BruteForce {
public:
    std::vector<std::vector<int>> factorCombinations(int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(result, current, n, 2);
        return result;
    }

    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, int n, int start) {
        if (n == 1) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                current.push_back(i);
                backtrack(result, current, n / i, i);
                current.pop_back();
            }
        }
    }
};

// Optimal solution with O(2^n) complexity
class Solution_Optimal {
public:
    std::vector<std::vector<int>> factorCombinations(int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(result, current, n, 2);
        return result;
    }

    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, int n, int start) {
        if (n == 1) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        for (int i = start; i * i <= n; i++) {
            if (n % i == 0) {
                current.push_back(i);
                backtrack(result, current, n / i, i);
                current.pop_back();
            }
        }
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<std::vector<int>> result1 = solution.factorCombinations(12);
    std::cout << "Test case 1: ";
    for (const auto& combination : result1) {
        std::cout << "(";
        for (int i = 0; i < combination.size(); i++) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ") ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> result2 = solution.factorCombinations(24);
    std::cout << "Test case 2: ";
    for (const auto& combination : result2) {
        std::cout << "(";
        for (int i = 0; i < combination.size(); i++) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ") ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> result3 = solution.factorCombinations(37);
    std::cout << "Test case 3: ";
    for (const auto& combination : result3) {
        std::cout << "(";
        for (int i = 0; i < combination.size(); i++) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ") ";
    }
    std::cout << std::endl;

    return 0;
}
```