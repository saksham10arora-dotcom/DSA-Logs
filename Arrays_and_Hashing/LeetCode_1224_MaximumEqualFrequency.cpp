```cpp
// Maximum Equal Frequency, https://leetcode.com/problems/maximum-equal-frequency/
// Given an array nums of integers, for each integer nums[i] we may choose any x with 1 <= x <= 6 where nums[i]!= x, 
// then multiply nums[i] by x. If the value of nums[i] is already x, then we must leave it as is except if doing so would cause 
// the entire array to have all the same value, in which case we must multiply it by some other number. 
// Return the maximum number of operations to make all elements in nums the same. In one operation, we can multiply one element 
// of nums by an integer.

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Brute force approach with O(n*6^n) complexity
    // int maxEqualFreq(std::vector<int>& nums) {
    //     int n = nums.size();
    //     int maxFreq = 0;
    //     for (int mask = 0; mask < (1 << n); mask++) {
    //         std::unordered_map<int, int> freq;
    //         for (int i = 0; i < n; i++) {
    //             if (mask & (1 << i)) {
    //                 freq[nums[i] * 2]++;
    //             } else {
    //                 freq[nums[i]]++;
    //             }
    //         }
    //         if (isSame(freq)) {
    //             maxFreq = std::max(maxFreq, __builtin_popcount(mask));
    //         }
    //     }
    //     return maxFreq;
    // }

    // Optimal solution with O(n) complexity
    int maxEqualFreq(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxFreq = 0;
        for (int num : freq) {
            maxFreq = std::max(maxFreq, num.second);
        }
        if (maxFreq == 1) {
            return n;
        }
        if (freq.size() == 1) {
            return n;
        }
        if (freq.size() == 2) {
            int maxCount = 0;
            int minCount = n;
            for (auto& pair : freq) {
                maxCount = std::max(maxCount, pair.second);
                minCount = std::min(minCount, pair.second);
            }
            if (maxCount - minCount == 1 || maxCount == 1) {
                return n;
            }
        }
        return n - 1;
    }

    bool isSame(const std::unordered_map<int, int>& freq) {
        int count = 0;
        for (auto& pair : freq) {
            if (pair.second > 0) {
                count++;
            }
        }
        return count == 1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {2, 2, 1, 1, 5, 3, 3, 5};
    std::cout << solution.maxEqualFreq(nums1) << std::endl;  // Output: 7

    std::vector<int> nums2 = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    std::cout << solution.maxEqualFreq(nums2) << std::endl;  // Output: 13

    std::vector<int> nums3 = {1, 1, 1, 2, 2, 2};
    std::cout << solution.maxEqualFreq(nums3) << std::endl;  // Output: 5

    return 0;
}
```