```cpp
// LeetCode problem 115: Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/
// Given a string S and a string T, count the number of distinct subsequences of S which equals T.

// Brute force approach: generate all possible subsequences of S and check if they equal T, O(2^n * m) complexity
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int count = 0;
//         int n = s.size(), m = t.size();
//         for (int mask = 0; mask < (1 << n); mask++) {
//             string sub;
//             for (int i = 0; i < n; i++) {
//                 if (mask & (1 << i)) sub += s[i];
//             }
//             if (sub == t) count++;
//         }
//         return count;
//     }
// };

// Optimal solution: dynamic programming, O(n * m) complexity
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    cout << solution.numDistinct("rabbbit", "rabbit") << endl;  // Output: 3
    cout << solution.numDistinct("subscription", "subscription") << endl;  // Output: 1
    cout << solution.numDistinct("subscription", "sub") << endl;  // Output: 6
    return 0;
}
```