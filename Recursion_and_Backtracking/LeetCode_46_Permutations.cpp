```cpp
// LeetCode Problem: Permutations
// https://leetcode.com/problems/permutations/
// Given a collection of distinct numbers, return all possible permutations.

#include <iostream>
#include <vector>

// Brute force approach: Generate all permutations and check if they are valid (O(n*n!))
// However, since we are generating all permutations, we can simply return them (O(n*n!))

// Optimal solution: Use backtracking to generate all permutations (O(n*n!))
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }

    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); i++) {
                std::swap(nums[start], nums[i]);
                backtrack(result, nums, start + 1);
                std::swap(nums[start], nums[i]);
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> result1 = solution.permute(nums1);
    std::cout << "Permutations of [1, 2, 3]:\n";
    for (const auto& permutation : result1) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> nums2 = {0, 1};
    std::vector<std::vector<int>> result2 = solution.permute(nums2);
    std::cout << "Permutations of [0, 1]:\n";
    for (const auto& permutation : result2) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> nums3 = {5, 4, 3, 2, 1};
    std::vector<std::vector<int>> result3 = solution.permute(nums3);
    std::cout << "Permutations of [5, 4, 3, 2, 1]:\n";
    for (const auto& permutation : result3) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```