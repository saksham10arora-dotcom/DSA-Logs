```cpp
// LeetCode problem 1278: Palindrome Partitioning III
// https://leetcode.com/problems/palindrome-partitioning-iii/
// You are given a string s and an integer k. You need to partition the string into k non-empty substrings such that each substring is a palindrome.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Brute force approach with O(2^n * n) complexity
class Solution_BruteForce {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current;
        backtrack(s, 0, current, result);
        return result;
    }

    void backtrack(std::string& s, int start, std::vector<std::string>& current, std::vector<std::vector<std::string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            std::string substr = s.substr(start, end - start + 1);
            if (isPalindrome(substr)) {
                current.push_back(substr);
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(const std::string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};

// Optimal solution with O(n * 2^n) complexity
class Solution_Optimal {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current;
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }
        backtrack(s, 0, current, result, dp);
        return result;
    }

    void backtrack(std::string& s, int start, std::vector<std::string>& current, std::vector<std::vector<std::string>>& result, std::vector<std::vector<bool>>& dp) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (dp[start][end]) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result, dp);
                current.pop_back();
            }
        }
    }
};

int main() {
    Solution_Optimal solution;
    std::string s1 = "aab";
    std::vector<std::vector<std::string>> result1 = solution.partition(s1);
    for (const auto& partition : result1) {
        for (const auto& substr : partition) {
            std::cout << substr << " ";
        }
        std::cout << std::endl;
    }

    std::string s2 = "abba";
    std::vector<std::vector<std::string>> result2 = solution.partition(s2);
    for (const auto& partition : result2) {
        for (const auto& substr : partition) {
            std::cout << substr << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```