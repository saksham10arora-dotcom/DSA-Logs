```cpp
// Word Search II, https://cses.fi/problemset/task/1784, 
// Given a grid of characters and a list of words, find all words that can be formed by moving right or down in the grid.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach with O(2^(m*n) * k) complexity
// void bruteForce(std::vector<std::vector<char>>& grid, std::vector<std::string>& words) {
//     // implementation
// }

// Optimal solution with O(m*n*4^L) complexity, where m and n are the dimensions of the grid and L is the maximum length of a word
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    std::string word;

    TrieNode() : isEndOfWord(false) {}
};

void insert(TrieNode* root, const std::string& word) {
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

void search(std::vector<std::vector<char>>& grid, TrieNode* root, int i, int j, std::unordered_set<std::string>& result) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#') {
        return;
    }

    char c = grid[i][j];
    if (root->children.find(c) == root->children.end()) {
        return;
    }

    root = root->children[c];
    if (root->isEndOfWord) {
        result.insert(root->word);
    }

    grid[i][j] = '#';
    search(grid, root, i + 1, j, result);
    search(grid, root, i - 1, j, result);
    search(grid, root, i, j + 1, result);
    search(grid, root, i, j - 1, result);
    grid[i][j] = c;
}

std::vector<std::string> wordSearchII(std::vector<std::vector<char>>& grid, std::vector<std::string>& words) {
    TrieNode* root = new TrieNode();
    for (const std::string& word : words) {
        insert(root, word);
    }

    std::unordered_set<std::string> result;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            search(grid, root, i, j, result);
        }
    }

    std::vector<std::string> res(result.begin(), result.end());
    return res;
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
    std::vector<std::string> words2 = {"abc", "def", "ghi", "jkl"};
    std::vector<std::string> result2 = wordSearchII(grid2, words2);
    for (const std::string& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<std::vector<char>> grid3 = {
        {'a'}
    };
    std::vector<std::string> words3 = {"a"};
    std::vector<std::string> result3 = wordSearchII(grid3, words3);
    for (const std::string& word : result3) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
```