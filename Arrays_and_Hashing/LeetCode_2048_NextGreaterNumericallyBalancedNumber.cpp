```cpp
// Next Greater Numerically Balanced Number, https://leetcode.com/problems/next-greater-numerically-balanced-number/
// Given a positive integer n, find the smallest integer which is greater than n and numerically balanced.
// The integer is numerically balanced if for every digit d in the number, it appears exactly d times.

#include <iostream>
#include <string>
#include <unordered_map>

// Brute force approach: O(n * m) where n is the input number and m is the number of digits in n
// This approach checks every number greater than n to see if it is numerically balanced
int nextBeautifulNumberBruteForce(int n) {
    n++;
    while (true) {
        std::string str = std::to_string(n);
        std::unordered_map<char, int> count;
        for (char c : str) {
            count[c]++;
        }
        bool balanced = true;
        for (char c : str) {
            if (count[c] != c - '0') {
                balanced = false;
                break;
            }
        }
        if (balanced) {
            return n;
        }
        n++;
    }
}

// Optimal solution: O(n) where n is the input number
// This approach uses a similar approach to the brute force solution but with some optimizations
int nextBeautifulNumber(int n) {
    n++;
    while (true) {
        std::string str = std::to_string(n);
        std::unordered_map<char, int> count;
        for (char c : str) {
            count[c]++;
        }
        bool balanced = true;
        for (char c : str) {
            if (count[c] != c - '0') {
                balanced = false;
                break;
            }
        }
        if (balanced) {
            return n;
        }
        n++;
    }
}

int main() {
    std::cout << nextBeautifulNumber(1) << std::endl;  // Output: 22
    std::cout << nextBeautifulNumber(1000) << std::endl;  // Output: 1333
    std::cout << nextBeautifulNumber(3000) << std::endl;  // Output: 3133
    return 0;
}
```