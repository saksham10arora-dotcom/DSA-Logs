```cpp
// Codeforces_560E_StringHashesAdvanced
// https://codeforces.com/contest/560/problem/E
// Given a string and a set of queries, find the number of substrings that match each query.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^3) complexity
int bruteForce(const std::string& s, const std::string& q) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            if (s.substr(i, j - i) == q) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n + m) complexity
struct Hash {
    static const int MOD = 1e9 + 7;
    static const int BASE = 31;

    std::vector<int> prefixHash;
    std::vector<int> power;

    Hash(const std::string& s) {
        int n = s.size();
        prefixHash.resize(n + 1);
        power.resize(n + 1);

        power[0] = 1;
        for (int i = 1; i <= n; ++i) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        prefixHash[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefixHash[i] = (prefixHash[i - 1] * BASE + s[i - 1] - 'a' + 1) % MOD;
        }
    }

    int getHash(int l, int r) {
        int hash = (prefixHash[r + 1] - (long long)prefixHash[l] * power[r - l + 1] % MOD + MOD) % MOD;
        return hash;
    }
};

int optimalSolution(const std::string& s, const std::string& q) {
    Hash hash(s);
    int count = 0;
    for (int i = 0; i <= s.size() - q.size(); ++i) {
        if (hash.getHash(i, i + q.size() - 1) == hash.getHash(0, q.size() - 1)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string s1 = "abc";
    std::string q1 = "ab";
    std::cout << "Brute force: " << bruteForce(s1, q1) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(s1, q1) << std::endl;

    std::string s2 = "aaaa";
    std::string q2 = "aa";
    std::cout << "Brute force: " << bruteForce(s2, q2) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(s2, q2) << std::endl;

    std::string s3 = "abcdef";
    std::string q3 = "def";
    std::cout << "Brute force: " << bruteForce(s3, q3) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(s3, q3) << std::endl;

    return 0;
}
```