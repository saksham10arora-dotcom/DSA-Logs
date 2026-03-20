```cpp
// LeetCode problem 3022: Minimize Or Of Remaining Elements Using Operations
// https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/
// Given an array of integers, find the minimum OR of remaining elements after removing one element.

#include <iostream>
#include <vector>
#include <climits>

// Brute force approach: O(n^2) complexity
int bruteForceMinOr(std::vector<int>& nums) {
    int minOr = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int orVal = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i != j) {
                orVal |= nums[j];
            }
        }
        minOr = std::min(minOr, orVal);
    }
    return minOr;
}

// Optimal solution: O(n) complexity
int minOr(std::vector<int>& nums) {
    int maxVal = 0;
    for (int num : nums) {
        maxVal = std::max(maxVal, num);
    }
    int minOr = INT_MAX;
    for (int num : nums) {
        if (num == maxVal) {
            int orVal = 0;
            for (int other : nums) {
                if (other != num) {
                    orVal |= other;
                }
            }
            minOr = std::min(minOr, orVal);
        }
    }
    return minOr;
}

int main() {
    std::vector<int> test1 = {1, 2, 3};
    std::vector<int> test2 = {1, 2, 4};
    std::vector<int> test3 = {1, 0, 2};

    std::cout << "Test 1: " << minOr(test1) << std::endl;
    std::cout << "Test 2: " << minOr(test2) << std::endl;
    std::cout << "Test 3: " << minOr(test3) << std::endl;

    return 0;
}
```