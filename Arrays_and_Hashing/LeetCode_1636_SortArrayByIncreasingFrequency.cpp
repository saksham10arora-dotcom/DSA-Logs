```cpp
// LeetCode problem 1636: Sort Array By Increasing Frequency, https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Given an array of integers, sort the array in ascending order by frequency of elements. If multiple elements have the same frequency, sort them in ascending order.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Brute force approach: O(n^2) - not efficient for large inputs
// std::vector<int> frequencySort(std::vector<int>& nums) {
//     std::vector<int> result;
//     while (!nums.empty()) {
//         int minFreq = INT_MAX;
//         int minNum = INT_MAX;
//         for (int num : nums) {
//             int freq = std::count(nums.begin(), nums.end(), num);
//             if (freq < minFreq || (freq == minFreq && num < minNum)) {
//                 minFreq = freq;
//                 minNum = num;
//             }
//         }
//         for (int i = 0; i < minFreq; ++i) {
//             result.push_back(minNum);
//         }
//         nums.erase(std::remove(nums.begin(), nums.end(), minNum), nums.end());
//     }
//     return result;
// }

// Optimal solution: O(n) - using unordered_map to count frequencies
std::vector<int> frequencySort(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        ++freq[num];
    }
    std::sort(nums.begin(), nums.end(), [&freq](int a, int b) {
        if (freq[a] == freq[b]) {
            return a < b;
        }
        return freq[a] < freq[b];
    });
    return nums;
}

int main() {
    std::vector<int> nums1 = {1, 1, 2, 2, 3};
    std::vector<int> result1 = frequencySort(nums1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {2, 3, 1, 3, 2};
    std::vector<int> result2 = frequencySort(nums2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {4, 5, 5, 6};
    std::vector<int> result3 = frequencySort(nums3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```