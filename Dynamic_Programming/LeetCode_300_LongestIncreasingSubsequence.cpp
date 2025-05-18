```cpp
// LeetCode problem 300: Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
// Given an integer array nums, return the length of the longest increasing subsequence.

#include <vector>
#include <algorithm>

class Solution {
public:
    // Brute force approach with O(2^n) complexity
    int lengthOfLIS_BruteForce(std::vector<int>& nums) {
        int n = nums.size();
        int max_length = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<int> subsequence;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    subsequence.push_back(nums[i]);
                }
            }
            if (isIncreasing(subsequence)) {
                max_length = std::max(max_length, (int)subsequence.size());
            }
        }
        return max_length;
    }

    // Optimal solution with O(n^2) complexity
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        std::vector<int> dp(n, 1);
        int max_length = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_length = std::max(max_length, dp[i]);
        }
        return max_length;
    }

    bool isIncreasing(const std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    std::vector<int> nums3 = {7, 6, 5, 4, 3, 2};
    std::cout << solution.lengthOfLIS(nums1) << std::endl;  // Output: 4
    std::cout << solution.lengthOfLIS(nums2) << std::endl;  // Output: 4
    std::cout << solution.lengthOfLIS(nums3) << std::endl;  // Output: 1
    return 0;
}
```