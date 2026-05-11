```cpp
/**
 * @brief LeetCode Problem 198: House Robber
 * https://leetcode.com/problems/house-robber/
 * You are a professional thief planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 */

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
class SolutionBruteForce {
public:
    int rob(std::vector<int>& nums) {
        return robHelper(nums, 0);
    }
    
    int robHelper(std::vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        int include = nums[index] + robHelper(nums, index + 2);
        int exclude = robHelper(nums, index + 1);
        return std::max(include, exclude);
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp.back();
    }
};

int main() {
    Solution solution;
    std::vector<int> test1 = {1,2,3,1};
    std::vector<int> test2 = {2,7,9,3,1};
    std::vector<int> test3 = {2,1,1,2};
    std::cout << solution.rob(test1) << std::endl;  // Output: 4
    std::cout << solution.rob(test2) << std::endl;  // Output: 12
    std::cout << solution.rob(test3) << std::endl;  // Output: 4
    return 0;
}
```