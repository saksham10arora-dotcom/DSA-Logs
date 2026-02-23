```cpp
// LeetCode problem 125: Valid Palindrome, https://leetcode.com/problems/valid-palindrome/
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
// it reads the same backward as forward. Return true if the given string is a palindrome. Otherwise, return false.

// Brute force approach: Create a new string with only alphanumeric characters and compare it with its reverse. O(n) + O(n) = O(2n) = O(n)
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string str;
//         for (char c : s) {
//             if (isalnum(c)) {
//                 str += tolower(c);
//             }
//         }
//         string rev = str;
//         reverse(rev.begin(), rev.end());
//         return str == rev;
//     }
// };

// Optimal solution: Use two pointers to compare characters from both ends. O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << boolalpha;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;  // True
    cout << solution.isPalindrome("Not a palindrome") << endl;  // False
    cout << solution.isPalindrome("Was it a car or a cat I saw?") << endl;  // True
    return 0;
}
```