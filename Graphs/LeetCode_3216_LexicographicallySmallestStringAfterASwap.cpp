```cpp
// LeetCode problem 3216: Lexicographically Smallest String After A Swap
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
// Given a string s and an integer k, find the lexicographically smallest string after applying the given operations.

#include <iostream>
#include <string>
#include <algorithm>

// Brute force approach with O(n^2) complexity
std::string lexicographicallySmallestStringBruteForce(std::string s, int k) {
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] > s[j] && k > 0) {
                std::swap(s[i], s[j]);
                k--;
            }
        }
    }
    return s;
}

// Optimal solution with O(n) complexity
std::string lexicographicallySmallestStringOptimal(std::string s, int k) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        char minChar = s[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < minChar) {
                minChar = s[j];
                minIndex = j;
            }
        }
        if (minIndex != i && k > 0) {
            std::swap(s[i], s[minIndex]);
            k--;
        }
    }
    return s;
}

int main() {
    std::string s1 = "11112";
    int k1 = 4;
    std::cout << "Lexicographically smallest string after applying operations: " << lexicographicallySmallestStringOptimal(s1, k1) << std::endl;

    std::string s2 = "00110";
    int k2 = 1;
    std::cout << "Lexicographically smallest string after applying operations: " << lexicographicallySmallestStringOptimal(s2, k2) << std::endl;

    std::string s3 = "11111";
    int k3 = 10;
    std::cout << "Lexicographically smallest string after applying operations: " << lexicographicallySmallestStringOptimal(s3, k3) << std::endl;

    return 0;
}
```