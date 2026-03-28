```cpp
// LeetCode problem 1943: Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Design a data structure that supports adding new words and finding if a given word is in the data structure.

#include <iostream>
#include <unordered_map>
#include <string>

class WordDictionary {
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool isWord;
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(const std::string& word) {
        // O(m) where m is the length of the word
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool search(const std::string& word) {
        // O(m) where m is the length of the word
        return searchFrom(root, word);
    }

    bool searchFrom(TrieNode* node, const std::string& word) {
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (auto& child : node->children) {
                    if (searchFrom(child.second, word.substr(i + 1))) {
                        return true;
                    }
                }
                return false;
            }
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isWord;
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    std::cout << std::boolalpha << wordDictionary.search("pad") << std::endl; // False
    std::cout << std::boolalpha << wordDictionary.search("bad") << std::endl; // True
    std::cout << std::boolalpha << wordDictionary.search(".ad") << std::endl; // True
    std::cout << std::boolalpha << wordDictionary.search("b..") << std::endl; // True
    return 0;
}
```