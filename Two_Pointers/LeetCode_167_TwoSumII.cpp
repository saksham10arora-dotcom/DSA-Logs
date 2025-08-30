```cpp
// LeetCode problem 167: Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length. Return the indices of the two numbers, index1 and index2, added by 1 as an integer array [index1, index2] of length 2.

#include <iostream>
#include <vector>

// Brute force approach with O(n^2) complexity
std::vector<int> twoSumBruteForce(std::vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
        }
    }
    return {};
}

// Optimal solution with O(n) complexity
std::vector<int> twoSumOptimal(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    std::vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSumOptimal(numbers1, target1);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl;

    std::vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSumOptimal(numbers2, target2);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl;

    std::vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    std::vector<int> result3 = twoSumOptimal(numbers3, target3);
    std::cout << "[" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
```