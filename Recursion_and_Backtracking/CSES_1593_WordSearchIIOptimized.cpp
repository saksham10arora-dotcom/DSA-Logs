```cpp
// Word Search II Optimized
// https://cses.fi/problemset/task/1593
// Given a grid of characters and a list of words, find all words that can be formed
// by traversing the grid in any direction (horizontally, vertically, or diagonally).

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach with O(26^L * N * M * L) complexity
// where L is the length of the longest word, N is the number of words, and M is the size of the grid
// This approach is inefficient and will not pass the time limit for large inputs

// Optimal solution with O(N * M * 4^L) complexity
// where N is the number of words, M is the size of the grid, and L is the length of the longest word
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    std::string word;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
        node->word = word;
    }

    void search(const std::vector<std::vector<char>>& grid, int x, int y, TrieNode* node, std::unordered_set<std::string>& result) {
        if (node->isEndOfWord) {
            result.insert(node->word);
        }
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') {
            return;
        }
        char c = grid[x][y];
        if (node->children.find(c) == node->children.end()) {
            return;
        }
        grid[x][y] = '#';
        search(grid, x - 1, y - 1, node->children[c], result);
        search(grid, x - 1, y, node->children[c], result);
        search(grid, x - 1, y + 1, node->children[c], result);
        search(grid, x, y - 1, node->children[c], result);
        search(grid, x, y + 1, node->children[c], result);
        search(grid, x + 1, y - 1, node->children[c], result);
        search(grid, x + 1, y, node->children[c], result);
        search(grid, x + 1, y + 1, node->children[c], result);
        grid[x][y] = c;
    }
};

std::vector<std::string> wordSearchII(const std::vector<std::vector<char>>& grid, const std::vector<std::string>& words) {
    Trie trie;
    for (const std::string& word : words) {
        trie.insert(word);
    }
    std::unordered_set<std::string> result;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            trie.search(grid, i, j, trie.root, result);
        }
    }
    std::vector<std::string> answer(result.begin(), result.end());
    return answer;
}

int main() {
    // Test case 1
    std::vector<std::vector<char>> grid1 = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    std::vector<std::string> words1 = {"oath", "pea", "eat", "rain"};
    std::vector<std::string> result1 = wordSearchII(grid1, words1);
    for (const std::string& word : result1) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::vector<std::vector<char>> grid2 = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };
    std::vector<std::string> words2 = {"abc", "def", "ghi"};
    std::vector<std::string> result2 = wordSearchII(grid2, words2);
    for (const std::string& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<std::vector<char>> grid3 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    std::vector<std::string> words3 = {"aaaa", "aa", "a"};
    std::vector<std::string> result3 = wordSearchII(grid3, words3);
    for (const std::string& word : result3) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
```