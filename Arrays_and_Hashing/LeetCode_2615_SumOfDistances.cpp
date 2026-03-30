```cpp
// LeetCode problem 2615: Sum Of Distances
// https://leetcode.com/problems/sum-of-distances/
// Given an integer array nums, return the sum of the distances of the given array.

#include <iostream>
#include <vector>
#include <numeric>

// Brute force approach with O(n^2) complexity
int sumOfDistancesInArrayBruteForce(std::vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i!= j) {
                sum += std::abs(nums[i] - nums[j]);
            }
        }
    }
    return sum;
}

// Optimal solution with O(n) complexity
int sumOfDistancesInArrayOptimal(std::vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int num : nums) {
        int countLess = 0, countGreater = 0;
        for (int otherNum : nums) {
            if (otherNum < num) {
                countLess++;
            } else if (otherNum > num) {
                countGreater++;
            }
        }
        sum += countLess * num - countGreater * num;
    }
    return sum;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    std::vector<int> nums3 = {1, 3, 5, 7, 9};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << sumOfDistancesInArrayBruteForce(nums1) << std::endl;
    std::cout << "Test case 2: " << sumOfDistancesInArrayBruteForce(nums2) << std::endl;
    std::cout << "Test case 3: " << sumOfDistancesInArrayBruteForce(nums3) << std::endl;

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << "Test case 1: " << sumOfDistancesInArrayOptimal(nums1) << std::endl;
    std::cout << "Test case 2: " << sumOfDistancesInArrayOptimal(nums2) << std::endl;
    std::cout << "Test case 3: " << sumOfDistancesInArrayOptimal(nums3) << std::endl;

    return 0;
}
```