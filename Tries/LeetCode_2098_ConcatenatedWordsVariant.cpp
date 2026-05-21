```cpp
// LeetCode problem 2098: Concatenated Words Variant
// https://leetcode.com/problems/concatenated-words-variant/
// Given a list of strings words, return all the concatenated words in the list.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach: O(n^2 * m) where n is the number of words and m is the average length of a word
class SolutionBrute {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        std::unordered_set<std::string> wordSet(words.begin(), words.end());
        std::vector<std::string> result;
        for (const auto& word : words) {
            if (isConcatenated(word, wordSet)) {
                result.push_back(word);
            }
        }
        return result;
    }

    bool isConcatenated(const std::string& word, const std::unordered_set<std::string>& wordSet) {
        for (int i = 1; i < word.size(); ++i) {
            std::string prefix = word.substr(0, i);
            std::string suffix = word.substr(i);
            if (wordSet.count(prefix) && (wordSet.count(suffix) || isConcatenated(suffix, wordSet))) {
                return true;
            }
        }
        return false;
    }
};

// Optimal solution: O(n * m) where n is the number of words and m is the average length of a word
class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        std::unordered_set<std::string> wordSet(words.begin(), words.end());
        std::vector<std::string> result;
        for (const auto& word : words) {
            if (isConcatenated(word, wordSet)) {
                result.push_back(word);
            }
        }
        return result;
    }

    bool isConcatenated(const std::string& word, const std::unordered_set<std::string>& wordSet) {
        std::vector<bool> dp(word.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= word.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[word.size()];
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatsdogcat"};
    std::vector<std::string> result1 = solution.findAllConcatenatedWordsInADict(words1);
    for (const auto& word : result1) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words2 = {"cat", "dog", "catdog"};
    std::vector<std::string> result2 = solution.findAllConcatenatedWordsInADict(words2);
    for (const auto& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words3 = {"cat", "dog", "catdog", "dogcat"};
    std::vector<std::string> result3 = solution.findAllConcatenatedWordsInADict(words3);
    for (const auto& word : result3) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
```