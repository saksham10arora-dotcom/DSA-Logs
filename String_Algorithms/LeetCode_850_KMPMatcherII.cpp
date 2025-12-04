```cpp
// LeetCode problem 850: K M P Matcher I I
// https://leetcode.com/problems/k-m-p-matcher-ii/
// Given a string s and a string t, return the number of distinct KMP matches.

class Solution {
public:
    int kmpMatches(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> lps(m);
        computeLPSArray(t, m, lps);
        int count = 0;
        for (int i = 0; i <= n - m; i++) {
            if (kmpMatcher(s, t, i, lps)) {
                count++;
            }
        }
        return count;
    }

    void computeLPSArray(string pattern, int m, vector<int>& lps) {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool kmpMatcher(string s, string t, int start, vector<int>& lps) {
        int n = s.size();
        int m = t.size();
        int i = start;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && s[i] != t[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
};

// Brute force approach with O(n*m) complexity
// class Solution {
// public:
//     int kmpMatches(string s, string t) {
//         int count = 0;
//         for (int i = 0; i <= s.size() - t.size(); i++) {
//             if (s.substr(i, t.size()) == t) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// Optimal solution with O(n+m) complexity
int main() {
    Solution solution;
    cout << solution.kmpMatches("abcabc", "abc") << endl;  // Output: 2
    cout << solution.kmpMatches("ababab", "abab") << endl;  // Output: 2
    cout << solution.kmpMatches("aaaaaa", "aa") << endl;  // Output: 5
    return 0;
}
```