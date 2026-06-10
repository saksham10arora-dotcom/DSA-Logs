```cpp
// LeetCode problem 1638: Word Search I I I I
// https://leetcode.com/problems/word-search-ii/
// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach with O(N * M * 4^L * W) complexity, where N is the number of rows, M is the number of columns, L is the maximum length of a word, and W is the number of words.
class Solution_BruteForce {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        std::vector<std::string> result;
        for (const auto& word : words) {
            if (exist(board, word)) {
                result.push_back(word);
            }
        }
        return result;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(std::vector<std::vector<char>>& board, std::string word, int i, int j, int k, std::vector<std::vector<bool>>& visited) {
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k]) {
            return false;
        }
        visited[i][j] = true;
        bool found = dfs(board, word, i + 1, j, k + 1, visited) ||
                      dfs(board, word, i - 1, j, k + 1, visited) ||
                      dfs(board, word, i, j + 1, k + 1, visited) ||
                      dfs(board, word, i, j - 1, k + 1, visited);
        visited[i][j] = false;
        return found;
    }
};

// Optimal solution with O(N * M * 4^L + W) complexity, where N is the number of rows, M is the number of columns, L is the maximum length of a word, and W is the number of words.
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isWord;
    std::string word;
    TrieNode() : isWord(false) {}
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isWord = true;
            node->word = word;
        }
        std::vector<std::string> result;
        int rows = board.size();
        int cols = board[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j, visited, result);
            }
        }
        return result;
    }

    void dfs(std::vector<std::vector<char>>& board, TrieNode* node, int i, int j, std::vector<std::vector<bool>>& visited, std::vector<std::string>& result) {
        if (node->isWord) {
            result.push_back(node->word);
            node->isWord = false;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || node->children.find(board[i][j]) == node->children.end()) {
            return;
        }
        visited[i][j] = true;
        dfs(board, node->children[board[i][j]], i + 1, j, visited, result);
        dfs(board, node->children[board[i][j]], i - 1, j, visited, result);
        dfs(board, node->children[board[i][j]], i, j + 1, visited, result);
        dfs(board, node->children[board[i][j]], i, j - 1, visited, result);
        visited[i][j] = false;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> board1 = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    std::vector<std::string> words1 = {"oath", "pea", "eat", "rain"};
    std::vector<std::string> result1 = solution.findWords(board1, words1);
    for (const auto& word : result1) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<char>> board2 = {{'a', 'b'}, {'c', 'd'}};
    std::vector<std::string> words2 = {"ab", "cb", "ad", "cd", "ac", "bd"};
    std::vector<std::string> result2 = solution.findWords(board2, words2);
    for (const auto& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<char>> board3 = {{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, {'a', 'a', 'a