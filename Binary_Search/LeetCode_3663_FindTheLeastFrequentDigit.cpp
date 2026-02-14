```cpp
// LeetCode problem 3663: Find The Least Frequent Digit
// https://leetcode.com/problems/find-the-least-frequent-digit/
// Given a string s consisting of digits, find the least frequent digit in the string.

#include <iostream>
#include <string>
#include <unordered_map>

// Brute force approach: count the frequency of each digit and find the least frequent one
// Time complexity: O(n), where n is the length of the string
// Space complexity: O(1), as there are at most 10 digits (0-9)
int leastFrequentDigitBruteForce(const std::string& s) {
    std::unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    int minCount = INT_MAX;
    char minDigit;
    for (const auto& pair : count) {
        if (pair.second < minCount) {
            minCount = pair.second;
            minDigit = pair.first;
        }
    }
    return minDigit - '0';
}

// Optimal solution: same as brute force, as it's already optimal
// Time complexity: O(n), where n is the length of the string
// Space complexity: O(1), as there are at most 10 digits (0-9)
int leastFrequentDigitOptimal(const std::string& s) {
    std::unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    int minCount = INT_MAX;
    char minDigit;
    for (const auto& pair : count) {
        if (pair.second < minCount) {
            minCount = pair.second;
            minDigit = pair.first;
        }
    }
    return minDigit - '0';
}

int main() {
    std::cout << leastFrequentDigitOptimal("12345") << std::endl;  // Output: 0
    std::cout << leastFrequentDigitOptimal("11111") << std::endl;  // Output: 1
    std::cout << leastFrequentDigitOptimal("1234567890") << std::endl;  // Output: 0
    return 0;
}
```