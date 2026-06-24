```cpp
// LeetCode problem 1: Two Sum, https://leetcode.com/problems/two-sum/
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// Optimal solution with O(n) complexity
std::vector<int> twoSumOptimal(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i};
        }
        numToIndex[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSumOptimal(nums1, target1);
    std::cout << "Indices: " << result1[0] << ", " << result1[1] << std::endl;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSumOptimal(nums2, target2);
    std::cout << "Indices: " << result2[0] << ", " << result2[1] << std::endl;

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSumOptimal(nums3, target3);
    std::cout << "Indices: " << result3[0] << ", " << result3[1] << std::endl;

    return 0;
}
```