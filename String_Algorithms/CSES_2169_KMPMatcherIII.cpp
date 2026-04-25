```cpp
// K M P Matcher I I I, https://cses.fi/problemset/task/2169, 
// Given a string and a pattern, find all occurrences of the pattern in the string.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m) complexity
std::vector<int> bruteForce(const std::string& s, const std::string& p) {
    std::vector<int> result;
    for (int i = 0; i <= s.size() - p.size(); i++) {
        bool match = true;
        for (int j = 0; j < p.size(); j++) {
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

// Optimal solution with O(n+m) complexity using KMP algorithm
std::vector<int> computeLPS(const std::string& p) {
    std::vector<int> lps(p.size());
    int length = 0;
    for (int i = 1; i < p.size(); i++) {
        while (length > 0 && p[i] != p[length]) {
            length = lps[length - 1];
        }
        if (p[i] == p[length]) {
            length++;
        }
        lps[i] = length;
    }
    return lps;
}

std::vector<int> kmpMatcher(const std::string& s, const std::string& p) {
    std::vector<int> lps = computeLPS(p);
    std::vector<int> result;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = lps[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == p.size()) {
            result.push_back(i - p.size() + 1);
            j = lps[j - 1];
        }
    }
    return result;
}

int main() {
    std::string s1 = "abcabcabc";
    std::string p1 = "abc";
    std::vector<int> result1 = kmpMatcher(s1, p1);
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string s2 = "abxabcabc";
    std::string p2 = "abc";
    std::vector<int> result2 = kmpMatcher(s2, p2);
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string s3 = "aaaaaa";
    std::string p3 = "aa";
    std::vector<int> result3 = kmpMatcher(s3, p3);
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```