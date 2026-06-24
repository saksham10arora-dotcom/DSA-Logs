```cpp
// LeetCode problem 2399: Check Distances Between Same Letters
// https://leetcode.com/problems/check-distances-between-same-letters/
// Given a string s and an array of integers distance.
// Check if the distance between same letters in the string is equal to the given distance.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkDistances(const std::string& s, const std::vector<int>& distance) {
        // Brute force approach with O(n^2) complexity
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i + 1; j < s.size(); j++) {
        //         if (s[i] == s[j]) {
        //             if (j - i - 1 != distance[s[i] - 'a']) {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;

        // Optimal solution with O(n) complexity
        std::unordered_map<char, int> first_occurrence;
        for (int i = 0; i < s.size(); i++) {
            if (first_occurrence.find(s[i]) == first_occurrence.end()) {
                first_occurrence[s[i]] = i;
            } else {
                if (i - first_occurrence[s[i]] - 1 != distance[s[i] - 'a']) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.checkDistances("abaccb", {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << std::endl;  // true
    std::cout << solution.checkDistances("aa", {1}) << std::endl;  // false
    return 0;
}
```