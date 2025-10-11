```cpp
// LeetCode problem 115: Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(2^n) complexity
class Solution_BruteForce {
public:
    int numDistinct(std::string s, std::string t) {
        return dfs(s, t, 0, 0);
    }

    int dfs(const std::string& s, const std::string& t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        int count = 0;
        if (s[i] == t[j]) count += dfs(s, t, i + 1, j + 1);
        count += dfs(s, t, i + 1, j);
        return count;
    }
};

// Optimal solution with O(n*m) complexity
class Solution_Optimal {
public:
    int numDistinct(std::string s, std::string t) {
        int n = s.size(), m = t.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution_BruteForce bruteForce;
    Solution_Optimal optimal;

    std::cout << "Brute Force Solution:" << std::endl;
    std::cout << bruteForce.numDistinct("rabbbit", "rabbit") << std::endl;  // Output: 3
    std::cout << bruteForce.numDistinct("subscription", "subscription") << std::endl;  // Output: 1
    std::cout << bruteForce.numDistinct("subscription", "sub") << std::endl;  // Output: 5

    std::cout << "\nOptimal Solution:" << std::endl;
    std::cout << optimal.numDistinct("rabbbit", "rabbit") << std::endl;  // Output: 3
    std::cout << optimal.numDistinct("subscription", "subscription") << std::endl;  // Output: 1
    std::cout << optimal.numDistinct("subscription", "sub") << std::endl;  // Output: 5

    return 0;
}
```