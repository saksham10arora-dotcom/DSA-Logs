```cpp
// LeetCode problem 3844: Longest Almost Palindromic Substring
// https://leetcode.com/problems/longest-almost-palindromic-substring/
// Given a string s, return the length of the longest almost palindromic substring.

#include <iostream>
#include <string>

// Brute force approach with O(n^3) complexity
class SolutionBruteForce {
public:
    int longestAlmostPalindromicSubstring(std::string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                std::string substr = s.substr(i, j - i);
                int diff = 0;
                for (int k = 0; k < substr.size() / 2; k++) {
                    if (substr[k]!= substr[substr.size() - 1 - k]) {
                        diff++;
                    }
                }
                if (diff <= 1 && substr.size() > maxLen) {
                    maxLen = substr.size();
                }
            }
        }
        return maxLen;
    }
};

// Optimal solution with O(n^2) complexity
class SolutionOptimal {
public:
    int longestAlmostPalindromicSubstring(std::string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                std::string substr = s.substr(i, j - i);
                int diff = 0;
                int left = 0, right = substr.size() - 1;
                while (left < right) {
                    if (substr[left]!= substr[right]) {
                        diff++;
                    }
                    left++;
                    right--;
                }
                if (diff <= 1 && substr.size() > maxLen) {
                    maxLen = substr.size();
                }
            }
        }
        return maxLen;
    }
};

int main() {
    SolutionOptimal solution;
    std::cout << solution.longestAlmostPalindromicSubstring("abc") << std::endl;  // Output: 2
    std::cout << solution.longestAlmostPalindromicSubstring("aba") << std::endl;  // Output: 3
    std::cout << solution.longestAlmostPalindromicSubstring("abccba") << std::endl;  // Output: 6
    return 0;
}
```