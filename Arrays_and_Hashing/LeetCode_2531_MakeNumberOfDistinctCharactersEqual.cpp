```cpp
// LeetCode problem 2531: Make Number Of Distinct Characters Equal
// https://leetcode.com/problems/make-number-of-distinct-characters-equal/
// Given two strings s and target, return true if you can make the number of distinct characters in s equal to the number of distinct characters in target.

#include <iostream>
#include <string>
#include <unordered_set>

// Brute force approach: O(n * m) where n and m are the lengths of the strings
bool makeEqualBruteForce(std::string s, std::string target) {
    int countS = 0;
    int countTarget = 0;
    std::unordered_set<char> setS;
    std::unordered_set<char> setTarget;

    for (char c : s) {
        if (setS.find(c) == setS.end()) {
            setS.insert(c);
            countS++;
        }
    }

    for (char c : target) {
        if (setTarget.find(c) == setTarget.end()) {
            setTarget.insert(c);
            countTarget++;
        }
    }

    return countS == countTarget;
}

// Optimal solution: O(n + m) where n and m are the lengths of the strings
bool makeEqualOptimal(std::string s, std::string target) {
    std::unordered_set<char> setS;
    std::unordered_set<char> setTarget;

    for (char c : s) {
        setS.insert(c);
    }

    for (char c : target) {
        setTarget.insert(c);
    }

    return setS.size() == setTarget.size();
}

int main() {
    std::cout << std::boolalpha;
    std::cout << makeEqualOptimal("abc", "bca") << std::endl;  // true
    std::cout << makeEqualOptimal("abc", "cbad") << std::endl;  // false
    std::cout << makeEqualOptimal("a", "aaaa") << std::endl;  // true
    return 0;
}
```