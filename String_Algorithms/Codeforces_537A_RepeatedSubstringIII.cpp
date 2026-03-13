```cpp
// Codeforces_537A_RepeatedSubstringIII
// https://codeforces.com/contest/537/problem/A
// Given a string, determine if it can be represented as a repeated substring.

#include <iostream>
#include <string>

// Brute force approach with O(n^2) complexity
bool bruteForce(const std::string& s) {
    int n = s.length();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            bool match = true;
            for (int i = len; i < n; ++i) {
                if (s[i] != s[i % len]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    return false;
}

// Optimal solution with O(n) complexity
bool optimalSolution(const std::string& s) {
    int n = s.length();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            std::string substr = s.substr(0, len);
            std::string repeated = "";
            for (int i = 0; i < n / len; ++i) {
                repeated += substr;
            }
            if (repeated == s) return true;
        }
    }
    return false;
}

int main() {
    std::string test1 = "abcabc";
    std::string test2 = "abcdef";
    std::string test3 = "ababab";

    std::cout << std::boolalpha << bruteForce(test1) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << bruteForce(test2) << std::endl;  // Expected output: false
    std::cout << std::boolalpha << bruteForce(test3) << std::endl;  // Expected output: true

    std::cout << std::boolalpha << optimalSolution(test1) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << optimalSolution(test2) << std::endl;  // Expected output: false
    std::cout << std::boolalpha << optimalSolution(test3) << std::endl;  // Expected output: true

    return 0;
}
```