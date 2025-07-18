```cpp
// LeetCode problem 1152: Integer Replacement Variant
// https://leetcode.com/problems/integer-replacement-variant
// Given an integer n, find the minimum number of operations required to reduce n to 1.

#include <iostream>
#include <climits>

// Brute force approach with O(2^n) complexity
int integerReplacementBruteForce(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) return 1 + integerReplacementBruteForce(n / 2);
    return 1 + std::min(integerReplacementBruteForce(n - 1), integerReplacementBruteForce(n + 1));
}

// Optimal solution with O(log n) complexity
int integerReplacement(int n) {
    long long N = n;
    int count = 0;
    while (N!= 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else if (N % 4 == 1 || N == 3) {
            N--;
        } else {
            N++;
        }
        count++;
    }
    return count;
}

int main() {
    std::cout << integerReplacement(8) << std::endl;  // Output: 3
    std::cout << integerReplacement(7) << std::endl;  // Output: 4
    std::cout << integerReplacement(4) << std::endl;  // Output: 2
    return 0;
}
```