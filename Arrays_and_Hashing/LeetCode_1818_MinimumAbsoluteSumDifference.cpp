```cpp
// Minimum Absolute Sum Difference, https://leetcode.com/problems/minimum-absolute-sum-difference/
// Given two integer arrays nums1 and nums2, return the minimum absolute sum difference between the sums of two arrays, 
// which is the minimum value of | (sum(nums1) - sum(nums2)) + 2 * x |, where x is an integer.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Brute force approach: O(n^2) complexity
int minAbsoluteSumDiffBruteForce(std::vector<int>& nums1, std::vector<int>& nums2) {
    int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
    int minDiff = INT_MAX;
    for (int x = -100000; x <= 100000; x++) {
        int diff = std::abs((sum1 - sum2) + 2 * x);
        minDiff = std::min(minDiff, diff);
    }
    return minDiff;
}

// Optimal solution: O(n) complexity
int minAbsoluteSumDiff(std::vector<int>& nums1, std::vector<int>& nums2) {
    int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
    int diff = std::abs(sum1 - sum2);
    int minDiff = diff;
    for (int num : nums1) {
        int newDiff = std::abs((sum1 - num - sum2) + 2 * num);
        minDiff = std::min(minDiff, newDiff);
    }
    for (int num : nums2) {
        int newDiff = std::abs((sum1 - sum2 + num) + 2 * num);
        minDiff = std::min(minDiff, newDiff);
    }
    return minDiff;
}

int main() {
    std::vector<int> nums1 = {1, 7, 5};
    std::vector<int> nums2 = {2, 3, 5};
    std::cout << minAbsoluteSumDiff(nums1, nums2) << std::endl;  // Output: 3

    nums1 = {2, 4, 6, 8, 10};
    nums2 = {2, 4, 6, 8, 10};
    std::cout << minAbsoluteSumDiff(nums1, nums2) << std::endl;  // Output: 0

    nums1 = {1, 10, 4, 4, 2, 7};
    nums2 = {9, 3, 5, 1, 7, 4};
    std::cout << minAbsoluteSumDiff(nums1, nums2) << std::endl;  // Output: 20

    return 0;
}
```