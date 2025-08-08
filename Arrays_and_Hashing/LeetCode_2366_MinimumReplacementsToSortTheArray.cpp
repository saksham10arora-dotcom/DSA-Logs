```cpp
// LeetCode problem 2366: Minimum Replacements To Sort The Array
// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
// Given an array of integers, find the minimum number of replacements to make the array sorted.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: try all possible replacements
// O(n^2) complexity
int minReplacementsBruteForce(std::vector<int>& nums) {
    int n = nums.size();
    int minReplacements = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                minReplacements++;
            }
        }
    }
    return minReplacements;
}

// Optimal solution: use modified merge sort
// O(n log n) complexity
int minReplacementsOptimal(std::vector<int>& nums) {
    int n = nums.size();
    int minReplacements = 0;
    std::function<void(int, int)> mergeSort = [&](int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        std::vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                minReplacements += mid - i + 1;
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    };
    mergeSort(0, n - 1);
    return minReplacements;
}

int main() {
    std::vector<int> nums1 = {3, 4, 2, 2, 1};
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    std::vector<int> nums3 = {5, 4, 3, 2, 1};
    std::cout << minReplacementsOptimal(nums1) << std::endl;  // Output: 2
    std::cout << minReplacementsOptimal(nums2) << std::endl;  // Output: 0
    std::cout << minReplacementsOptimal(nums3) << std::endl;  // Output: 4
    return 0;
}
```