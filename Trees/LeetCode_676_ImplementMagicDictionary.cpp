```cpp
// LeetCode problem 676: Implement Magic Dictionary
// https://leetcode.com/problems/implement-magic-dictionary/
// Implement a magic dictionary that supports the following operations:
// buildDict(String[] dict) - Build a dictionary through a list of words
// search(String word) - Returns the number of words that can be formed by changing exactly one character

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class MagicDictionary {
public:
    std::unordered_map<int, std::vector<std::string>> dict;

    MagicDictionary() {}

    void buildDict(std::vector<std::string> dict) {
        for (const auto& word : dict) {
            this->dict[word.size()].push_back(word);
        }
    }

    bool search(std::string word) {
        // Brute force approach with O(n*m) complexity
        // for (const auto& w : dict[word.size()]) {
        //     int diff = 0;
        //     for (int i = 0; i < word.size(); i++) {
        //         if (word[i]!= w[i]) diff++;
        //     }
        //     if (diff == 1) return true;
        // }
        // return false;

        // Optimal solution with O(n*m) complexity
        for (const auto& w : dict[word.size()]) {
            int diff = 0;
            for (int i = 0; i < word.size(); i++) {
                if (word[i]!= w[i]) diff++;
                if (diff > 1) break;
            }
            if (diff == 1) return true;
        }
        return false;
    }
};

int main() {
    MagicDictionary magicDictionary;
    std::vector<std::string> dict = {"hello", "leetcode"};
    magicDictionary.buildDict(dict);
    std::cout << std::boolalpha << magicDictionary.search("hello") << std::endl;  // False
    std::cout << std::boolalpha << magicDictionary.search("hhllo") << std::endl;  // True
    std::cout << std::boolalpha << magicDictionary.search("hell") << std::endl;  // False
    std::cout << std::boolalpha << magicDictionary.search("leetcoded") << std::endl;  // False
    return 0;
}
```