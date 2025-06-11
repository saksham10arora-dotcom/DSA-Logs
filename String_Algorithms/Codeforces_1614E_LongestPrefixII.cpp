```cpp
// Codeforces_1614E_LongestPrefixII
// https://codeforces.com/contest/1614/problem/E
// Given a string s, find the longest prefix that is also a suffix of the string.

#include <iostream>
#include <string>

// Brute force approach with O(n^2) complexity
std::string longestPrefixSuffixBruteForce(const std::string& s) {
    for (int i = s.length() - 1; i >= 0; --i) {
        std::string prefix = s.substr(0, i + 1);
        std::string suffix = s.substr(s.length() - i - 1);
        if (prefix == suffix) {
            return prefix;
        }
    }
    return "";
}

// Optimal solution with O(n) complexity using KMP algorithm
std::string longestPrefixSuffixOptimal(const std::string& s) {
    int n = s.length();
    std::string t = s + "#" + s;
    int lps[n + 2];
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i <= 2 * n) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len!= 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return s.substr(0, lps[2 * n - 1]);
}

int main() {
    std::string testCases[] = {"abab", "aaaa", "abcde"};
    for (const auto& testCase : testCases) {
        std::cout << "Test case: " << testCase << std::endl;
        std::cout << "Brute force: " << longestPrefixSuffixBruteForce(testCase) << std::endl;
        std::cout << "Optimal: " << longestPrefixSuffixOptimal(testCase) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
```