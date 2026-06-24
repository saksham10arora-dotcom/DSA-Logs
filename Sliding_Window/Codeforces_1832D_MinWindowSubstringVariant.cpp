```cpp
// Codeforces_1832D_MinWindowSubstringVariant
// https://codeforces.com/contest/1832/problem/D
// Given two strings s and t, find the minimum window substring of s that contains all characters of t.

#include <iostream>
#include <string>
#include <unordered_map>

// Brute force approach: O(n^3) - generate all substrings and check if they contain all characters of t
std::string bruteForce(const std::string& s, const std::string& t) {
    std::string minWindow = "";
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            std::string window = s.substr(i, j - i);
            bool containsAll = true;
            for (char c : t) {
                if (window.find(c) == std::string::npos) {
                    containsAll = false;
                    break;
                }
            }
            if (containsAll && (minWindow.empty() || window.size() < minWindow.size())) {
                minWindow = window;
            }
        }
    }
    return minWindow;
}

// Optimal solution: O(n) - use a sliding window and a frequency map to track characters in t
std::string optimalSolution(const std::string& s, const std::string& t) {
    if (s.size() < t.size()) {
        return "";
    }

    std::unordered_map<char, int> tCount;
    for (char c : t) {
        tCount[c]++;
    }

    int requiredChars = tCount.size();
    int formedChars = 0;

    std::unordered_map<char, int> windowCounts;
    int minWindowLen = INT_MAX;
    std::string minWindow = "";
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
        char rightChar = s[windowEnd];
        windowCounts[rightChar]++;

        if (tCount.find(rightChar) != tCount.end() && windowCounts[rightChar] == tCount[rightChar]) {
            formedChars++;
        }

        while (windowStart <= windowEnd && formedChars == requiredChars) {
            if (windowEnd - windowStart + 1 < minWindowLen) {
                minWindowLen = windowEnd - windowStart + 1;
                minWindow = s.substr(windowStart, windowEnd - windowStart + 1);
            }

            char leftChar = s[windowStart];
            windowCounts[leftChar]--;
            if (tCount.find(leftChar) != tCount.end() && windowCounts[leftChar] < tCount[leftChar]) {
                formedChars--;
            }

            windowStart++;
        }
    }

    return minWindow;
}

int main() {
    std::cout << optimalSolution("ADOBECODEBANC", "ABC") << std::endl;  // "BANC"
    std::cout << optimalSolution("a", "aa") << std::endl;  // ""
    std::cout << optimalSolution("bba", "ab") << std::endl;  // "ba"
    return 0;
}
```