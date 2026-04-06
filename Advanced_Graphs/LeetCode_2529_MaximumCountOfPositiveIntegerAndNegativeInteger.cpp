```cpp
// Maximum Count Of Positive Integer And Negative Integer
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
// Given an array of integers, find the maximum count of positive integer and negative integer.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n) complexity
class Solution_BruteForce {
public:
    std::vector<int> maximumCount(std::vector<int>& nums) {
        int pos = 0, neg = 0;
        for (int num : nums) {
            if (num > 0) pos++;
            else if (num < 0) neg++;
        }
        return {std::max(pos, neg)};
    }
};

// Optimal solution with O(n) complexity
class Solution_Optimal {
public:
    std::vector<int> maximumCount(std::vector<int>& nums) {
        int pos = std::count_if(nums.begin(), nums.end(), [](int x){ return x > 0; });
        int neg = std::count_if(nums.begin(), nums.end(), [](int x){ return x < 0; });
        return {std::max(pos, neg)};
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<int> test1 = {1, 2, 3, -4, -5};
    std::vector<int> test2 = {1, 2, 3, 4, 5};
    std::vector<int> test3 = {-1, -2, -3, -4, -5};
    std::cout << solution.maximumCount(test1)[0] << std::endl;  // Output: 3
    std::cout << solution.maximumCount(test2)[0] << std::endl;  // Output: 5
    std::cout << solution.maximumCount(test3)[0] << std::endl;  // Output: 5
    return 0;
}
```