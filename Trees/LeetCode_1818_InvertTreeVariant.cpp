```cpp
// LeetCode problem 1818: Minimum Absolute Sum Difference
// https://leetcode.com/problems/minimum-absolute-sum-difference/
// Given an integer array and a target value, find the minimum absolute sum difference.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minAbsoluteSumDiff(std::vector<int>& nums, int target) {
        // Brute force approach with O(n^2) complexity
        // int minDiff = INT_MAX;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 0; j < nums.size(); j++) {
        //         int diff = std::abs(nums[i] - target);
        //         int newDiff = std::abs(nums[j] - target);
        //         minDiff = std::min(minDiff, std::abs(diff - newDiff));
        //     }
        // }
        // return minDiff;

        // Optimal solution with O(n log n) complexity
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());
        int minDiff = INT_MAX;
        for (int num : nums) {
            int diff = std::abs(num - target);
            auto it = std::lower_bound(sortedNums.begin(), sortedNums.end(), target);
            if (it!= sortedNums.end()) {
                minDiff = std::min(minDiff, std::abs(*it - target));
            }
            if (it!= sortedNums.begin()) {
                minDiff = std::min(minDiff, std::abs(*std::prev(it) - target));
            }
        }
        return minDiff;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 7, 5};
    int target1 = 2;
    std::cout << solution.minAbsoluteSumDiff(nums1, target1) << std::endl;

    std::vector<int> nums2 = {2, 3, 5};
    int target2 = 6;
    std::cout << solution.minAbsoluteSumDiff(nums2, target2) << std::endl;

    std::vector<int> nums3 = {4, 7, 6};
    int target3 = 7;
    std::cout << solution.minAbsoluteSumDiff(nums3, target3) << std::endl;

    return 0;
}
```