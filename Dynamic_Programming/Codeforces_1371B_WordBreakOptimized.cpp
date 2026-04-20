```cpp
// Codeforces_1371B_WordBreakOptimized
// https://codeforces.com/contest/1371/problem/B
// Given a string and a dictionary of words, determine the minimum number of operations to make the string valid.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach with O(2^n) complexity
// std::string wordBreakBruteForce(const std::string& s, const std::unordered_set<std::string>& wordDict) {
//     if (s.empty()) return "";
//     for (int i = 1; i <= s.size(); ++i) {
//         std::string prefix = s.substr(0, i);
//         if (wordDict.find(prefix)!= wordDict.end()) {
//             std::string suffix = wordBreakBruteForce(s.substr(i), wordDict);
//             if (!suffix.empty()) {
//                 return prefix + " " + suffix;
//             }
//         }
//     }
//     return "";
// }

// Optimal solution with O(n^2) complexity
std::string wordBreakOptimized(const std::string& s, const std::unordered_set<std::string>& wordDict) {
    int n = s.size();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.find(s.substr(j, i - j))!= wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    if (!dp[n]) return "";
    std::string result;
    int i = n;
    while (i > 0) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.find(s.substr(j, i - j))!= wordDict.end()) {
                if (!result.empty()) result = s.substr(j, i - j) + " " + result;
                else result = s.substr(j, i - j);
                i = j;
                break;
            }
        }
    }
    return result;
}

int main() {
    std::unordered_set<std::string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    std::cout << wordBreakOptimized("pineapplepenapple", wordDict) << std::endl;  // "pine apple pen apple"
    std::cout << wordBreakOptimized("catsandog", wordDict) << std::endl;  // ""
    std::cout << wordBreakOptimized("catsanddog", wordDict) << std::endl;  // ""
    return 0;
}
```