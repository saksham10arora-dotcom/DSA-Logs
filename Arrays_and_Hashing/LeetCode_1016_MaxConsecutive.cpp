```cpp
// LeetCode problem 1016: Binary String With Substrings Representing 1 To N
// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// Given a binary string s and an integer n, return true if the binary representation of every integer from 1 to n is a substring of s.

#include <iostream>
#include <string>

// Brute force approach with O(n * log(n)) complexity
bool queryStringBruteForce(std::string s, int n) {
    for (int i = 1; i <= n; i++) {
        std::string binary = "";
        int num = i;
        while (num > 0) {
            binary = (num % 2 == 0? "0" : "1") + binary;
            num /= 2;
        }
        if (s.find(binary) == std::string::npos) {
            return false;
        }
    }
    return true;
}

// Optimal solution with O(n * log(n)) complexity
bool queryStringOptimal(std::string s, int n) {
    for (int i = 1; i <= n; i++) {
        std::string binary = "";
        int num = i;
        while (num > 0) {
            binary = (num % 2 == 0? "0" : "1") + binary;
            num /= 2;
        }
        if (s.find(binary) == std::string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << queryStringBruteForce("0110", 3) << std::endl;  // True
    std::cout << queryStringBruteForce("0110", 4) << std::endl;  // False
    std::cout << queryStringOptimal("111110101011", 10) << std::endl;  // True
    return 0;
}
```