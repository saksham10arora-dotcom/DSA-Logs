```cpp
// LeetCode problem 208: Implement Trie, https://leetcode.com/problems/implement-trie/
// A Trie (prefix tree) is a tree-like data structure, which is often used to store a dynamic set or associative array where the keys are usually strings.

// Brute force approach: Using a hash map to store all words and check if a word is in the map, O(n) complexity for search and insert operations
// class Trie {
//     unordered_map<string, bool> words;
// public:
//     void insert(string word) {
//         words[word] = true;
//     }
//     bool search(string word) {
//         return words.count(word);
//     }
//     bool startsWith(string prefix) {
//         for (auto& w : words) {
//             if (w.first.find(prefix) == 0) return true;
//         }
//         return false;
//     }
// };

// Optimal solution: Using a Trie data structure with a nested unordered_map to store characters and their corresponding child nodes, O(m) complexity for search, insert and startsWith operations where m is the length of the word
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;   // True
    cout << boolalpha << trie.search("app") << endl;     // False
    cout << boolalpha << trie.startsWith("app") << endl; // True
    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // True
    return 0;
}
```