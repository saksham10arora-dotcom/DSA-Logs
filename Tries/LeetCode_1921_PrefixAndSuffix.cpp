```cpp
// LeetCode problem 1921: Prefix And Suffix, https://leetcode.com/problems/eliminate-maximum-number-of-rounded-rectangles/
// Given an array of integers nums where every element is either 0 or 1, return the maximum number of elements that can be made equal to 1.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
class SolutionBruteForce {
public:
    int eliminateMaximum(std::vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) && nums[i] != 0) {
                    count++;
                }
            }
            maxCount = std::max(maxCount, count);
        }
        return maxCount;
    }
};

// Optimal solution with O(n log n) complexity
class SolutionOptimal {
public:
    int eliminateMaximum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= time) {
                return i;
            }
            time++;
        }
        return n;
    }
};

int main() {
    SolutionOptimal solution;
    std::vector<int> nums1 = {3, 2, 3};
    std::vector<int> nums2 = {2, 2, 1, 2};
    std::vector<int> nums3 = {1, 1, 1};
    std::cout << solution.eliminateMaximum(nums1) << std::endl;  // Output: 3
    std::cout << solution.eliminateMaximum(nums2) << std::endl;  // Output: 2
    std::cout << solution.eliminateMaximum(nums3) << std::endl;  // Output: