```cpp
// LeetCode problem 2309: Greatest English Letter In Upper And Lower Case
// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
// Given a string of English letters, return the greatest English letter which occurs as both a lowercase and uppercase letter in the string.

#include <iostream>
#include <string>
#include <unordered_set>

// Brute force approach with O(n^2) complexity
std::string greatestLetterBruteForce(std::string s) {
    std::string result = "";
    for (char c = 'z'; c >= 'a'; --c) {
        if (s.find(c) != std::string::npos && s.find(c - 32) != std::string::npos) {
            result = c;
            break;
        }
    }
    return result;
}

// Optimal solution with O(n) complexity
std::string greatestLetterOptimal(std::string s) {
    std::unordered_set<char> lower, upper;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') lower.insert(c);
        else upper.insert(c);
    }
    for (char c = 'z'; c >= 'a'; --c) {
        if (lower.find(c) != lower.end() && upper.find(c - 32) != upper.end()) {
            return std::string(1, c);
        }
    }
    return "";
}

int main() {
    std::cout << greatestLetterOptimal("lEtLeT") << std::endl;  // "E"
    std::cout << greatestLetterOptimal("arRAzFif") << std::endl;  // "R"
    std::cout << greatestLetterOptimal("AbCdEfGh") << std::endl;  // ""
    return 0;
}
```