```cpp
// LeetCode problem 1755: Closest Subsequence Sum, https://leetcode.com/problems/closest-subsequence-sum/
// The problem requires finding the closest subsequence sum to the target from the given array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Brute force approach with O(2^n) complexity
class Solution_BruteForce {
public:
    int minAbsDifference(std::vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX;
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    sum += nums[i];
                }
            }
            min_diff = std::min(min_diff, std::abs(target - sum));
        }
        return min_diff;
    }
};

// Optimal solution with O(n * target) complexity
class Solution {
public:
    int minAbsDifference(std::vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX;
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            std::vector<bool> next_dp(target + 1, false);
            for (int j = 0; j <= target; j++) {
                if (dp[j]) {
                    next_dp[j] = true;
                    if (j + nums[i] <= target) {
                        next_dp[j + nums[i]] = true;
                    }
                }
            }
            dp = next_dp;
        }
        for (int i = 0; i <= target; i++) {
            if (dp[i]) {
                min_diff = std::min(min_diff, std::abs(target - i));
            }
        }
        return min_diff;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {9, -10, 7, 4, 2, 4, -8, 7, 5, -3, -5, -7, -2, 2, 4, 8, 3};
    int target1 = -14;
    std::cout << "Test case 1: " << solution.minAbsDifference(nums1, target1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 10;
    std::cout << "Test case 2: " << solution.minAbsDifference(nums2, target2) << std::endl;

    std::vector<int> nums3 = {1, 2, 3};
    int target3 = 5;
    std::cout << "Test case 3: " << solution.minAbsDifference(nums3, target3) << std::endl;

    return 0;
}
```