```cpp
// Maximum Number Of Pairs In Array, https://leetcode.com/problems/maximum-number-of-pairs-in-array/, 
// Given an integer array nums, return the maximum number of pairs in the array.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    int maximumNumberOfPairs(std::vector<int>& nums) {
        int pairs = 0;
        std::vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    pairs++;
                    visited[i] = true;
                    visited[j] = true;
                    break;
                }
            }
        }
        return pairs;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int maximumNumberOfPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        int pairs = 0;
        for (int num : nums) {
            if (count.find(num) != count.end()) {
                pairs++;
                count.erase(num);
            } else {
                count[num]++;
            }
        }
        return pairs;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3, 2, 1, 3, 2, 2};
    std::vector<int> nums2 = {1, 1};
    std::vector<int> nums3 = {0};
    std::cout << solution.maximumNumberOfPairs(nums1) << std::endl;  // Output: 3
    std::cout << solution.maximumNumberOfPairs(nums2) << std::endl;  // Output: 1
    std::cout << solution.maximumNumberOfPairs(nums3) << std::endl;  // Output: 0
    return 0;
}
```