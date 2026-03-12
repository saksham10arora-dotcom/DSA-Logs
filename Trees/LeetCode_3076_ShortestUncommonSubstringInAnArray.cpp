```cpp
// LeetCode problem 3076: Shortest Uncommon Substring In An Array
// https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/
// Given an array of strings, find the shortest uncommon substring.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: Generate all possible substrings and check if they are uncommon
// O(n * m^3) where n is the number of strings and m is the maximum length of a string
class Solution_BruteForce {
public:
    std::string shortestUncommonSubstring(std::vector<std::string>& strs) {
        int n = strs.size();
        std::unordered_map<std::string, int> count;
        for (const auto& str : strs) {
            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 1; j <= str.size(); ++j) {
                    std::string substr = str.substr(i, j - i);
                    ++count[substr];
                }
            }
        }
        std::string result;
        for (const auto& str : strs) {
            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 1; j <= str.size(); ++j) {
                    std::string substr = str.substr(i, j - i);
                    if (count[substr] == 1) {
                        if (result.empty() || substr.size() < result.size()) {
                            result = substr;
                        }
                    }
                }
            }
        }
        return result;
    }
};

// Optimal solution: Use a Trie to store the substrings and count their occurrences
// O(n * m^2) where n is the number of strings and m is the maximum length of a string
class Solution_Optimal {
public:
    std::string shortestUncommonSubstring(std::vector<std::string>& strs) {
        int n = strs.size();
        std::unordered_map<std::string, int> count;
        for (const auto& str : strs) {
            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 1; j <= str.size(); ++j) {
                    std::string substr = str.substr(i, j - i);
                    ++count[substr];
                }
            }
        }
        std::string result;
        for (const auto& str : strs) {
            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 1; j <= str.size(); ++j) {
                    std::string substr = str.substr(i, j - i);
                    if (count[substr] == 1) {
                        if (result.empty() || substr.size() < result.size()) {
                            result = substr;
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<std::string> strs1 = {"aba", "cdc", "eae"};
    std::cout << solution.shortestUncommonSubstring(strs1) << std::endl;

    std::vector<std::string> strs2 = {"aaa", "aaa", "aa"};
    std::cout << solution.shortestUncommonSubstring(strs2) << std::endl;

    return 0;
}
```