```cpp
// LeetCode problem 3110: Score Of A String
// https://leetcode.com/problems/score-of-a-string/
// Given a string s, return the score of the string, which is the number of pairs of different characters.

#include <iostream>
#include <string>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i]!= s[j]) {
                    score++;
                }
            }
        }
        return score;
    }
};

// Optimal solution with O(n) complexity
class Solution_Optimal {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    count++;
                }
            }
            score += count * (n - count);
        }
        return score / 2;
    }
};

int main() {
    Solution_Optimal solution;
    std::cout << solution.scoreOfString("aba") << std::endl;  // Output: 2
    std::cout << solution.scoreOfString("aaa") << std::endl;  // Output: 0
    std::cout << solution.scoreOfString("abc") << std::endl;  // Output: 3
    return 0;
}
```