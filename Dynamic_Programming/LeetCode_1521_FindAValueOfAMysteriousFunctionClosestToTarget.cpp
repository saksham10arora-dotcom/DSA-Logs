```cpp
// LeetCode problem 1521: Find A Value Of A Mysterious Function Closest To Target
// https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Given an array of integers arr, a mysterious function f(x) that returns the value x and an integer target.
// Return the closest number to target in the array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int closestToTarget(std::vector<int>& arr, int target) {
        // Brute force approach with O(n * 2^n) complexity
        // int result = INT_MAX;
        // for (int i = 0; i < (1 << arr.size()); i++) {
        //     int sum = 0;
        //     for (int j = 0; j < arr.size(); j++) {
        //         if ((i & (1 << j)) != 0) {
        //             sum += arr[j];
        //         }
        //     }
        //     result = std::min(result, std::abs(sum - target));
        // }
        // return result;

        // Optimal solution with O(n * 2^n) complexity
        int result = INT_MAX;
        std::vector<int> sums;
        for (int i = 0; i < arr.size(); i++) {
            std::vector<int> newSums;
            newSums.push_back(arr[i]);
            for (int sum : sums) {
                newSums.push_back(sum & arr[i]);
            }
            sums = newSums;
            for (int sum : sums) {
                result = std::min(result, std::abs(sum - target));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> arr1 = {9, 12, 3, 7, 15};
    std::cout << solution.closestToTarget(arr1, 5) << std::endl;  // Output: 2
    std::vector<int> arr2 = {1000000, 1000000, 1000000};
    std::cout << solution.closestToTarget(arr2, 1) << std::endl;  // Output: 0
    std::vector<int> arr3 = {1, 2, 4, 8, 16};
    std::cout << solution.closestToTarget(arr3, 50) << std::endl;  // Output: