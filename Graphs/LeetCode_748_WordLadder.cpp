```cpp
// Word Ladder, https://leetcode.com/problems/word-ladder/, 
// Given two words (beginWord and endWord), and a dictionary's word list, 
// find the length of shortest transformation sequence from beginWord to endWord, 
// such that: Only one letter can be changed at a time. Each intermediate word must exist in the word list.

#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>

// Brute force approach: generate all possible transformations of the current word, 
// and check if the transformed word is in the dictionary. O(26 * N * M) where N is the length of the word and M is the number of words in the dictionary
class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            if (word == endWord) return length;
            for (int i = 0; i < word.size(); ++i) {
                std::string nextWord = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    nextWord[i] = c;
                    if (dict.count(nextWord) && nextWord != word) {
                        q.push({nextWord, length + 1});
                        dict.erase(nextWord);
                    }
                }
            }
        }
        return 0;
    }
};

// Optimal solution: use a bidirectional BFS to reduce the search space. O(N * M) where N is the length of the word and M is the number of words in the dictionary
class SolutionOptimal {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        std::unordered_set<std::string> visited;
        std::queue<std::pair<std::string, int>> q1, q2;
        q1.push({beginWord, 1});
        q2.push({endWord, 1});
        visited.insert(beginWord);
        visited.insert(endWord);
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() <= q2.size()) {
                auto [word, length] = q1.front();
                q1.pop();
                for (int i = 0; i < word.size(); ++i) {
                    std::string nextWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[i] = c;
                        if (nextWord == endWord) return length + 1;
                        if (dict.count(nextWord) && !visited.count(nextWord)) {
                            q1.push({nextWord, length + 1});
                            visited.insert(nextWord);
                        }
                    }
                }
            } else {
                auto [word, length] = q2.front();
                q2.pop();
                for (int i = 0; i < word.size(); ++i) {
                    std::string nextWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[i] = c;
                        if (nextWord == beginWord) return length + 1;
                        if (dict.count(nextWord) && !visited.count(nextWord)) {
                            q2.push({nextWord, length + 1});
                            visited.insert(nextWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::cout << solution.ladderLength("hit", "cog", wordList1) << std::endl;  // Output: 5
    std::vector<std::string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    std::cout << solution.ladderLength("hit", "cog", wordList2) << std::endl;  // Output: 0
    std::vector<std::string> wordList3 = {"a", "b", "c"};
    std::cout << solution.ladderLength("a", "c", wordList3) << std::endl;  // Output: 2
    return 0;
}
```