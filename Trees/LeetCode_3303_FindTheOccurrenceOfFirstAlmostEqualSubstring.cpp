```cpp
// LeetCode problem 3303: Find The Occurrence Of First Almost Equal Substring
// https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/
// Given a string s and a string p, return the index of the first occurrence of p in s, 
// or -1 if it is not an almost equal substring.

#include <iostream>
#include <string>
#include <vector>

// Brute force approach with O(n*m) complexity
int findFirstAlmostEqualSubstringBruteForce(const std::string& s, const std::string& p) {
    int n = s.size();
    int m = p.size();
    for (int i = 0; i <= n - m; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != p[j]) {
                diff++;
            }
        }
        if (diff <= 1) {
            return i;
        }
    }
    return -1;
}

// Optimal solution with O(n*m) complexity
int findFirstAlmostEqualSubstring(const std::string& s, const std::string& p) {
    int n = s.size();
    int m = p.size();
    for (int i = 0; i <= n - m; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != p[j]) {
                diff++;
                if (diff > 1) {
                    break;
                }
            }
        }
        if (diff <= 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::cout << findFirstAlmostEqualSubstring("abcd", "abcd") << std::endl;  // Expected output: 0
    std::cout << findFirstAlmostEqualSubstring("abcd", "abce") << std::endl;  // Expected output: 0
    std::cout << findFirstAlmostEqualSubstring("abcd", "abcf") << std::endl;  // Expected output: 0
    std::cout << findFirstAlmostEqualSubstring("abcd", "abde") << std::endl;  // Expected output: -1
    return 0;
}
```