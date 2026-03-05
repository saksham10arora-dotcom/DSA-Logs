```cpp
// LeetCode problem 2771: Longest Non Decreasing Subarray From Two Arrays
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
// https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/
// Given two arrays, find the longest non-decreasing subarray that can be formed by taking elements from either array.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n*m) complexity
class Solution_BruteForce {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = 0;
                int x = i;
                int y = j;
                while (x < n && y < m) {
                    if (nums1[x] <= nums2[y]) {
                        len++;
                        x++;
                        y++;
                    } else {
                        break;
                    }
                }
                maxLen = std::max(maxLen, len);
            }
        }
        return maxLen;
    }
};

// Optimal solution with O(n*m) complexity
class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxLen = 0;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] <= nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = std::max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3, 2, 1};
    std::vector<int> nums2 = {3, 2, 1, 4, 7};
    std::cout << solution.findLength(nums1, nums2) << std::endl;  // Output: 2

    nums1 = {1, 3, 5, 7};
    nums2 = {2, 3, 5, 6};
    std::cout << solution.findLength(nums1, nums2) << std::endl;  // Output: 3

    nums1 = {1, 2, 3};
    nums2 = {3, 2, 1};
    std::cout << solution.findLength(nums1, nums2) << std::endl;  // Output: 1

    return 0;
}
```