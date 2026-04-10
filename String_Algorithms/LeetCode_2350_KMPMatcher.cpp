```cpp
// LeetCode problem 2350: K M P Matcher
// https://leetcode.com/problems/k-m-p-matcher/
// The KMP (Knuth-Morris-Pratt) matcher is a string searching algorithm that efficiently searches for occurrences of a word within a main string.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m) complexity
class KMPMatcherBruteForce {
public:
    std::vector<int> kmpMatcher(const std::string& s, const std::string& p) {
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
};

// Optimal solution with O(n+m) complexity
class KMPMatcherOptimal {
public:
    std::vector<int> kmpMatcher(const std::string& s, const std::string& p) {
        std::vector<int> lps(p.size(), 0);
        computeLPSArray(p, lps);
        std::vector<int> result;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (p[j] == s[i]) {
                i++;
                j++;
            }
            if (j == p.size()) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < s.size() && p[j] != s[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    void computeLPSArray(const std::string& p, std::vector<int>& lps) {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while (i < p.size()) {
            if (p[i] == p[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};

int main() {
    KMPMatcherOptimal matcher;
    std::string s = "abxabcabcaby";
    std::string p = "abcaby";
    std::vector<int> result = matcher.kmpMatcher(s, p);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    s = "hello";
    p = "ll";
    result = matcher.kmpMatcher(s, p);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    s = "aaaaa";
    p = "bba";
    result = matcher.kmpMatcher(s, p);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```