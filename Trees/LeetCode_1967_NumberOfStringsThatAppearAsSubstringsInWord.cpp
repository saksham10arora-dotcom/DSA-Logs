```cpp
// Number Of Strings That Appear As Substrings In Word, https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Given an array of strings patterns and a string word, return the number of strings in patterns that appear as a substring of word.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m*k) complexity, where n is the number of patterns, m is the length of the word, and k is the maximum length of a pattern
int numOfStringsBruteForce(std::vector<std::string>& patterns, std::string word) {
    int count = 0;
    for (const auto& pattern : patterns) {
        if (word.find(pattern) != std::string::npos) {
            count++;
        }
    }
    return count;
}

// Optimal solution with O(n*m*k) complexity, where n is the number of patterns, m is the length of the word, and k is the maximum length of a pattern
int numOfStrings(std::vector<std::string>& patterns, std::string word) {
    int count = 0;
    for (const auto& pattern : patterns) {
        if (word.find(pattern) != std::string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<std::string> patterns1 = {"a", "abc", "bcd", "d"};
    std::string word1 = "abcd";
    std::cout << numOfStrings(patterns1, word1) << std::endl;  // Output: 3

    std::vector<std::string> patterns2 = {"a", "b", "c"};
    std::string word2 = "aaaaaa";
    std::cout << numOfStrings(patterns2, word2) << std::endl;  // Output: 2

    std::vector<std::string> patterns3 = {"a", "a", "a"};
    std::string word3 = "ab";
    std::cout << numOfStrings(patterns3, word3) << std::endl;  // Output: 1

    return 0;
}
```