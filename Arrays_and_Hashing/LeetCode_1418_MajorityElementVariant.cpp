```cpp
// LeetCode problem 1418: Majority Element Variant
// https://leetcode.com/problems/majority-element-variant/
// Given an array of integers, find the majority element that appears more than n/3 times.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach: O(n^2) complexity
std::vector<int> majorityElementBruteForce(std::vector<int>& nums) {
    std::vector<int> result;
    for (int num : nums) {
        int count = 0;
        for (int n : nums) {
            if (n == num) count++;
        }
        if (count > nums.size() / 3 && std::find(result.begin(), result.end(), num) == result.end()) {
            result.push_back(num);
        }
    }
    return result;
}

// Optimal solution: O(n) complexity
std::vector<int> majorityElement(std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }
    for (auto& pair : countMap) {
        if (pair.second > nums.size() / 3) {
            result.push_back(pair.first);
        }
    }
    return result;
}

int main() {
    std::vector<int> test1 = {3, 2, 3};
    std::vector<int> test2 = {1, 1, 1, 3, 3, 2, 2, 2};
    std::vector<int> test3 = {1, 1, 2, 2, 3, 3, 3, 3};

    std::vector<int> result1 = majorityElement(test1);
    std::vector<int> result2 = majorityElement(test2);
    std::vector<int> result3 = majorityElement(test3);

    std::cout << "Test 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 3: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```