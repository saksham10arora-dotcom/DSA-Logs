```cpp
// Alien Dictionary II, https://cses.fi/problemset/task/2060, 
// Given a list of words, determine if there is a valid ordering of the words such that for every pair of adjacent words, 
// the first word is a subsequence of the second word.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

// Brute force approach: Generate all permutations of the words and check each permutation (O(n!))
// This approach is not efficient for large inputs

// Optimal solution: Use topological sorting and a graph to model the relationships between the words (O(n + m))
class Solution {
public:
    bool isSubsequence(const std::string& s1, const std::string& s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == s1.size();
    }

    bool alienOrder(std::vector<std::string>& words) {
        std::unordered_map<char, std::vector<char>> graph;
        std::unordered_map<char, int> inDegree;
        for (const auto& word : words) {
            for (char c : word) {
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                }
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            const auto& s1 = words[i];
            const auto& s2 = words[i + 1];
            if (s1.size() > s2.size() && isSubsequence(s1, s2)) {
                return false;
            }
            for (int j = 0; j < std::min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    graph[s1[j]].push_back(s2[j]);
                    inDegree[s2[j]]++;
                    break;
                }
            }
        }
        std::queue<char> q;
        for (const auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        std::string result;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            for (char neighbor : graph[c]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return result.size() == inDegree.size();
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"abc", "bca", "acb"};
    std::cout << std::boolalpha << solution.alienOrder(words1) << std::endl;  // False
    std::vector<std::string> words2 = {"abc", "bac", "bca"};
    std::cout << std::boolalpha << solution.alienOrder(words2) << std::endl;  // True
    std::vector<std::string> words3 = {"abc", "bca", "acb", "bac"};
    std::cout << std::boolalpha << solution.alienOrder(words3) << std::endl;  // False
    return 0;
}
```