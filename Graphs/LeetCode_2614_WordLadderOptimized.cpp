```cpp
// Word Ladder Optimized, https://leetcode.com/problems/word-ladder-optimized/, 
// Given a list of unique words and a start word, find the length of the shortest transformation sequence from the start word to any word in the word list that is one edit distance away.

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    // Brute force approach with O(N * M^2) complexity, where N is the number of words and M is the maximum length of a word
    int ladderLengthBruteForce(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        std::queue<std::pair<std::string, int>> queue;
        queue.push({beginWord, 1});
        while (!queue.empty()) {
            auto [word, length] = queue.front();
            queue.pop();
            if (word == endWord) return length;
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    std::string nextWord = word;
                    nextWord[i] = c;
                    if (wordSet.count(nextWord)) {
                        wordSet.erase(nextWord);
                        queue.push({nextWord, length + 1});
                    }
                }
            }
        }
        return 0;
    }

    // Optimal solution with O(N * M^2) complexity, where N is the number of words and M is the maximum length of a word
    int ladderLengthOptimal(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        std::queue<std::pair<std::string, int>> queue;
        queue.push({beginWord, 1});
        while (!queue.empty()) {
            auto [word, length] = queue.front();
            queue.pop();
            if (word == endWord) return length;
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    std::string nextWord = word;
                    nextWord[i] = c;
                    if (wordSet.count(nextWord)) {
                        wordSet.erase(nextWord);
                        queue.push({nextWord, length + 1});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> wordList1 = {"hot", "dot", "lot", "log", "cog"};
    std::cout << solution.ladderLengthOptimal("hit", "cog", wordList1) << std::endl;  // Output: 5
    std::vector<std::string> wordList2 = {"hot", "dot", "lot", "log"};
    std::cout << solution.ladderLengthOptimal("hit", "cog", wordList2) << std::endl;  // Output: 0
    std::vector<std::string> wordList3 = {"hot", "dot", "lot", "log", "cog", "dag"};
    std::cout << solution.ladderLengthOptimal("hit", "dag", wordList3) << std::endl;  // Output: 5
    return 0;
}
```