```cpp
// Codeforces_1348A_WordBreakVariant, https://codeforces.com/contest/1348/problem/A
// Given a string and a set of words, determine if the string can be broken into words from the set.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach: try all possible word breaks, O(2^n) complexity
// bool canBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
//     if (s.empty()) return true;
//     for (int i = 1; i <= s.size(); ++i) {
//         if (wordDict.find(s.substr(0, i))!= wordDict.end() && canBreak(s.substr(i), wordDict)) {
//             return true;
//         }
//     }
//     return false;
// }

// Optimal solution: use dynamic programming to store intermediate results, O(n^2) complexity
bool canBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
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
    return dp[n];
}

int main() {
    std::unordered_set<std::string> wordDict1 = {"apple", "pen"};
    std::cout << std::boolalpha << canBreak("applepenapple", wordDict1) << std::endl;  // true

    std::unordered_set<std::string> wordDict2 = {"cats", "dog", "sand", "and", "cat"};
    std::cout << std::boolalpha << canBreak("catsandog", wordDict2) << std::endl;  // false

    std::unordered_set<std::string> wordDict3 = {"a", "b", "c"};
    std::cout << std::boolalpha << canBreak("abc", wordDict3) << std::endl;  // true

    return 0;
}
```