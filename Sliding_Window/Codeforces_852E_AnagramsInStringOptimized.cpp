```cpp
// Codeforces_852E_AnagramsInStringOptimized
// https://codeforces.com/contest/852/problem/E
// Find all anagrams of a given string in another string.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n*m*log(m)) complexity
std::vector<int> bruteForce(const std::string& s, const std::string& p) {
    std::vector<int> result;
    std::string sortedP = p;
    std::sort(sortedP.begin(), sortedP.end());
    for (int i = 0; i <= s.size() - p.size(); ++i) {
        std::string substr = s.substr(i, p.size());
        std::string sortedSubstr = substr;
        std::sort(sortedSubstr.begin(), sortedSubstr.end());
        if (sortedSubstr == sortedP) {
            result.push_back(i);
        }
    }
    return result;
}

// Optimal solution: O(n) complexity
std::vector<int> optimalSolution(const std::string& s, const std::string& p) {
    std::vector<int> result;
    if (s.size() < p.size()) return result;
    std::unordered_map<char, int> pCount;
    for (char c : p) {
        ++pCount[c];
    }
    std::unordered_map<char, int> windowCount;
    for (int i = 0; i < p.size(); ++i) {
        ++windowCount[s[i]];
    }
    if (windowCount == pCount) {
        result.push_back(0);
    }
    for (int i = p.size(); i < s.size(); ++i) {
        --windowCount[s[i - p.size()]];
        if (windowCount[s[i - p.size()]] == 0) {
            windowCount.erase(s[i - p.size()]);
        }
        ++windowCount[s[i]];
        if (windowCount == pCount) {
            result.push_back(i - p.size() + 1);
        }
    }
    return result;
}

int main() {
    std::string s1 = "abxaba";
    std::string p1 = "ab";
    std::vector<int> result1 = optimalSolution(s1, p1);
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string s2 = "abcde";
    std::string p2 = "cd";
    std::vector<int> result2 = optimalSolution(s2, p2);
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string s3 = "aaaaa";
    std::string p3 = "aa";
    std::vector<int> result3 = optimalSolution(s3, p3);
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```