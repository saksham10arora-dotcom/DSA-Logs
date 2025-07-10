```cpp
// Path With Minimum Variant, https://leetcode.com/problems/get-equal-substrings-within-budget/
// Given two strings s and t, return the length of their longest common subsequence.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without disturbing the relative positions of the remaining characters.
// For example, "ace" is a subsequence of "abcde".

// Brute force approach with O(2^n) complexity
// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         int n = s.size();
//         int maxLen = 0;
//         for (int mask = 0; mask < (1 << n); mask++) {
//             int cost = 0;
//             int len = 0;
//             for (int i = 0; i < n; i++) {
//                 if ((mask & (1 << i)) != 0) {
//                     cost += abs(s[i] - t[i]);
//                     len++;
//                 }
//             }
//             if (cost <= maxCost) {
//                 maxLen = max(maxLen, len);
//             }
//         }
//         return maxLen;
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxLen = 0;
        int left = 0;
        int cost = 0;
        for (int right = 0; right < n; right++) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    cout << solution.equalSubstring("abcd", "bcdf", 3) << endl;  // Output: 3
    cout << solution.equalSubstring("abcd", "cdef", 3) << endl;  // Output: 1
    cout << solution.equalSubstring("abcd", "acde", 0) << endl;  // Output: 1
    return 0;
}
```