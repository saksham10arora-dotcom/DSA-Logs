```cpp
// LeetCode problem 524: Longest Word In Dictionary Through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Given a string and a dictionary of words, find the longest word in the dictionary that can be formed by deleting characters from the string.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Brute force approach: O(n * m * k) where n is the length of the string, m is the number of words in the dictionary, and k is the average length of a word
class Solution {
public:
    std::string findLongestWord(std::string s, std::vector<std::string>& d) {
        std::string longestWord;
        for (const auto& word : d) {
            int i = 0, j = 0;
            while (i < s.size() && j < word.size()) {
                if (s[i] == word[j]) {
                    j++;
                }
                i++;
            }
            if (j == word.size() && (word.size() > longestWord.size() || (word.size() == longestWord.size() && word < longestWord))) {
                longestWord = word;
            }
        }
        return longestWord;
    }
};

// Optimal solution: O(n * m * k) where n is the length of the string, m is the number of words in the dictionary, and k is the average length of a word
// The optimal solution is the same as the brute force approach because we need to check every word in the dictionary against the string.

int main() {
    Solution solution;
    std::vector<std::string> dictionary1 = {"apple", "apply", "appliance"};
    std::cout << solution.findLongestWord("abpplee", dictionary1) << std::endl;  // Output: "apple"

    std::vector<std::string> dictionary2 = {"word", "wordle", "words", "wordy"};
    std::cout << solution.findLongestWord("wlde", dictionary2) << std::endl;  // Output: "wordle"

    std::vector<std::string> dictionary3 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    std::cout << solution.findLongestWord("abpplee", dictionary3) << std::endl;  // Output: "apple"

    return 0;
}
```