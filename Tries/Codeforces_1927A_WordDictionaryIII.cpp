```cpp
// Codeforces_1927A_WordDictionaryIII
// https://codeforces.com/contest/1927/problem/A
// Design a word dictionary with basic operations.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n*m) where n is the number of words and m is the average length of a word
class WordDictionary {
public:
    std::vector<std::string> words;
    bool search(const std::string& word) {
        for (const auto& w : words) {
            if (w == word) return true;
        }
        return false;
    }
    void addWord(const std::string& word) {
        words.push_back(word);
    }
};

// Optimal solution: O(m) where m is the length of a word
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class WordDictionaryOptimal {
public:
    TrieNode* root;
    WordDictionaryOptimal() : root(new TrieNode()) {}
    void addWord(const std::string& word) {
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
        return searchHelper(root, word, 0);
    }
    bool searchHelper(TrieNode* node, const std::string& word, int index) {
        if (index == word.size()) return node->isEndOfWord;
        if (word[index] == '.') {
            for (auto& child : node->children) {
                if (searchHelper(child.second, word, index + 1)) return true;
            }
            return false;
        }
        if (node->children.find(word[index]) == node->children.end()) return false;
        return searchHelper(node->children[word[index]], word, index + 1);
    }
};

int main() {
    WordDictionaryOptimal dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    std::cout << std::boolalpha << dict.search("pad") << std::endl; // false
    std::cout << std::boolalpha << dict.search("bad") << std::endl; // true
    std::cout << std::boolalpha << dict.search(".ad") << std::endl; // true
    std::cout << std::boolalpha << dict.search("b..") << std::endl; // true
    return 0;
}
```