```cpp
// LeetCode problem 1950: String Hashes I I I
// https://leetcode.com/problems/string-hashes-iii/
// Given a string s, return the hash value of the string.

#include <iostream>
#include <string>

// Brute force approach with O(n) complexity
class Solution_BruteForce {
public:
    long long hash(string s) {
        long long hashValue = 0;
        for (char c : s) {
            hashValue = (hashValue * 31 + c - 'a' + 1) % 1000000007;
        }
        return hashValue;
    }
};

// Optimal solution with O(n) complexity
class Solution_Optimal {
public:
    long long hash(string s) {
        const int MOD = 1000000007;
        const int P = 31;
        long long hashValue = 0;
        long long pPow = 1;
        for (char c : s) {
            hashValue = (hashValue + (c - 'a' + 1) * pPow) % MOD;
            pPow = (pPow * P) % MOD;
        }
        return hashValue;
    }
};

int main() {
    Solution_Optimal solution;
    std::cout << solution.hash("leetcode") << std::endl;
    std::cout << solution.hash("loveleetcode") << std::endl;
    std::cout << solution.hash("a") << std::endl;
    return 0;
}
```