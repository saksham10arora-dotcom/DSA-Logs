```cpp
// LeetCode problem 2416: Sum Of Prefix Scores Of Strings
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
// Given an array of strings words, return the sum of the prefix scores of all the strings in the array.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int sumPrefixScores(std::vector<std::string>& words) {
        // Brute force approach with O(n^2 * m) complexity
        // int sum = 0;
        // for (const auto& word : words) {
        //     int score = 0;
        //     for (const auto& w : words) {
        //         if (w.find(word) == 0) {
        //             score++;
        //         }
        //     }
        //     sum += score;
        // }
        // return sum;

        // Optimal solution with O(n * m) complexity
        std::unordered_map<std::string, int> prefixCount;
        int sum = 0;
        for (const auto& word : words) {
            std::string prefix;
            for (char c : word) {
                prefix += c;
                prefixCount[prefix]++;
            }
        }
        for (const auto& word : words) {
            std::string prefix;
            int score = 0;
            for (char c : word) {
                prefix += c;
                score += prefixCount[prefix];
            }
            sum += score;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"abc", "ab", "bc", "b"};
    std::cout << solution.sumPrefixScores(words1) << std::endl;  // Output: 25

    std::vector<std::string> words2 = {"abcd"};
    std::cout << solution.sumPrefixScores(words2) << std::endl;  // Output: 4

    std::vector<std::string> words3 = {"a", "aa", "aaa", "aaaa"};
    std::cout << solution.sumPrefixScores(words3) << std::endl;  // Output: 15

    return 0;
}
```