```cpp
// LeetCode problem 1226: Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/
// Given a string s, return the number of all possible palindromic substrings.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: O(n^3) - generate all substrings and check if they are palindromes
class SolutionBruteForce {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                std::string substr = s.substr(i, j - i + 1);
                bool isPalindrome = true;
                for (int k = 0; k < substr.size() / 2; k++) {
                    if (substr[k] != substr[substr.size() - k - 1]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Optimal solution: O(n^2) - use dynamic programming to store whether each substring is a palindrome
class Solution {
public:
    int countSubstrings(std::string s) {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::cout << solution.countSubstrings("abc") << std::endl;  // Output: 3
    std::cout << solution.countSubstrings("aaa") << std::endl;  // Output: 6
    std::cout << solution.countSubstrings("abccba") << std::endl;  // Output: 9
    return 0;
}
```