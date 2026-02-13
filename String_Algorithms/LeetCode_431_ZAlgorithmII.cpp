```cpp
// LeetCode problem 431: Z Algorithm II
// https://leetcode.com/problems/number-of-ways-to-reconstruct-a-string/
// Given a string s and an integer k, return the number of ways to reconstruct s from a dictionary of words.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(2^n * n) - exponential time complexity due to recursive nature
class SolutionBruteForce {
public:
    int numberOfWays(std::string s, int k) {
        std::unordered_map<std::string, int> memo;
        return dfs(s, k, 0, memo);
    }

    int dfs(const std::string& s, int k, int start, std::unordered_map<std::string, int>& memo) {
        if (start == s.size()) return 1;
        std::string key = std::to_string(start) + "," + std::to_string(k);
        if (memo.count(key)) return memo[key];
        int count = 0;
        for (int i = start; i < s.size(); ++i) {
            std::string substr = s.substr(start, i - start + 1);
            if (substr.size() <= k) {
                count += dfs(s, k, i + 1, memo);
            }
        }
        memo[key] = count;
        return count;
    }
};

// Optimal solution: O(n * k) - dynamic programming approach
class Solution {
public:
    int numberOfWays(std::string s, int k) {
        int n = s.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int len = 1; len <= j && i - len >= 0; ++len) {
                    dp[i][j] += dp[i - len][j - len];
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    Solution solution;
    std::cout << solution.numberOfWays("abc", 2) << std::endl;  // Output: 1
    std::cout << solution.numberOfWays("aba", 2) << std::endl;  // Output: 2
    std::cout << solution.numberOfWays("aaaa", 3) << std::endl; // Output: 5
    return 0;
}
```