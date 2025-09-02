```cpp
/**
 * LeetCode Problem 258: Add Digits
 * https://leetcode.com/problems/add-digits/
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 */

#include <iostream>

// Brute force approach with O(n) complexity where n is the number of digits in num
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

// Optimal solution with O(1) complexity using mathematical formula
class SolutionOptimal {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return (num - 1) % 9 + 1;
    }
};

int main() {
    Solution solution;
    SolutionOptimal solutionOptimal;

    std::cout << "Brute force approach:" << std::endl;
    std::cout << solution.addDigits(38) << std::endl;  // Output: 2
    std::cout << solution.addDigits(0) << std::endl;   // Output: 0
    std::cout << solution.addDigits(9) << std::endl;   // Output: 9

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << solutionOptimal.addDigits(38) << std::endl;  // Output: 2
    std::cout << solutionOptimal.addDigits(0) << std::endl;   // Output: 0
    std::cout << solutionOptimal.addDigits(9) << std::endl;   // Output: 9

    return 0;
}
```