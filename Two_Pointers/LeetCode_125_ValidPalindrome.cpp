/**
 * Problem: Valid Palindrome (LeetCode 125)
 * Link: https://leetcode.com/problems/valid-palindrome/
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// --- Optimal Solution (Two Pointers) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
        } else if (!isalnum(s[right])) {
            right--;
        } else {
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(s) ? "True" : "False") << endl;
    return 0;
}



























