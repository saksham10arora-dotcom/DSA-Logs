/**
 * Problem: Longest Repeating Character Replacement (LeetCode 424)
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Sliding Window) ---
// Time Complexity: O(N)
// Space Complexity: O(26)
int characterReplacement(string s, int k) {
    int left = 0, right = 0, maxCount = 0, maxLen = 0;
    vector<int> count(26, 0);
    while (right < s.length()) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        if ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    cout << "Max Len: " << characterReplacement(s, k) << endl;
    return 0;
}





























