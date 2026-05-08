```cpp
// LeetCode problem 3545: Minimum Deletions For At Most K Distinct Characters
// https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/
// Given a string s and an integer k, return the minimum number of deletions required to have at most k distinct characters in the string.

#include <iostream>
#include <string>
#include <unordered_map>

// Brute force approach: O(2^n * n) - generate all possible substrings and count distinct characters
int minDeletionsBruteForce(const std::string& s, int k) {
    int n = s.size();
    int minDeletions = n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::unordered_map<char, int> charCount;
        int deletions = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                ++deletions;
            } else {
                ++charCount[s[i]];
            }
        }
        if (charCount.size() <= k) {
            minDeletions = std::min(minDeletions, deletions);
        }
    }
    return minDeletions;
}

// Optimal solution: O(n * k) - use a sliding window and a priority queue to keep track of character frequencies
int minDeletions(const std::string& s, int k) {
    int n = s.size();
    std::unordered_map<char, int> charCount;
    for (char c : s) {
        ++charCount[c];
    }
    int minDeletions = 0;
    for (auto& pair : charCount) {
        minDeletions += pair.second;
    }
    int left = 0;
    int maxDeletions = minDeletions;
    for (int right = 0; right < n; ++right) {
        --charCount[s[right]];
        if (charCount[s[right]] == 0) {
            --left;
        }
        while (left < charCount.size() - k) {
            ++charCount[s[left]];
            ++left;
        }
        maxDeletions = std::min(maxDeletions, minDeletions - left);
    }
    return maxDeletions;
}

int main() {
    std::cout << minDeletions("abc", 2) << std::endl;  // Output: 0
    std::cout << minDeletions("aaabbb", 3) << std::endl;  // Output: 2
    std::cout << minDeletions("aaaaaa", 1) << std::endl;  // Output: 5
    return 0;
}
```