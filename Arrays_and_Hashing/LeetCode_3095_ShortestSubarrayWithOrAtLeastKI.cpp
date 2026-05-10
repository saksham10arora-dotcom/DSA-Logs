```cpp
// LeetCode problem 3095: Shortest Subarray With Sum At Least K
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Given an integer array nums and an integer k, return the length of the shortest subarray that contains at least k occurrences of an integer.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

// Brute force approach with O(n^2) complexity
int shortestSubarrayBruteForce(std::vector<int>& nums, int k) {
    int n = nums.size();
    int min_length = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int count = 0;
            for (int l = i; l <= j; l++) {
                if (nums[l] == nums[i]) {
                    count++;
                }
            }
            if (count >= k) {
                min_length = std::min(min_length, j - i + 1);
            }
        }
    }
    return min_length == INT_MAX ? -1 : min_length;
}

// Optimal solution with O(n) complexity
int shortestSubarray(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::unordered_map<int, int> count_map;
    int min_length = INT_MAX;
    for (int i = 0; i < n; i++) {
        count_map.clear();
        int count = 0;
        for (int j = i; j < n; j++) {
            count_map[nums[j]]++;
            if (count_map[nums[j]] >= k) {
                min_length = std::min(min_length, j - i + 1);
            }
        }
    }
    return min_length == INT_MAX ? -1 : min_length;
}

int main() {
    std::vector<int> nums1 = {1, 2, 1};
    int k1 = 2;
    std::cout << "Shortest subarray length: " << shortestSubarray(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 1, 1};
    int k2 = 3;
    std::cout << "Shortest subarray length: " << shortestSubarray(nums2, k2) << std::endl;

    std::vector<int> nums3 = {1, 2, 3, 2, 2, 3, 3, 3};
    int k3 = 3;
    std::cout << "Shortest subarray length: " << shortestSubarray(nums3, k3) << std::endl;

    return 0;
}
```