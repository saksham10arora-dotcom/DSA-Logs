```cpp
// LeetCode problem 3043: Find The Length Of The Longest Common Prefix
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
// Given an array of strings, find the length of the longest common prefix.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m) complexity, where n is the number of strings and m is the maximum length of a string
int longestCommonPrefixBruteForce(std::vector<std::string>& strs) {
    if (strs.empty()) return 0;
    int minLen = strs[0].length();
    for (const auto& str : strs) {
        if (str.length() < minLen) minLen = str.length();
    }
    for (int i = 0; i < minLen; ++i) {
        char c = strs[0][i];
        for (const auto& str : strs) {
            if (str[i] != c) return i;
        }
    }
    return minLen;
}

// Optimal solution with O(n*m) complexity, where n is the number of strings and m is the maximum length of a string
int longestCommonPrefixOptimal(std::vector<std::string>& strs) {
    if (strs.empty()) return 0;
    for (int i = 0; i < strs[0].length(); ++i) {
        char c = strs[0][i];
        for (const auto& str : strs) {
            if (i == str.length() || str[i] != c) return i;
        }
    }
    return strs[0].length();
}

int main() {
    std::vector<std::string> test1 = {"flower","flow","flight"};
    std::vector<std::string> test2 = {"dog","racecar","car"};
    std::vector<std::string> test3 = {"a","ab","abc"};
    std::cout << "Brute force approach:" << std::endl;
    std::cout << longestCommonPrefixBruteForce(test1) << std::endl;  // Output: 2
    std::cout << longestCommonPrefixBruteForce(test2) << std::endl;  // Output: 0
    std::cout << longestCommonPrefixBruteForce(test3) << std::endl;  // Output: 0
    std::cout << "Optimal solution:" << std::endl;
    std::cout << longestCommonPrefixOptimal(test1) << std::endl;  // Output: 2
    std::cout << longestCommonPrefixOptimal(test2) << std::endl;  // Output: 0
    std::cout << longestCommonPrefixOptimal(test3) << std::endl;  // Output: 0
    return 0;
}
```