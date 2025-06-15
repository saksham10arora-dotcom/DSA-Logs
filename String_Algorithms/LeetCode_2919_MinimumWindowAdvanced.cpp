```cpp
// LeetCode problem 2919: Minimum Window Advanced
// https://leetcode.com/problems/minimum-window-substring/
// Given two strings s and t of lengths m and n, return the minimum window substring of s such that every character in t can be checked off in the string.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        // Brute force approach: O(m * n) complexity
        // int minLen = INT_MAX;
        // std::string minWindow;
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i + 1; j <= s.size(); j++) {
        //         std::string window = s.substr(i, j - i);
        //         if (checkWindow(window, t)) {
        //             if (j - i < minLen) {
        //                 minLen = j - i;
        //                 minWindow = window;
        //             }
        //         }
        //     }
        // }
        // return minWindow;

        // Optimal solution: O(m + n) complexity
        if (s.size() < t.size()) return "";
        std::unordered_map<char, int> tCount;
        for (char c : t) tCount[c]++;
        int required = tCount.size();
        int l = 0, r = 0;
        int formed = 0;
        std::unordered_map<char, int> windowCounts;
        int minLen = INT_MAX;
        std::string minWindow;
        while (r < s.size()) {
            char c = s[r];
            windowCounts[c]++;
            if (tCount.find(c)!= tCount.end() && windowCounts[c] == tCount[c]) formed++;
            while (l <= r && formed == required) {
                c = s[l];
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minWindow = s.substr(l, r - l + 1);
                }
                windowCounts[c]--;
                if (tCount.find(c)!= tCount.end() && windowCounts[c] < tCount[c]) formed--;
                l++;
            }
            r++;
        }
        return minWindow;
    }

    bool checkWindow(const std::string& window, const std::string& t) {
        std::unordered_map<char, int> tCount;
        for (char c : t) tCount[c]++;
        std::unordered_map<char, int> windowCount;
        for (char c : window) windowCount[c]++;
        for (auto& pair : tCount) {
            if (windowCount.find(pair.first) == windowCount.end() || windowCount[pair.first] < pair.second) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.minWindow("ADOBECODEBANC", "ABC") << std::endl;  // "BANC"
    std::cout << solution.minWindow("a", "aa") << std::endl;  // ""
    std::cout << solution.minWindow("bba", "ab") << std::endl;  // "ba"
    return 0;
}
```