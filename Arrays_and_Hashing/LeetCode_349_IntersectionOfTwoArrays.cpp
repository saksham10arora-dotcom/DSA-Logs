```cpp
// LeetCode problem 349: Intersection Of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
// Given two arrays, write a function to compute their intersection.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach: O(n*m) complexity
std::vector<int> intersectionOfTwoArraysBruteForce(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result;
    for (int num1 : nums1) {
        for (int num2 : nums2) {
            if (num1 == num2 && std::find(result.begin(), result.end(), num1) == result.end()) {
                result.push_back(num1);
            }
        }
    }
    return result;
}

// Optimal solution: O(n + m) complexity
std::vector<int> intersectionOfTwoArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    std::vector<int> result;
    for (int num : set1) {
        if (set2.find(num)!= set2.end()) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> result = intersectionOfTwoArrays(nums1, nums2);
    std::cout << "Intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    result = intersectionOfTwoArrays(nums1, nums2);
    std::cout << "Intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    nums1 = {1, 2, 3};
    nums2 = {4, 5, 6};
    result = intersectionOfTwoArrays(nums1, nums2);
    std::cout << "Intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```