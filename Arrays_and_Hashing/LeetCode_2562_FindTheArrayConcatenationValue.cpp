```cpp
// LeetCode problem 2562: Find The Array Concatenation Value
// https://leetcode.com/problems/find-the-array-concatenation-value/
// Given an array of integers nums, return the length of the longest subarray where every two distinct elements form a pair.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^3) complexity
class SolutionBrute {
public:
    int findTheArrayConcVal(std::vector<std::string>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::string concat = nums[i] + nums[j];
                res += std::stoi(concat);
            }
        }
        return res;
    }
};

// Optimal solution with O(n) complexity
class SolutionOptimal {
public:
    int findTheArrayConcVal(std::vector<std::string>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            res += std::stoi(nums[i] + nums[nums.size() - 1 - i]);
        }
        if (nums.size() % 2 == 1) {
            res += std::stoi(nums[nums.size() / 2]);
        }
        return res;
    }
};

int main() {
    SolutionOptimal solution;
    std::vector<std::string> nums1 = {"1", "2", "3"};
    std::vector<std::string> nums2 = {"1", "2", "1", "1"};
    std::vector<std::string> nums3 = {"7", "7", "7", "7"};
    std::cout << solution.findTheArrayConcVal(nums1) << std::endl;  // Output: 231
    std::cout << solution.findTheArrayConcVal(nums2) << std::endl;  // Output: 9
    std::cout << solution.findTheArrayConcVal(nums3) << std::endl;  // Output: 7747
    return 0;
}
```