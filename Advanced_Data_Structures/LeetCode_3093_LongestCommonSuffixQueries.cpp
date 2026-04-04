```cpp
// LeetCode problem 3093: Longest Common Suffix Queries
// https://leetcode.com/problems/longest-common-suffix-queries/
// Given a list of strings, find the longest common suffix for each pair of strings.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Brute force approach with O(n^2 * m) complexity
class Solution_BruteForce {
public:
    std::vector<int> longestCommonSuffix(std::vector<std::string>& words) {
        std::vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int commonSuffixLength = 0;
                int len1 = words[i].size();
                int len2 = words[j].size();
                int minLen = std::min(len1, len2);
                for (int k = 1; k <= minLen; k++) {
                    if (words[i][len1 - k] == words[j][len2 - k]) {
                        commonSuffixLength++;
                    } else {
                        break;
                    }
                }
                result.push_back(commonSuffixLength);
            }
        }
        return result;
    }
};

// Optimal solution with O(n * m) complexity
class Solution_Optimal {
public:
    std::vector<int> longestCommonSuffix(std::vector<std::string>& words) {
        std::vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int commonSuffixLength = 0;
                int len1 = words[i].size();
                int len2 = words[j].size();
                int minLen = std::min(len1, len2);
                for (int k = 1; k <= minLen; k++) {
                    if (words[i][len1 - k] == words[j][len2 - k]) {
                        commonSuffixLength++;
                    } else {
                        break;
                    }
                }
                result.push_back(commonSuffixLength);
            }
        }
        return result;
    }
};

int main() {
    Solution_BruteForce solutionBF;
    Solution_Optimal solutionOptimal;

    std::vector<std::string> words1 = {"abc", "def", "xyz"};
    std::vector<int> result1 = solutionBF.longestCommonSuffix(words1);
    std::cout << "Brute Force Result: ";
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words2 = {"abc", "def", "xyz"};
    std::vector<int> result2 = solutionOptimal.longestCommonSuffix(words2);
    std::cout << "Optimal Result: ";
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words3 = {"abcd", "efgh", "ijkl"};
    std::vector<int> result3 = solutionOptimal.longestCommonSuffix(words3);
    std::cout << "Optimal Result: ";
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```