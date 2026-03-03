```cpp
// Codeforces_1822B_WordSearchII, https://codeforces.com/contest/1822/problem/B
// Given a grid of characters and a list of words, find all the words that can be formed by traversing the grid.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach: Check all possible paths in the grid for each word, O(4^n * m) where n is the length of the word and m is the number of words
// class Solution {
// public:
//     std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
//         std::vector<std::string> result;
//         for (const auto& word : words) {
//             for (int i = 0; i < board.size(); ++i) {
//                 for (int j = 0; j < board[0].size(); ++j) {
//                     if (dfs(board, word, i, j, 0)) {
//                         result.push_back(word);
//                         break;
//                     }
//                 }
//             }
//         }
//         return result;
//     }

//     bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int k) {
//         if (k == word.size()) return true;
//         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
//         char temp = board[i][j];
//         board[i][j] = '#';
//         bool found = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
//         board[i][j] = temp;
//         return found;
//     }
// };

// Optimal solution: Use a Trie to store the words and then perform DFS on the grid, O(n * m * 4^L) where n and m are the dimensions of the grid and L is the maximum length of a word
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    std::string word;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word;
        }

        std::vector<std::string> result;
        std::unordered_set<std::string> set;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, root, i, j, set);
            }
        }

        for (const auto& word : set) {
            result.push_back(word);
        }
        return result;
    }

    void dfs(std::vector<std::vector<char>>& board, TrieNode* node, int i, int j, std::unordered_set<std::string>& set) {
        if (node->word != "") {
            set.insert(node->word);
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || !node->children.count(board[i][j])) return;
        char temp = board[i][j];
        board[i][j] = '#';
        dfs(board, node->children[temp], i + 1, j, set);
        dfs(board, node->children[temp], i - 1, j, set);
        dfs(board, node->children[temp], i, j + 1, set);
        dfs(board, node->children[temp], i, j - 1, set);
        board[i][j] = temp;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> board1 = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    std::vector<std::string> words1 = {"oath", "pea", "eat", "rain"};
    for (const auto& word : solution.findWords(board1, words1)) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<char>> board2 = {{'a', 'b'}, {'c', 'd'}};
    std::vector<std::string> words2 = {"abcb"};
    for (const auto& word : solution.findWords(board2, words2)) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<char>> board3 = {{'a', 'a'}};
    std::vector<std::string> words3 = {"aaa"};
    for (const auto& word : solution.findWords(board3, words3)) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
```