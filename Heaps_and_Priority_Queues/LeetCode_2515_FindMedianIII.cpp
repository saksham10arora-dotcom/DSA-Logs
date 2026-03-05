```cpp
// LeetCode problem 2515: Find Median I I I
// https://leetcode.com/problems/find-median-iii/
// Given an array of integers, find the median of the array.

#include <queue>
#include <vector>
#include <iostream>

// Brute force approach: sorting the array, O(n log n)
class Solution_Brute_Force {
public:
    double findMedian(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 0) {
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        } else {
            return nums[n / 2];
        }
    }
};

// Optimal solution: using priority queue (max heap and min heap), O(n log n)
class Solution {
public:
    double findMedian(vector<int>& nums) {
        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int num : nums) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> nums3 = {1, 3, 5, 7, 9};
    std::cout << solution.findMedian(nums1) << std::endl;  // Output: 3
    std::cout << solution.findMedian(nums2) << std::endl;  // Output: 2.5
    std::cout << solution.findMedian(nums3) << std::endl;  // Output: 5
    return 0;
}
```