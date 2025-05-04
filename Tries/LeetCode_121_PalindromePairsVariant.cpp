```cpp
// LeetCode problem 336: Palindrome Pairs Variant, https://leetcode.com/problems/palindrome-pairs/
// Given a list of unique words, return all pairs of indices [i, j] that the concatenation of the words at indices i and j results in a palindrome.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: check every pair of words and see if their concatenation is a palindrome
// O(n^2 * m) where n is the number of words and m is the maximum length of a word
std::vector<std::vector<int>> palindromePairsBruteForce(std::vector<std::string>& words) {
    std::vector<std::vector<int>> result;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i != j && isPalindrome(words[i] + words[j])) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

bool isPalindrome(const std::string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++, right--;
    }
    return true;
}

// Optimal solution: use a Trie to store the reversed words and check for palindrome
// O(n * m) where n is the number of words and m is the maximum length of a word
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int index;
    TrieNode() : index(-1) {}
};

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < words.size(); i++) {
        std::string reversed = words[i];
        std::reverse(reversed.begin(), reversed.end());
        TrieNode* node = root;
        for (char c : reversed) {
            if (!node->children.count(c)) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->index = i;
    }

    std::vector<std::vector<int>> result;
    for (int i = 0; i < words.size(); i++) {
        TrieNode* node = root;
        for (int j = 0; j < words[i].size(); j++) {
            if (node->index != -1 && isPalindrome(words[i].substr(j))) {
                result.push_back({i, node->index});
            }
            if (!node->children.count(words[i][j])) break;
            node = node->children[words[i][j]];
        }
        if (node->index != -1 && node->index != i) {
            result.push_back({i, node->index});
        }
    }
    return result;
}

int main() {
    std::vector<std::string> words1 = {"bat", "tab", "cat"};
    std::vector<std::vector<int>> result1 = palindromePairs(words1);
    for (const auto& pair : result1) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words2 = {"a", ""};
    std::vector<std::vector<int>> result2 = palindromePairs(words2);
    for (const auto& pair : result2) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    std::vector<std::string> words3 = {"abcd", "dcba", "lls", "s", "sssll"};
    std::vector<std::vector<int>> result3 = palindromePairs(words3);
    for (const auto& pair : result3) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    return 0;
}
```