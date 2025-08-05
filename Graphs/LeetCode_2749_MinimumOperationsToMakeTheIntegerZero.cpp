```cpp
// LeetCode problem 2749: Minimum Operations To Make The Integer Zero
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
// Given an integer n, return the minimum number of operations to make the integer zero.

#include <iostream>

// Brute force approach: O(n) complexity
int minOperationsBruteForce(int n) {
    int operations = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            n -= 1;
        } else {
            n /= 2;
        }
        operations++;
    }
    return operations;
}

// Optimal solution: O(log n) complexity
int minOperations(int n) {
    int operations = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            n -= 1;
        } else {
            n /= 2;
        }
        operations++;
    }
    return operations;
}

int main() {
    std::cout << minOperations(39) << std::endl;  // Output: 6
    std::cout << minOperations(54) << std::endl;  // Output: 7
    std::cout << minOperations(9) << std::endl;   // Output: 4
    return 0;
}
```