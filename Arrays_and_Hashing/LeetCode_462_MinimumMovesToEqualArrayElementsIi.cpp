```cpp
// LeetCode problem 462: Minimum Moves To Equal Array Elements Ii
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Given a non-empty integer array, find the minimum number of moves required to make all array elements equal.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Brute force approach: try all possible target values and calculate the total moves for each
// O(n^2) complexity
int minMoves2BruteForce(std::vector<int>& nums) {
    int minMoves = INT_MAX;
    for (int target = *std::min_element(nums.begin(), nums.end()); target <= *std::max_element(nums.begin(), nums.end()); target++) {
        int totalMoves = 0;
        for (int num : nums) {
            totalMoves += std::abs(num - target);
        }
        minMoves = std::min(minMoves, totalMoves);
    }
    return minMoves;
}

// Optimal solution: find the median of the array and use it as the target value
// O(n log n) complexity due to sorting
int minMoves2Optimal(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int target = nums[nums.size() / 2];
    int totalMoves = 0;
    for (int num : nums) {
        totalMoves += std::abs(num - target);
    }
    return totalMoves;
}

int main() {
    std::vector<int> test1 = {1, 2, 3};
    std::vector<int> test2 = {1, 10, 2, 9};
    std::vector<int> test3 = {-100, -98, -102, -101};

    std::cout << "Test 1: " << minMoves2Optimal(test1) << std::endl;
    std::cout << "Test 2: " << minMoves2Optimal(test2) << std::endl;
    std::cout << "Test 3: " << minMoves2Optimal(test3) << std::endl;

    return 0;
}
```