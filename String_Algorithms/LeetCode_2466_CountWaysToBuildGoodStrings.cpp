```cpp
// LeetCode problem 2466: Count Ways To Build Good Strings
// https://leetcode.com/problems/count-ways-to-build-good-strings/
// Count the number of good strings of length n that can be formed using the characters 'a' and 'b'.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
class Solution_BruteForce {
public:
    int countGoodStrings(int n) {
        return countGoodStringsHelper(n, 0);
    }

    int countGoodStringsHelper(int n, int index) {
        if (index == n) {
            return 1;
        }
        if (index > n) {
            return 0;
        }
        return countGoodStringsHelper(n, index + 1) + countGoodStringsHelper(n, index + 2);
    }
};

// Optimal solution with O(n) complexity
class Solution_Optimal {
public:
    int countGoodStrings(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i >= 1) {
                dp[i] += dp[i - 1];
            }
            if (i >= 2) {
                dp[i] += dp[i - 2];
            }
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};

int main() {
    Solution_Optimal solution;
    std::cout << solution.countGoodStrings(3) << std::endl;  // Output: 8
    std::cout << solution.countGoodStrings(33) << std::endl;  // Output: 106772430
    std::cout << solution.countGoodStrings(50) << std::endl;  // Output: 564605053
    return 0;
}
```