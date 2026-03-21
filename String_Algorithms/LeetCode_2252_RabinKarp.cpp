```cpp
// Rabin Karp, https://leetcode.com/problems/rabin-karp/, 
// Given a string s and a pattern p, find all the occurrences of the pattern in the string.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m) complexity
std::vector<int> findAnagramsBruteForce(const std::string& s, const std::string& p) {
    std::vector<int> result;
    int n = s.size(), m = p.size();
    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != p[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            result.push_back(i);
        }
    }
    return result;
}

// Optimal solution with O(n+m) complexity
std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    std::vector<int> result;
    int n = s.size(), m = p.size();
    if (n < m) return result;
    const int base = 26;
    int pHash = 0, sHash = 0;
    int power = 1;
    for (int i = 0; i < m - 1; i++) {
        power = (power * base) % 101;
    }
    for (int i = 0; i < m; i++) {
        pHash = (pHash * base + p[i] - 'a') % 101;
        sHash = (sHash * base + s[i] - 'a') % 101;
    }
    for (int i = 0; i <= n - m; i++) {
        if (pHash == sHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        if (i < n - m) {
            sHash = ((sHash - (s[i] - 'a') * power) * base + s[i + m] - 'a') % 101;
            if (sHash < 0) sHash += 101;
        }
    }
    return result;
}

int main() {
    std::vector<int> result1 = findAnagrams("abxaba", "ab");
    std::cout << "Result 1: ";
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> result2 = findAnagrams("abab", "ab");
    std::cout << "Result 2: ";
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> result3 = findAnagrams("aaaa", "aa");
    std::cout << "Result 3: ";
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```