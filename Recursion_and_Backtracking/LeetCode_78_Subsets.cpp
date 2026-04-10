```cpp
// LeetCode problem 78: Subsets, https://leetcode.com/problems/subsets/
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Brute force approach: Generate all possible subsets by checking each element in the array
// Time complexity: O(2^n) where n is the number of elements in the array
// Space complexity: O(2^n) for storing all subsets

// Optimal solution: Use backtracking to generate all subsets
// Time complexity: O(2^n) where n is the number of elements in the array
// Space complexity: O(2^n) for storing all subsets

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(result, nums, 0, {});
        return result;
    }

    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& nums, int start, std::vector<int> current) {
        result.push_back(current);
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(result, nums, i + 1, current);
            current.pop_back();
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {0};
    std::vector<int> nums3 = {1, 2, 3, 4, 5};

    std::vector<std::vector<int>> result1 = solution.subsets(nums1);
    std::vector<std::vector<int>> result2 = solution.subsets(nums2);
    std::vector<std::vector<int>> result3 = solution.subsets(nums3);

    std::cout << "Test case 1:" << std::endl;
    for (const auto& subset : result1) {
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Test case 2:" << std::endl;
    for (const auto& subset : result2) {
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Test case 3:" << std::endl;
    for (const auto& subset : result3) {
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```