```cpp
// LeetCode problem 1658: Surrounded Regions Variant
// https://leetcode.com/problems/minimum-operations-to-make-all-elements-equal/
// Given an array of integers nums, return the minimum number of operations required to make all array elements equal.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(n^2) complexity
int minOperationsBruteForce(std::vector<int>& nums) {
    int n = nums.size();
    int minOperations = n;
    for (int i = 0; i < n; i++) {
        int operations = 0;
        for (int j = 0; j < n; j++) {
            operations += std::abs(nums[j] - nums[i]);
        }
        minOperations = std::min(minOperations, operations);
    }
    return minOperations;
}

// Optimal solution: O(n) complexity
int minOperationsOptimal(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int median = nums[n / 2];
    int minOperations = 0;
    for (int i = 0; i < n; i++) {
        minOperations += std::abs(nums[i] - median);
    }
    return minOperations;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {10, 20, 30, 40, 50};
    std::vector<int> nums3 = {1, 1, 1, 1, 1};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << minOperationsBruteForce(nums1) << std::endl;
    std::cout << "Test case 2: " << minOperationsBruteForce(nums2) << std::endl;
    std::cout << "Test case 3: " << minOperationsBruteForce(nums3) << std::endl;

    std::cout << "Optimal solution:" << std::endl;
    std::cout << "Test case 1: " << minOperationsOptimal(nums1) << std::endl;
    std::cout << "Test case 2: " << minOperationsOptimal(nums2) << std::endl;
    std::cout << "Test case 3: " << minOperationsOptimal(nums3) << std::endl;

    return 0;
}
```