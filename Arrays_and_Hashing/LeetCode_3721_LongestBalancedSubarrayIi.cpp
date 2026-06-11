```cpp
// LeetCode problem 3721: Longest Balanced Subarray II, https://leetcode.com/problems/longest-balanced-subarray-ii/
// Given an array of integers, find the length of the longest balanced subarray.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach: O(n^3) complexity
class Solution_BruteForce {
public:
    int longestBalancedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                if (sum == 0) {
                    maxLength = std::max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};

// Optimal solution: O(n) complexity
class Solution_Optimal {
public:
    int longestBalancedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        std::unordered_map<int, int> prefixSum;
        int sum = 0;
        prefixSum[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (prefixSum.find(sum) != prefixSum.end()) {
                maxLength = std::max(maxLength, i - prefixSum[sum]);
            } else {
                prefixSum[sum] = i;
            }
        }
        return maxLength;
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<int> nums1 = {1, -1, 1, -1, 1, -1};
    std::vector<int> nums2 = {1, 1, 1, 1, 1};
    std::vector<int> nums3 = {-1, -1, -1, -1, -1};
    std::cout << solution.longestBalancedSubarray(nums1) << std::endl;  // Output: 6
    std::cout << solution.longestBalancedSubarray(nums2) << std::endl;  // Output: 0
    std::cout << solution.longestBalancedSubarray(nums3) << std::endl;  // Output: 0
    return 0;
}
```