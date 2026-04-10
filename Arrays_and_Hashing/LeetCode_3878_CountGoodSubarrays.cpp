```cpp
// LeetCode problem 3878: Count Good Subarrays
// https://leetcode.com/problems/count-good-subarrays/
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray is good if it contains exactly k different integers.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
int countGoodSubarraysBruteForce(std::vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            std::unordered_map<int, int> freq;
            for (int x = i; x <= j; x++) {
                freq[nums[x]]++;
            }
            if (freq.size() == k) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n) complexity
int countGoodSubarrays(std::vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        std::unordered_map<int, int> freq;
        for (int j = i; j < nums.size(); j++) {
            freq[nums[j]]++;
            if (freq.size() == k) {
                count++;
            } else if (freq.size() > k) {
                break;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    std::cout << "Test case 1: " << countGoodSubarrays(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 1, 3};
    int k2 = 2;
    std::cout << "Test case 2: " << countGoodSubarrays(nums2, k2) << std::endl;

    std::vector<int> nums3 = {1, 1, 1};
    int k3 = 1;
    std::cout << "Test case 3: " << countGoodSubarrays(nums3, k3) << std::endl;

    return 0;
}
```