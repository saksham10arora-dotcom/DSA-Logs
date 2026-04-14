```cpp
// LeetCode problem 3917: Count Indices With Opposite Parity
// https://leetcode.com/problems/count-indices-with-opposite-parity/
// Given an integer array nums, return the number of indices i such that nums[i] and i have opposite parity.

#include <iostream>
#include <vector>

// Brute force approach with O(n) complexity
int countIndicesWithOppositeParityBruteForce(std::vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2)!= (i % 2)) {
            count++;
        }
    }
    return count;
}

// Optimal solution with O(n) complexity
int countIndicesWithOppositeParityOptimal(std::vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] & 1)!= (i & 1)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> nums1 = {2, 1, 3, 4};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> nums3 = {4, 3, 2, 1};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << countIndicesWithOppositeParityBruteForce(nums1) << std::endl;
    std::cout << "Test case 2: " << countIndicesWithOppositeParityBruteForce(nums2) << std::endl;
    std::cout << "Test case 3: " << countIndicesWithOppositeParityBruteForce(nums3) << std::endl;

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << "Test case 1: " << countIndicesWithOppositeParityOptimal(nums1) << std::endl;
    std::cout << "Test case 2: " << countIndicesWithOppositeParityOptimal(nums2) << std::endl;
    std::cout << "Test case 3: " << countIndicesWithOppositeParityOptimal(nums3) << std::endl;

    return 0;
}
```