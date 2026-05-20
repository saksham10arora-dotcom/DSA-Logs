```cpp
// LeetCode problem 336: Palindrome Pairs III
// https://leetcode.com/problems/palindrome-pairs-iii/
// Given a list of unique words, find all pairs of indices (i, j) such that the concatenation of the words at indices i and j results in a palindrome.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n^2 * m) where n is the number of words and m is the maximum length of a word
class Solution {
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

    bool isPalindrome(const std::string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Optimal solution: O(n * m) where n is the number of words and m is the maximum length of a word
class SolutionOptimal {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::unordered_map<std::string, int> wordMap;
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            std::string word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                std::string prefix = word.substr(0, j);
                std::string suffix = word.substr(j);
                if (isPalindrome(prefix) && isPalindrome(suffix) && wordMap.find(suffix) != wordMap.end() && wordMap[suffix] != i) {
                    result.push_back({wordMap[suffix], i});
                }
                if (isPalindrome(suffix) && isPalindrome(reverse(prefix)) && wordMap.find(reverse(suffix)) != wordMap.end() && wordMap[reverse(suffix)] != i) {
                    result.push_back({i, wordMap[reverse(suffix)]});
                }
            }
        }
        return result;
    }

    bool isPalindrome(const std::string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    std::string reverse(const std::string& s) {
        std::string result = s;
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    SolutionOptimal solutionOptimal;

    std::vector<std::string> words1 = {"bat", "tab", "cat"};
    std::vector<std::vector<int>> result1 = solutionOptimal.palindromePairs(words1);
    for (const auto& pair : result1) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words2 = {"a", ""};
    std::vector<std::vector<int>> result2 = solutionOptimal.palindromePairs(words2);
    for (const auto& pair : result2) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words3 = {"abcd", "dcba", "lls", "s", "sssll"};
    std::vector<std::vector<int>> result3 = solutionOptimal.palindromePairs(words3);
    for (const auto& pair : result3) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    return 0;
}
```