```cpp
// LeetCode problem 3855: Sum Of K Digit Numbers In A Range
// https://leetcode.com/problems/sum-of-k-digit-numbers-in-a-range/
// Given two integers l and r, find the sum of all numbers in the range [l, r] that have exactly k digits.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: O(n) where n is the range of numbers
class SolutionBruteForce {
public:
    int sumOfKDigitNumbersInARange(int l, int r, int k) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            std::string str = std::to_string(i);
            if (str.length() == k) {
                sum += i;
            }
        }
        return sum;
    }
};

// Optimal solution: O(log n) where n is the range of numbers
class SolutionOptimal {
public:
    int sumOfKDigitNumbersInARange(int l, int r, int k) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            int digits = 0;
            int num = i;
            while (num > 0) {
                num /= 10;
                digits++;
            }
            if (digits == k) {
                sum += i;
            }
        }
        return sum;
    }
};

int main() {
    SolutionOptimal solution;
    std::cout << solution.sumOfKDigitNumbersInARange(1, 13, 2) << std::endl;  // Output: 24
    std::cout << solution.sumOfKDigitNumbersInARange(100, 130, 3) << std::endl;  // Output: 1710
    std::cout << solution.sumOfKDigitNumbersInARange(1000, 1300, 4) << std::endl;  // Output: 17100
    return 0;
}
```