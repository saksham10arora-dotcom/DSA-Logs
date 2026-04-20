```cpp
// LeetCode problem 491: Non Decreasing Subsequences
// https://leetcode.com/problems/non-decreasing-subsequences/
// Given an integer array nums, return all the different possible non-decreasing subsequences of nums.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
std::vector<std::vector<int>> findSubsequencesBruteForce(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    for (int mask = 1; mask < (1 << n); mask++) {
        std::vector<int> subsequence;
        bool isNonDecreasing = true;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                if (!subsequence.empty() && subsequence.back() > nums[i]) {
                    isNonDecreasing = false;
                    break;
                }
                subsequence.push_back(nums[i]);
            }
        }
        if (isNonDecreasing && subsequence.size() > 1) {
            result.push_back(subsequence);
        }
    }
    return result;
}

// Optimal solution with O(2^n) complexity
std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::function<void(int)> backtrack = [&](int start) {
        if (start == nums.size()) {
            if (current.size() > 1) {
                result.push_back(current);
            }
            return;
        }
        if (current.empty() || current.back() <= nums[start]) {
            current.push_back(nums[start]);
            backtrack(start + 1);
            current.pop_back();
        }
        backtrack(start + 1);
    };
    std::sort(nums.begin(), nums.end());
    backtrack(0);
    return result;
}

int main() {
    std::vector<int> nums1 = {4, 6, 7, 7};
    std::vector<std::vector<int>> result1 = findSubsequences(nums1);
    std::cout << "Result 1: ";
    for (const auto& subsequence : result1) {
        std::cout << "{";
        for (int num : subsequence) {
            std::cout << num << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1, 2, 3};
    std::vector<std::vector<int>> result2 = findSubsequences(nums2);
    std::cout << "Result 2: ";
    for (const auto& subsequence : result2) {
        std::cout << "{";
        for (int num : subsequence) {
            std::cout << num << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {5, 5, 5};
    std::vector<std::vector<int>> result3 = findSubsequences(nums3);
    std::cout << "Result 3: ";
    for (const auto& subsequence : result3) {
        std::cout << "{";
        for (int num : subsequence) {
            std::cout << num << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    return 0;
}
```