```cpp
/**
 * @brief LeetCode problem 3350: Adjacent Increasing Subarrays Detection II
 * https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
 * Given an array of integers, find the number of adjacent increasing subarrays.
 */

#include <iostream>
#include <vector>

// Brute force approach with O(n^2) complexity
int bruteForce(std::vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j <= nums.size(); j++) {
            bool increasing = true;
            for (int k = i; k < j - 1; k++) {
                if (nums[k] >= nums[k + 1]) {
                    increasing = false;
                    break;
                }
            }
            if (increasing) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n) complexity
int optimalSolution(std::vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        bool increasing = true;
        for (int j = i; j < n - 1; j++) {
            if (nums[j] >= nums[j + 1]) {
                increasing = false;
                break;
            }
            if (increasing) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> test1 = {1, 2, 3, 4};
    std::vector<int> test2 = {1, 1, 1, 1};
    std::vector<int> test3 = {1, 3, 2, 4};

    std::cout << "Test case 1: " << optimalSolution(test1) << std::endl;
    std::cout << "Test case 2: " << optimalSolution(test2) << std::endl;
    std::cout << "Test case 3: " << optimalSolution(test3) << std::endl;

    return 0;
}
```