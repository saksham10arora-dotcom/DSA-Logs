/**
 * Problem: Longest Substring Without Repeating Characters (LeetCode 3)
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Sliding Window) ---
// Time Complexity: O(N)
// Space Complexity: O(min(m, n)) - m is the size of the charset
int lengthOfLongestSubstring(string s) {
    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n) {
        if (mpp[s[right]] != -1) {
            left = max(mpp[s[right]] + 1, left);
        }
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main() {
    string s = "abcabcbb";
    cout << "Length: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}



























