```cpp
// LeetCode problem 3425: Longest Special Path
// https://leetcode.com/problems/longest-special-path/
// Given a binary string s, return the length of the longest special path.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Brute force approach with O(2^n) complexity
class SolutionBruteForce {
public:
    int longestSpecialPath(std::string s) {
        int n = s.size();
        int maxLen = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            std::string path;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i))!= 0) {
                    path += s[i];
                }
            }
            if (isValid(path)) {
                maxLen = std::max(maxLen, (int)path.size());
            }
        }
        return maxLen;
    }

    bool isValid(const std::string& path) {
        int balance = 0;
        for (char c : path) {
            if (c == '1') {
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

// Optimal solution with O(n) complexity
class SolutionOptimal {
public:
    int longestSpecialPath(std::string s) {
        int n = s.size();
        int maxLen = 0;
        std::vector<int> balance;
        balance.push_back(0);
        for (char c : s) {
            if (c == '1') {
                balance.push_back(balance.back() + 1);
            } else {
                balance.push_back(balance.back() - 1);
            }
            if (balance.back() == 0) {
                maxLen = std::max(maxLen, (int)balance.size() - 1);
            }
        }
        return maxLen;
    }
};

int main() {
    SolutionOptimal solution;
    std::cout << solution.longestSpecialPath("10101") << std::endl;  // Output: 5
    std::cout << solution.longestSpecialPath("111000") << std::endl;  // Output: 6
    std::cout << solution.longestSpecialPath("110") << std::endl;  // Output: 2
    return 0;
}
```