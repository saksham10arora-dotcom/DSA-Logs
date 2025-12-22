/**
 * Problem: Longest Palindromic Substring (LeetCode 5)
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Manacher's Algorithm) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
string longestPalindrome(string s) {
    string t = "#";
    for (char c : s) { t += c; t += "#"; }
    int n = t.size();
    vector<int> p(n, 0);
    int c = 0, r = 0, maxLen = 0, centerIndex = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mirror]);
        while (i + 1 + p[i] < n && i - 1 - p[i] >= 0 && t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) { c = i; r = i + p[i]; }
        if (p[i] > maxLen) { maxLen = p[i]; centerIndex = i; }
    }
    return s.substr((centerIndex - maxLen) / 2, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindrome: " << longestPalindrome(s) << endl;
    return 0;
}










