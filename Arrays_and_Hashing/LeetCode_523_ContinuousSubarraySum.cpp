```cpp
// LeetCode problem 523: Continuous Subarray Sum, https://leetcode.com/problems/continuous-subarray-sum/
// Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subarrays such that the sum of the integers in each subarray is equal to the sum of the integers in the array divided by k, i.e., sum(nums) / k. Otherwise, return false.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
bool checkSubarraySumBruteForce(std::vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum % k == 0 && j - i + 1 > 1) {
                return true;
            }
        }
    }
    return false;
}

// Optimal solution with O(n) complexity
bool checkSubarraySum(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::unordered_map<int, int> prefixSum;
    int sum = 0;
    prefixSum[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (k != 0) {
            sum %= k;
        }
        if (prefixSum.find(sum) != prefixSum.end()) {
            if (i - prefixSum[sum] > 1) {
                return true;
            }
        } else {
            prefixSum[sum] = i;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 13;
    std::cout << std::boolalpha << checkSubarraySum(nums1, k1) << std::endl;  // Output: true

    std::vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 13;
    std::cout << std::boolalpha << checkSubarraySum(nums2, k2) << std::endl;  // Output: false

    std::vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 0;
    std::cout << std::boolalpha << checkSubarraySum(nums3, k3) << std::endl;  // Output: false

    return 0;
}
```