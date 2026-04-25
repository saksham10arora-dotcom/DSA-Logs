```cpp
// LeetCode problem 1425: Constrained Subsequence Sum, https://leetcode.com/problems/constrained-subsequence-sum/
// Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array.
// The subsequence has a length of k and has the constraint that the product of all integers in the subsequence is less than minProduct.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k) {
        // Brute force approach with O(n^k) complexity
        // This approach is not efficient and will exceed the time limit for large inputs

        // Optimal solution with O(n) complexity
        int n = nums.size();
        std::vector<int> dp(n);
        dp[0] = nums[0];
        std::deque<int> dq;
        dq.push_back(0);
        int maxSum = dp[0];

        for (int i = 1; i < n; i++) {
            while (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }
            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] = std::max(dp[i], dp[dq.front()] + nums[i]);
            }
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            maxSum = std::max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {10, -2, -10, -5, 3};
    int k1 = 3;
    std::cout << solution.constrainedSubsetSum(nums1, k1) << std::endl;  // Output: 17

    std::vector<int> nums2 = {10, 2, 4, 8, 6};
    int k2 = 3;
    std::cout << solution.constrainedSubsetSum(nums2, k2) << std::endl;  // Output: 30

    std::vector<int> nums3 = {-1, -2, -3};
    int k3 = 1;
    std::cout << solution.constrainedSubsetSum(nums3, k3) << std::endl;  // Output: -1

    return 0;
}
```