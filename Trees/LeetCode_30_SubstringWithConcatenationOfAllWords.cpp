```cpp
// Substring With Concatenation Of All Words, https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// You are given a string s and an array of strings words. All the strings of words are of the same length.
// A concatenated substring in s is a substring that contains each string of words exactly once.
// Return the starting indices of all the concatenated substrings in s.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n * m * k) where n is the length of s, m is the number of words, and k is the length of each word
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        int wordCount = words.size();
        int wordLength = words[0].size();
        int totalLength = wordCount * wordLength;
        std::unordered_map<std::string, int> wordMap;
        
        for (const auto& word : words) {
            wordMap[word]++;
        }
        
        for (int i = 0; i <= s.size() - totalLength; i++) {
            std::unordered_map<std::string, int> tempMap = wordMap;
            for (int j = 0; j < wordCount; j++) {
                std::string word = s.substr(i + j * wordLength, wordLength);
                if (tempMap.find(word) == tempMap.end() || tempMap[word] == 0) {
                    break;
                }
                tempMap[word]--;
                if (j == wordCount - 1) {
                    result.push_back(i);
                }
            }
        }
        
        return result;
    }
};

// Optimal solution: O(n * m * k) where n is the length of s, m is the number of words, and k is the length of each word
class SolutionOptimal {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        int wordCount = words.size();
        int wordLength = words[0].size();
        int totalLength = wordCount * wordLength;
        std::unordered_map<std::string, int> wordMap;
        
        for (const auto& word : words) {
            wordMap[word]++;
        }
        
        for (int i = 0; i < wordLength; i++) {
            std::unordered_map<std::string, int> tempMap;
            int left = i;
            int count = 0;
            for (int j = i; j <= s.size() - wordLength; j += wordLength) {
                std::string word = s.substr(j, wordLength);
                if (wordMap.find(word) != wordMap.end()) {
                    tempMap[word]++;
                    count++;
                    if (tempMap[word] > wordMap[word]) {
                        while (tempMap[word] > wordMap[word]) {
                            std::string leftWord = s.substr(left, wordLength);
                            tempMap[leftWord]--;
                            count--;
                            left += wordLength;
                        }
                    }
                    if (count == wordCount) {
                        result.push_back(left);
                        std::string leftWord = s.substr(left, wordLength);
                        tempMap[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                } else {
                    tempMap.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    SolutionOptimal solutionOptimal;
    
    std::string s1 = "barfoothefoobarman";
    std::vector<std::string> words1 = {"foo","bar"};
    std::vector<int> result1 = solution.findSubstring(s1, words1);
    std::vector<int> resultOptimal1 = solutionOptimal.findSubstring(s1, words1);
    std::cout << "Result: ";
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Result Optimal: ";
    for (int i : resultOptimal1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::string s2 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words2 = {"word","good","best","word"};
    std::vector<int> result2 = solution.findSubstring(s2, words2);
    std::vector<int> resultOptimal2 = solutionOptimal.findSubstring(s2, words2);
    std::cout << "Result: ";
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Result Optimal: ";
    for (int i : resultOptimal2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::string s3 = "barfoofoobarthefoobarman";
    std::vector<std::string> words3 = {"bar","foo","the"};
    std::vector<int> result3 = solution.findSubstring(s3, words3);
    std::vector<int> resultOptimal3 = solutionOptimal.findSubstring(s3, words3);
    std::cout << "Result: ";
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Result Optimal: ";
    for (int i : resultOptimal3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```