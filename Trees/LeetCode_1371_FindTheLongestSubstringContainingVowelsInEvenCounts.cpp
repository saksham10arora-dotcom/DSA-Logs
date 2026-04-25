```cpp
// LeetCode problem 1371: Find The Longest Substring Containing Vowels In Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// Given the string s, find the longest substring that contains at least one vowel and has all vowels in even counts.

#include <iostream>
#include <string>
#include <unordered_map>

// Brute force approach: O(n^3) complexity
// int findTheLongestSubstring(std::string s) {
//     int maxLen = 0;
//     for (int i = 0; i < s.size(); i++) {
//         for (int j = i + 1; j <= s.size(); j++) {
//             std::string substr = s.substr(i, j - i);
//             int count[5] = {0};
//             for (char c : substr) {
//                 if (c == 'a') count[0]++;
//                 else if (c == 'e') count[1]++;
//                 else if (c == 'i') count[2]++;
//                 else if (c == 'o') count[3]++;
//                 else if (c == 'u') count[4]++;
//             }
//             bool allEven = true;
//             for (int k = 0; k < 5; k++) {
//                 if (count[k] % 2 != 0) {
//                     allEven = false;
//                     break;
//                 }
//             }
//             if (allEven && substr.find_first_of("aeiou") != std::string::npos) {
//                 maxLen = std::max(maxLen, (int)substr.size());
//             }
//         }
//     }
//     return maxLen;
// }

// Optimal solution: O(n) complexity
int findTheLongestSubstring(std::string s) {
    int maxLen = 0;
    std::unordered_map<int, int> countToIndex;
    countToIndex[0] = -1;
    int count[5] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') count[0]++;
        else if (s[i] == 'e') count[1]++;
        else if (s[i] == 'i') count[2]++;
        else if (s[i] == 'o') count[3]++;
        else if (s[i] == 'u') count[4]++;
        int key = 0;
        for (int j = 0; j < 5; j++) {
            key ^= (count[j] % 2) << j;
        }
        if (countToIndex.find(key) != countToIndex.end()) {
            maxLen = std::max(maxLen, i - countToIndex[key]);
        } else {
            countToIndex[key] = i;
        }
    }
    return maxLen;
}

int main() {
    std::cout << findTheLongestSubstring("eleetminicoworoep") << std::endl;  // Output: 13
    std::cout << findTheLongestSubstring("leetcodeisawesome") << std::endl;  // Output: 0
    std::cout << findTheLongestSubstring("a") << std::endl;  // Output: 0
    return 0;
}
```