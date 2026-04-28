```cpp
// LeetCode problem 1599: Interval List Advanced, https://leetcode.com/problems/minimum-cost-to-add-two-numbers/
// Given two non-negative integers num1 and num2, find the minimum cost to add them.
// The cost of adding two numbers is the sum of the number of digits in the two numbers.

#include <iostream>
#include <string>
#include <algorithm>

// Brute force approach: O(n) where n is the maximum number of digits in num1 and num2
// This approach involves converting the numbers to strings, counting the digits, and summing them up
int minCostBruteForce(int num1, int num2) {
    std::string str1 = std::to_string(num1);
    std::string str2 = std::to_string(num2);
    return str1.length() + str2.length();
}

// Optimal solution: O(log(n)) where n is the maximum of num1 and num2
// This approach involves using the logarithm to count the number of digits in the numbers
int minCostOptimal(int num1, int num2) {
    int count1 = (num1 == 0) ? 1 : (int)std::floor(std::log10(num1)) + 1;
    int count2 = (num2 == 0) ? 1 : (int)std::floor(std::log10(num2)) + 1;
    return count1 + count2;
}

int main() {
    std::cout << "Test case 1: " << minCostOptimal(1, 2) << std::endl;  // Expected output: 2
    std::cout << "Test case 2: " << minCostOptimal(10, 20) << std::endl;  // Expected output: 4
    std::cout << "Test case 3: " << minCostOptimal(100, 200) << std::endl;  // Expected output: 6
    return 0;
}
```