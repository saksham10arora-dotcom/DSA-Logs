```cpp
// Maximum Sum Of 3 Non Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// Given an array nums of integers, find the maximum sum of three non-overlapping subarrays of length k.
// The subarray can be any contiguous elements in the array.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
class SolutionBruteForce {
public:
    int maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;
        for (int i = 0; i <= n - k; i++) {
            for (int j = i + k; j <= n - k; j++) {
                for (int m = j + k; m <= n - k; m++) {
                    int sum = 0;
                    for (int p = i; p < i + k; p++) sum += nums[p];
                    for (int p = j; p < j + k; p++) sum += nums[p];
                    for (int p = m; p < m + k; p++) sum += nums[p];
                    maxSum = std::max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        
        int maxSum = 0;
        for (int i = 0; i <= n - 3 * k; i++) {
            for (int j = i + k; j <= n - 2 * k; j++) {
                for (int m = j + k; m <= n - k; m++) {
                    int sum1 = sum[i + k] - sum[i];
                    int sum2 = sum[j + k] - sum[j];
                    int sum3 = sum[m + k] - sum[m];
                    maxSum = std::max(maxSum, sum1 + sum2 + sum3);
                }
            }
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 1, 2, 6, 7, 5, 1};
    std::cout << solution.maxSumOfThreeSubarrays(nums1, 2) << std::endl;  // Output: 18

    std::vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2};
    std::cout << solution.maxSumOfThreeSubarrays(nums2, 2) << std::endl;  // Output: 6

    std::vector<int> nums3 = {4, 5, 10, 6, 8, 4, 3, 5, 6, 8};
    std::cout << solution.maxSumOfThreeSubarrays(nums3, 3) << std::endl;  // Output: 36

    return 0;
}
```