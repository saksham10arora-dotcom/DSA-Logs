```cpp
// LeetCode problem 2212: Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/
// Given a string s, find the length of the longest palindromic subsequence in s.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: O(2^n) complexity
class Solution_BruteForce {
public:
    int longestPalindromeSubseq(std::string s) {
        return helper(s, 0, s.size() - 1);
    }

    int helper(std::string& s, int start, int end) {
        if (start > end) return 0;
        if (start == end) return 1;
        if (s[start] == s[end]) return 2 + helper(s, start + 1, end - 1);
        return std::max(helper(s, start + 1, end), helper(s, start, end - 1));
    }
};

// Optimal solution: O(n^2) complexity
class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution solution;
    std::cout << solution.longestPalindromeSubseq("bbbab") << std::endl;  // Output: 4
    std::cout << solution.longestPalindromeSubseq("cbbd") << std::endl;   // Output: 2
    std::cout << solution.longestPalindromeSubseq("a") << std::endl;      // Output: 1
    return 0;
}
```