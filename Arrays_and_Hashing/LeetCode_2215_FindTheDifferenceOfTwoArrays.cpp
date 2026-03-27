```cpp
// LeetCode problem 2215: Find The Difference Of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays/
// Given two 0-indexed integer arrays nums1 and nums2, return a list of two arrays.
// The first array should contain all the elements that are in nums1 but not in nums2.
// The second array should contain all the elements that are in nums2 but not in nums1.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach with O(n*m) complexity
std::vector<std::vector<int>> findDifferenceBruteForce(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> diff1;
    std::vector<int> diff2;

    for (int num : nums1) {
        bool found = false;
        for (int num2 : nums2) {
            if (num == num2) {
                found = true;
                break;
            }
        }
        if (!found) {
            diff1.push_back(num);
        }
    }

    for (int num : nums2) {
        bool found = false;
        for (int num1 : nums1) {
            if (num == num1) {
                found = true;
                break;
            }
        }
        if (!found) {
            diff2.push_back(num);
        }
    }

    return {diff1, diff2};
}

// Optimal solution with O(n + m) complexity
std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    std::vector<int> diff1;
    std::vector<int> diff2;

    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            diff1.push_back(num);
        }
    }

    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            diff2.push_back(num);
        }
    }

    return {diff1, diff2};
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 5};
    std::vector<std::vector<int>> result = findDifference(nums1, nums2);
    std::cout << "[";
    for (int num : result[0]) {
        std::cout << num << " ";
    }
    std::cout << "], [";
    for (int num : result[1]) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    nums1 = {1, 2, 3, 3};
    nums2 = {1, 1, 2, 2};
    result = findDifference(nums1, nums2);
    std::cout << "[";
    for (int num : result[0]) {
        std::cout << num << " ";
    }
    std::cout << "], [";
    for (int num : result[1]) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    nums1 = {1, 2, 3};
    nums2 = {1, 2, 3};
    result = findDifference(nums1, nums2);
    std::cout << "[";
    for (int num : result[0]) {
        std::cout << num << " ";
    }
    std::cout << "], [";
    for (int num : result[1]) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
```