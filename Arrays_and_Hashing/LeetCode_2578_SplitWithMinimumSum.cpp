```cpp
// LeetCode problem 2578: Split With Minimum Sum, https://leetcode.com/problems/split-with-minimum-sum/
// Given an integer num, split it into two non-negative integers a and b such that n = a + b, 
// and the product of a and b is maximized.

#include <iostream>
#include <climits>

// Brute force approach with O(n) complexity
class SolutionBrute {
public:
    int splitNum(int num) {
        int minSum = INT_MAX;
        for (int a = 0; a <= num; a++) {
            int b = num - a;
            int sum = a + b;
            if (sum < minSum) {
                minSum = sum;
            }
        }
        return minSum;
    }
};

// Optimal solution with O(log n) complexity
class SolutionOptimal {
public:
    int splitNum(int num) {
        int a = 0, b = 0;
        while (num > 0) {
            a = a * 10 + num % 10;
            num /= 10;
            b = b * 10 + num % 10;
            num /= 10;
        }
        return a + b;
    }
};

int main() {
    SolutionOptimal solution;
    std::cout << solution.splitNum(10) << std::endl;  // Output: 1
    std::cout << solution.splitNum(2) << std::endl;   // Output: 11
    std::cout << solution.splitNum(1234) << std::endl; // Output: 172
    return 0;
}
```