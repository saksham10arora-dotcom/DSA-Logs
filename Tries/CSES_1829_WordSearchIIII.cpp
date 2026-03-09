```cpp
// Word Search I I I I, https://cses.fi/problemset/task/1829
// Given a grid of characters and a list of words, find all the words in the grid.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach: O(n*m*4^L) where n is the number of rows, m is the number of columns, and L is the maximum length of a word
// This approach is inefficient because it checks all possible directions for each cell in the grid.

// Optimal solution: O(n*m*4^L) can be improved by using a Trie data structure to store the words, resulting in O(n*m*3^L) in the worst case
// This approach is more efficient because it uses a Trie to quickly check if a word is present in the grid.

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
};

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    Trie trie;
    for (const std::string& word : words) {
        trie.insert(word);
    }

    std::unordered_set<std::string> result;
    int rows = board.size();
    int cols = board[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    std::function<void(int, int, std::string, TrieNode*)> dfs = [&](int x, int y, std::string word, TrieNode* node) {
        if (node->isEndOfWord) {
            result.insert(word);
        }

        visited[x][y] = true;

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && node->children.find(board[nx][ny]) != node->children.end()) {
                dfs(nx, ny, word + board[nx][ny], node->children[board[nx][ny]]);
            }
        }

        visited[x][y] = false;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (trie.root->children.find(board[i][j]) != trie.root->children.end()) {
                dfs(i, j, std::string(1, board[i][j]), trie.root->children[board[i][j]]);
            }
        }
    }

    std::vector<std::string> res(result.begin(), result.end());
    return res;
}

int main() {
    // Test case 1
    std::vector<std::vector<char>> board1 = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    std::vector<std::string> words1 = {"oath", "pea", "eat", "rain"};
    std::vector<std::string> result1 = findWords(board1, words1);
    for (const std::string& word : result1) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::vector<std::vector<char>> board2 = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };
    std::vector<std::string> words2 = {"abc", "def", "ghi"};
    std::vector<std::string> result2 = findWords(board2, words2);
    for (const std::string& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<std::vector<char>> board3 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    std::vector<std::string> words3 = {"a", "aa", "aaa", "aaaa"};
    std::vector<std::string> result3 = findWords(board3, words3);
    for (const std::string& word : result3) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
```