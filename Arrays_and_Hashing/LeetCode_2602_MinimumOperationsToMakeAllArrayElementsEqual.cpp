```cpp
// LeetCode problem 2602: Minimum Operations To Make All Array Elements Equal
// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/
// Given an array of integers nums, return the minimum number of operations required to make all array elements equal.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible values and count the number of operations required to make all elements equal to that value
// O(n^2) complexity
int minOperationsBruteForce(std::vector<int>& nums) {
    int minOperations = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int operations = 0;
        for (int j = 0; j < nums.size(); j++) {
            operations += std::abs(nums[j] - nums[i]);
        }
        minOperations = std::min(minOperations, operations);
    }
    return minOperations;
}

// Optimal solution: Find the median of the array, which is the value that minimizes the sum of absolute differences
// O(n log n) complexity
int minOperationsOptimal(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    int operations = 0;
    for (int num : nums) {
        operations += std::abs(num - median);
    }
    return operations;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {10, 20, 30, 40, 50};
    std::vector<int> nums3 = {1, 1, 1, 1, 1};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << minOperationsBruteForce(nums1) << std::endl;
    std::cout << "Test case 2: " << minOperationsBruteForce(nums2) << std::endl;
    std::cout << "Test case 3: " << minOperationsBruteForce(nums3) << std::endl;

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << "Test case 1: " << minOperationsOptimal(nums1) << std::endl;
    std::cout << "Test case 2: " << minOperationsOptimal(nums2) << std::endl;
    std::cout << "Test case 3: " << minOperationsOptimal(nums3) << std::endl;

    return 0;
}
```