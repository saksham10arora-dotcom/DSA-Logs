```cpp
// LeetCode problem 939: Palindrome Pairs Advanced
// https://leetcode.com/problems/palindrome-pairs/
// Given a list of unique word, return all pairs of distinct indices (i, j) in the given list, 
// so that the concatenation of the two words is a palindrome.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n^2 * m) where n is the number of words and m is the maximum length of a word
class Solution_BruteForce {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::vector<std::vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && isPalindrome(words[i] + words[j])) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    bool isPalindrome(const std::string& word) {
        int left = 0, right = word.size() - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Optimal solution: O(n * m) where n is the number of words and m is the maximum length of a word
class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::unordered_map<std::string, int> wordMap;
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                std::string prefix = words[i].substr(0, j);
                std::string suffix = words[i].substr(j);
                if (isPalindrome(prefix)) {
                    std::string reversedSuffix = suffix;
                    std::reverse(reversedSuffix.begin(), reversedSuffix.end());
                    if (wordMap.find(reversedSuffix) != wordMap.end() && wordMap[reversedSuffix] != i) {
                        result.push_back({wordMap[reversedSuffix], i});
                    }
                }
                if (j != words[i].size() && isPalindrome(suffix)) {
                    std::string reversedPrefix = prefix;
                    std::reverse(reversedPrefix.begin(), reversedPrefix.end());
                    if (wordMap.find(reversedPrefix) != wordMap.end() && wordMap[reversedPrefix] != i) {
                        result.push_back({i, wordMap[reversedPrefix]});
                    }
                }
            }
        }
        return result;
    }

    bool isPalindrome(const std::string& word) {
        int left = 0, right = word.size() - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"bat", "tab", "cat"};
    std::vector<std::vector<int>> result1 = solution.palindromePairs(words1);
    for (const auto& pair : result1) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words2 = {"a", ""};
    std::vector<std::vector<int>> result2 = solution.palindromePairs(words2);
    for (const auto& pair : result2) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words3 = {"abcd", "dcba", "lls", "s", "sssll"};
    std::vector<std::vector<int>> result3 = solution.palindromePairs(words3);
    for (const auto& pair : result3) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    return 0;
}
```