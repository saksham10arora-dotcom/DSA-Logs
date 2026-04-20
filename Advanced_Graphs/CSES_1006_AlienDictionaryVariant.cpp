```cpp
// Alien Dictionary Variant, https://cses.fi/problemset/task/1006
// Given a list of words, determine the order of the letters in the alien dictionary.

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

// Brute force approach: Generate all permutations of the alphabet and check if they satisfy the given conditions. O(n! * m)
// However, this approach is impractical due to its high time complexity.

// Optimal solution: Use topological sorting to find the order of the letters. O(n + m)
std::string alienDictionaryVariant(const std::vector<std::string>& words) {
    std::unordered_map<char, std::vector<char>> graph;
    std::unordered_map<char, int> inDegree;

    // Build the graph
    for (int i = 0; i < words.size() - 1; ++i) {
        const std::string& word1 = words[i];
        const std::string& word2 = words[i + 1];

        int j = 0;
        while (j < word1.size() && j < word2.size() && word1[j] == word2[j]) {
            ++j;
        }

        if (j < word1.size() && j < word2.size()) {
            graph[word1[j]].push_back(word2[j]);
            inDegree[word2[j]]++;
        } else if (word1.size() > word2.size()) {
            return "";
        }
    }

    // Find all unique characters
    std::unordered_set<char> characters;
    for (const std::string& word : words) {
        for (char c : word) {
            characters.insert(c);
        }
    }

    // Initialize in-degree for all characters
    for (char c : characters) {
        if (inDegree.find(c) == inDegree.end()) {
            inDegree[c] = 0;
        }
    }

    // Topological sorting
    std::queue<char> queue;
    for (const auto& pair : inDegree) {
        if (pair.second == 0) {
            queue.push(pair.first);
        }
    }

    std::string result;
    while (!queue.empty()) {
        char c = queue.front();
        queue.pop();
        result += c;

        for (char neighbor : graph[c]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }

    // Check if all characters are included in the result
    if (result.size() != characters.size()) {
        return "";
    }

    return result;
}

int main() {
    std::vector<std::string> words1 = {"wrt", "wrf", "er", "ett", "rftt"};
    std::cout << alienDictionaryVariant(words1) << std::endl;  // "wertf"

    std::vector<std::string> words2 = {"z", "x"};
    std::cout << alienDictionaryVariant(words2) << std::endl;  // "zx"

    std::vector<std::string> words3 = {"z", "x", "z"};
    std::cout << alienDictionaryVariant(words3) << std::endl;  // ""

    return 0;
}
```