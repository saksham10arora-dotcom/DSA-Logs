```cpp
// LeetCode problem 556: Next Greater Element III
// https://leetcode.com/problems/next-greater-element-iii/
// Given a positive integer n, find the smallest integer which is greater than n and has the same digits.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int nextGreaterElement(int n) {
        // Convert integer to vector of digits
        std::vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        std::reverse(digits.begin(), digits.end());

        // Find the first decreasing digit from the right
        int i = digits.size() - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }

        // If no decreasing digit is found, the number is the largest possible
        if (i < 0) {
            return -1;
        }

        // Find the smallest digit greater than digits[i] from the right
        int j = digits.size() - 1;
        while (digits[j] <= digits[i]) {
            j--;
        }

        // Swap digits[i] and digits[j]
        std::swap(digits[i], digits[j]);

        // Sort the digits to the right of i in ascending order
        std::sort(digits.begin() + i + 1, digits.end());

        // Convert vector of digits back to integer
        long long result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }

        // Check for overflow
        if (result > INT_MAX) {
            return -1;
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::cout << solution.nextGreaterElement(12) << std::endl;  // Output: 21

    // Test case 2
    std::cout << solution.nextGreaterElement(21) << std::endl;  // Output: -1

    // Test case 3
    std::cout << solution.nextGreaterElement(123) << std::endl;  // Output: 132

    return 0;
}
```