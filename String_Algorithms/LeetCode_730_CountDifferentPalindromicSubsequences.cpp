```cpp
// LeetCode problem 730: Count Different Palindromic Subsequences
// https://leetcode.com/problems/count-different-palindromic-subsequences/
// Given a string S, count the number of different palindromic subsequences in S.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(2^n) complexity
class Solution_BruteForce {
public:
    int countPalindromicSubsequence(std::string s) {
        int count = 0;
        for (int mask = 0; mask < (1 << s.size()); ++mask) {
            std::string subsequence;
            for (int i = 0; i < s.size(); ++i) {
                if (mask & (1 << i)) {
                    subsequence += s[i];
                }
            }
            if (isPalindrome(subsequence)) {
                count++;
            }
        }
        return count;
    }

    bool isPalindrome(const std::string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Optimal solution: O(n^2) complexity
class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        int count = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int first = s.find(c);
            int last = s.rfind(c);
            if (first != std::string::npos) {
                std::unordered_map<char, int> charCount;
                for (int i = first + 1; i < last; ++i) {
                    charCount[s[i]]++;
                }
                count += charCount.size();
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::cout << solution.countPalindromicSubsequence("abc") << std::endl;  // Output: 3
    std::cout << solution.countPalindromicSubsequence("aaa") << std::endl;  // Output: 1
    return 0;
}
```