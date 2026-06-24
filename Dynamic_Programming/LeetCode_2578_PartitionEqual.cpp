```cpp
// LeetCode problem 2578: Partition Equal Subset Sum, https://leetcode.com/problems/partition-equal-subset-sum/
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of elements in both subsets is equal.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
class Solution_Brute_Force {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        return dfs(nums, 0, 0, target);
    }

    bool dfs(std::vector<int>& nums, int index, int sum, int target) {
        if (sum == target) return true;
        if (sum > target || index == nums.size()) return false;
        return dfs(nums, index + 1, sum + nums[index], target) || dfs(nums, index + 1, sum, target);
    }
};

// Optimal solution with O(n * sum) complexity
class Solution_Optimal {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) dp[i] = true;
            }
        }
        return dp[target];
    }
};

int main() {
    Solution_Brute_Force solution_brute_force;
    Solution_Optimal solution_optimal;

    std::vector<int> nums1 = {1, 5, 11, 5};
    std::cout << std::boolalpha << solution_brute_force.canPartition(nums1) << std::endl;  // true
    std::cout << std::boolalpha << solution_optimal.canPartition(nums1) << std::endl;  // true

    std::vector<int> nums2 = {1, 2, 3, 5};
    std::cout << std::boolalpha << solution_brute_force.canPartition(nums2) << std::endl;  // false
    std::cout << std::boolalpha << solution_optimal.canPartition(nums2) << std::endl;  // false

    std::vector<int> nums3 = {10, 10, 10, 7, 7, 7, 4, 3, 3};
    std::cout << std::boolalpha << solution_brute_force.canPartition(nums3) << std::endl;  // true
    std::cout << std::boolalpha << solution_optimal.canPartition(nums3) << std::endl;  // true

    return 0;
}
```