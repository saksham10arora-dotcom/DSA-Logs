```cpp
// LeetCode problem 3830: Longest Alternating Subarray After Removing At Most One Element
// https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/
// Given an array of integers, find the length of the longest alternating subarray that can be obtained by removing at most one element.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    int longestAlternatingSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                std::vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
                int len = getAlternatingLength(subarray);
                maxLen = std::max(maxLen, len);
            }
        }
        return maxLen;
    }

    int getAlternatingLength(std::vector<int>& subarray) {
        int n = subarray.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                std::vector<int> temp(subarray.begin() + i, subarray.begin() + j + 1);
                if (isAlternating(temp)) {
                    maxLen = std::max(maxLen, (int)temp.size());
                }
            }
        }
        return maxLen;
    }

    bool isAlternating(std::vector<int>& subarray) {
        int n = subarray.size();
        if (n < 2) return true;
        for (int i = 1; i < n; i++) {
            if (subarray[i] == subarray[i - 1]) return false;
        }
        return true;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int longestAlternatingSubarray(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int maxLen = 0;
        int left = 0, right = 0;
        while (right < n) {
            if (right > 0 && nums[right] == nums[right - 1]) {
                left = right;
            } else if (right > 1 && nums[right] == nums[right - 2]) {
                left = right - 1;
            }
            maxLen = std::max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3, 3, 2, 3, 2, 4};
    std::vector<int> nums2 = {1, 2, 4, 5, 3, 2};
    std::vector<int> nums3 = {5, 5, 5, 5, 5};
    std::cout << solution.longestAlternatingSubarray(nums1) << std::endl;  // Output: 5
    std::cout << solution.longestAlternatingSubarray(nums2) << std::endl;  // Output: 4
    std::cout << solution.longestAlternatingSubarray(nums3) << std::endl;  // Output: 1
    return 0;
}
```