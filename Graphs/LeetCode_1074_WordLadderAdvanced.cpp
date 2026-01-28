```cpp
// LeetCode problem 1074: Word Ladder Advanced
// https://leetcode.com/problems/number-of-ways-to-build-wooden-rectangles/
// Given a list of words, find the number of ways to build wooden rectangles.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

// Brute force approach: O(26^n * n * m) where n is the length of the word and m is the number of words
class SolutionBruteForce {
public:
    int numWays(std::vector<std::string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                for (int k = 0; k < words[i].size(); k++) {
                    for (int l = 0; l < words[j].size(); l++) {
                        if (words[i][k] != words[j][l]) {
                            continue;
                        }
                        std::string newWord = words[i].substr(0, k) + words[j].substr(l + 1);
                        if (isValid(newWord, words)) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    bool isValid(const std::string& word, const std::vector<std::string>& words) {
        for (const auto& w : words) {
            if (w == word) {
                return true;
            }
        }
        return false;
    }
};

// Optimal solution: O(n * m * 26) where n is the length of the word and m is the number of words
class Solution {
public:
    int numWays(std::vector<std::string>& words) {
        std::unordered_map<char, std::vector<int>> charToIndices;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                charToIndices[words[i][j]].push_back(i);
            }
        }

        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                for (int k = 0; k < words[i].size(); k++) {
                    for (int l = 0; l < words[j].size(); l++) {
                        if (words[i][k] != words[j][l]) {
                            continue;
                        }
                        std::string newWord = words[i].substr(0, k) + words[j].substr(l + 1);
                        if (isValid(newWord, charToIndices, words)) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    bool isValid(const std::string& word, const std::unordered_map<char, std::vector<int>>& charToIndices, const std::vector<std::string>& words) {
        std::unordered_set<int> indices;
        for (char c : word) {
            if (charToIndices.find(c) == charToIndices.end()) {
                return false;
            }
            for (int i : charToIndices.at(c)) {
                indices.insert(i);
            }
        }
        return indices.size() > 1;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"abc", "def", "ghi"};
    std::cout << solution.numWays(words1) << std::endl;

    std::vector<std::string> words2 = {"abc", "def", "ghi", "jkl"};
    std::cout << solution.numWays(words2) << std::endl;

    std::vector<std::string> words3 = {"abc", "def", "ghi", "jkl", "mno"};
    std::cout << solution.numWays(words3) << std::endl;

    return 0;
}
```