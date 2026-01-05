```cpp
// LeetCode problem 3233: Find The Count Of Numbers Which Are Not Special
// https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/
// Given an array of integers, find the count of numbers which are not special.
// A special number is a number that has exactly one 1-bit in its binary representation.

#include <iostream>
#include <vector>
#include <bitset>

// Brute force approach with O(n) complexity
int countNonSpecialNumbersBruteForce(const std::vector<int>& nums) {
    int count = 0;
    for (const auto& num : nums) {
        std::bitset<32> binary(num);
        int ones = binary.count();
        if (ones!= 1) {
            count++;
        }
    }
    return count;
}

// Optimal solution with O(n) complexity
int countNonSpecialNumbersOptimal(const std::vector<int>& nums) {
    int count = 0;
    for (const auto& num : nums) {
        if (__builtin_popcount(num)!= 1) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> test1 = {2, 3, 5, 7};
    std::vector<int> test2 = {1, 2, 4, 8};
    std::vector<int> test3 = {10, 20, 30, 40};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << countNonSpecialNumbersBruteForce(test1) << std::endl;
    std::cout << "Test case 2: " << countNonSpecialNumbersBruteForce(test2) << std::endl;
    std::cout << "Test case 3: " << countNonSpecialNumbersBruteForce(test3) << std::endl;

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << "Test case 1: " << countNonSpecialNumbersOptimal(test1) << std::endl;
    std::cout << "Test case 2: " << countNonSpecialNumbersOptimal(test2) << std::endl;
    std::cout << "Test case 3: " << countNonSpecialNumbersOptimal(test3) << std::endl;

    return 0;
}
```