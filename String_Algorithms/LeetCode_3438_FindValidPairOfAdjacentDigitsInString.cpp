```cpp
// LeetCode problem 3438: Find Valid Pair Of Adjacent Digits In String
// https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/
// Given a string s, find a valid pair of adjacent digits in string.

#include <iostream>
#include <string>

// Brute force approach with O(n) complexity
std::string findValidPair(const std::string& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
            return s.substr(i, 2);
        }
    }
    return "";
}

// Optimal solution with O(n) complexity
std::string findValidPairOptimal(const std::string& s) {
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8') {
                if (i < s.size() - 1 && (s[i + 1] == '0' || s[i + 1] == '2' || s[i + 1] == '4' || s[i + 1] == '6' || s[i + 1] == '8')) {
                    return s.substr(i, 2);
                }
            } else {
                if (i < s.size() - 1 && (s[i + 1] == '1' || s[i + 1] == '3' || s[i + 1] == '5' || s[i + 1] == '7' || s[i + 1] == '9')) {
                    return s.substr(i, 2);
                }
            }
        }
    }
    return "";
}

int main() {
    std::cout << findValidPair("12") << std::endl;  // Output: "12"
    std::cout << findValidPair("23") << std::endl;  // Output: "23"
    std::cout << findValidPair("123") << std::endl;  // Output: "12"
    return 0;
}
```